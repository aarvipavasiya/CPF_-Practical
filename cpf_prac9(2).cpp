#include <iostream>
#include <iomanip>
#include <string>
#include <new>
using namespace std;

// Structure to store student details
struct Student
{
    string enrollmentNumber;
    string name;
    string branch;
    int semester;
    float percentage;
    string grade;
};

// Part C1: Display all student records using address-based access
void displayRecords(Student *ptr, int n)
{
    cout << "\nStudent Records using Address-based Access\n";
    for (int i = 0; i < n; i++)
    {
        Student *current = ptr + i;

        cout << "Address : " << static_cast<void*>(current) << endl;

        cout << current->enrollmentNumber << " "
             << current->name << " "
             << current->branch << " "
             << current->semester << " "
             << fixed << setprecision(2)
             << current->percentage << " "
             << current->grade << endl;

        cout << "--------------------------------------------\n";
    }
}

// Part C2, C3 and C4: Calculate academic summary
void academicSummary(Student *ptr, int n)
{
    float total = 0.0f;
    float highest = ptr->percentage;
    float lowest = ptr->percentage;

    for (int i = 0; i < n; i++)
    {
        Student *current = ptr + i;

        total += current->percentage;

        if (current->percentage > highest)
            highest = current->percentage;

        if (current->percentage < lowest)
            lowest = current->percentage;
    }

    cout << "\nAcademic Summary\n";
    cout << fixed << setprecision(2);
    cout << "Class Average Percentage : "
         << total / n << " %\n";
    cout << "Highest Percentage : " << highest << " %\n";
    cout << "Lowest Percentage : " << lowest << " %\n";
    cout << "--------------------------------------------\n";
}

int main()
{
    int n;

    cout << "********************************************\n";
    cout << "     STUDENT RECORD MANAGEMENT SYSTEM\n";
    cout << "********************************************\n";

    cout << "Enter Number of Students : ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of students.\n";
        return 1;
    }

    // Part A: Dynamic memory allocation
    Student *students = new (nothrow) Student[n];

    if (students == nullptr)
    {
        cout << "Memory allocation failed.\n";
        return 1;
    }

    cout << "Dynamic Memory Allocated Successfully\n";
    cout << "--------------------------------------------\n";

    cout << "\nEnter Student Details\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Enrollment Number : ";
        cin >> students[i].enrollmentNumber;

        cout << "Student Name : ";
        getline(cin >> ws, students[i].name);

        cout << "Branch : ";
        cin >> students[i].branch;

        cout << "Semester : ";
        cin >> students[i].semester;

        cout << "Percentage : ";
        cin >> students[i].percentage;

        cout << "Grade : ";
        cin >> students[i].grade;

        cout << "--------------------------------------------\n";
    }

    // Part B: Offset-based memory access
    displayRecords(students, n);

    // Part C: Address-based function access
    academicSummary(students, n);

    // Part D: Dynamic memory deallocation
    delete[] students;
    students = nullptr;

    cout << "\nDynamic Memory Released Successfully\n";
    cout << "Address Variable Reset Successfully\n";
    cout << "--------------------------------------------\n";

    cout << "Program Executed Successfully\n";
    cout << "--------------------------------------------\n";

    return 0;
}


