CC = gcc
CFLAGS = -O2 -Wall -I ..

all: adder subtraction

adder: adder.c
	$(CC) $(CFLAGS) -o adder adder.c
subtraction:subtraction.c
	$(CC) $(CFLAGS) -o subtraction subtraction.c

clean:
	rm -f adder *~
