
CC = gcc
CFLAGS = -Wall -Werror -std=c11 -g

.PHONY: all
all: testReachable

testReachable: testReachable.c reachable.c Graph.c Set.c Queue.c
	$(CC) $(CFLAGS) -o testReachable testReachable.c reachable.c Graph.c Set.c Queue.c

.PHONY: clean
clean:
	rm -f testReachable

