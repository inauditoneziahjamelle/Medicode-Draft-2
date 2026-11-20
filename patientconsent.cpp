#include <iostream>
#include "patientconsent.h"
#include "exitprogram.h"

using namespace std;

bool patientconsent()
{
    int choice;

    cout << endl;
    cout << "===============================================================" << endl;
    cout << "                      \033[1mPATIENT CONSENT\033[0m" << endl;
    cout << "===============================================================" << endl;

    cout << "\033[3m";
    cout << "       By using MEDICODE, your personal and medical information will be" << endl;
    cout << "       collected to help provide healthcare navigation" << endl;
    cout << "       and connect you with a GP." << endl << endl;
    cout << "\033[0m";

    cout << "===============================================================" << endl;
    cout << "1. Agree" << endl;
    cout << "2. Disagree" << endl;

    cout << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "===============================================================" << endl;

    if (choice == 1)
    {
        return true;
    }
    else if (choice == 2)
    {
        cout << "\nConsent was not provided. MEDICODE will now close." << endl;
        exitprogram();
        return false;
    }
    else
    {
        cout << "Invalid choice. Please choose either 1 or 2." << endl;
        return patientconsent();
    }
}