#include <stdio.h>

// ---------- Prototypes ----------
void print1toN(int n);
void printNto1(int n);
int reverseNumber(int n, int rev);
int sumOfDigits(int n);
void decimalToBinary(int n);

int main() {
    int N, num, rev, sum;

    printf("********************************************\n");
    printf("      RECURSIVE UTILITY ANALYZER\n");
    printf("********************************************\n\n");

    // ---------- Part A : Recursive Traversal ----------
    printf("--------------------------------------------\n");
    printf("Part A - Recursive Traversal\n");
    printf("--------------------------------------------\n\n");
    printf("Enter Value of N : ");
    scanf("%d", &N);

    printf("\nNumbers from 1 to N : ");
    print1toN(N);

    printf("\nNumbers from N to 1 : ");
    printNto1(N);
    printf("\n");

    // ---------- Part B : Recursive Number Processing ----------
    printf("\n--------------------------------------------\n");
    printf("Part B - Recursive Number Processing\n");
    printf("--------------------------------------------\n\n");
    printf("Enter Number : ");
    scanf("%d", &num);

    rev = reverseNumber(num, 0);
    sum = sumOfDigits(num);

    printf("\nReverse Number : %d\n", rev);
    printf("Sum of Digits  : %d\n", sum);

    // ---------- Part C : Recursive Number Conversion ----------
    printf("\n--------------------------------------------\n");
    printf("Part C - Decimal to Binary\n");
    printf("--------------------------------------------\n\n");
    printf("Enter Decimal Number : ");
    scanf("%d", &num);

    printf("\nBinary Representation : ");
    if(num == 0)
        printf("0");
    else
        decimalToBinary(num);
    printf("\n");

    // ---------- Part D : Comparative Analysis ----------
    printf("\n--------------------------------------------\n");
    printf("Part D - Comparative Analysis\n");
    printf("--------------------------------------------\n\n");
    printf("Parameter              Iterative       Recursive\n");
    printf("------------------------------------------------\n");
    printf("Program Readability    Moderate        High\n");
    printf("Execution Flow         Loop            Self-Call + Stack\n");
    printf("Function Calls         1               Many\n");
    printf("Memory Usage           Low             High (Stack)\n");
    printf("Code Complexity        More lines      Less lines\n");
    printf("\n--------------------------------------------\n");
    printf("Conclusion: Recursion is readable but uses\n");
    printf("more stack memory and function calls.\n");
    printf("--------------------------------------------\n");

    return 0;
}

// ---------- Part A Definitions ----------

// Print 1 to N : Print AFTER recursive call
// For N=5 : print1toN(5) -> print1toN(4) -> ... -> print 1,2,3,4,5
void print1toN(int n) {
    if(n == 0) return; // Base Case
    print1toN(n - 1);
    printf("%d ", n);
}

// Print N to 1 : Print BEFORE recursive call
void printNto1(int n) {
    if(n == 0) return; // Base Case
    printf("%d ", n);
    printNto1(n - 1);
}

// ---------- Part B Definitions ----------

// Reverse : rev = rev*10 + last digit
int reverseNumber(int n, int rev) {
    if(n == 0) return rev; // Base Case
    return reverseNumber(n / 10, rev * 10 + n % 10);
}

// Sum of Digits : sum(n) = (n%10) + sum(n/10)
int sumOfDigits(int n) {
    if(n == 0) return 0; // Base Case
    return (n % 10) + sumOfDigits(n / 10);
}

// ---------- Part C Definitions ----------

// Binary : Print AFTER recursive call to get correct order
void decimalToBinary(int n) {
    if(n == 0) return; // Base Case
    decimalToBinary(n / 2);
    printf("%d", n % 2);
}
