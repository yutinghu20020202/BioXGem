#include <stdio.h>

typedef unsigned long long uint64_t;

// 0 1 1 2 3 5 8
// 0 1 2 3 4 5 6

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1) {
    if (k == 0) {
        *f2k = 0; // fib(0)
        *f2k1 = 1; // fib(1)
        return;
    }

    uint64_t fk, fk1; // k / 2
    fib_aux(k, &fk, &fk1); //fib(k) and fib(k+1)

    *f2k = fk * (2 * fk1 - fk);      // fib(2k)
    *f2k1 = fk * fk + fk1 * fk1;     // fib(2k+1)
}

void fib_aux(unsigned n, uint64_t *fn, uint64_t *fn1) {
    if (n == 0) {
        *fn = 0;
        *fn1 = 1;
        return;
    }

    uint64_t a, b;
    fib_aux(n / 2, &a, &b); // n / 2

    uint64_t c = a * (2 * b - a);    //fib(n)
    uint64_t d = a * a + b * b;      //fib(n+1)

    if (n % 2 == 0) {
        *fn = c;
        *fn1 = d;
    } else {
        *fn = d;
        *fn1 = c + d;
    }
}

int main()
{
    unsigned k;
    scanf("%u", &k);

    uint64_t f2k, f2k1;
    fib_fast_doubling(k / 2, &f2k, &f2k1);

    printf("%llu", (k & 0x1) ? f2k1 : f2k);

    return 0;
}