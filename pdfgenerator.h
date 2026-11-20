#ifndef PDFGENERATOR_H
#define PDFGENERATOR_H

#include "patientdata.h"
#include "symptomdata.h"

void generatePatientPDF(const PatientData &patient,
                        const SymptomData &symptomData);

#endif