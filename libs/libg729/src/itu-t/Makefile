#CFLAGS += -Wall -O3 -funroll-loops -fPIC -ggdb
CFLAGS += -lm -fPIC -w -fvisibility=hidden -DSWITCH_API_VISIBILITY=1 -DHAVE_VISIBILITY=1 -DHAVE_OPENSSL -O2 -std=c99 -pedantic -D_GNU_SOURCE -DHAVE_CONFIG_H
LIB=libg729.a

OBJS=\
acelp_ca.o \
basic_op.o \
cod_ld8a.o \
cor_func.o \
de_acelp.o \
dec_gain.o \
dec_lag3.o \
dec_ld8a.o \
dspfunc.o \
filter.o \
gainpred.o \
lpc.o \
lpcfunc.o \
lspdec.o \
lspgetq.o \
oper_32b.o \
pitch_a.o \
postfilt.o \
post_pro.o \
p_parity.o \
pred_lt3.o \
pre_proc.o \
qua_gain.o \
qua_lsp.o \
tab_ld8a.o \
taming.o \
util.o

all: $(LIB)


$(LIB): $(OBJS)
#	ar cr $(LIB) $(OBJS)
#	ranlib $(LIB)

clean:
	rm -f $(LIB) *.o

install:

