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

    cout << "                                                                               +==============================================================+" << endl;
    cout << "                                                                               ||                   HEALTHCARE ASSISTANCE                    ||"<< endl;
    cout << "                                                                               +==============================================================+" << endl;
    cout << "                                                                               ||     [ 1 ] View Symptom Summary                             ||" << endl;
    cout << "                                                                               ||     [ 2 ] Connect to an Available General Practitioner     ||" << endl;
    cout << "                                                                               ||     [ 3 ] Back to Main Menu                                ||" << endl;
    cout << "                                                                               ||     [ 4 ] Exit                                             ||" << endl;
    cout << "                                                                               +==============================================================+" << endl;
    cout << "                                                                                                    Enter your choice: ";
    cin >> nextChoice;

    if (nextChoice == 1)
    {
        displaySymptomSummary(symptomData);
        return;
    }
    else if (nextChoice == 2)
    {
        cout << "                                                                               Connecting to an Available General Practitioner...\n";
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