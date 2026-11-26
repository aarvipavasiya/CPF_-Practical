#include <iostream>
using namespace std;

int main() {
    int choice;
    int rows = 5;

    do {
        cout << "\n=========================================\n";
        cout << "    CHARACTER PATTERN DISPLAY SYSTEM     \n";
        cout << "=========================================\n";
        cout << "1. Numeric Pattern\n";
        cout << "2. Lowercase Alphabet Pattern\n";
        cout << "3. Uppercase Alphabet Pattern\n";
        cout << "4. Right Half Number Triangle\n";
        cout << "5. Full Number Pyramid\n";
        cout << "6. Full Alphabet Pyramid\n";
        cout << "7. Exit\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        cout << "\n";

        if (choice == 1) {
            cout << "Pattern 1 - Numeric Pattern:\n\n";
            for (int i = 1; i <= rows; i++) {
                for (int j = 1; j <= i; j++) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 2) {
            cout << "Pattern 2 - Lowercase Alphabet Pattern:\n\n";
            for (int i = 1; i <= rows; i++) {
                for (int j = 0; j < i; j++) {
                    cout << (char)('a' + j) << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 3) {
            cout << "Pattern 3 - Uppercase Alphabet Pattern:\n\n";
            for (int i = 1; i <= A; i++) {
                for (int j = 0; j < i; j++) {
                    cout << (char)('A' + j) << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 4) {
            cout << "Pattern 4 - Right Half Number Triangle:\n\n";
            for (int i = 1; i <= rows; i++) {
                for (int s = 1; s <= (rows - i) * 2; s++) {
                    cout << " ";
                }
                for (int j = 1; j <= i; j++) {
                    cout << j << (j == i ? "" : " ");
                }
                cout << endl;
            }
        }
        else if (choice == 5) {
            cout << "Pattern 5 - Full Number Pyramid:\n\n";
            for (int i = 1; i <= rows; i++) {
                for (int s = 0; s < (rows - i) * 2; s++) {
                    cout << " ";
                }
                for (int j = 1; j <= i; j++) {
                    cout << j << " ";
                }
                for (int j = i - 1; j >= 1; j--) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 6) {
            cout << "Pattern 6 - Full Alphabet Pyramid:\n\n";
            for (int i = 1; i <= rows; i++) {
                for (int s = 0; s < (rows - i) * 2; s++) {
                    cout << " ";
                }
                for (int j = 0; j < i; j++) {
                    cout << (char)('A' + j) << " ";
                }
                for (int j = i - 2; j >= 0; j--) {
                    cout << (char)('A' + j) << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 7) {
            cout << "Exiting system. Goodbye!\n";
        }
        else {
            cout << "Invalid choice! Please select a number from 1 to 7.\n";
        }
    } while (choice != 7);

    return 0;
}
