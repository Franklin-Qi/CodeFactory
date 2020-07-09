CC=gcc -Wall -g

CALLLIBS=

all: mysudo

mysudo: mysudo.c
	$(CC) $^ -o $@ $(CALLLIBS) 

.PHONY: clean
clean:
	rm -f *.o mysudo
