// Prints out the first 55 Fibonacci numbers

#include <stdio.h>
#include <unistd.h>

typedef unsigned long long ull;

ull fib(unsigned int n);

int main(void) {

    for (int i = 0; i <= 55; i++) {
        printf("[fib1] fib(%d) = %llu\n", i, fib(i));
    }

    printf("[fib1] Done\n");
}

// a very inefficient way of
// calculating Fibonacci numbers
ull fib(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}
