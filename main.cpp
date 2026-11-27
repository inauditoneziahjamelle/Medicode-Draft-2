
#include <iostream>
#include <string>

#include "patientdata.h"
#include "medicodebanner.h"
#include "mainmenu.h"
#include "exitprogram.h"
#include "healthcarefacility.h"
#include "patientconsent.h"
#include "patientpersonalinfo.h"
#include "generalquestions.h"
#include "patientprofile.h"
#include "healthcare.h"
#include "pdfgenerator.h"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main()
{
    PatientData patient;
    SymptomData symptomData;

    // VALIDATE USSD FIRST
    if (!medicodebanner(patient, symptomData))
    {
        cout << "Invalid USSD code. MEDICODE will now close." << endl;
        return false;
    }

    // CONTINUE ONLY IF USSD IS VALID
    mainmenu(patient, symptomData);

    healthcare(patient, symptomData);

    generatepatientpdf(patient, symptomData);

    return 0;
}
