#include <iostream>
#include "patientdata.h"
#include "medicodebanner.h"
#include "mainmenu.h"
#include "exitprogram.h"
#include "healthcarefacility.h"
#include "patientconsent.h"
#include "patientpersonalinfo.h"
#include "generalquestions.h"
#include "updatepatientinfo.h"
#include "patientprofile.h" 
#include "symptomdata.h"
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>

#include "pdfgenerator.h"
#include "PDFgen/pdfgen.h"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void patientprofile(PatientData &patient, SymptomData &symptomData)
{
    int choice;
    
    cout << "==============================================================" << endl;
    cout << "                    PATIENT PROFILE MENU                      " << endl;
    cout << "==============================================================" << endl;
    cout << "              1. Update Personal Information                  " << endl;
    cout << "              2. View Symptom Summary                         " << endl;
    cout << "              3. Print User Profile                           " << endl;
    cout << "              4. Back to Main Menu                            " << endl;
    cout << "==============================================================" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1: //update personal info
            {
                updatePatientInformation(patient);
                break; 
            }

        case 2: //view symptom summary
        {
           displaySymptomSummary (symptomData);
            break;
        }
        
        case 3: //prinr user profile
        {
            generatePatientPDF (patient, symptomData);
            break;
        }

        case 4: //main menu
        {
            mainmenu (patient, symptomData);
            break;
        }
    }

}
