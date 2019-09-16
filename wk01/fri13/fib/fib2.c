// Prints out the first 50 Fibonacci numbers

#include <stdio.h>
#include <unistd.h>

typedef unsigned long long ull;

ull fib(unsigned int n);

int main(void) {

    for (int i = 0; i <= 50; i++) {
        printf("\t\t\t\t\t[fib2] fib(%d) = %llu\n", i, fib(i));
    }

    printf("\t\t\t\t\t[fib2] Done\n");
}

ull fib(unsigned int n) {
    if (n == 0) return 0;
    
    int i = 1;
    ull q = 0; // fib(i - 1)
    ull r = 1; // fib(i)
    while (i < n) {
        r = q + r;
        q = r - q;
        i++;
    }
    return r;
}
