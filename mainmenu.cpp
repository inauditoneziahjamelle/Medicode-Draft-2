
#include <iostream>
#include <limits>
#include "mainmenu.h"
#include "generalquestions.h"
#include "patientpersonalinfo.h"
#include "exitprogram.h"
#include "patientprofile.h"
#include "healthcare.h"


using namespace std;

void mainmenu(PatientData &patient, SymptomData &symptoms)
{
    int choice;

    // Main menu
    while (true)
    {
        cout << endl;
        cout << "==============================================================" << endl;
        cout << "||                        \033[1mMAIN MENU\033[0m                         ||" << endl;
        cout << "==============================================================" << endl;
        cout << "||                   1. REQUEST A DOCTOR                    ||" << endl;
        cout << "||                   2. PATIENT PROFILE                     ||" << endl;
        cout << "||                   3. EXIT                                ||" << endl;
        cout << "==============================================================" << endl;
        cout << "Enter your choice: ";

        // Checks if user input is a valid integer and within the range of menu options
        if (!(cin >> choice))
        {
            cin.clear(); // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input

            cout << "Please enter a valid number." << endl;
            continue; // Restart the loop to display the menu again
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
            case 1:
            {
                healthcare(patient, symptoms);
                break;
            }

            case 2:
            {
                cout << endl;
                cout << "Accessing Patient Profile..." << endl;
                patientprofile(patient, symptoms);

                break;
            }

            case 3:
            {
                exitprogram();
                break;
            }

            default:
            {
                cout << "Please choose a valid option." << endl;
                break;
            }
        }
    }
}
