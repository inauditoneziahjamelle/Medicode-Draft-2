#include <iostream>
#include <string>
#include <limits>
#include "generalquestions.h"
#include "healthcarefacility.h"
#include "patientdata.h"
#include "symptomdata.h"
#include "mainmenu.h"
#include "exitprogram.h"

using namespace std;

void healthcare(PatientData &patient,SymptomData &symptomData)
{
 int nextChoice;

    cout << "\n========================================\n";
    cout << "           HEALTHCARE ASSISTANCE          \n";
    cout << "========================================\n";
    cout << "1. View Symptom Summary\n";
    cout << "2. Connect to an Available General Practitioner\n";
    cout << "3. Back to Main Menu\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> nextChoice;

    if (nextChoice == 1)
    {
        displaySymptomSummary(symptomData);
        return;
    }
    else if (nextChoice == 2)
    {
        cout << "\nConnecting to an Available General Practitioner...\n";
        healthcarefacility();
        return;
    }
    else if (nextChoice == 3)
    {
        mainmenu(patient,symptomData);
        return;
    }
    else if (nextChoice == 4)
    {
        exitprogram();
        return;
    }
    
}