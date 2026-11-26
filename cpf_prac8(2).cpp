#include <iostream>
using namespace std;

// Global Variable
int globalValue = 100;

// =====================================================
// PART A - FUNCTION DESIGN
// =====================================================

// 1. Without Parameter and Without Return Value
void displayMessage()
{
    cout << "1. Hello! Welcome to Function Programming." << endl;
}

// 2. Without Parameter and With Return Value
int getNumber()
{
    return 50;
}

// 3. With Parameter and Without Return Value
void displaySquare(int n)
{
    cout << "3. Square = " << n * n << endl;
}

// 4. With Parameter and With Return Value
int add(int a, int b)
{
    return a + b;
}

// =====================================================
// PART B - PARAMETER PASSING
// =====================================================

// Call by Value
void callByValue(int x)
{
    x = 100;
}

// Call by Reference
void callByReference(int &x)
{
    x = 100;
}

// =====================================================
// PART C - SCOPE
// =====================================================

void scopeDemo()
{
    // Local Variable
    int localValue = 50;

    cout << "Inside Function:" << endl;
    cout << "Local Value = " << localValue << endl;
    cout << "Global Value = " << globalValue << endl;
}

// =====================================================
// PART D - FUNCTION OVERLOADING
// =====================================================

void displayStudent(string name)
{
    cout << "Name: " << name << endl;
}

void displayStudent(string name, int marks)
{
    cout << "Name: " << name << endl;
    cout << "Marks: " << marks << endl;
}

void displayStudent(string name, int marks, string mobile)
{
    cout << "Name: " << name << endl;
    cout << "Marks: " << marks << endl;
    cout << "Mobile: " << mobile << endl;
}

// =====================================================
// MAIN FUNCTION
// =====================================================

int main()
{
    cout << "===== PART A: FUNCTION DESIGN =====" << endl;

    // 1. No Parameter + No Return
    displayMessage();

    // 2. No Parameter + Return
    int number = getNumber();
    cout << "2. Returned Number = " << number << endl;

    // 3. Parameter + No Return
    displaySquare(5);

    // 4. Parameter + Return
    int result = add(10, 20);
    cout << "4. Addition = " << result << endl;

    cout << endl;
    cout << "===== PART B: PARAMETER PASSING =====" << endl;

    int a = 10;

    cout << "Before Call by Value: " << a << endl;

    callByValue(a);

    cout << "After Call by Value: " << a << endl;

    int b = 10;

    cout << "Before Call by Reference: " << b << endl;

    callByReference(b);

    cout << "After Call by Reference: " << b << endl;

    cout << endl;
    cout << "===== PART C: SCOPE =====" << endl;

    scopeDemo();

    cout << "Global Value in Main = "
         << globalValue << endl;

    cout << endl;
    cout << "===== PART D: FUNCTION OVERLOADING =====" << endl;

    displayStudent("Nirav");

    cout << endl;

    displayStudent("Nirav", 85);

    cout << endl;

    displayStudent("Nirav", 85, "9876543210");

    return 0;



