
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "mainmenu.h"
#include "generalquestions.h"
#include "patientpersonalinfo.h"
#include "exitprogram.h"
#include "patientprofile.h"
#include "healthcare.h"
#include "displaybox.h"

using namespace std;

void mainmenu(PatientData &patient, SymptomData &symptoms)
{
    int choice;

    while (true)
    {
        cout << endl;

        displayQuestionBox("MAIN MENU", {
            "[ 1 ] REQUEST A DOCTOR",
            "[ 2 ] PATIENT PROFILE",
            "[ 3 ] EXIT"
        });

        cout << endl;
        cout << "Enter your choice: ";

        // Check if the input is a valid integer
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Please enter a valid number." << endl;
            continue;
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
                return;
            }

            default:
            {
                cout << "Please choose a valid option." << endl;
                break;
            }
        }
    }
}
