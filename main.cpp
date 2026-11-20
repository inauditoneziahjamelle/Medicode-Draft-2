#include <iostream>
#include "patientdata.h"
#include "medicodebanner.h"
#include "mainmenu.h"
#include "exitprogram.h"
#include "healthcarefacility.h"
#include "patientconsent.h"
#include "patientpersonalinfo.h"
#include "generalquestions.h"
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>

#include "pdfgenerator.h"
#include "PDFgen/pdfgen.h"

#ifdef _WIN32
#include <windows.h>
#endif


int main()
{
    PatientData patient{};
    SymptomData symptoms{};

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    medicodebanner();

    if (patientconsent())
    {
        patientpersonalinfo(patient, symptoms);
    }

    return 0;
}