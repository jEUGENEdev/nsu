#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

char isPrime(unsigned long long x) {
    assert(x >= 2);
    for(unsigned long long i = 2; i <= sqrt((double) x); i++)
        if(x % i == 0) {
            return 0;
        }
    return 1;
}

int main() {
    unsigned long long N;
    scanf("%lld", &N);
    printf("is prime: %d\n", isPrime(N));
    return 0;
}
