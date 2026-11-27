#include <iostream>
#include "medicodebanner.h"
#include <string>
#include <windows.h>
#include "patientconsent.h"
#include "patientdata.h"
#include "exitprogram.h"


using namespace std;


void medicodebanner(PatientData &patient)
{

    string code;
    int choice;
    
    cout << "                                                                                         +================================+" << endl;
    cout << "                                                                                                Input USSD: ";
    cin >> code;
    cout << "                                                                                         +================================+" << endl;
    cout << endl;
    cout << endl;

    if (code == "*206#")
    {
    SetConsoleOutputCP(CP_UTF8);
        cout << "\033[1;38;5;88m";

cout << R"(
                                                                            ███╗   ███╗███████╗██████╗ ██╗ ██████╗ ██████╗ ██████╗ ███████╗                
                                                                            ████╗ ████║██╔════╝██╔══██╗██║██╔════╝██╔═══██╗██╔══██╗██╔════╝
                                                                            ██╔████╔██║█████╗  ██║  ██║██║██║     ██║   ██║██║  ██║█████╗  
                                                                            ██║╚██╔╝██║██╔══╝  ██║  ██║██║██║     ██║   ██║██║  ██║██╔══╝  
                                                                            ██║ ╚═╝ ██║███████╗██████╔╝██║╚██████╗╚██████╔╝██████╔╝███████╗                                                       
)" << endl;

        cout << "\033[0m  \033[1m";
        cout << "                                                                             Ａ  ＵＳＳＤ  Ｃｏｄｅ  ｆｏｒ  Ｎｏｎ－ｃｒｉｔｉｃａｌ    " << endl;
        cout << "                                                                                          Ｍｅｄｉｃａｌ  Ａｓｓｉｓｔａｎｃｅ．" << endl;
                                                                                                                                      
       
                               
        cout << "\033[0m";
        cout << "\033[1;38;5;88m";
        cout << "                                                                                           ▄ ▄ ▄                               " << endl;
        cout << "                                                                                           ▄███▄ ████▄  ▄██▄  ▄██▀▀▀  ▄ ▄      " << endl;
        cout << "                                                                                           ▄▀█▀▄  ▄██▀ ██  ██ ██▄▄▄  ▀█▀█▀     " << endl;
        cout << "                                                                                                 ███▄▄  ▀██▀  ▀█▄▄█▀ ▀█▀█▀     " << endl;
        cout << "\033[0m";
        
        cout << endl;
        cout << endl;
        cout << "\033[1;38;2;225;132;132m";
        cout << "                                                                           +=============================================================+" << endl;
        cout << "                                                                           ||  \033[0m                       \033[1mDISCLAIMER:\033[0m       \033[1;38;2;225;132;132m                ||" << endl;
        cout << "                                                                           +=============================================================+" << endl;
        cout << "                                                                           ||                                                           ||" << endl;
        cout << "                                                                           || \033[0m  \033[3mMEDICODE asks questions about your symptoms and\033[0m    \033[1;38;2;225;132;132m     ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         || \033[0m  \033[3mconnects you to available General Practitioners (GPs)\033[0m \033[1;38;2;225;132;132m  ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         || \033[0m  \033[3mwho can provide general health guidance.\033[0m             \033[1;38;2;225;132;132m   ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         ||                                                           ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         || \033[0m  \033[3mIt caters only to Green Triage cases, which are\033[0m      \033[1;38;2;225;132;132m   ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         || \033[0m  \033[3mgenerally non-emergency conditions that are bearable\033[0m  \033[1;38;2;225;132;132m  ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         || \033[0m  \033[3mand can wait for routine medical assessment.\033[0m           \033[1;38;2;225;132;132m ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         ||                                                           ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         || \033[0m  \033[3mA GP may refer you to a Specialized Practitioner\033[0m     \033[1;38;2;225;132;132m   ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         || \033[0m  \033[3mif necessary.\033[0m                                      \033[1;38;2;225;132;132m     ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         ||                                                           ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         ||  \033[0m \033[3mMEDICODE does not directly diagnose illnesses or\033[0m    \033[1;38;2;225;132;132m    ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         ||  \033[0m \033[3mprovide Specialized Practitioner consultations.\033[0m     \033[1;38;2;225;132;132m    ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         ||                                                           ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         +=============================================================+" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         ||   \033[0m                     [ 1 ] Proceed                   \033[1;38;2;225;132;132m   ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         ||   \033[0m                     [ 2 ] No                     \033[1;38;2;225;132;132m      ||" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                         +=============================================================+" << endl;
        cout << "  \033[1;38;2;225;132;132m                                                                                \033[0m                Enter your choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            cout << "                                                                                           Proceeding to Patient Consent Form..." << endl;
            patientconsent(patient);
        }
        else if (choice == 2)
        {
            exitprogram();
        }
        else
        {
            cout << "                                                                                              Please choose either 1 or 2." << endl;
        }
    }
    else
    {
        cout << "                                                                                             USSD Invalid. Please Try Again." << endl;
    }

}