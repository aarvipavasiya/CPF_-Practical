#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    char paragraph[500], additional[200];
    char updated[700], firstWord[100], lastWord[100];
    char keyword[100], upper[700], lower[700];
    char reverse[700], word[100], copied[700];
    char compareText[700], concatText[900];

    int i, j, k;
    int characters = 0, words = 0, alphabets = 0;
    int digits = 0, special = 0, position = -1;

    cout << "********************************************" << endl;
    cout << "          DOCUMENT TEXT ANALYZER" << endl;
cout << "********************************************" << endl;

    // Part A: Input Paragraph
    cout << "\nEnter Paragraph:" << endl;
    cin.getline(paragraph, 500);

    // Text Analysis
    for (i = 0; paragraph[i] != '\0'; i++)
    {
        characters++;

        if (isalpha((unsigned char)paragraph[i]))
            alphabets++;
        else if (isdigit((unsigned char)paragraph[i]))
            digits++;
        else if (!isspace((unsigned char)paragraph[i]))
            special++;

        if (!isspace((unsigned char)paragraph[i]) &&
            (i == 0 || isspace((unsigned char)paragraph[i - 1])))
            words++;
    }

    cout << "\n--------------------------------------------" << endl;
    cout << "Text Analysis" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Characters : " << characters << endl;
    cout << "Words : " << words << endl;
    cout << "Alphabets : " << alphabets << endl;
    cout << "Digits : " << digits << endl;
    cout << "Special Characters : " << special << endl;

    // Part B: String Extraction
    i = 0;
    while (paragraph[i] != '\0' &&
           isspace((unsigned char)paragraph[i]))
        i++;

    j = 0;
    while (paragraph[i] != '\0' &&
           !isspace((unsigned char)paragraph[i]))
        firstWord[j++] = paragraph[i++];

    firstWord[j] = '\0';

    int len = strlen(paragraph);
    i = len - 1;

    while (i >= 0 && isspace((unsigned char)paragraph[i]))
        i--;

    j = i;

    while (j >= 0 && !isspace((unsigned char)paragraph[j]))
        j--;

    k = 0;
    for (i = j + 1; i <= len - 1 &&
         paragraph[i] != '\0'; i++)
        lastWord[k++] = paragraph[i];

    lastWord[k] = '\0';

    cout << "\n--------------------------------------------" << endl;
    cout << "String Extraction" << endl;
    cout << "--------------------------------------------" << endl;

    cout << "First Word : " << firstWord << endl;
    cout << "Last Word : " << lastWord << endl;

    if (len > 0)
    {
        cout << "First Character : " << paragraph[0] << endl;
        cout << "Last Character : " << paragraph[len - 1] << endl;
    }

    // Part C: Concatenation
    cout << "\n--------------------------------------------" << endl;
    cout << "Concatenation" << endl;
    cout << "--------------------------------------------" << endl;

    cout << "Enter Additional Sentence:" << endl;
    cin.getline(additional, 200);

    // Manual concatenation
    i = 0;
    while (paragraph[i] != '\0')
    {
        updated[i] = paragraph[i];
        i++;
    }

    updated[i++] = '\n';

    j = 0;
    while (additional[j] != '\0')
        updated[i++] = additional[j++];

    updated[i] = '\0';

    cout << "\nUpdated Paragraph" << endl;
    cout << updated << endl;

    // Standard concatenation
    char standardConcat[700];
    strcpy(standardConcat, paragraph);
    strcat(standardConcat, "\n");
    strcat(standardConcat, additional);

    // Part D: Pattern Matching
    cout << "\n--------------------------------------------" << endl;
    cout << "Pattern Matching" << endl;
    cout << "--------------------------------------------" << endl;

    cout << "Enter Search Word : ";
    cin.getline(keyword, 100);

    // Manual substring search
    int paragraphLength = strlen(updated);
    int keywordLength = strlen(keyword);

    if (keywordLength > 0)
    {
        for (i = 0; i <= paragraphLength - keywordLength; i++)
        {
            j = 0;

            while (j < keywordLength &&
                   updated[i + j] == keyword[j])
                j++;

            if (j == keywordLength)
            {
                position = i;
                break;
            }
        }
    }

    if (position != -1)
    {
        cout << "Keyword Found" << endl;
        cout << "First Occurrence Position : "
             << position + 1 << endl;
    }
    else
        cout << "Keyword Not Found" << endl;

    // Standard substring search
    if (strstr(updated, keyword) != NULL && keywordLength > 0)
        cout << "Using strstr(): Found" << endl;
    else
        cout << "Using strstr(): Not Found" << endl;

    // Part E: String Transformation
    strcpy(upper, updated);
    strcpy(lower, updated);

    // Manual uppercase and lowercase
    for (i = 0; updated[i] != '\0'; i++)
    {
        if (updated[i] >= 'a' && updated[i] <= 'z')
            upper[i] = updated[i] - 32;

        if (updated[i] >= 'A' && updated[i] <= 'Z')
            lower[i] = updated[i] + 32;
    }

    cout << "\n--------------------------------------------" << endl;
    cout << "String Transformation" << endl;
    cout << "--------------------------------------------" << endl;

    cout << "\nUppercase (Manual)" << endl;
    cout << upper << endl;
    cout << "\nLowercase (Manual)" << endl;
    cout << lower << endl;

    // Reverse manually
    len = strlen(updated);

    for (i = 0; i < len; i++)
        reverse[i] = updated[len - 1 - i];

    reverse[len] = '\0';

    cout << "\nReverse" << endl;
    cout << reverse << endl;

    // Palindrome Check
    cout << "\n--------------------------------------------" << endl;
    cout << "Palindrome Check" << endl;

    cout << "Enter Word : ";
    cin.getline(word, 100);

    len = strlen(word);
    bool palindrome = true;

    for (i = 0; i < len / 2; i++)
    {
        if (tolower((unsigned char)word[i]) !=
            tolower((unsigned char)word[len - 1 - i]))
        {
            palindrome = false;
            break;
        }
    }

    if (palindrome)
        cout << "Result : Palindrome" << endl;
    else
        cout << "Result : Not a Palindrome" << endl;

    // Part F: Standard String Functions
    cout << "\n--------------------------------------------" << endl;
    cout << "Standard String Functions" << endl;
    cout << "--------------------------------------------" << endl;

cout << "Length : " << strlen(updated) << endl;

    strcpy(copied, updated);
    cout << "String Copied Successfully" << endl;

    strcpy(compareText, updated);

    if (strcmp(updated, compareText) == 0)
        cout << "Comparison Result : Equal" << endl;
    else
        cout << "Comparison Result : Not Equal" << endl;

    strcpy(concatText, paragraph);
    strcat(concatText, "\n");
    strcat(concatText, additional);

    cout << "Concatenation : Successful" << endl;

    if (strstr(updated, keyword) != NULL && keywordLength > 0)
        cout << "Substring Search : Found" << endl;
    else
        cout << "Substring Search : Not Found" << endl;

    // Standard uppercase
    for (i = 0; updated[i] != '\0'; i++)
        upper[i] = toupper((unsigned char)updated[i]);
    upper[i] = '\0';

    cout << "toupper() : Successful" << endl;

    // Standard lowercase
    for (i = 0; updated[i] != '\0'; i++)
        lower[i] = tolower((unsigned char)updated[i]);
    lower[i] = '\0';

    cout << "tolower() : Successful" << endl;

    cout << "--------------------------------------------" << endl;

    return 0;
}

