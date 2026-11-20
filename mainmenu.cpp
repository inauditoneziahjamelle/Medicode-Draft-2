#include <iostream>
#include "mainmenu.h"
#include "generalquestions.h"
#include "patientpersonalinfo.h"
#include "exitprogram.h"

using namespace std;

void mainmenu(PatientData &patient, SymptomData &symptoms)
{
    int choice;

    while (true)
    {
        cout << endl;
        cout << "===============================================================" << endl;
        cout << "                          \033[1mMAIN MENU\033[0m" << endl;
        cout << "===============================================================" << endl;

        cout << "1. REQUEST A DOCTOR" << endl;
        cout << "2. PATIENT PROFILE" << endl;
        cout << "3. EXIT" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                if (generalquestions(symptoms))
                {
                    exitprogram();
                    return;
                }

                break;
            }

            case 2:
            {
                cout << endl;
                cout << "Accessing Patient Profile..." << endl;

                // A separate profile-viewing function is needed here.
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