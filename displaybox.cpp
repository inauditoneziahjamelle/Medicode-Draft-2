#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "displaybox.h"

using namespace std;

void displayQuestionBox(const string& title, const vector<string>& options)
{
    const int width = 96;
    const int consoleWidth = 150;
    const int consoleHeight = 40;

    int leftPadding = (consoleWidth - width - 2) / 2;

    if (leftPadding < 0)
    {
        leftPadding = 0;
    }

    string padding(leftPadding, ' ');

    int boxHeight = options.size() + 4;

    int topPadding = (consoleHeight - boxHeight) / 2;

    if (topPadding < 0)
    {
        topPadding = 0;
    }

    for (int i = 0; i < topPadding; i++)
    {
        cout << endl;
    }

    cout << padding << "+" << string(width, '=') << "+" << endl;

    cout << padding << "|"
         << setw(width) << left << ("  " + title)
         << "|" << endl;

    cout << padding << "+" << string(width, '=') << "+" << endl;

    for (const string& option : options)
    {
        cout << padding << "|"
             << setw(width) << left << ("  " + option)
             << "|" << endl;
    }

    cout << padding << "+" << string(width, '=') << "+" << endl;

    cout << "\033[0m";
}