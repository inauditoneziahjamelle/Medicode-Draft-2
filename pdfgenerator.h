#ifndef PDFGENERATOR_H
#define PDFGENERATOR_H

#include "patientdata.h"
#include "symptomdata.h"

void generatepatientpdf(const PatientData &patient,
                        const SymptomData &symptomData);

#endif