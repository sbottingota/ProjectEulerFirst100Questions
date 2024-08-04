CC=gcc
CFLAGS=-Wall -Wextra -O
LDLIBS=-lm

%: %.c %.txt
	$(CC) $(CFLAGS) $@.c -o $@ $(LDLIBS)
