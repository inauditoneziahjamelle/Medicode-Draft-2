#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <set>
#include <stdexcept>
#include <windows.h>
#include "patientpersonalinfo.h"
#include "patientdata.h"
#include "generalquestions.h"
#include "mainmenu.h"

using namespace std;

// VALIDATES REQUIRED TEXT INPUT

string readRequiredText()
{
    string input;
    string indent = "                                                                                                   ";

    while (true)
    {
         getline(cin, input);

        if (input.find_first_not_of(" \t") == string::npos)
        {
            cout << endl;
            cout << indent << "\033[3;31mYou need to fill this up!\033[0m" << endl;
            cout << indent << "Please enter the information: ";
        }
        else
        {
            return input;
        }
    }
}




int readChoice(int minimum, int maximum)
{
    string input;
    string indent = "                                                                                                   ";

    while (true)
    {
        getline(cin, input);

        if (input.find_first_not_of(" \t") == string::npos)
        {
            cout << indent << "\033[3;31mInput missing!\033[0m" << endl;
            cout << indent<< "Please enter your choice: ";
            continue;
        }

        size_t position = 0;
        int value;

        try
        {
            value = stoi(input, &position);
        }
        catch (const invalid_argument&)
        {
                                cout << indent << "\033[3;31mPlease enter a number only.\033[0m" << endl;
                                cout << indent << "Please enter your choice: ";
            continue;
        }
        catch (const out_of_range&)
        {
            cout << indent << "\033[3;31mNumber is out of range.\033[0m" << endl;
            cout << indent << "Please enter your choice: ";
            continue;
        }

        if (position != input.length())
        {
            cout << indent << "\033[3;31mPlease enter a number only.\033[0m" << endl;
            cout << indent << "Please enter your choice: ";
            continue;
        }

        if (value < minimum || value > maximum)
        {
            cout << indent << "\033[3;31mInvalid choice.\033[0m" << endl;
            cout << indent << "Please enter your choice: ";
            continue;
        }

        return value;
    }
}



// STORES GENERATED PATIENT IDS
set<string> usedPatientIDs;


// GENERATES A UNIQUE RANDOM PATIENT ID
string generatePatientID()
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dist(100000, 999999);

    string patientID;

    do
    {
        patientID = "MED-" + to_string(dist(gen));
    }
    while (usedPatientIDs.find(patientID) != usedPatientIDs.end());

    usedPatientIDs.insert(patientID);

    return patientID;
}


