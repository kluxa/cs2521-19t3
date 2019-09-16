
CC = gcc
CFLAGS = -Wall -Werror -std=c11
BINS = sumList listRefresher

.PHONY: all
all: $(BINS)

sumList: sumList.c list.c
listRefresher: listRefresher.c list.c

.PHONY: clean
clean:
	rm -f $(BINS)

# What does .PHONY mean?
# https://stackoverflow.com/questions/2145590/what-is-the-purpose-of-phony-in-a-makefile

