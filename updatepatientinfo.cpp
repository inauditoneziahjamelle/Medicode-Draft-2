
#include <iostream>
#include <string>
#include <limits>
#include "updatepatientinfo.h"

using namespace std;

void updatePatientInformation(PatientData &patient)
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "     UPDATE PERSONAL INFORMATION\n";
        cout << "====================================\n";

        cout << "1. Update Name\n";
        cout << "2. Update Age\n";
        cout << "3. Update Sex\n";
        cout << "4. Update Address\n";
        cout << "5. Update Civil Status\n";
        cout << "6. Update All Information\n";
        cout << "7. Back\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
            case 1:
                cout << "Current Name: " << patient.name << endl;
                cout << "Enter New Name: ";
                getline(cin, patient.name);
                break;

            case 2:
                cout << "Current Age: " << patient.age << endl;
                cout << "Enter New Age: ";
                getline(cin, patient.age);
                break;

            case 3:
                cout << "Current Sex: " << patient.sex << endl;
                cout << "Enter New Sex: ";
                getline(cin, patient.sex);
                break;

            case 4:
                cout << "Current Address: " << patient.address << endl;
                cout << "Enter New Address: ";
                getline(cin, patient.address);
                break;

            case 5:
                cout << "Current Civil Status: " << patient.civilStatus << endl;
                cout << "Enter New Civil Status: ";
                getline(cin, patient.civilStatus);
                break;

            case 6:
                cout << "\nEnter Updated Information\n";

                cout << "Name: ";
                getline(cin, patient.name);

                cout << "Age: ";
                getline(cin, patient.age);

                cout << "Sex: ";
                getline(cin, patient.sex);

                cout << "Address: ";
                getline(cin, patient.address);

                cout << "Civil Status: ";
                getline(cin, patient.civilStatus);
                break;

            case 7:
                cout << "\nReturning...\n";
                return;

            default:
                cout << "\nInvalid choice.\n";
        }

        if (choice >= 1 && choice <= 6)
        {
            cout << "\nPersonal information updated successfully!\n";
        }

    } while (choice != 7);
}
