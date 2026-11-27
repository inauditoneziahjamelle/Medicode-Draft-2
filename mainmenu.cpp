
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

            case 4:
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
