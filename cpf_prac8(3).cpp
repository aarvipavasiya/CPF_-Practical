#include <stdio.h>

// ---------- Prototypes ----------
long long factorialIterative(int n);
long long factorialRecursive(int n);
int fibonacciRecursive(int n);
void fibonacciIterative(int n);

// Counter to show Number of Function Calls
int recCalls = 0;

int main() {
    int n, i;
    long long factI, factR;

    printf("********************************************\n");
    printf("  RECURSIVE MATHEMATICAL OPERATIONS\n");
    printf("             ANALYZER\n");
    printf("********************************************\n\n");

    // ---------- Part A : Factorial ----------
    printf("--------------------------------------------\n");
    printf("Part A - Factorial\n");
    printf("--------------------------------------------\n\n");
    printf("Enter Number : ");
    scanf("%d", &n);

    factI = factorialIterative(n);

    recCalls = 0;
    factR = factorialRecursive(n);
    int factCalls = recCalls;

    printf("\nIterative Factorial : %lld\n", factI);
    printf("Recursive Factorial : %lld\n", factR);
    printf("Recursive Function Calls : %d\n", factCalls);

    // ---------- Part B : Fibonacci ----------
    printf("\n--------------------------------------------\n");
    printf("Part B - Fibonacci Series\n");
    printf("--------------------------------------------\n\n");
    printf("Enter Number of Terms : ");
    scanf("%d", &n);

    printf("\nIterative Fibonacci Series : ");
    fibonacciIterative(n);

    recCalls = 0;
    printf("\nRecursive Fibonacci Series : ");
    for(i = 0; i < n; i++) {
        printf("%d ", fibonacciRecursive(i));
    }
    printf("\nRecursive Function Calls : %d\n", recCalls);

    // ---------- Part C : Comparison ----------
    printf("\n--------------------------------------------\n");
    printf("Part C - Comparison\n");
    printf("--------------------------------------------\n\n");
    printf("Parameter              Iterative       Recursive\n");
    printf("------------------------------------------------\n");
    printf("Function Calls         1               Many\n");
    printf("Program Readability    Moderate        High\n");
    printf("Code Complexity        More lines      Less lines\n");
    printf("Execution Flow         Loop            Self-Call + Stack\n");
    printf("Memory Usage           Low             High (Stack)\n");
    printf("Speed                  Fast            Slow for Fibonacci\n");

    printf("\n--------------------------------------------\n");
    printf("Conclusion: Recursion is readable but uses\n");
    printf("more stack memory and function calls.\n");
    printf("--------------------------------------------\n");

    return 0;
}

// ---------- Part A Definitions ----------

// Iterative Factorial : using for loop
long long factorialIterative(int n) {
    long long fact = 1;
    for(int i = 1; i <= n; i++)
        fact = fact * i;
    return fact;
}

// Recursive Factorial : fact(n) = n * fact(n-1)
long long factorialRecursive(int n) {
    recCalls++;
    if(n == 0 || n == 1)
        return 1;
    return n * factorialRecursive(n - 1);
}

// ---------- Part B Definitions ----------

// Iterative Fibonacci : using loop
void fibonacciIterative(int n) {
    int a = 0, b = 1, c, i;
    for(i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

// Recursive Fibonacci : fib(n) = fib(n-1) + fib(n-2)
int fibonacciRecursive(int n) {
    recCalls++;
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
