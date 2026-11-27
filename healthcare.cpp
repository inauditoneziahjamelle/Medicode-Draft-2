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

 // Display Healthcare Assistance Menu
 while(true){
 
    
    cout << "                                                                               \033[31m+==============================================================+\033[0m" << endl;
    cout << "                                                                               \033[31m||\033[0m                   HEALTHCARE ASSISTANCE                    \033[31m||\033[0m" << endl;
    cout << "                                                                               \033[31m+==============================================================+\033[0m" << endl;
    cout << "                                                                               \033[31m||\033[0m     [ 1 ] View Symptom Summary                             \033[31m||\033[0m" << endl;
    cout << "                                                                               \033[31m||\033[0m     [ 2 ] Connect to an Available General Practitioner     \033[31m||\033[0m" << endl;
    cout << "                                                                               \033[31m||\033[0m     [ 3 ] Back to Main Menu                                \033[31m||\033[0m" << endl;
    cout << "                                                                               \033[31m||\033[0m     [ 4 ] Exit                                             \033[31m||\033[0m" << endl;
    cout << "                                                                               \033[31m+==============================================================+\033[0m" << endl;
   
    cin >> nextChoice;


           if (nextChoice == 1)
        {
            displaySymptomSummary(symptomData); 
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
        break;
    }
  }
}
