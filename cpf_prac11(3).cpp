#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    cout << "********************************************" << endl;
    cout << "       STUDENT RECORD MANAGEMENT SYSTEM" << endl;
    cout << "********************************************" << endl;

    int n;

    // Part A: Create and Write Student Records
    ofstream outFile("StudentRecords.txt");

    if (!outFile)
    {
        cout << "Error: Unable to Create Student Record File." << endl;
        return 1;
    }

    cout << "StudentRecords.txt Created Successfully" << endl;

    cout << "\n--------------------------------------------" << endl;

    cout << "Enter Number of Students : ";

    if (!(cin >> n) || n <= 0)
    {
        cout << "Error: Invalid Number of Students." << endl;
        outFile.close();
        return 1;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 1; i <= n; i++)
    {
        string enrollment, name, branch, grade;
        int semester;
        float percentage;

        cout << "\nStudent " << i << endl;

        cout << "Enrollment Number : ";
        getline(cin, enrollment);

        cout << "Student Name : ";
        getline(cin, name);

        cout << "Branch : ";
        getline(cin, branch);

        cout << "Semester : ";
        cin >> semester;

        cout << "Percentage : ";
        cin >> percentage;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Grade : ";
        getline(cin, grade);

        // Store records in file
        outFile << enrollment << endl;
        outFile << name << endl;
        outFile << branch << endl;
        outFile << semester << endl;
        outFile << percentage << endl;
        outFile << grade << endl;

        cout << "--------------------------------------------" << endl;
    }

    outFile.close();
    cout << "\nStudent Records Stored Successfully" << endl;

    cout << "\n--------------------------------------------" << endl;

    // Part B: Read and Display Student Records
    ifstream inFile("StudentRecords.txt");

    if (!inFile)
    {
        cout << "Error: Unable to Open Student Record File." << endl;
        return 1;
    }

    cout << "\nReading StudentRecords.txt" << endl;

    string enrollment, name, branch, grade;
    int semester;
    float percentage;

    int count = 1;

    while (getline(inFile, enrollment))
    {
        if (!getline(inFile, name) ||
            !getline(inFile, branch) ||
            !(inFile >> semester) ||
            !(inFile >> percentage))
        {
            cout << "Error: Incomplete Student Record." << endl;
            inFile.close();
            return 1;
        }

        inFile.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!getline(inFile, grade))
        {
            cout << "Error: Incomplete Student Record." << endl;
            inFile.close();
            return 1;
        }

        cout << "\nEnrollment : " << enrollment << endl;
        cout << "Name : " << name << endl;
        cout << "Branch : " << branch << endl;
        cout << "Semester : " << semester << endl;
        cout << "Percentage : " << percentage << endl;
        cout << "Grade : " << grade << endl;

        cout << "--------------------------------------------" << endl;

        count++;
    }

    if (inFile.eof())
    {
        cout << "End of File Reached Successfully" << endl;
    }

    inFile.close();

    cout << "\n--------------------------------------------" << endl;

    // Part C: Backup Student Records
    cout << "Creating BackupStudentRecords.txt" << endl;

    ifstream source("StudentRecords.txt");

    if (!source)
    {
        cout << "Error: Unable to Open Source File." << endl;
        return 1;
    }

    ofstream backup("BackupStudentRecords.txt");

    if (!backup)
    {
        cout << "Error: Unable to Create Backup File." << endl;
        source.close();
        return 1;
    }

    backup << source.rdbuf();

    source.close();
    backup.close();

    cout << "Backup Completed Successfully" << endl;

    cout << "\n--------------------------------------------" << endl;
    cout << "Program Executed Successfully" << endl;
    cout << "--------------------------------------------" << endl;

    return 0;
}



