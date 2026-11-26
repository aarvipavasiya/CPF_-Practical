#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Part A: Address and Value
    int num = 25;
    char ch = 'A';
    float price = 85.60f;

    cout << "********************************************\n";
    cout << "         MEMORY ADDRESS EXPLORER\n";
    cout << "********************************************\n";

    cout << "\n------------ Variable Information ------------\n";

    cout << "Integer Value : " << num << endl;
    cout << "Memory Address : " << static_cast<void*>(&num) << endl;
    cout << "----------------------------------------------\n";

    cout << "Character Value : " << ch << endl;
    cout << "Memory Address : " << static_cast<void*>(&ch) << endl;
    cout << "----------------------------------------------\n";

    cout << fixed << setprecision(2);
    cout << "Floating Value : " << pric
    cout << "Memory Address : " << static_cast<void*>(&price) << endl;
    cout << "----------------------------------------------\n";

    // Part B: Indirect Referencing
    int *ptr = &num;

    cout << "\n------------ Indirect Referencing ------------\n";
    cout << "Stored Value : " << *ptr << endl;

    // Modify the value using the pointer
    *ptr = 30;

    cout << "Modified Value : " << *ptr << endl;
    cout << "Updated Integer Value : " << num << endl;
    cout << "----------------------------------------------\n";

    // Part C: Sequential Data Collections
    int arr[5] = {10, 20, 30, 40, 50};

    cout << "\n------------ Sequential Data Collection ------------\n";

    cout << "Array using Index\n";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nArray using Address-based Access\n";
    for (int i = 0; i < 5; i++)
    {
        cout << *(arr + i) << " ";
    }

    cout << "\n----------------------------------------------\n";

    cout << "\nObservation\n";
    cout << "Both approaches access the same array elements.\n";
    cout << "Array indexing and pointer arithmetic access\n";
    cout << "the same memory locations.\n";

    return 0;
}

