CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -O
LDLIBS=-lm

all:
	for file in $$(ls *.c); do \
	    make --silent $${file%.*}; \
	done

clean:
	for file in $$(ls); do \
		if git check-ignore -q $$file; then \
			rm $$file; \
		fi; \
	done; \

%: %.c
	if grep -q 'gmp.h' $@.c; then \
		$(CC) $(CFLAGS) $@.c -o $@ $(LDLIBS) -lgmp; \
	else \
		$(CC) $(CFLAGS) $@.c -o $@ $(LDLIBS); \
	fi
