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

    // Display participant records
    cout << "\n----------------------------------------------\n";
    cout << "          Participant Performance\n";
    cout << "----------------------------------------------\n";
    cout << left << setw(10) << "ID"
         << setw(15) << "Name"
         << "Score" << endl;
cout << "----------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(10) << id[i] << setw(15) << name[i]
             << score[i] << endl;
    }

    // Calculate total, highest and lowest
    int total = 0;
    int highest = score[0];
    int lowest = score[0];

    for (int i = 0; i < n; i++)
    {
        total += score[i];

        if (score[i] > highest)
            highest = score[i];

        if (score[i] < lowest)
            lowest = score[i];
    }
    double average = (double)total / n;

    // Display results
    cout << "----------------------------------------------\n";
    cout << "Total Score: " << total << endl;
    cout << fixed << setprecision(2);
    cout << "Average Score: " << average << endl;
    cout << "Highest Score: " << highest << endl;
    cout << "Lowest Score: " << lowest << endl;

    return 0;
}

