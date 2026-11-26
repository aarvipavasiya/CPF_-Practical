#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char enrollment[20];
    char name[50];
    char branch[20];
    char keyword[30];

    char reference[80];
    char firstName[30];
    char lastName[30];

    cout << "**************************************************" << endl;
    cout << "        STUDENT RECORD MANAGEMENT SYSTEM" << endl;
    cout << "**************************************************" << endl;

    // Input
    cout << "Enter Enrollment Number : ";
    cin.getline(enrollment, 20);
    cout << "Enter Student Name : ";
    cin.getline(name, 50);

    cout << "Enter Branch : ";
    cin.getline(branch, 20);

    // ------------------------------------------------
    // 1. Generate Student Reference ID
    // Manual concatenation
    // ------------------------------------------------
    int i = 0, j = 0;

    while (name[i] != '\0')
    {
        reference[i] = name[i];
        i++;
    }

    reference[i++] = '-';

    while (enrollment[j] != '\0')
    {
        reference[i++] = enrollment[j++];
    }

    reference[i] = '\0';

    cout << "\n--------------------------------------------" << endl;
    cout << "Student Reference" << endl;
    cout << reference << endl;

    // ------------------------------------------------
    // Standard string concatenation
    // ------------------------------------------------
    char reference2[80];

    strcpy(reference2, name);
    strcat(reference2, "-");
    strcat(reference2, enrollment);

    cout << "\nUsing Standard String Functions:" << endl;
    cout << reference2 << endl;

    // ------------------------------------------------
    // 2. Extract First Name and Last Name manually
    // ------------------------------------------------
    int space = -1;

    for (i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == ' ')
        {
            space = i;
            break;
        }
    }

    if (space != -1)
    {
        // First Name
        for (i = 0; i < space; i++)
        {
            firstName[i] = name[i];
        }
        firstName[space] = '\0';

        // Last Name
        j = 0;
        for (i = space + 1; name[i] != '\0'; i++)
        {
            lastName[j++] = name[i];
        }
        lastName[j] = '\0';
    }
    else
    {
        strcpy(firstName, name);
        strcpy(lastName, "");
    }

    cout << "\n--------------------------------------------" << endl;
    cout << "First Name" << endl;
    cout << firstName << endl;

    cout << "\nLast Name" << endl;
    cout << lastName << endl;
    // ------------------------------------------------
    // 3. Extract using standard string functions
    // strchr()
    // ------------------------------------------------
    char firstName2[30];
    char lastName2[30];

    char *ptr = strchr(name, ' ');

    if (ptr != NULL)
    {
        int firstLength = ptr - name;

        strncpy(firstName2, name, firstLength);
        firstName2[firstLength] = '\0';

        strcpy(lastName2, ptr + 1);
    }
    else
    {
        strcpy(firstName2, name);
        strcpy(lastName2, "");
    }

    cout << "\nUsing Standard String Functions:" << endl;
    cout << "First Name : " << firstName2 << endl;
    cout << "Last Name  : " << lastName2 << endl;
    // ------------------------------------------------
    // 4. Keyword Search
    // ------------------------------------------------
    cout << "\n--------------------------------------------" << endl;
    cout << "Enter Keyword : ";
    cin.getline(keyword, 30);

    // Manual pattern matching
    bool found = false;

    int nameLength = strlen(name);
    int keyLength = strlen(keyword);

    for (i = 0; i <= nameLength - keyLength; i++)
    {
        j = 0;

        while (j < keyLength && name[i + j] == keyword[j])
        {
            j++;
        }

        if (j == keyLength)
        {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Keyword Found." << endl;
    else
        cout << "Keyword Not Found." << endl;

    // ------------------------------------------------
    // Standard string function strstr()
    // ------------------------------------------------
    if (strstr(name, keyword) != NULL)
        cout << "Using strstr(): Keyword Found." << endl;
    else
        cout << "Using strstr(): Keyword Not Found." << endl;

    // ------------------------------------------------
    // 5. Complete Student Report
    // ------------------------------------------------
    cout << "\n--------------------------------------------" << endl;
    cout << "Student Report" << endl;

    cout << "Enrollment Number : " << enrollment << endl;
    cout << "Student Name      : " << name << endl;
    cout << "Branch            : " << branch << endl;
    cout << "Student Reference : " << reference << endl;
    cout << "First Name        : " << firstName << endl;
    cout << "Last Name         : " << lastName << endl;

    cout << "--------------------------------------------" << endl;

    return 0;
}
