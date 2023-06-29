#CFLAGS += -Wall -O3 -funroll-loops -fPIC -ggdb

CFLAGS += -lm -fPIC -Werror -Wno-unused-result -fvisibility=hidden -DSWITCH_API_VISIBILITY=1 -DHAVE_VISIBILITY=1 -DHAVE_OPENSSL -O2 -Wall -std=c99 -pedantic -Wdeclaration-after-statement -D_GNU_SOURCE -DHAVE_CONFIG_H

ITUTDIR = itu-t
IPPDIR = ipp

LIB = libg729.a
	
all : itu-t_sub libg729.itu-t.o
	ar cr $(LIB) $(ITUTDIR)/*.o libg729.o
	ranlib $(LIB)

ipp : ipp_sub libg729.ipp.o
	ar cr $(LIB) $(IPPDIR)/*.o libg729.o
	ranlib $(LIB)

libg729.itu-t.o:
	gcc $(CFLAGS) -c -o libg729.o libg729.itu-t.c 

libg729.ipp.o:
	gcc $(CFLAGS) -c -o libg729.o libg729.ipp.c

itu-t_sub :
	for dir in $(ITUTDIR); do \
		$(MAKE) -C $$dir; \
	done

ipp_sub :
	for dir in $(IPPDIR); do \
                $(MAKE) -C $$dir; \
        done

clean :
	for dir in $(ITUTDIR); do \
		$(MAKE) clean -C $$dir; \
        done
	#for dir in $(IPPDIR); do \
	#	$(MAKE) clean -C $$dir; \
        #done
	rm -f $(LIB) *.o

install : 
	mkdir -p ../.libs
	cp $(LIB) ../.libs/

uninstall :
	rm -rf ../.libs
