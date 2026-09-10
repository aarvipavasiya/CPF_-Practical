#include <iostream>
#include <string>
using namespace std;

int main()
{
    string enrollmentNumber;
    string studentName;
    string branch;
    int semester;
    string mobileNumber;
    char registerAnother;

    cout << "\n**************************************************\n";
    cout << "              STUDENT RECORD MANAGEMENT SYSTEM\n";
    cout << "**************************************************\n";

    do
    {
        cout << "\nStudent Registration\n\n";

        cout << "Enrollment Number : ";
        cin >> enrollmentNumber;

        cout << "Student Name      : ";
        cin.ignore();
        getline(cin, studentName);

        cout << "Branch            : ";
        cin >> branch;

        cout << "Semester          : ";
        cin >> semester;

        cout << "Mobile Number     : ";
        cin >> mobileNumber;

        cout << "\nStudent Registered Successfully.\n";

        cout << "\nRegister Another Student? (Y/N) : ";
        cin >> registerAnother;

        if (registerAnother == 'Y' || registerAnother == 'y')
        {
            cout << "\n--------------------------------------------------\n";
        }

    } while (registerAnother == 'Y' || registerAnother == 'y');

    cout << "\nReturning to Main Menu...\n";

    return 0;
}
