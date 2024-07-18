CFLAGS=-Wall -Wextra -lm

%: %.c
	gcc $@.c -o $@ $(CFLAGS)

clean:
	find . -perm /111 -type f -exec echo rm -v {} \;

