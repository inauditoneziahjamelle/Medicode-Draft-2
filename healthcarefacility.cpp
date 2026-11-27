
#include <iostream>
#include "healthcarefacility.h"
#include <string>
#include "exitprogram.h"
#include <cstdlib>

using namespace std;

void healthcarefacility()
{
    int facilityChoice;
    int doctorChoice;

    string number;
    string location;
    string fee;
    string time;
    string day;

    cout << endl;
    cout << "                                                                               \033[31m+==============================================================+\033[0m" << endl;
    cout << "                                                                               \033[31m||\033[0m                   CHOOSE A HEALTHCARE FACILITY             \033[31m||\033[0m" << endl;
    cout << "                                                                               \033[31m+==============================================================+\033[0m" << endl;
    cout << "                                                                               \033[31m||\033[0m               [ 1 ] Public Hospital                       \033[31m||\033[0m" << endl;
    cout << "                                                                               \033[31m||\033[0m               [ 2 ] Private Hospital                      \033[31m||\033[0m" << endl;
    cout << "                                                                               \033[31m||\033[0m               [ 3 ] Back to Main Menu                     \033[31m||\033[0m" << endl;
    cout << "                                                                               \033[31m||\033[0m               [ 4 ] Exit                                  \033[31m||\033[0m" << endl;
    cout << "                                                                               \033[31m+==============================================================+\033[0m" << endl;
    cout << "                                                                                                   Enter your choice: ";
    cin >> facilityChoice;


    // PUBLIC

    if (facilityChoice == 1)
    {
        cout << endl;
        cout << "                                                                               \033[31m+==============================================================+\033[0m" << endl;
        cout << "                                                                               \033[31m||\033[0m               AVAILABLE PUBLIC DOCTORS                    \033[31m||\033[0m" << endl;
        cout << "                                                                               \033[31m+==============================================================+\033[0m" << endl;
        cout << "                                                                               \033[31m||\033[0m              [ 1 ] Dr. Adrian Villanueva                   \033[31m||\033[0m" << endl;
        cout << "                                                                               \033[31m||\033[0m              [ 2 ] Dr. Marcus Javier                       \033[31m||\033[0m" << endl;
        cout << "                                                                               \033[31m||\033[0m              [ 3 ] Dr. Nathaniel Cruz                      \033[31m||\033[0m" << endl;
        cout << "                                                                               \033[31m+==============================================================+\033[0m" << endl;
        cout << "                                                                                                   Select Doctor: ";
        cin >> doctorChoice;

        switch (doctorChoice)
        {
            case 1:

                number = "09178362451";
                location = "West Visayas State University Medical Center";
                fee = "300-800 PHP";
                day = "Monday, Wednesday, Friday";
                time = "8:00 AM - 11:00 AM and 1:00 PM - 4:00 PM";

                break;

            case 2:

                number = "09285619374";
                location = "Metro Iloilo Hospital and MedicalCenter, Inc.";
                fee = "600-1000 PHP";
                day = "Tuesday, Thursday, Saturday";
                time = "9:00 AM - 12:00 PM and 2:00 PM - 5:00 PM";

                break;

            case 3:

                number = "09285619374";
                location = "Western Visayas Medical Center";
                fee = "500-1000 PHP";
                day = "Wednesday, Friday, Sunday";
                time = "8:00 AM - 11:00 AM and 2:00 PM - 4:00 PM";

                break;

            default:

                cout << "Invalid doctor selection!" << endl;

                return;
        }
    }


    // PRIVATE

    else if (facilityChoice == 2)
    {
        cout << endl;
       cout << "                                                                               \033[31m+==============================================================+\033[0m" << endl;
        cout << "                                                                               \033[31m||\033[0m                AVAILABLE PRIVATE DOCTORS             \033[31m||\033[0m" << endl;
        cout << "                                                                               \033[31m+==============================================================+\033[0m" << endl;
        cout << "                                                                               \033[31m||\033[0m                   [ 1 ] Dr. Daniel Santiagp                   \033[31m||\033[0m" << endl;
        cout << "                                                                               \033[31m||\033[0m                   [ 2 ] Dr. Matthew Alcantara                  \033[31m||\033[0m" << endl;
        cout << "                                                                               \033[31m||\033[0m                   [ 3 ] Dr. Gabriel Mendoza                 \033[31m||\033[0m" << endl;
        cout << "                                                                               \033[31m+==============================================================+\033[0m" << endl;
        cout << "                                                                                                           Select Doctor: ";
        cin >> doctorChoice;

        switch (doctorChoice)
        {
            case 1:

                number = "09162483957";
                location = "Iloilo Doctor's Hospital";
                fee = "800-1800 PHP";
                day = "Monday, Tuesday, Saturday";
                time = "9:00 AM - 12:00 AM and 3:00 PM - 5:00 PM";

                number = "09162483957";
                location = "Iloilo Mission Hospital";
                fee = "1000 PHP";
                day = "Monday, Tuesday, Saturday";
                time = "9:00 AM - 12:00 AM and 3:00 PM - 5:00 PM";

                break;

            case 2:

                number = "09273461825";
                location = "The Medical City Iloilo";
                fee = "1000 - 2000 PHP";
                day = "Wednesday, Friday, Saturday";
                time = "8:00 AM - 11:00 AM and 1:00 PM - 4:00 PM";

                break;

            case 3:

                number = "09986732145";
                location = "St. Paul's Hospital Iloilo";
                fee = "1000-2000 PHP";
                day = "Tuesday, Thursday, Saturday";
                time = "9:00 AM - 12:00 AM and 1:00 PM - 3:00 PM";

                break;

            default:

                cout << "Invalid doctor selection!" << endl;

                return;
        }
    }


    // BACK TO MAIN MENU

    else if (facilityChoice == 3)
    {
        cout << endl;
        cout << "Returning to Main Menu..." << endl;

        return;
    }


    // EXIT

    else if (facilityChoice == 4)
    {
        cout << endl;
        cout << "Exiting the program..." << endl;
        exitprogram();
    
    }


    // INVALID FACILITY

    else
    {
        cout << "Invalid selection!" << endl;

        return;
    }


    // SELECTED DOCTOR

    cout << endl;
    cout << "\033[31m==============================================================================\033[0m" << endl;
    cout << "\033[31m||\033[0m                    Selected Doctor!                                     \033[31m||\033[0m" << endl;
    cout << "\033[31m==============================================================================\033[0m" << endl;
    cout << "\033[31m||\033[0m Doctor's Contact Number: |  " << number << endl;
    cout << "\033[31m||\033[0m Doctor's Location:       |  " << location << endl;
    cout << "\033[31m||\033[0m Consultation Fee:        |  " << fee << endl;
    cout << "\033[31m||\033[0m Days of Availability:    |  " << day << endl;
    cout << "\033[31m||\033[0m Time of Availability:    |  " << time << endl;
    cout << "\033[31m==============================================================================\033[0m" << endl;
    cout << endl;


    // WIRELESS PHONE DIALER

    cout << "Opening phone dialer..." << endl;

    string device = "adb-RF8WC00XQHP-cR6WsD._adb-tls-connect._tcp";

    string command =
        "\"C:\\platform-tools\\adb.exe\" "
        "-s " + device +
        " shell am start "
        "-a android.intent.action.DIAL "
        "-d tel:" + number;

    int result = system(command.c_str());

    if (result == 0)
    {
        cout << "ADB command executed." << endl;
    }
    else
    {
        cout << "Failed to open phone dialer." << endl;
        cout << "Check your wireless ADB connection." << endl;
    }

    cout << endl;
}
