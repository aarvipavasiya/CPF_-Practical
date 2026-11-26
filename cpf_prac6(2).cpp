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

    string id[n];
    string name[n];
    int score[n];

    // Input participant details
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
    // 1. SEARCH PARTICIPANT BY ID
    // ------------------------------------------------

    string searchID;
    bool found = false;

    cout << "\n----------------------------------------------\n";
    cout << "           SEARCH PARTICIPANT\n";
    cout << "----------------------------------------------\n";

    cout << "Enter Participant ID to search: ";
    cin >> searchID;

    for (int i = 0; i < n; i++)
    {
        if (id[i] == searchID)
        {
            cout << "\nParticipant Found!\n";
            cout << "Participant ID   : " << id[i] << endl;
            cout << "Participant Name : " << name[i] << endl;
            cout << "Score            : " << score[i] << endl;
found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nParticipant not found.\n";
    }

    // ------------------------------------------------
    // 2. SORT PARTICIPANTS BY SCORE (DESCENDING)
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
    // 3. DISPLAY RANKING LIST
    // ------------------------------------------------

    cout << "\n----------------------------------------------\n";
    cout << "              RANKING LIST\n";
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
    // 4. DISPLAY TOP THREE PERFORMERS
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
