#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cout << "********************************************" << endl;
    cout << " FILE ORGANIZATION & FILE OPERATIONS UTILITY" << endl;
    cout << "********************************************" << endl;

    string line;

    // Part A: File Creation and Writing
    ofstream outFile("Document.txt");

    if (!outFile)
    {
        cout << "Unable to Create File." << endl;
        return 1;
    }

    cout << "\nDocument.txt Created Successfully" << endl;
    cout << "\n--------------------------------------------" << endl;

    cout << "Enter File Contents" << endl;
    cout << "(Enter END to finish writing)" << endl;

    while (true)
    {
        getline(cin, line);

        if (line == "END")
            break;

        outFile << line << endl;
    }

    outFile.close();

    cout << "Data Written Successfully" << endl;

    cout << "\n--------------------------------------------" << endl;

    // Part B: File Reading
    ifstream inFile("Document.txt");

    if (!inFile)
    {
        cout << "Unable to Open File." << endl;
        return 1;
    }

    cout << "\nReading Document.txt" << endl;

    while (getline(inFile, line))
    {
        cout << line << endl;
    }

    if (inFile.eof())
        cout << "End of File Reached Successfully" << endl;

    inFile.close();

    cout << "\n--------------------------------------------" << endl;

    // Part C: File Copying
    cout << "Creating BackupDocument.txt" << endl;

    ifstream source("Document.txt");
    if (!source)
    {
        cout << "Unable to Open Source File." << endl;
        return 1;
    }

    ofstream backup("BackupDocument.txt");

    if (!backup)
    {
        cout << "Unable to Create Backup File." << endl;
        return 1;
    }

    backup << source.rdbuf();

    source.close();
    backup.close();

    cout << "Contents Copied Successfully" << endl;
    cout << "Backup File Created Successfully" << endl;

    cout << "\n--------------------------------------------" << endl;

    // Part D: Random File Access
    ifstream randomFile("Document.txt");

    if (!randomFile)
    {
        cout << "Unable to Open File." << endl;
        return 1;
    }

    // Move pointer to end to find file size
    randomFile.seekg(0, ios::end);

    cout << "Current File Position : " << randomFile.tellg() << endl;

    // Move pointer to beginning
    randomFile.seekg(0, ios::beg);

    cout << "\nMoving File Pointer..." << endl;

    // Skip first line
    getline(randomFile, line);

    cout << "Displaying Contents after Repositioning" << endl;

    // Display second line
    if (getline(randomFile, line))
    {
        cout << line << endl;
    }

    cout << "\n--------------------------------------------" << endl;

    // Reset file pointer
    cout << "Resetting File Pointer" << endl;

    randomFile.clear();
    randomFile.seekg(0, ios::beg);

    while (getline(randomFile, line))
    {
        cout << line << endl;
    }

    randomFile.close();

    cout << "\n--------------------------------------------" << endl;
    cout << "Program Executed Successfully" << endl;
    cout << "--------------------------------------------" << endl;

    return 0;
}

