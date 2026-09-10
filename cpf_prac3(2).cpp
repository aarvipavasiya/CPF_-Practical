#include <iostream>
#include <iomanip>
using namespace std;

// Function to display student record
void displayStudentRecord(string studentName, int rollNumber, int cpfMarks, int mathMarks)
{
    cout << "\n========================================\n";
    cout << "        STUDENT RECORD SYSTEM\n";
    cout << "========================================\n";

    cout << left << setw(20) << "Student Name" << ": " << studentName << endl;
    cout << left << setw(20) << "Roll Number" << ": " << rollNumber << endl;
    cout << left << setw(20) << "CPF Marks" << ": " << cpfMarks << endl;
    cout << left << setw(20) << "Mathematics Marks" << ": " << mathMarks << endl;

    cout << "========================================\n";
}

int main()
{
    // Student information
    string studentName = "Aarvi";
    int rollNumber = 101;

    // Subject marks
    int cpfMarks = 70;
    int mathMarks = 80;

    // Display student record
    displayStudentRecord(studentName, rollNumber, cpfMarks, mathMarks);

    return 0;
}
