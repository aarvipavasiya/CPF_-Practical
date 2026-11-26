#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int n;

    cout << "********************************************\n";
    cout << "       SPORTS EVENT SCORE ANALYSIS\n";
    cout << "********************************************\n";

    cout << "Enter Number of Participants: ";
    cin >> n;

    string id[100];
    string name[100];
    int score[100];

    // ------------------------------------------------
    // 1. INPUT PARTICIPANT DETAILS
    // ------------------------------------------------

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Participant ID: ";
        cin >> id[i];

cout << "Enter Participant Name: ";
        cin >> name[i];

        cout << "Enter Score: ";
        cin >> score[i];
    }

    // ------------------------------------------------
    // 2. DISPLAY CURRENT RECORDS
    // ------------------------------------------------

    cout << "\n----------------------------------------------\n";
    cout << "           CURRENT PARTICIPANT RECORDS\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << id[i] << " "
             << name[i] << " "
             << score[i] << endl;
    }

    // ------------------------------------------------
    // 3. INSERT NEW PARTICIPANT
    // ------------------------------------------------

    int position;

    cout << "\n----------------------------------------------\n";
    cout << "           INSERT NEW PARTICIPANT\n";
    cout << "----------------------------------------------\n";

    cout << "Enter Position: ";
    cin >> position;

    // Shift records to the right
    for (int i = n; i >= position; i--)
    {
        id[i] = id[i - 1];
        name[i] = name[i - 1];
        score[i] = score[i - 1];
    }

    cout << "Enter Participant ID: ";
    cin >> id[position - 1];

    cout << "Enter Participant Name: ";
    cin >> name[position - 1];
cout << "Enter Score: ";
    cin >> score[position - 1];

    n++;

    cout << "\nRecord Inserted Successfully.\n";

    // Display after insertion
    cout << "\n----------------------------------------------\n";
    cout << "        UPDATED PARTICIPANT RECORDS\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << id[i] << " "
             << name[i] << " "
             << score[i] << endl;
    }

    // ------------------------------------------------
    // 4. UPDATE PARTICIPANT SCORE
    // ------------------------------------------------

    string searchID;
    bool found = false;

    cout << "\n----------------------------------------------\n";
    cout << "           UPDATE PARTICIPANT RECORD\n";
    cout << "----------------------------------------------\n";

    cout << "Enter Participant ID: ";
    cin >> searchID;

    for (int i = 0; i < n; i++)
    {
        if (id[i] == searchID)
        {
            cout << "Enter New Score: ";
            cin >> score[i];

            found = true;

            cout << "\nRecord Updated Successfully.\n";
            break;
        }
    }
if (!found)
    {
        cout << "\nParticipant Not Found.\n";
    }

    // ------------------------------------------------
    // 5. DELETE PARTICIPANT
    // ------------------------------------------------

    cout << "\n----------------------------------------------\n";
    cout << "           DELETE PARTICIPANT RECORD\n";
    cout << "----------------------------------------------\n";

    cout << "Enter Position: ";
    cin >> position;

    // Shift records to the left
    for (int i = position - 1; i < n - 1; i++)
    {
        id[i] = id[i + 1];
        name[i] = name[i + 1];
        score[i] = score[i + 1];
    }
    n--;

    cout << "\nRecord Deleted Successfully.\n";

    // ------------------------------------------------
    // 6. SORT PARTICIPANTS BY SCORE
    //    DESCENDING ORDER
    // ------------------------------------------------

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (score[i] < score[j])
            {
                swap(score[i], score[j]);
                swap(id[i], id[j]);
                swap(name[i], name[j]);
            }
        }
    }

    // ------------------------------------------------
    // 7. DISPLAY RANKING LIST
// ------------------------------------------------

    cout << "\n----------------------------------------------\n";
    cout << "              FINAL RANKING LIST\n";
    cout << "----------------------------------------------\n";

    cout << left << setw(8) << "Rank"
         << setw(10) << "ID"
         << setw(15) << "Name"
         << "Score" << endl;

    cout << "----------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(8) << i + 1
             << setw(10) << id[i]
             << setw(15) << name[i]
             << score[i] << endl;
    }

    // ------------------------------------------------
    // 8. DISPLAY TOP THREE PERFORMERS
    // ------------------------------------------------
    cout << "\n----------------------------------------------\n";
    cout << "           TOP THREE PERFORMERS\n";
    cout << "----------------------------------------------\n";

    int limit;

    if (n < 3)
        limit = n;
    else
        limit = 3;

    for (int i = 0; i < limit; i++)
    {
        cout << "\nRank " << i + 1 << endl;
        cout << "ID    : " << id[i] << endl;
        cout << "Name  : " << name[i] << endl;
        cout << "Score : " << score[i] << endl;
    }

    return 0;
}

