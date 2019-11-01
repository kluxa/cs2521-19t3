
CC = gcc
CFLAGS = -Wall -Werror -std=c11 -g

all: testList

testList: testList.c list.c
	$(CC) $(CFLAGS) -o testList testList.c list.c

.PHONY: clean
clean:
	rm -f testList
