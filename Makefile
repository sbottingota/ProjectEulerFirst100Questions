CC=gcc
CFLAGS=-Wall -Wextra -O
LDLIBS=-lm

%: %.c
	if grep -q 'gmp.h' $@.c; then \
		$(CC) $(CFLAGS) $@.c -o $@ $(LDLIBS) -lgmp; \
	else \
		$(CC) $(CFLAGS) $@.c -o $@ $(LDLIBS); \
	fi

clean:
	for file in $$(ls); do \
		if git check-ignore -q $$file; then \
			rm $$file; \
		fi; \
	done; \
