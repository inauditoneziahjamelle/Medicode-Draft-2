#include <iostream>
#include "patientconsent.h"
#include "exitprogram.h"
#include "patientpersonalinfo.h"

using namespace std;

void patientconsent()
{
    int choice;

    cout << endl;
    cout << "===============================================================" << endl;
    cout << "                      \033[1mPATIENT CONSENT\033[0m" << endl;
    cout << "===============================================================" << endl;

    cout << "\033[3m";
    cout << "       By using MEDICODE, your personal and medical" << endl;
    cout << "       information will becollected to help provide " << endl;
    cout << "       healthcare navigation and connect you with a GP." << endl << endl;
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
        cout << "Please input here your personal information." << endl;
        patientpersonalinfo ();
        return; 
    }
    
    else if (choice == 2)
    {
        cout << "\nConsent was not provided. MEDICODE will now close." << endl;
        exitprogram();
        return;
    }
    else
    {
        cout << "Invalid choice. Please choose either 1 or 2." << endl;
        patientconsent();
    }
}