#include <iostream>
using namespace std;

// Part A: User-defined function with local variables (stack memory)
void stackMemory()
{
    int localVar = 100;

    cout << "\n--------------- Stack Memory ----------------\n";
    cout << "Local Variable Value\n";
    cout << localVar << endl;

    cout << "Memory Address\n";
    cout << static_cast<void*>(&localVar) << endl;
    cout << "---------------------------------------------\n";
}

int main()
{
    cout << "********************************************\n";
    cout << "       MEMORY ORGANIZATION ANALYZER\n";
    cout << "********************************************\n";

    // Part A: Stack memory
    stackMemory();

    // Dynamically allocated memory (heap/free store)
    int *heapPtr = new int(250);

    cout << "\n------- Dynamically Allocated Memory --------\n";
    cout << "Allocated Value\n";
    cout << *heapPtr << endl;

    cout << "Memory Address\n";
    cout << static_cast<void*>(heapPtr) << endl;
    cout << "---------------------------------------------\n";

    // Part B: Multi-level referencing
    int value = 50;

    int *ptr1 = &value;       // Single-level pointer
    int **ptr2 = &ptr1;       // Double-level pointer
    int ***ptr3 = &ptr2;      // Triple-level pointer

    cout << "\n---------- Multi-level Referencing ----------\n";
    cout << "Original Value\n";
    cout << value << endl;

    cout << "Single-level Address\n";
    cout << static_cast<void*>(ptr1) << endl;

    cout << "Double-level Address\n";
    cout << static_cast<void*>(ptr2) << endl;

    cout << "Triple-level Address\n";
    cout << static_cast<void*>(ptr3) << endl;

    cout << "Value Accessed through Three Levels\n";
    cout << ***ptr3 << endl;
    cout << "---------------------------------------------\n";

    // Part C: Memory safety
    cout << "\n------------- Memory Safety -----------------\n";

    // Null reference
    int *nullPtr = nullptr;
    cout << "Null Reference\n";
    if (nullPtr == nullptr)
        cout << "Safe (Reference is NULL; not dereferenced)\n";
    cout << "---------------------------------------------\n";

    // Invalid reference after deallocation
    int *invalidPtr = heapPtr;

    delete heapPtr;
    heapPtr = nullptr;

    cout << "\nInvalid Reference\n";
    cout << "Memory Released Successfully\n";
    cout << "Reference Invalid (Do not dereference)\n";

    // Reset the dangling pointer copy without accessing its target
    invalidPtr = nullptr;
    cout << "Pointer Reset to NULL\n";
    cout << "---------------------------------------------\n";

    // Uninitialized pointer: observation only
    int *uninitializedPtr; // Intentionally uninitialized

    cout << "\nUninitialized Address Variable\n";
    cout << "Unsafe to Access (Pointer has no valid initialized address)\n";
    cout << "Pointer is not dereferenced or read.\n";
    cout << "---------------------------------------------\n";

    // Part D: Observations
    cout << "\n--------------- Observations ----------------\n";

    cout << "1. Stack memory stores local variables with automatic lifetime.\n";
    cout << "2. Dynamic memory is allocated at runtime and released using delete.\n";
    cout << "3. Single-level pointer accesses a value through one pointer.\n";
    cout << "4. Multi-level pointers access values through pointer chains.\n";
    cout << "5. Null pointers can be checked safely but not dereferenced.\n";
    cout << "6. Dangling and uninitialized pointers must not be dereferenced.\n";
    cout << "---------------------------------------------\n";

    cout << "\nProgram Executed Successfully\n";

    return 0;
}

