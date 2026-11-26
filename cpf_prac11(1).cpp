#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

// Global variable
int globalVar = 100;

int main()
{
    cout << "********************************************" << endl;
    cout << "   PROGRAM EXECUTION & ERROR HANDLING" << endl;
    cout << "                ANALYZER" << endl;
    cout << "********************************************" << endl;

    // Part A: Memory Observation
    cout << "\nCompile-time and Run-time Memory" << endl;

    int localVar = 200;

    int *ptr = new int;
    *ptr = 300;

    cout << "Global Variable Value : " << globalVar << endl;
    cout << "Local Variable Value : " << localVar << endl;
    cout << "Dynamic Memory Value : " << *ptr << endl;

    delete ptr;
    ptr = nullptr;

    cout << "\n--------------------------------------------" << endl;

    // Part B: Arithmetic Overflow
    cout << "Low-level Error Demonstration" << endl;

    unsigned int a = UINT_MAX;
    unsigned int b = a + 1;

    cout << "Arithmetic Overflow Observed" << endl;
    cout << "Maximum Unsigned Value : " << a << endl;
    cout << "After Overflow : " << b << endl;

    cout << "\n--------------------------------------------" << endl;
    // Pointer Aliasing
    cout << "Pointer Aliasing" << endl;

    int num = 50;

    int *p1 = &num;
    int *p2 = &num;

    cout << "Original Value : " << *p1 << endl;

    *p1 = 75;

    cout << "Updated Value : " << *p2 << endl;
    cout << "Both Address Variables Refer to the Same Memory Location" << endl;

    cout << "\n--------------------------------------------" << endl;

    // Memory Leak Demonstration
    cout << "Memory Leak Demonstration" << endl;

    int *memory = new int(500);

    cout << "Dynamic Memory Allocated" << endl;

    delete memory;
    memory = nullptr;

    cout << "Memory Released Successfully" << endl;

    cout << "\n--------------------------------------------" << endl;

    // Part C: Error Handling
    double dividend, divisor;

    cout << "\nArithmetic Operation" << endl;

    cout << "Enter Dividend : ";
    if (!(cin >> dividend))
    {
        cout << "Error : Invalid Numerical Input." << endl;
        return 0;
    }

    cout << "Enter Divisor : ";
    if (!(cin >> divisor))
    {
        cout << "Error : Invalid Numerical Input." << endl;
        return 0;
    }

    if (divisor == 0)
    {
        cout << "Error : Division by Zero is not Allowed." << endl;
    }
    else
    {
        cout << "Result : " << dividend / divisor << endl;
    }

    cout << "\n--------------------------------------------" << endl;

    // Part D: File Operation
    cout << "File Operation" << endl;

    ifstream file("NotFound.txt");

    if (!file.is_open())
    {
        cout << "Unable to Open File." << endl;
    }
    else
    {
        cout << "File Opened Successfully." << endl;
        file.close();
    }

    cout << "\n--------------------------------------------" << endl;
    cout << "Program Executed Successfully" << endl;
    cout << "--------------------------------------------" << endl;

    return 0;
}

