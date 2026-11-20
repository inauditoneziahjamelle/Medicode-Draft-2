#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <set>
#include "patientpersonalinfo.h"
#include "mainmenu.h"
#include "patientdata.h"
#include "symptomdata.h"
#include "exitprogram.h"

using namespace std;


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
void patientpersonalinfo(PatientData &patient, SymptomData &symptoms)
{
    int choice;
    int sexChoice;
    int option;
    int moreChoice;

    // GENERATE PATIENT ID
    string assignedPatientID = generatePatientID();


    // I. GENERAL DATA
    string name, age, sex, address, civilStatus;

    // II. HISTORY OF PRESENT ILLNESS
    string historyPresentIllness;
    string tempOthers;
    string entry;

    // III. PAST MEDICAL HISTORY
    string operations;
    string immunizations;
    string allergies;
    string hospitalizations;
    string maintenanceMeds;
    string othersMedical;

    // IV. FAMILY HISTORY
    string bronchialAsthma;
    string diabetesMellitus;
    string hypertension;
    string pulmonaryTuberculosis;
    string othersFamily;

    // V. SOCIAL, ENVIRONMENTAL, PERSONAL HISTORY
    string smoker;
    string alcoholicBeverageDrinker;
    string workEnvironmentalHazards;

    // VI. OB-GYNE HISTORY
    string menarche;
    string menstrualHistory;
    string gravida;
    string para;
    string lastMenstrualPeriod;
    string menopause;
    string othersOBGyne;


    cout << endl;
    cout << "=============================================" << endl;
    cout << "            PATIENT'S INFORMATION" << endl;
    cout << "=============================================" << endl;

    cout << endl;
    cout << "USER ID AND INFORMATION" << endl;
    cout << "Patient ID: " << assignedPatientID << endl;


    // I. GENERAL DATA
    cout << endl;
    cout << "I. GENERAL DATA" << endl;

    cout << "Name of Patient: ";
    getline(cin, name);

    cout << "Age: ";
    getline(cin, age);

    cout << endl;
    cout << "Sex:" << endl;
    cout << "1. Male" << endl;
    cout << "2. Female" << endl;
    cout << "Enter choice: ";
    cin >> sexChoice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (sexChoice == 1) {
        sex = "Male";
    } else if (sexChoice == 2) {
        sex = "Female";
    } else {
        sex = "Not Specified";
    }

    cout << "Address: ";
    getline(cin, address);

    cout << "Civil Status: ";
    getline(cin, civilStatus);


    // II. HISTORY OF PRESENT ILLNESS
    cout << endl;
    cout << "II. HISTORY OF PRESENT ILLNESS" << endl;
    cout << "Chief Complaint:" << endl;
    cout << "1. Fever" << endl;
    cout << "2. Coughing/Cold" << endl;
    cout << "3. Pain/Ache" << endl;
    cout << "4. Dizziness/Fatigue" << endl;
    cout << "5. Others" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1) {
        historyPresentIllness = "Fever";
    } else if (option == 2) {
        historyPresentIllness = "Coughing/Cold";
    } else if (option == 3) {
        historyPresentIllness = "Pain/Ache";
    } else if (option == 4) {
        historyPresentIllness = "Dizziness/Fatigue";
    } else if (option == 5) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        do {
            cout << "Please specify: ";
            getline(cin, entry);

            if (tempOthers.empty()) {
                tempOthers = entry;
            }
            else {
                tempOthers += ", " + entry;
            }

            cout << endl;
            cout << "Is that all? (1. Yes, 2. No): ";
            cin >> moreChoice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (moreChoice == 2);

        historyPresentIllness = tempOthers;
    } else {
        historyPresentIllness = "Not Specified";
    }

    // III. PAST MEDICAL HISTORY
    cout << endl;
    cout << "III. PAST MEDICAL HISTORY" << endl;


    cout << endl;
    cout << "OPERATIONS:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please specify: ";
        getline(cin, operations);
    } else if (option == 2) {
        operations = "No";
    } else if (option == 3) {
        operations = "Unknown";
    } else {
        operations = "Not Specified";
    }


    cout << endl;
    cout << "IMMUNIZATIONS:" << endl;
    cout << "1. Complete" << endl;
    cout << "2. Incomplete" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please specify: ";
        getline(cin, immunizations);
    } else if (option == 2) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please specify what immunizations are incomplete (If you don't know, please type 'Unknown'): ";
        getline(cin, immunizations);
    } else if (option == 3) {
        immunizations = "Unknown";
    } else {
        immunizations = "Not Specified";
    }


    cout << endl;
    cout << "ALLERGIES:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please specify: ";
        getline(cin, allergies);
    } else if (option == 2) {
        allergies = "No";
    } else if (option == 3) {
        allergies = "Unknown";
    } else {
        allergies = "Not Specified";
    }


    cout << endl;
    cout << "HOSPITALIZATIONS:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please specify: ";
        getline(cin, hospitalizations);
    } else if (option == 2) {
        hospitalizations = "No";
    } else if (option == 3) {
        hospitalizations = "Unknown";
    } else {
        hospitalizations = "Not Specified";
    }


    cout << endl;
    cout << "MAINTENANCE MEDICATIONS:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please specify: ";
        getline(cin, maintenanceMeds);
    } else if (option == 2) {
        maintenanceMeds = "No";
    } else if (option == 3) {
        maintenanceMeds = "Unknown";
    } else {
        maintenanceMeds = "Not Specified";
    }


    cout << endl;
    cout << "OTHERS" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please specify: ";
        getline(cin, maintenanceMeds);
    } else if (option == 2) {
        othersMedical = "No";
    } else {
        othersMedical = "Not Specified";
    }

    // IV. FAMILY HISTORY
    cout << endl;
    cout << "IV. FAMILY HISTORY" << endl;


    cout << endl;
    cout << "BRONCHIAL ASTHMA:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1) {
        bronchialAsthma = "Yes";
    } else if (option == 2) {
        bronchialAsthma = "No";
    } else if (option == 3) {
        bronchialAsthma = "Unknown";
    } else {
        bronchialAsthma = "Not Specified";
    }


    cout << endl;
    cout << "DIABETES MELLITUS:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1) {
        diabetesMellitus = "Yes";
    } else if (option == 2) {
        diabetesMellitus = "No";
    } else if (option == 3) {
        diabetesMellitus = "Unknown";
    } else {
        diabetesMellitus = "Not Specified";
    }

    cout << endl;
    cout << "HYPERTENSION:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1) {
        hypertension = "Yes";
    } else if (option == 2) {
        hypertension = "No";
    } else if (option == 3) {
        hypertension = "Unknown";
    } else {
        hypertension = "Not Specified";
    }

    cout << endl;
    cout << "PULMONARY TUBERCULOSIS:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1) {
        pulmonaryTuberculosis = "Yes";
    } else if (option == 2) {
        pulmonaryTuberculosis = "No";
    } else if (option == 3) {
        pulmonaryTuberculosis = "Unknown";
    } else {
        pulmonaryTuberculosis = "Not Specified";
    }


    cout << endl;
    cout << "OTHERS" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Please specify: ";
    getline(cin, othersFamily);
    } else if (option == 2) {
        othersFamily = "No";
    } else {
        othersFamily = "Not Specified";
    }

    // V. SOCIAL, ENVIRONMENTAL, PERSONAL HISTORY

    cout << endl;
    cout << "V. SOCIAL, ENVIRONMENTAL, PERSONAL HISTORY" << endl;


    cout << endl;
    cout << "SMOKER:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Former Smoker" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1) {
        smoker = "Yes";
    } else if (option == 2) {
        smoker = "No";
    } else {
        smoker = "Former Smoker";
    }

    cout << endl;
    cout << "ALCOHOLIC BEVERAGE DRINKER:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Occasionally" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1) {
        alcoholicBeverageDrinker = "Yes";
    } else if (option == 2) {
        alcoholicBeverageDrinker = "No";
    } else {
        alcoholicBeverageDrinker = "Occasionally";
    }

    cout << endl;
    cout << "WORK/ENVIRONMENTAL HAZARDS:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please specify: ";
        getline(cin, workEnvironmentalHazards);
    } else if (option == 2) {
        workEnvironmentalHazards = "No";
    } else {
        workEnvironmentalHazards = "Unknown";
    }

    // VI. OB-GYNE HISTORY
    // FEMALE only

    if (sexChoice == 2) {
        cout << endl;
        cout << "VI. OB-GYNE HISTORY" << endl;


        cout << endl;
        cout << "MENARCHE (First menstruation):" << endl;
        cout << "1. Before 10 years old" << endl;
        cout << "2. 10-12 years old" << endl;
        cout << "3. 13-15 years old" << endl;
        cout << "4. 16 years old or above" << endl;
        cout << "5. Unknown" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1) {
            menarche = "Before 10 years old";
        } else if (option == 2) {
            menarche = "10-12 years old";
        } else if (option == 3) {
            menarche = "13-15 years old";
        } else if (option == 4) {
            menarche = "16 years old or above";
        } else {
            menarche = "Unknown";
        }
     
        cout << endl;
        cout << "MENSTRUAL HISTORY:" << endl;
        cout << "1. Regular" << endl;
        cout << "2. Irregular" << endl;
        cout << "3. Not Applicable" << endl;
        cout << "4. Unknown" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1) {
            menstrualHistory = "Regular";
        } else if (option == 2) {
            menstrualHistory = "Irregular";
        } else if (option == 3) {
            menstrualHistory = "Not Applicable";
        } else {
            menstrualHistory = "Unknown";
        }

        cout << endl;
        cout << "GRAVIDA (Number of pregnancies):" << endl;
        cout << "1. 0" << endl;
        cout << "2. 1" << endl;
        cout << "3. 2" << endl;
        cout << "4. 3 or more" << endl;
        cout << "5. Unknown" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1) {
            gravida = "0";
        } else if (option == 2) {
            gravida = "1";
        } else if (option == 3) {
            gravida = "2";
        } else if (option == 4) {
            gravida = "3 or more";
        } else {
            gravida = "Unknown";
        }

        cout << endl;
        cout << "PARA (Number of living children):" << endl;
        cout << "1. No living children" << endl;
        cout << "2. One living child" << endl;
        cout << "3. Two living children" << endl;
        cout << "4. Three or more living children" << endl;
        cout << "5. Unknown" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1) {
            para = "No living children";
        } else if (option == 2) {
            para = "One living child";
        } else if (option == 3) {
            para = "Two living children";
        } else if (option == 4) {
            para = "Three or more living children";
        } else {
            para = "Unknown";
        }

        cout << endl;
        cout << "LAST MENSTRUAL PERIOD:" << endl;
        cout << "1. Within the last month" << endl;
        cout << "2. 1-3 months ago" << endl;
        cout << "3. More than 3 months ago" << endl;
        cout << "4. Unknown" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1) {
            lastMenstrualPeriod = "Within the last month";
        } else if (option == 2) {
            lastMenstrualPeriod = "1-3 months ago";
        } else if (option == 3) {
            lastMenstrualPeriod = "More than 3 months ago";
        } else {
            lastMenstrualPeriod = "Unknown";
        }

        cout << endl;
        cout << "MENOPAUSE (Permanent cessation of menstruation):" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "3. Unknown" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1) {
            menopause = "Yes";
        } else if (option == 2) {
            menopause = "No";
        } else {
            menopause = "Unknown";
        }

        cout << endl;
        cout << "OTHERS:" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please specify: ";
            getline(cin, othersOBGyne);
        } else {
            othersOBGyne = "No";
        }
    }
    


    // PATIENT SUMMARY
    cout << endl;
    cout << "=============================================" << endl;
    cout << "          PATIENT INFORMATION SUMMARY" << endl;
    cout << "=============================================" << endl;

    cout << endl;
    cout << "Patient ID: " << assignedPatientID << endl;

    cout << endl;
    cout << "I. GENERAL DATA" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Sex: " << sex << endl;
    cout << "Address: " << address << endl;
    cout << "Civil Status: " << civilStatus << endl;


    cout << endl;
    cout << "II. HISTORY OF PRESENT ILLNESS" << endl;
    cout << historyPresentIllness << endl;


    cout << endl;
    cout << "III. PAST MEDICAL HISTORY" << endl;
    cout << "Operations: " << operations << endl;
    cout << "Immunizations: " << immunizations << endl;
    cout << "Allergies: " << allergies << endl;
    cout << "Hospitalizations: " << hospitalizations << endl;
    cout << "Maintenance Medications: " << maintenanceMeds << endl;
    cout << "Others: " << othersMedical << endl;


    cout << endl;
    cout << "IV. FAMILY HISTORY" << endl;
    cout << "Bronchial Asthma: " << bronchialAsthma << endl;
    cout << "Diabetes Mellitus: " << diabetesMellitus << endl;
    cout << "Hypertension: " << hypertension << endl;
    cout << "Pulmonary Tuberculosis: " << pulmonaryTuberculosis << endl;
    cout << "Others: " << othersFamily << endl;


    cout << endl;
    cout << "V. SOCIAL, ENVIRONMENTAL, PERSONAL HISTORY" << endl;
    cout << "Smoker: " << smoker << endl;
    cout << "Alcoholic Beverage Drinker: "
         << alcoholicBeverageDrinker << endl;
    cout << "Work/Environmental Hazards: "
         << workEnvironmentalHazards << endl;


    // SHOW OB-GYNE SUMMARY ONLY FOR FEMALE
    if (sexChoice == 2)
    {
        cout << endl;
        cout << "VI. OB-GYNE HISTORY" << endl;
        cout << "Menarche: " << menarche << endl;
        cout << "Menstrual History: " << menstrualHistory << endl;
        cout << "Gravida: " << gravida << endl;
        cout << "Para: " << para << endl;
        cout << "Last Menstrual Period: "
             << lastMenstrualPeriod << endl;
        cout << "Menopause: " << menopause << endl;
        cout << "Others: " << othersOBGyne << endl;
    }



    // FINAL OPTIONS

    cout << endl;
    cout << "=============================================" << endl;
    cout << "1. Proceed" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << endl;
        cout << "Proceeding to Main Menu..." << endl;
        mainmenu(patient, symptoms);
    }
    else if (choice == 2)
    {
        cout << endl;
        exitprogram();
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}
        
    
