CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -O
LDLIBS=-lm
# RUSTC=rustc
RUSTC=clippy-driver --rustc
RUSTFLAGS=-C opt-level=3

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

%: %.rs
	$(RUSTC) $(RUSTFLAGS) $@.rs

%: %.c
	if grep -q 'gmp.h' $@.c; then \
		$(CC) $(CFLAGS) $@.c -o $@ $(LDLIBS) -lgmp; \
	else \
		$(CC) $(CFLAGS) $@.c -o $@ $(LDLIBS); \
	fi
