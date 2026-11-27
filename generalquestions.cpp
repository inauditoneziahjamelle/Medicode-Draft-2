
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <iomanip>

#include "generalquestions.h"
#include "healthcarefacility.h"
#include "patientdata.h"
#include "symptomdata.h"
#include "displaybox.h"
#include "mainmenu.h"
#include "exitprogram.h"
#include "healthcare.h"

using namespace std;

int readChoice(int minimum, int maximum);


// ============================================================
// MEDICODE QUESTION GUI
// ============================================================




// ============================================================
// QUESTION 1 - DURATION
// ============================================================

bool genquesnum1(PatientData &patient, SymptomData &symptomData)
{
    int choice;

    displayQuestionBox("QUESTION 1: DURATION", {
        "How long have you experienced this problem?",
        "",
        "[ 1 ] Today - Started today",
        "[ 2 ] A Few Days - Lasted 1-3 days",
        "[ 3 ] One Week or Longer - Lasted at least 7 days",
        "[ 4 ] Not Sure",
        "[ 5 ] Back to Main Menu"
    });

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

    return true;
}


// ============================================================
// QUESTION 2 - SEVERITY
// ============================================================

bool genquesnum2(PatientData &patient, SymptomData &symptomData)
{
    int choice;

    displayQuestionBox("QUESTION 2: SEVERITY", {
        "How severe is your concern?",
        "",
        "[ 1 ] Mild - Does not greatly affect daily activities",
        "[ 2 ] Moderate - Makes some daily activities difficult",
        "[ 3 ] Severe - Makes normal daily activities very difficult",
        "[ 4 ] Back to Previous Question",
        "[ 5 ] Back to Main Menu"
    });

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


// ============================================================
// QUESTION 3 - IMPACT ON ACTIVITIES
// ============================================================

bool genquesnum3(PatientData &patient, SymptomData &symptomData)
{
    int choice;

    displayQuestionBox("QUESTION 3: IMPACT ON ACTIVITIES", {
        "How does this concern affect your activities?",
        "",
        "[ 1 ] Not at All - Daily activities are mostly unaffected",
        "[ 2 ] Slightly - Some activities are affected",
        "[ 3 ] Moderately - Several activities are difficult",
        "[ 4 ] Not Sure",
        "[ 5 ] Back to Previous Question",
        "[ 6 ] Back to Main Menu"
    });

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


// ============================================================
// QUESTION 4 - CONDITION PROGRESSION
// ============================================================

bool genquesnum4(PatientData &patient, SymptomData &symptomData)
{
    int choice;

    displayQuestionBox("QUESTION 4: CONDITION PROGRESSION", {
        "Is your condition getting worse?",
        "",
        "[ 1 ] Yes - Becoming more severe",
        "[ 2 ] No - Staying the same",
        "[ 3 ] Improving - Getting better",
        "[ 4 ] Not Sure",
        "[ 5 ] Back to Previous Question",
        "[ 6 ] Back to Main Menu"
    });

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


// ============================================================
// QUESTION 5 - OTHER SYMPTOMS
// ============================================================

bool genquesnum5(PatientData &patient, SymptomData &symptomData)
{
    int choice;

    displayQuestionBox("QUESTION 5: OTHER SYMPTOMS", {
        "Do you have other symptoms or concerns?",
        "",
        "[ 1 ] Yes - Describe in a sentence",
        "[ 2 ] No",
        "[ 3 ] Back to Previous Question",
        "[ 4 ] Back to Main Menu"
    });

    cout << "Enter your choice: ";
    choice = readChoice(1, 4);

    if (choice == 1)
    {
        cout << "Please describe your other symptoms in a sentence: ";

        getline(cin >> ws, symptomData.symptoms);

        return true;
    }
    else if (choice == 2)
    {
        symptomData.symptoms =
            "The user reported no other symptoms or concerns.";

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


// ============================================================
// QUESTION 6 - URGENT WARNING SIGNS
// ============================================================

bool genquesnum6(PatientData &patient, SymptomData &symptomData)
{
    int choice;
    string selectedSigns = "";

    while (true)
    {
        displayQuestionBox("QUESTION 6: URGENT WARNING SIGNS", {
            "Are you experiencing any urgent warning signs?",
            "",
            "[ 1 ] Difficulty breathing",
            "[ 2 ] Chest pain or pressure",
            "[ 3 ] Fainting or sudden confusion",
            "[ 4 ] Severe allergic reaction",
            "[ 5 ] Feeling unsafe or needing immediate mental health support",
            "[ 6 ] None of These",
            "[ 7 ] Back to Previous Question",
            "[ 8 ] Back to Main Menu"
        });

        cout << "Enter your choice: ";
        choice = readChoice(1, 8);

        if (choice >= 1 && choice <= 5)
        {
            string sign;

            if (choice == 1)
            {
                sign = "Difficulty breathing";
            }
            else if (choice == 2)
            {
                sign = "Chest pain or pressure";
            }
            else if (choice == 3)
            {
                sign = "Fainting or sudden confusion";
            }
            else if (choice == 4)
            {
                sign = "Severe allergic reaction";
            }
            else if (choice == 5)
            {
                sign = "Feeling unsafe or needing immediate mental health support";
            }

            // Add the sign only if it has not already been selected
            if (selectedSigns.find(sign) == string::npos)
            {
                if (!selectedSigns.empty())
                {
                    selectedSigns += ", ";
                }

                selectedSigns += sign;
            }
            else
            {
                cout << "You already added \"" << sign << "\".\n";
            }

            cout << "Selected so far: " << selectedSigns << "\n";
            cout << "Add another? (1. Yes, 2. No): ";

            int addMore = readChoice(1, 2);

            if (addMore == 2)
            {
                symptomData.warningSigns = selectedSigns;
                return true;
            }
        }
        else if (choice == 6)
        {
            if (selectedSigns.empty())
            {
                symptomData.warningSigns = "None of These";
            }
            else
            {
                symptomData.warningSigns = selectedSigns;
            }

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
    }
}


// ============================================================
// QUESTION 7 - MEDICATION AND TREATMENT
// ============================================================

bool genquesnum7(PatientData &patient, SymptomData &symptomData)
{
    int choice;

    displayQuestionBox("QUESTION 7: MEDICATION AND TREATMENT", {
        "Have you taken any medication or received treatment?",
        "",
        "[ 1 ] Yes",
        "[ 2 ] No",
        "[ 3 ] Not Applicable",
        "[ 4 ] Back to Previous Question",
        "[ 5 ] Back to Main Menu"
    });

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
        mainmenu(patient, symptomData);
        return false;
    }

    return true;
}


// ============================================================
// QUESTION 8 - ADDITIONAL NOTES
// ============================================================

bool genquesnum8(PatientData &patient, SymptomData &symptomData)
{
    int choice;

    displayQuestionBox("QUESTION 8: ADDITIONAL NOTES", {
        "Is there anything else you'd like to add?",
        "",
        "[ 1 ] Yes",
        "[ 2 ] No",
        "[ 3 ] Back to Previous Question",
        "[ 4 ] Back to Main Menu"
    });

    cout << "Enter your choice: ";
    choice = readChoice(1, 4);

    if (choice == 1)
    {
        cout << "Please enter anything else you'd like to add: ";

        getline(cin >> ws, symptomData.additionalNotes);

        if (symptomData.additionalNotes.find_first_not_of(" \t")
            == string::npos)
        {
            symptomData.additionalNotes = "None";
        }

        return true;
    }
    else if (choice == 2)
    {
        symptomData.additionalNotes = "None";
        return true;
    }
    else if (choice == 3)
    {
        if (!genquesnum7(patient, symptomData))
        {
            return false;
        }

        return genquesnum8(patient, symptomData);
    }
    else if (choice == 4)
    {
        mainmenu(patient, symptomData);
        return false;
    }

    return true;
}


// ============================================================
// DISPLAY SYMPTOM SUMMARY
// ============================================================

void displaySymptomSummary(const SymptomData &symptomData)
{
    cout << "\n";

    displayQuestionBox("SYMPTOM SUMMARY", {
        "Duration: " + symptomData.duration,
        "Severity: " + symptomData.severity,
        "Impact on Activities: " + symptomData.impact,
        "Progression: " + symptomData.progression,
        "Other Symptoms: " + symptomData.symptoms,
        "Urgent Signs: " + symptomData.warningSigns,
        "Medication/Treatment: " + symptomData.medications,
        "Additional Notes: " + symptomData.additionalNotes
    });

    if (symptomData.warningSigns != "None of These"
        && !symptomData.warningSigns.empty())
    {
        cout << "\nIMPORTANT: You selected an urgent warning sign.\n";
        cout << "Seek immediate professional medical assistance.\n";
        cout << "Do not wait for an automated consultation.\n";
    }
}


// ============================================================
// GENERAL QUESTIONS - MAIN FLOW
// ============================================================

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

    if (!genquesnum8(patient, symptomData))
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
        "\nMedication/Treatment: " + symptomData.medications +
        "\nAdditional Notes: " + symptomData.additionalNotes;

    symptomData.summaryCompleted = true;

    return true;
}