// PATIENT PERSONAL INFORMATION
void patientpersonalinfo(PatientData &patient)
{
    SetConsoleOutputCP(CP_UTF8);
    int choice;
    int sexChoice;
    int option;
    int moreChoice;
    int count;

    string tempOthers;
    string entry;
    string item;

    // GENERATE PATIENT ID
    if (patient.patientID.empty())
    {
        patient.patientID = generatePatientID();
    }


    // I. GENERAL DATA

    cout << endl;
    cout << "                                                                           +=============================================================+" << endl;
    cout << "                                                                           ||                  \033[1mPATIENT'S INFORMATION\033[0m                    ||" << endl; 
    cout << "                                                                           +=============================================================+" << endl;

    cout << endl;
    cout << "                                                                                               USER ID AND INFORMATION" << endl;
    cout << "                                                                                               Patient ID: " << patient.patientID << endl;


    cout << endl;
    cout << "                                                                                       I. GENERAL DATA" << endl;
    cout << endl;

    cout << "                                                                                                   Name of Patient: ";
                                                                                                                patient.name = readRequiredText();

    cout << "                                                                                                   Age: ";
                                                                                                                patient.age = readRequiredText();

    cout << "                                                                                                   Address: ";
                                                                                                                patient.address = readRequiredText();

    cout << "                                                                                                   Civil Status: ";
                                                                                                                patient.civilStatus = readRequiredText();

    cout << "                                                                                                   Sex:" << endl;
    cout << "                                                                                                   [ 1 ] Male" << endl;
    cout << "                                                                                                   [ 2 ] Female" << endl;
    cout << "                                                                                                   Enter choice: ";
                                                                                                                sexChoice = readChoice(1, 2);
    if (sexChoice == 1)
    {
        patient.sexChoice = "Male";
    }
    else if (sexChoice == 2)
    {
        patient.sexChoice = "Female";
    }
    else
    {
        patient.sexChoice = "Not Specified";
    }

    // II. HISTORY OF PRESENT ILLNESS

    cout << endl;
    cout << "                                                                                       II. HISTORY OF PRESENT ILLNESS" << endl;
    cout << endl;
    cout << "                                                                                                   Chief Complaint:" << endl;

    patient.historyPresentIllness.clear();
    count = 0;

    do
    {
        cout << "                                                                                                   [ 1 ] Fever" << endl;
        cout << "                                                                                                   [ 2 ] Coughing/Cold" << endl;
        cout << "                                                                                                   [ 3 ] Pain/Ache" << endl;
        cout << "                                                                                                   [ 4 ] Dizziness/Fatigue" << endl;
        cout << "                                                                                                   [ 5 ] Others" << endl;
        cout << "                                                                                                   Enter choice: ";
        option = readChoice(1, 5);

        item = "";

        if (option == 1)      item = "Fever";
        else if (option == 2) item = "Coughing/Cold";
        else if (option == 3) item = "Pain/Ache";
        else if (option == 4) item = "Dizziness/Fatigue";
        else if (option == 5)
        {
            cout << "                                                                                           Please specify: ";
            item = readRequiredText();
        }

        if (!item.empty())
        {
            if (count > 0)
            {
                patient.historyPresentIllness += "\n";
            }
            count++;
            patient.historyPresentIllness += to_string(count) + ". " + item;
        }
        else if (option < 1 || option > 5)
        {
            cout << "                                                                                           Invalid choice." << endl;
        }

        cout << endl;
        cout << "                                                                                                   Add another? (1. Yes, 2. No): ";
        moreChoice = readChoice(1, 2);
    }
    while (moreChoice == 1);

    if (patient.historyPresentIllness.empty())
    {
        patient.historyPresentIllness = "Not Specified";
    }

    // III. PAST MEDICAL HISTORY

    cout << endl;
    cout << "                                                                                       III. PAST MEDICAL HISTORY" << endl;


    // OPERATIONS

    cout << endl;
    cout << "                                                                                                   OPERATIONS:" << endl;
    cout << "                                                                                                   [ 1 ] Yes" << endl;
    cout << "                                                                                                   [ 2 ] No" << endl;
    cout << "                                                                                                   [ 3 ] Unknown" << endl;
    cout << "                                                                                                   Enter choice: ";
    option = readChoice(1, 3);

    if (option == 1)
    {
        cout << "                                                                                                   Please specify: ";
        patient.operations = readRequiredText();
    }
    else if (option == 2)
    {
        patient.operations = "No";
    }
    else if (option == 3)
    {
        patient.operations = "Unknown";
    }
    else
    {
        patient.operations = "Not Specified";
    }


    // IMMUNIZATIONS

    cout << endl;
    cout << "                                                                                                   IMMUNIZATIONS:" << endl;
    cout << "                                                                                                   [ 1 ] Complete" << endl;
    cout << "                                                                                                   [ 2 ] Incomplete" << endl;
    cout << "                                                                                                   [ 3 ] Unknown" << endl;
    cout << "                                                                                                   Enter choice: ";
    option = readChoice(1, 3);

    if (option == 1)
    {
        cout << "                                                                                                   Please specify: ";
        patient.immunizations = readRequiredText();
    }
    else if (option == 2)
    {
        cout << "                                                                                                   Please specify what immunizations are incomplete: ";
        patient.immunizations = readRequiredText();
    }
    else if (option == 3)
    {
        patient.immunizations = "Unknown";
    }
    else
    {
        patient.immunizations = "Not Specified";
    }


    // ALLERGIES

    cout << endl;
    cout << "                                                                                                   ALLERGIES:" << endl;
    cout << "                                                                                                   [ 1 ] Yes" << endl;
    cout << "                                                                                                   [ 2 ] No" << endl;
    cout << "                                                                                                   [ 3 ] Unknown" << endl;
    cout << "                                                                                                   Enter choice: ";
    option = readChoice(1, 3);

    if (option == 1)
    {
        cout << "                                                                                                   Please specify: ";
        patient.allergies = readRequiredText();
    }
    else if (option == 2)
    {
        patient.allergies = "No";
    }
    else if (option == 3)
    {
        patient.allergies = "Unknown";
    }
    else
    {
        patient.allergies = "Not Specified";
    }


    // HOSPITALIZATIONS

    cout << endl;
    cout << "                                                                                                   HOSPITALIZATIONS:" << endl;
    cout << "                                                                                                   [ 1 ] Yes" << endl;
    cout << "                                                                                                   [ 2 ] No" << endl;
    cout << "                                                                                                   [ 3 ] Unknown" << endl;
    cout << "                                                                                                   Enter choice: ";
    option = readChoice(1, 3);

    if (option == 1)
    {
        cout << "                                                                                                   Please specify: ";
        patient.hospitalizations = readRequiredText();
    }
    else if (option == 2)
    {
        patient.hospitalizations = "No";
    }
    else if (option == 3)
    {
        patient.hospitalizations = "Unknown";
    }
    else
    {
        patient.hospitalizations = "Not Specified";
    }


    // MAINTENANCE MEDICATIONS

    cout << endl;
    cout << "                                                                                                   MAINTENANCE MEDICATIONS:" << endl;
    cout << "                                                                                                   [ 1 ] Yes" << endl;
    cout << "                                                                                                   [ 2 ] No" << endl;
    cout << "                                                                                                   [ 3 ] Unknown" << endl;
    cout << "                                                                                                   Enter choice: ";
    option = readChoice(1, 3);

    if (option == 1)
    {
        cout << "                                                                                                   Please specify: ";
        patient.maintenanceMeds = readRequiredText();
    }
    else if (option == 2)
    {
        patient.maintenanceMeds = "No";
    }
    else if (option == 3)
    {
        patient.maintenanceMeds = "Unknown";
    }
    else
    {
        patient.maintenanceMeds = "Not Specified";
    }


    // OTHERS

    cout << endl;
    cout << "                                                                                                   OTHERS" << endl;
    cout << "                                                                                                   [ 1 ] Yes" << endl;
    cout << "                                                                                                   [ 2 ] No" << endl;
    cout << "                                                                                                   Enter choice: ";
    option = readChoice(1, 2);

    if (option == 1)
    {
        cout << "                                                                                                   Please specify: ";
        patient.othersMedical = readRequiredText();
    }
    else if (option == 2)
    {
        patient.othersMedical = "No";
    }
    else
    {
        patient.othersMedical = "Not Specified";
    }


    // IV. FAMILY HISTORY

    cout << endl;
    cout << "                                                                                       IV. FAMILY HISTORY" << endl;


    // BRONCHIAL ASTHMA

    cout << endl;
    cout << "                                                                                                   BRONCHIAL ASTHMA:" << endl;
    cout << "                                                                                                   [ 1 ] Yes" << endl;
    cout << "                                                                                                   [ 2 ] No" << endl;
    cout << "                                                                                                   [ 3 ] Unknown" << endl;
    cout << "                                                                                                   Enter choice: ";
    option = readChoice(1, 3);

    if (option == 1)
        patient.bronchialAsthma = "Yes";
    else if (option == 2)
        patient.bronchialAsthma = "No";
    else if (option == 3)
        patient.bronchialAsthma = "Unknown";
    else
        patient.bronchialAsthma = "Not Specified";


    // DIABETES MELLITUS

    cout << endl;
    cout << "                                                                                                   DIABETES MELLITUS:" << endl;
    cout << "                                                                                                   [ 1 ] Yes" << endl;
    cout << "                                                                                                   [ 2 ] No" << endl;
    cout << "                                                                                                   [ 3 ] Unknown" << endl;
    cout << "                                                                                                   Enter choice: ";
    option = readChoice(1, 3);

    if (option == 1)
        patient.diabetesMellitus = "Yes";
    else if (option == 2)
        patient.diabetesMellitus = "No";
    else if (option == 3)
        patient.diabetesMellitus = "Unknown";
    else
        patient.diabetesMellitus = "Not Specified";


    // HYPERTENSION

    cout << endl;
    cout << "                                                                                                   HYPERTENSION:" << endl;
    cout << "                                                                                                   [ 1 ] Yes" << endl;
    cout << "                                                                                                   [ 2 ] No" << endl;
    cout << "                                                                                                   [ 3 ] Unknown" << endl;
    cout << "                                                                                                   Enter choice: ";
    option = readChoice(1, 3);

    if (option == 1)
        patient.hypertension = "Yes";
    else if (option == 2)
        patient.hypertension = "No";
    else if (option == 3)
        patient.hypertension = "Unknown";
    else
        patient.hypertension = "Not Specified";


    // PULMONARY TUBERCULOSIS

    cout << endl;
    cout << "                                                                                                   PULMONARY TUBERCULOSIS:" << endl;
    cout << "                                                                                                   [ 1 ] Yes" << endl;
    cout << "                                                                                                   [ 2 ] No" << endl;
    cout << "                                                                                                   [ 3 ] Unknown" << endl;
    cout << "                                                                                                   Enter choice: ";
    option = readChoice(1, 3);

    if (option == 1)
        patient.pulmonaryTuberculosis = "Yes";
    else if (option == 2)
        patient.pulmonaryTuberculosis = "No";
    else if (option == 3)
        patient.pulmonaryTuberculosis = "Unknown";
    else
        patient.pulmonaryTuberculosis = "Not Specified";


    // FAMILY HISTORY OTHERS

    cout << endl;
    cout << "                                                                                                   OTHERS" << endl;
    cout << "                                                                                                   [ 1 ] Yes" << endl;
    cout << "                                                                                                   [ 2 ] No" << endl;
    cout << "                                                                                                   Enter choice: ";
    option = readChoice(1, 2);

    if (option == 1)
    {
        cout << "                                                                                                   Please specify: ";
        patient.othersFamily = readRequiredText();
    }
    else if (option == 2)
    {
        patient.othersFamily = "No";
    }
    else
    {
        patient.othersFamily = "Not Specified";
    }


    // V. SOCIAL, ENVIRONMENTAL, PERSONAL HISTORY

    cout << endl;
    cout << "                                                                                       V. SOCIAL, ENVIRONMENTAL, PERSONAL HISTORY" << endl;


    // SMOKER

    cout << endl;
    cout << "                                                                                                   SMOKER:" << endl;
    cout << "                                                                                                   [ 1 ] Yes" << endl;
    cout << "                                                                                                   [ 2 ] No" << endl;
    cout << "                                                                                                   [ 3 ] Former Smoker" << endl;
    cout << "                                                                                                   Enter choice: ";
    option = readChoice(1, 3);

    if (option == 1)
        patient.smoker = "Yes";
    else if (option == 2)
        patient.smoker = "No";
    else if (option == 3)
        patient.smoker = "Former Smoker";
    else
        patient.smoker = "Not Specified";


    // ALCOHOLIC BEVERAGE DRINKER

    cout << endl;
    cout << "                                                                                                   ALCOHOLIC BEVERAGE DRINKER:" << endl;
    cout << "                                                                                                   [ 1 ] Yes" << endl;
    cout << "                                                                                                   [ 2 ] No" << endl;
    cout << "                                                                                                   [ 3 ] Occasionally" << endl;
    cout << "                                                                                                   Enter choice: ";
    option = readChoice(1, 3);

    if (option == 1)
        patient.alcoholicBeverageDrinker = "Yes";
    else if (option == 2)
        patient.alcoholicBeverageDrinker = "No";
    else if (option == 3)
        patient.alcoholicBeverageDrinker = "Occasionally";
    else
        patient.alcoholicBeverageDrinker = "Not Specified";


    // WORK / ENVIRONMENTAL HAZARDS

    cout << endl;
    cout << "                                                                                                   WORK/ENVIRONMENTAL HAZARDS:" << endl;
    cout << "                                                                                                   [ 1 ] Yes" << endl;
    cout << "                                                                                                   [ 2 ] No" << endl;
    cout << "                                                                                                   [ 3 ] Unknown" << endl;
    cout << "                                                                                                   Enter choice: ";
    option = readChoice(1, 3);

    if (option == 1)
    {
        cout << "                                                                                                   Please specify: ";
        patient.workEnvironmentalHazards = readRequiredText();
    }
    else if (option == 2)
    {
        patient.workEnvironmentalHazards = "No";
    }
    else if (option == 3)
    {
        patient.workEnvironmentalHazards = "Unknown";
    }
    else
    {
        patient.workEnvironmentalHazards = "Not Specified";
    }

    // VI. OB-GYNE HISTORY
    // FEMALE ONLY

    if (patient.sexChoice == "Female")
    {
        cout << endl;
        cout << "                                                                                   VI. OB-GYNE HISTORY" << endl;
        cout << endl;

        // MENARCHE
        cout << "                                                                                               MENARCHE (First menstruation):" << endl;
        cout << "                                                                                               [ 1 ] Before 10 years old" << endl;
        cout << "                                                                                               [ 2 ] 10-12 years old" << endl;
        cout << "                                                                                               [ 3 ] 13-15 years old" << endl;
        cout << "                                                                                               [ 4 ] 16 years old or above" << endl;
        cout << "                                                                                               [ 5 ] Unknown" << endl;
        cout << "                                                                                               Enter choice: ";
        option = readChoice(1, 5);

        if (option == 1)
            patient.menarche = "Before 10 years old";
        else if (option == 2)
            patient.menarche = "10-12 years old";
        else if (option == 3)
            patient.menarche = "13-15 years old";
        else if (option == 4)
            patient.menarche = "16 years old or above";
        else
            patient.menarche = "Unknown";


        // MENSTRUAL HISTORY

        cout << endl;
        cout << "                                                                                               MENSTRUAL HISTORY:" << endl;
        cout << "                                                                                               [ 1 ] Regular" << endl;
        cout << "                                                                                               [ 2 ] Irregular" << endl;
        cout << "                                                                                               [ 3 ] Not Applicable" << endl;
        cout << "                                                                                               [ 4 ] Unknown" << endl;
        cout << "                                                                                               Enter choice: ";
        option = readChoice(1, 4);

        if (option == 1)
            patient.menstrualHistory = "Regular";
        else if (option == 2)
            patient.menstrualHistory = "Irregular";
        else if (option == 3)
            patient.menstrualHistory = "Not Applicable";
        else
            patient.menstrualHistory = "Unknown";


        // GRAVIDA

        cout << endl;
        cout << "                                                                                               GRAVIDA (Number of pregnancies):" << endl;
        cout << "                                                                                               [ 1 ] 0" << endl;
        cout << "                                                                                               [ 2 ] 1" << endl;
        cout << "                                                                                               [ 3 ] 2" << endl;
        cout << "                                                                                               [ 4 ] 3 or more" << endl;
        cout << "                                                                                               [ 5 ] Unknown" << endl;
        cout << "                                                                                               Enter choice: ";
        option = readChoice(1, 5);

        if (option == 1)
            patient.gravida = "0";
        else if (option == 2)
            patient.gravida = "1";
        else if (option == 3)
            patient.gravida = "2";
        else if (option == 4)
            patient.gravida = "3 or more";
        else
            patient.gravida = "Unknown";


        // PARA

        cout << endl;
        cout << "                                                                                               PARA (Number of living children):" << endl;
        cout << "                                                                                               [ 1 ] No living children" << endl;
        cout << "                                                                                               [ 2 ] One living child" << endl;
        cout << "                                                                                               [ 3 ] Two living children" << endl;
        cout << "                                                                                               [ 4 ] Three or more living children" << endl;
        cout << "                                                                                               [ 5 ] Unknown" << endl;
        cout << "                                                                                               Enter choice: ";
        option = readChoice(1, 5);

        if (option == 1)
            patient.para = "No living children";
        else if (option == 2)
            patient.para = "One living child";
        else if (option == 3)
            patient.para = "Two living children";
        else if (option == 4)
            patient.para = "Three or more living children";
        else
            patient.para = "Unknown";


        // LAST MENSTRUAL PERIOD

        cout << endl;
        cout << "                                                                                               LAST MENSTRUAL PERIOD:" << endl;
        cout << "                                                                                               [ 1 ] Within the last month" << endl;
        cout << "                                                                                               [ 2 ] 1-3 months ago" << endl;
        cout << "                                                                                               [ 3 ] More than 3 months ago" << endl;
        cout << "                                                                                               [ 4 ] Unknown" << endl;
        cout << "                                                                                               Enter choice: ";
        option = readChoice(1, 4);

        if (option == 1)
            patient.lastMenstrualPeriod = "Within the last month";
        else if (option == 2)
            patient.lastMenstrualPeriod = "1-3 months ago";
        else if (option == 3)
            patient.lastMenstrualPeriod = "More than 3 months ago";
        else
            patient.lastMenstrualPeriod = "Unknown";


        // MENOPAUSE

        cout << endl;
        cout << "                                                                                               MENOPAUSE (Permanent cessation of menstruation):" << endl;
        cout << "                                                                                               [ 1 ] Yes" << endl;
        cout << "                                                                                               [ 2 ] No" << endl;
        cout << "                                                                                               [ 3 ] Unknown" << endl;
        cout << "                                                                                               Enter choice: ";
        option = readChoice(1, 3);

        if (option == 1)
            patient.menopause = "Yes";
        else if (option == 2)
            patient.menopause = "No";
        else
            patient.menopause = "Unknown";


        // OB-GYNE OTHERS

        cout << endl;
        cout << "                                                                                               OTHERS:" << endl;
        cout << "                                                                                               [ 1 ] Yes" << endl;
        cout << "                                                                                               [ 2 ] No" << endl;
        cout << "                                                                                               Enter choice: ";
        option = readChoice(1, 2);

        if (option == 1)
        {
            cout << "Please specify: ";
            patient.othersOBGyne = readRequiredText();
        }
        else
        {
            patient.othersOBGyne = "No";
        }
    }


    // MARK PROFILE AS COMPLETED
    patient.profileCompleted = true;


    // PATIENT SUMMARY
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\033[1;38;2;225;132;132m";
    cout << endl;
    cout << "                                                                           +=============================================================+" << endl;
    cout << "                                                                           ||                PATIENT INFORMATION SUMMARY                ||" << endl;
    cout << "                                                                           +=============================================================+" << endl;

    cout << "                                                                                             Patient ID: " << patient.patientID << "             " << endl;


    cout << "                                                                                                                                     " << endl;
    cout << "                                                                            I. GENERAL DATA                                           " << endl;
    cout << "                                                                            Name: " << patient.name << "                              " << endl;
    cout << "                                                                            Age: " << patient.age << "                                " << endl;
    cout << "                                                                            Sex: " << patient.sexChoice << "                          " << endl;
    cout << "                                                                            Address: " << patient.address << "                        " << endl;
    cout << "                                                                            Civil Status: " << patient.civilStatus << "               " << endl;

    
    cout << endl;
    cout << "                                                                            II. HISTORY OF PRESENT ILLNESS" << endl;
    cout << "                                                                            Illnesses:"<<  patient.historyPresentIllness << endl;


    cout << endl;
    cout << "                                                                            III. PAST MEDICAL HISTORY" << endl;
    cout << "                                                                            Operations: " << patient.operations << endl;
    cout << "                                                                            Immunizations: " << patient.immunizations << endl;
    cout << "                                                                            Allergies: " << patient.allergies << endl;
    cout << "                                                                            Hospitalizations: " << patient.hospitalizations << endl;
    cout << "                                                                            Maintenance Medications: " << patient.maintenanceMeds << endl;
    cout << "                                                                            Others: " << patient.othersMedical << endl;


    cout << endl;
    cout << "                                                                            IV. FAMILY HISTORY" << endl;
    cout << "                                                                            Bronchial Asthma: " << patient.bronchialAsthma << endl;
    cout << "                                                                            Diabetes Mellitus: " << patient.diabetesMellitus << endl;
    cout << "                                                                            Hypertension: " << patient.hypertension << endl;
    cout << "                                                                            Pulmonary Tuberculosis: " << patient.pulmonaryTuberculosis << endl;
    cout << "                                                                            Others: " << patient.othersFamily << endl;


    cout << endl;
    cout << "                                                                            V. SOCIAL, ENVIRONMENTAL, PERSONAL HISTORY" << endl;
    cout << "                                                                            Smoker: " << patient.smoker << endl;
    cout << "                                                                            Alcoholic Beverage Drinker: "
         <<                                                                              patient.alcoholicBeverageDrinker << endl;
    cout << "                                                                            Work/Environmental Hazards: "
         <<                                                                              patient.workEnvironmentalHazards << endl;


    // SHOW OB-GYNE SUMMARY ONLY FOR FEMALE

    if (patient.sexChoice == "Female")
    {
        cout << endl;
        cout << "                                                                            VI. OB-GYNE HISTORY" << endl;
        cout << "                                                                            Menarche: " << patient.menarche << endl;
        cout << "                                                                            Menstrual History: " << patient.menstrualHistory << endl;
        cout << "                                                                            Gravida: " << patient.gravida << endl;
        cout << "                                                                            Para: " << patient.para << endl;
        cout << "                                                                            Last Menstrual Period: "
             <<                                                                              patient.lastMenstrualPeriod << endl;
        cout << "                                                                            Menopause: " << patient.menopause << endl;
        cout << "                                                                            Others: " << patient.othersOBGyne << endl;
    }


    // FINAL OPTIONS

    cout << endl;
    cout << "                                                                            =============================================" << endl;
    cout << "                                                                                           1. Proceed" << endl;
    cout << "                                                                                           2. Exit" << endl;
    cout << endl;
    cout << "                                                                                           Enter choice: ";
    choice = readChoice(1, 2);

    if (choice == 1)
    {
        cout << endl;
    cout << "                                                               +=============================================================+" << endl;
    cout << "                                                               ||               \033[1mGENERAL PATIENT QUESTIONS\033[0m            ||" << endl; 
    cout << "                                                               +=============================================================+" << endl;

        SymptomData symptoms{};
        generalquestions(patient, symptoms);
        mainmenu(patient, symptoms);
    }
    else if (choice == 2)
    {
        cout << endl;
        cout << "MEDICODE - Quick Care, For A More Convenient Healthcare!"
             << endl;
        cout << "Thank you for using MEDICODE." << endl;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}