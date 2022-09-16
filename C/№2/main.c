#include <stdio.h>
#include <limits.h>

signed char a, b;
void calc() {
    scanf("%hhu", &a);
    scanf("%hhu", &b);
    if(b == 0) {
        printf("Division by zero >:c");
        return;
    }
    printf("+: %d, -: %d, /: %d, *: %d, &: %d, |: %d, %%: %d, ^: %d, >=: %d, <=: %d, >: %d, <: %d, >>: %d, <<: %d, !=: %d, ==: %d, ~: %d, &&: %d, ||: %d, !: %d\n",
           a + b, a - b, a / b, a * b, a & b, a | b, a % b, a ^ b, a >= b, a <= b, a > b, a < b, a >> b, a << b, a != b, a == b, ~a, a && b, a || b, !a);
}

void year() {
    int yr;
    scanf("%d", &yr);
    if(yr % 4 == 0 && yr % 100 != 0 || yr % 400 == 0) {
        printf("Leap year");
    } else {
        printf("Non-leap year");
    }
}

void fizz_buzz() {
    unsigned long N;
    scanf("%ld", &N);
    for(unsigned long i = 0; i <= N; i++)
        if(i % 3 == 0)
            printf("fizz\n");
        else if(i % 5 == 0)
            printf("buzz\n");
        else if(i % 3 == 0 && i % 5 == 0)
            printf("fizz buzz\n");
}

unsigned long searchDiv(unsigned long x) {
    unsigned long div = -1;
    for(unsigned long i = x - 1; i > 0; i--)
        if(x % i == 0) {
            div = i;
            break;
        }
    return div;
}

void sqr() {
    unsigned long N;
    scanf("%ld", &N);
    unsigned long j = 0;
    for(unsigned long i = 0; i < N*N; i++) {
        printf("%ld ", i);
        j++;
        if(j == N) {
            printf("  <-~-~ %ld\n", N);
            j = 0;
        }
    }
}

void triangle() {
    unsigned long N;
    scanf("%ld", &N);
    unsigned long iter = 1, cnt = 0;
    while(cnt < N) {
        for(unsigned long i = 0; i < iter; i++) {
            printf("%ld ", cnt);
            cnt++;
        }
        iter++;
        printf("\n");
    }
}

char checkSimpleNumber(unsigned long long n) {
    char simple = 1;
    if(n == 2)
        simple = 0;
    for(unsigned long long i = 2; i < n; i++)
        if(n % i == 0) {
            simple = 0;
            break;
        }
    return simple;
}

void simpleNumber() {
    unsigned long long N;
    scanf("%lld", &N);
    if(N < 2) {
        printf("Input err");
        return;
    }
    if(checkSimpleNumber(N))
        printf("Number is simple");
    else
        printf("Number is not simple");
}

void simpleNumbers() {
    unsigned long long N;
    scanf("%lld", &N);
    if(N < 2) {
        printf("Input err");
        return;
    }
    for(unsigned long long i = 2; i <= N; i++)
        if(checkSimpleNumber(i))
            printf("%lld\n", i);
}

void funnyTask() {
    unsigned long L, R;
    scanf("%ld%ld", &L, &R);
    if(L > R) {
        printf("Incorrect data >:C");
        return;
    }
    for(; L <= R; L++)
        if(L >= 100000 && L < 1000000 && L % 1000 == L / 1000)
            printf("%ld\n", L);
}

void withSC(signed long long *operations[]) {
    for(int i = 0; i < sizeof(operations); i++) {
        if(operations[i] > CHAR_MAX) {
            printf("\nOverflow 'signed char'!!!!!!!!!!\n");
            return;
        }
        printf("%lld\n", operations[i]);
    }
    printf("No overflow detected");
}

void superCalc() {
    scanf("%hhu", &a);
    scanf("%hhu", &b);
    if(b == 0) {
        printf("Division by zero >:c");
        return;
    }
    signed long long op[] = {a + b, a - b, a / b, a * b, a & b, a | b, a % b, a ^ b, a >= b, a <= b, a > b, a < b, a >> b, a << b, a != b, a == b, ~a, a && b, a || b, !a};
    withSC(op);
}

int main() {
//    calc();
//    year();
//    fizz_buzz();
//    sqr();
//    triangle();
//    simpleNumber();
//    simpleNumbers();
//    funnyTask();
//    superCalc();
    return 0;
}