#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "displaybox.h"

using namespace std;

void displayQuestionBox(const string& title, const vector<string>& options)
{
    const int width = 59;
    const int consoleWidth = 70;

    int leftPadding = (consoleWidth - width - 2) / 2 + 71;

    if (leftPadding < 0)
    {
        leftPadding = 0;
    }

    string padding(leftPadding, ' ');

    // SMALL VERTICAL SPACING
    cout << endl;

    // TOP BORDER
    cout << padding << "+" << string(width + 2, '=') << "+" << endl;

    // CENTERED TITLE
    int titlePadding = (width - title.length()) / 2;

    cout << padding << "||"
         << string(titlePadding, ' ')
         << title
         << string(width - titlePadding - title.length(), ' ')
         << "||" << endl;

    // TITLE BOTTOM BORDER
    cout << padding << "+" << string(width + 2, '=') << "+" << endl;

    // OPTIONS
    for (const string& option : options)
    {
        cout << padding << "||"
             << setw(width) << left << ("  " + option)
             << "||" << endl;
    }

    // BOTTOM BORDER
    cout << padding << "+" << string(width + 2, '=') << "+" << endl;

    // INPUT PROMPT
    string prompt = "Enter your choice: ";

    int promptPadding = (width + 4 - prompt.length()) / 2;

    cout << padding
         << string(promptPadding, ' ')
         << prompt;

    cout << "\033[0m";
}