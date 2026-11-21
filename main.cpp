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

using namespace std;

int main()
{
    PatientData patient;
    SymptomData symptomData;

    medicodebanner();
    generatePatientPDF (patient, symptomData);
    mainmenu (patient, symptomData);
}