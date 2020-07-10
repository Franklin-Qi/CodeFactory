CC=gcc
CFLAGS=-Wall -g -Wno-pointer-sign

BIN = libmyso.so
LIBLD= -L../lib64/ -lmyso

#TEST=soexe

.PHONY: all
all: $(BIN)
libmyso.so:log.c
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $^
	cp libmyso.so ../lib64/

#test: $(TEST)
#soexe: main.c
#	$(CC) $(CFLAGS) -o $@ $^ $(LIBLD)

clean:
	rm -f *.o *.so testing soexe exe TEST
