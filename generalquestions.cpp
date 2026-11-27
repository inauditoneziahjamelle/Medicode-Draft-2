#include <iostream>
#include <string>
#include <limits>
#include "generalquestions.h"
#include "healthcarefacility.h"
#include "patientdata.h"
#include "symptomdata.h"
#include "mainmenu.h"
#include "exitprogram.h"
#include "hc.h"

using namespace std;

bool genquesnum1(PatientData &patient, SymptomData &symptomData)
{
    int choice;

    cout << "\nHow long have you experienced this problem?\n";
    cout << "1. Today - Started today\n";
    cout << "2. A Few Days - Lasted 1-3 days.\n";
    cout << "3. One Week or Longer - Lasted at least 7 days.\n";
    cout << "4. Not Sure\n";
    cout << "5. Back to Main Menu\n";
    cout << "Enter your choice: ";
    choice = readChoice(1, 5); 

    if (choice == 1)
    {
        symptomData.duration = "Today";
        return true;
    }
    else if (choice == 2)
    {
        symptomData.duration = "A Few Days";
        return true;
    }
    else if (choice == 3)
    {
        symptomData.duration = "One Week or Longer";
        return true;
    }
    else if (choice == 4)
    {
        symptomData.duration = "Not Sure";
        return true;
    }
    else if (choice == 5)
    {
        mainmenu(patient, symptomData);
        return false;
    }
    else
    {
        symptomData.duration = "Not Sure";
        return true;
    }
}

bool genquesnum2(PatientData &patient, SymptomData &symptomData)
{
    int choice;

    cout << "\nHow severe is your concern?\n";
    cout << "1. Mild - Does not greatly affect daily activities.\n";
    cout << "2. Moderate - Makes some daily activities difficult.\n";
    cout << "3. Severe - Makes normal daily activities very difficult.\n";
    cout << "4. Back to Previous Question\n";
    cout << "5. Back to Main Menu\n";
    cout << "Enter your choice: ";
    choice = readChoice(1, 5); 

    if (choice == 1)
    {
        symptomData.severity = "Mild";
        return true;
    }
    else if (choice == 2)
    {
        symptomData.severity = "Moderate";
        return true;
    }
    else if (choice == 3)
    {
        symptomData.severity = "Severe";
        return true;
    }
    else if (choice == 4)
    {
        if (!genquesnum1(patient, symptomData))
        {
            return false;
        }
        return genquesnum2(patient, symptomData);
    }
    else if (choice == 5)
    {
        mainmenu(patient, symptomData);
        return false;
    }

    return true;
}

bool genquesnum3(PatientData &patient, SymptomData &symptomData)
{
    int choice;

    cout << "\nHow does this concern affect activities?\n";
    cout << "1. Not at All - Daily activities are mostly unaffected.\n";
    cout << "2. Slightly - Some activities are affected.\n";
    cout << "3. Moderately - Several activities are difficult.\n";
    cout << "4. Not Sure\n";
    cout << "5. Back to Previous Question\n";
    cout << "6. Back to Main Menu\n";
    cout << "Enter your choice: ";
    choice = readChoice(1, 6); 

    if (choice == 1)
    {
        symptomData.impact = "Not at All";
        return true;
    }
    else if (choice == 2)
    {
        symptomData.impact = "Slightly";
        return true;
    }
    else if (choice == 3)
    {
        symptomData.impact = "Moderately";
        return true;
    }
    else if (choice == 4)
    {
        symptomData.impact = "Not Sure";
        return true;
    }
    else if (choice == 5)
    {
        if (!genquesnum2(patient, symptomData))
        {
            return false;
        }
        return genquesnum3(patient, symptomData);
    }
    else if (choice == 6)
    {
        mainmenu(patient, symptomData);
        return false;
    }

    return true;
}

bool genquesnum4(PatientData &patient, SymptomData &symptomData)
{
    int choice;

    cout << "\nIs your condition getting worse?\n";
    cout << "1. Yes - Becoming more severe.\n";
    cout << "2. No - Staying the same.\n";
    cout << "3. Improving - Getting better.\n";
    cout << "4. Not Sure\n";
    cout << "5. Back to Previous Question\n";
    cout << "6. Back to Main Menu\n";
    cout << "Enter your choice: ";
    choice = readChoice(1, 6); 

    if (choice == 1)
    {
        symptomData.progression = "Yes - Becoming more severe";
        return true;
    }
    else if (choice == 2)
    {
        symptomData.progression = "No - Staying the same";
        return true;
    }
    else if (choice == 3)
    {
        symptomData.progression = "Improving - Getting better";
        return true;
    }
    else if (choice == 4)
    {
        symptomData.progression = "Not Sure";
        return true;
    }
    else if (choice == 5)
    {
        if (!genquesnum3(patient, symptomData))
        {
            return false;
        }
        return genquesnum4(patient, symptomData);
    }
    else if (choice == 6)
    {
        mainmenu(patient, symptomData);
        return false;
    }

    return true;
}

