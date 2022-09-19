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

/* START TASK 2 */

int NOD(int x, int y) {
    assert(x > 0 && y > 0);
    while(x != y) {
        if(x > y)
            x -= y;
        else
            y -= x;
    }
    return y;
}

void task2() {
    printf("%d", NOD(37, 74));
}

/* END TASK 2 */

/* START TASK 3 */

int max(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9, int x10) {
    int x0 = 0;
    if(x1 > x0) x0 = x1;
    if(x2 > x0) x0 = x2;
    if(x3 > x0) x0 = x3;
    if(x4 > x0) x0 = x4;
    if(x5 > x0) x0 = x5;
    if(x6 > x0) x0 = x6;
    if(x7 > x0) x0 = x7;
    if(x8 > x0) x0 = x8;
    if(x9 > x0) x0 = x9;
    if(x10 > x0) x0 = x10;
    return x0;
}

void task3() {
    printf("%d", max(10, 4, 5, 7, 4, 22, 64, 43, 75, 23));
}

/* END TASK 3 */

// ----------------------------------------------------------------------------------

/* GROUP №04 */

/* START TASK 0 */

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void task00() {
    int a = 10, b = 20;
    printf("%d, %d\n", a, b);
    swap(&a, &b);
    printf("%d, %d\n", a, b);
}

/* END TASK 0 */

/* START TASK 1 */

void foo() {
    int a = 12;
    printf("%d\n", &a);
}

void task01() {
    foo();
    foo();
}

/* END TASK 1 */

int main() {
    task01();
    return 0;
}
