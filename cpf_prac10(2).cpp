#include <iostream>
#include <iomanip>
using namespace std;

// Part A - Product Structure
struct Product
{   int id;
    float price;
    char category;
    double weight;
};

// Part B - Different member arrangements
struct DataA
{   char ch;
    double d;
    int i;
    short s;
};

struct DataB
{  double d;
    int i;
    short s;
    char ch;
};

// Part C - Union
union Data
{   int number;
    float value;
    char letter;
};

int main()
{
    cout << "********************************************" << endl;
    cout << " COMPOSITE DATA REPRESENTATION ANALYZER" << endl;
    cout << "********************************************" << endl;

    // Part A
    Product p;

    cout << "\nComposite Data Type - Product" << endl;

    cout << "Size of ID : " << sizeof(p.id) << " Bytes" << endl;
    cout << "Size of Price : " << sizeof(p.price) << " Bytes" << endl;
    cout << "Size of Category : " << sizeof(p.category) << " Bytes" << endl;
    cout << "Size of Weight : " << sizeof(p.weight) << " Bytes" << endl;

    cout << "Total Structure Size : "
         << sizeof(Product) << " Bytes" << endl;

    cout << "\n--------------------------------------------" << endl;

    // Part B
    cout << "\nPadding and Alignment" << endl;

    cout << "Structure A Size : " << sizeof(DataA) << " Bytes" << endl;
    cout << "Structure B Size : " << sizeof(DataB) << " Bytes" << endl;
    cout << "Padding depends on member arrangement." << endl;

    cout << "\n--------------------------------------------" << endl;

    // Part C
    Data u;
    cout << "\nShared Memory Representation (Union)" << endl;

    u.number = 120;
    cout << "Integer Value : " << u.number << endl;
    cout << "Address : " << &u << endl;

    u.value = 120.00;
    cout << "Floating Value : " << fixed << setprecision(2)
         << u.value << endl;
    cout << "Address : " << &u << endl;

    u.letter = 'x';
    cout << "Character Value : " << u.letter << endl;
    cout << "Address : " << static_cast<void*>(&u) << endl;

    cout << "\nAll union members share the same memory." << endl;

    cout << "\n--------------------------------------------" << endl;

    // Part D
    cout << "\nTrade-off Analysis" << endl;

    cout << "Structure:" << endl;
    cout << "Separate memory for every member." << endl;
    cout << "Stores all values simultaneously." << endl;

    cout << "\nUnion:" << endl;
    cout << "Shared memory for all members." << endl;
    cout << "Normally stores one active value at a time." << endl;

    cout << "\n--------------------------------------------" << endl;
    cout << "Program Executed Successfully" << endl;

    return 0;
}