bool genquesnum5(PatientData &patient, SymptomData &symptomData)
{
    int choice;

    cout << "\nDo you have other symptoms or concerns?\n";
    cout << "1. Yes (describe in a sentence)\n";
    cout << "2. No\n";
    cout << "3. Back to Previous Question\n";
    cout << "4. Back to Main Menu\n";
    cout << "Enter your choice: ";
    choice = readChoice(1, 4); 

    if (choice == 1)
    {
        cout << "Please describe your other symptoms in a sentence: ";
        getline(cin, symptomData.symptoms); 
        return true;
    }
    else if (choice == 2)
    {
        symptomData.symptoms = "The user reported no other symptoms or concerns.";
        return true;
    }
    else if (choice == 3)
    {
        if (!genquesnum4(patient, symptomData))
        {
            return false;
        }
        return genquesnum5(patient, symptomData);
    }
    else if (choice == 4)
    {
        mainmenu(patient, symptomData);
        return false;
    }

    return true;
}

bool genquesnum6(PatientData &patient, SymptomData &symptomData)
{
    int choice;

    cout << "\nAre you experiencing any urgent warning signs?\n";
    cout << "1. Difficulty breathing\n";
    cout << "2. Chest pain or pressure\n";
    cout << "3. Fainting or sudden confusion\n";
    cout << "4. Severe allergic reaction\n";
    cout << "5. Feeling unsafe or needing immediate mental health support\n";
    cout << "6. None of These\n";
    cout << "7. Back to Previous Question\n";
    cout << "8. Back to Main Menu\n";
    cout << "Enter your choice: ";
    choice = readChoice(1, 8); 

    if (choice == 1)
    {
        symptomData.warningSigns = "Difficulty breathing";
        return true;
    }
    else if (choice == 2)
    {
        symptomData.warningSigns = "Chest pain or pressure";
        return true;
    }
    else if (choice == 3)
    {
        symptomData.warningSigns = "Fainting or sudden confusion";
        return true;
    }
    else if (choice == 4)
    {
        symptomData.warningSigns = "Severe allergic reaction";
        return true;
    }
    else if (choice == 5)
    {
        symptomData.warningSigns = "Feeling unsafe or needing immediate mental health support";
        return true;
    }
    else if (choice == 6)
    {
        symptomData.warningSigns = "None of These";
        return true;
    }
    else if (choice == 7)
    {
        if (!genquesnum5(patient, symptomData))
        {
            return false;
        }
        return genquesnum6(patient, symptomData);
    }
    else if (choice == 8)
    {
        mainmenu(patient, symptomData);
        return false;
    }

    return true;
}

bool genquesnum7(PatientData &patient, SymptomData &symptomData)
{
    int choice;

    cout << "\nHave you taken any medication or received any treatment for this concern?\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cout << "3. Not Applicable\n";
    cout << "4. Back to Previous Question\n";
    cout << "5. Back to Main Menu\n";
    cout << "Enter your choice: ";
    choice = readChoice(1, 5); 

    if (choice == 1)
    {
        symptomData.medications = "Yes";
        return true;
    }
    else if (choice == 2)
    {
        symptomData.medications = "No";
        return true;
    }
    else if (choice == 3)
    {
        symptomData.medications = "Not Applicable";
        return true;
    }
    else if (choice == 4)
    {
        if (!genquesnum6(patient, symptomData))
        {
            return false;
        }
        return genquesnum7(patient, symptomData);
    }
    else if (choice == 5)
    {
        cout << "main menu\n";
        return false;
    }

    return true;
}

void displaySymptomSummary(const SymptomData &symptomData)
{
    cout << "\n========================================\n";
    cout << "             SYMPTOM SUMMARY\n";
    cout << "========================================\n";
    cout << "Duration: " << symptomData.duration << "\n";
    cout << "Severity: " << symptomData.severity << "\n";
    cout << "Impact on Activities: " << symptomData.impact << "\n";
    cout << "Progression: " << symptomData.progression << "\n";
    cout << "Other Symptoms: " << symptomData.symptoms << "\n";
    cout << "Urgent Signs: " << symptomData.warningSigns << "\n";
    cout << "Medication/Treatment: " << symptomData.medications << "\n";
    cout << "========================================\n";

    if (symptomData.warningSigns != "None of These" && !symptomData.warningSigns.empty())
    {
        cout << "\nIMPORTANT: You selected an urgent warning sign.\n";
        cout << "Seek immediate professional medical assistance.\n";
        cout << "Do not wait for an automated consultation.\n";
    }
}

bool generalquestions(PatientData &patient, SymptomData &symptomData)
{
    if (!genquesnum1(patient, symptomData))
    {
        return false;
    }
    if (!genquesnum2(patient, symptomData))
    {
        return false;
    }
    if (!genquesnum3(patient, symptomData))
    {
        return false;
    }
    if (!genquesnum4(patient, symptomData))
    {
        return false;
    }
    if (!genquesnum5(patient, symptomData))
    {
        return false;
    }
    if (!genquesnum6(patient, symptomData))
    {
        return false;
    }
    if (!genquesnum7(patient, symptomData))
    {
        return false;
    }

    symptomData.concern_summary =
        "Duration: " + symptomData.duration +
        "\nSeverity: " + symptomData.severity +
        "\nImpact on Activities: " + symptomData.impact +
        "\nProgression: " + symptomData.progression +
        "\nOther Symptoms: " + symptomData.symptoms +
        "\nUrgent Signs: " + symptomData.warningSigns +
        "\nMedication/Treatment: " + symptomData.medications;

    symptomData.summaryCompleted = true;

    return true;
}