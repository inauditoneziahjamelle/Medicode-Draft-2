#include <iostream>
#include "patientconsent.h"
#include "exitprogram.h"
#include "patientpersonalinfo.h"
#include "patientdata.h" 

using namespace std;

void patientconsent(PatientData &patient)
{
    int choice;

    cout << endl;
    cout << "===============================================================" << endl;
    cout << "||                    \033[1mPATIENT CONSENT\033[0m                        ||" << endl; 
    cout << "===============================================================" << endl;
    cout << "||                                                           ||" << endl;
    cout << "||      \033[3mBy using MEDICODE, your personal and medical\033[0m         ||" << endl;
    cout << "||     \033[3minformation will be collected to help provide\033[0m         ||" << endl;
    cout << "||     \033[3mhealthcare navigation and connect you with a GP.\033[0m      ||" << endl;
    cout << "||                                                           ||" << endl;
    cout << "===============================================================" << endl;
    cout << "1. Agree" << endl;
    cout << "2. Disagree" << endl;

    cout << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;

    cout << "===============================================================" << endl;

    if (choice == 1)
    {
        cout << "Please input here your personal information." << endl;
        patientpersonalinfo (patient);
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
        patientconsent(patient);
    }
}