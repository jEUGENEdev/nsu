#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

/* START TASK 0 */

char isPrime(unsigned long long x) {
    assert(x >= 2);
    for(unsigned long long i = 2; i <= (unsigned long long) sqrt((double) x); i++)
        if(x % i == 0) {
            return 0;
        }
    return 1;
}

void task0() {
    unsigned long long N;
    scanf("%lld", &N);
    for(unsigned long long i = 2; i <= N; i++)
        if(isPrime(i))
            printf("%lld\n", i);
}

/* END TASK 0 */

/* START TASK 1 */

int countDivs(int x) {
    assert(x > 0);
    int count = 0;
    for(int i = 1; i <= (int) sqrt(x); i++)
        if(x % i == 0)
            count += 2;
    return count;
}

void task1() {
    printf("%d", countDivs(100));
}

/* END TASK 1 */

int main() {
    task1();
    return 0;
}
