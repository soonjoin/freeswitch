#include <string.h>

#include "include/g729.h"

#include "itu-t/typedef.h"
#include "itu-t/basic_op.h"
#include "itu-t/ld8a.h"
#include "itu-t/tab_ld8a.h"
#include "itu-t/util.h"
#include "itu-t/pre_proc.h"

void g729_init_lib(){}

void g729_init_coder(PVT *hEncoder, int dummy){
    struct g72x_coder_pvt *state = hEncoder;
    state->coder = Init_Coder_ld8a();
    Init_Pre_Process(state->coder);
    return;
}

void g729_release_coder(PVT *hEncoder){
    struct g72x_coder_pvt *state = hEncoder;
    free (state->coder);
    free (state->scratch_mem);
}

void g729_init_decoder(PVT *hDecoder){
    struct g72x_coder_pvt *state = hDecoder;
    state->coder = Init_Decod_ld8a();
    Init_Post_Filter(state->coder);
    Init_Post_Process(state->coder);
    return;
}

void g729_release_decoder(PVT *hDecoder){
    struct g72x_coder_pvt *state = hDecoder;
    free (state->coder);
    free (state->scratch_mem);
}

void g729_coder(PVT *hEncoder, short *ddp, char *edp, int *cbret){
        Word16 parm[PRM_SIZE];

        Copy ((Word16 *) ddp, ((CodState*)hEncoder->coder)->new_speech, 80);
        Pre_Process(hEncoder->coder, ((CodState*)hEncoder->coder)->new_speech, 80);
        Coder_ld8a(hEncoder->coder, parm);
        Store_Params(parm, edp);
}

void g729_decoder(PVT *hDecoder, short *ddp, char *edp, int plen){
        Word16 i;
        Word16 *synth;
        Word16 parm[PRM_SIZE + 1];

        Restore_Params(edp, &parm[1]);
        synth = ((DecState*)hDecoder->coder)->synth_buf + M;

        parm[0] = 1;
        for (i = 0; i < PRM_SIZE; i++) {
                if (parm[i + 1] != 0) {
                        parm[0] = 0;
                        break;
                }
        }

        parm[4] = Check_Parity_Pitch(parm[3], parm[4]);	

        Decod_ld8a(hDecoder->coder, parm, synth, ((DecState*)hDecoder->coder)->Az_dec, 
                                            ((DecState*)hDecoder->coder)->T2, &((DecState*)hDecoder->coder)->bad_lsf);
        Post_Filter(hDecoder->coder, synth, ((DecState*)hDecoder->coder)->Az_dec, ((DecState*)hDecoder->coder)->T2);
        Post_Process(hDecoder->coder, synth, L_FRAME);
        memmove( ddp, synth, 2 * L_FRAME);
}

