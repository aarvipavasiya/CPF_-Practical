#include <iostream>
using namespace std;
struct Academic
{int semester;
    float percentage;
    string grade;};
struct Contact
{string mobile;
    string email;};
struct Student
{string enrollment;
    string name;
    string branch;
    Academic academic;
    Contact contact;};

void displayStudent(Student *s)
{cout << s->enrollment << " " << s->name
         << " " << s->branch << endl;
    cout << "Semester : " << s->academic.semester << endl;
    cout << "Percentage : " << s->academic.percentage << endl;
    cout << "Grade : " << s->academic.grade << endl;
    cout << "Mobile : " << s->contact.mobile << endl;
    cout << "Email : " << s->contact.email << endl;
}

void updateContact(Student *s)
{cout << "Enter new mobile number: ";
    cin >> s->contact.mobile;
 cout << "Enter new email ID: ";
    cin >> s->contact.email;
}

void displayAcademic(Student *s)
{   cout << "Semester : " << s->academic.semester << endl;
    cout << "Percentage : " << s->academic.percentage << endl;
    cout << "Grade : " << s->academic.grade << endl;
}

int main()
{Student s[100];
    int n;

    cout << "********************************************" << endl;
    cout << "       STUDENT RECORD MANAGEMENT SYSTEM" << endl;
    cout << "********************************************" << endl;

    cout << "Enter Number of Students : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {   cout << "--------------------------------------------" << endl;
        cout << "Student " << i + 1 << endl;

        cout << "Enrollment Number : ";
        cin >> s[i].enrollment;

        cout << "Student Name : ";
        cin >> ws;
        getline(cin, s[i].name);

        cout << "Branch : ";
        cin >> s[i].branch;

        cout << "Semester : ";
        cin >> s[i].academic.semester;

        cout << "Percentage : ";
        cin >> s[i].academic.percentage;
        cout << "Grade : ";
        cin >> s[i].academic.grade;

        cout << "Mobile Number : ";
        cin >> s[i].contact.mobile;

        cout << "Email ID : ";
        cin >> s[i].contact.email;}

    cout << "--------------------------------------------" << endl;
    cout << "Student Records" << endl;

    for (int i = 0; i < n; i++)
    {cout << "--------------------------------------------" << endl;
       displayStudent(&s[i]);}

    cout << "--------------------------------------------" << endl;
    cout << "Program Executed Successfully" << endl;
    cout << "--------------------------------------------" << endl;

    return 0;}


