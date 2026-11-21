
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "pdfgenerator.h"
#include "PDFgen/pdfgen.h"

using namespace std;

void generatePatientPDF(const PatientData &patient,
                        const SymptomData &symptomData)
{
    const double PAGE_TOP = 790.0;
    const double PAGE_BOTTOM = 50.0;
    const double LEFT_MARGIN = 50.0;
    const size_t MAX_LINE_LENGTH = 88;

    struct pdf_info info = {};
    snprintf(info.creator, sizeof(info.creator), "MEDICODE");
    snprintf(info.title, sizeof(info.title), "Patient Summary");

    pdf_doc *pdf = pdf_create(PDF_A4_WIDTH, PDF_A4_HEIGHT, &info);

    if (pdf == NULL)
    {
        cout << "PDF creation failed." << endl;
        return;
    }

    pdf_set_font(pdf, "Helvetica");
    pdf_append_page(pdf);

    double positionY = PAGE_TOP;

    // ==========================================
    // PDF CONTENT STRUCTURE
    // ==========================================

    struct PDFEntry
    {
        string label;
        string value;
        double fontSize;
        int type;
    };

    struct PDFLine
    {
        string text;
        double fontSize;
        double spacing;
    };

    vector<PDFEntry> entries;
    vector<PDFLine> lines;

    // ==========================================
    // MEDICODE TITLE
    // ==========================================

    entries.push_back({"MEDICODE", "", 24, 0});
    entries.push_back({"PATIENT SUMMARY", "", 16, 0});

    // ==========================================
    // PATIENT INFORMATION
    // ==========================================

    entries.push_back({"PATIENT INFORMATION", "", 14, 1});

    entries.push_back({"Patient ID", patient.patientID, 10, 2});
    entries.push_back({"Name", patient.name, 10, 2});
    entries.push_back({"Age", patient.age, 10, 2});
    entries.push_back({"Sex", patient.sex, 10, 2});
    entries.push_back({"Address", patient.address, 10, 2});
    entries.push_back({"Civil Status", patient.civilStatus, 10, 2});

    // ==========================================
    // HISTORY OF PRESENT ILLNESS
    // ==========================================

    entries.push_back({"HISTORY OF PRESENT ILLNESS", "", 14, 1});

    entries.push_back({"History of Present Illness",
                       patient.historyPresentIllness, 10, 2});

    // ==========================================
    // PAST MEDICAL HISTORY
    // ==========================================

    entries.push_back({"PAST MEDICAL HISTORY", "", 14, 1});

    entries.push_back({"Operations", patient.operations, 10, 2});
    entries.push_back({"Immunizations", patient.immunizations, 10, 2});
    entries.push_back({"Allergies", patient.allergies, 10, 2});
    entries.push_back({"Hospitalizations", patient.hospitalizations, 10, 2});
    entries.push_back({"Maintenance Medications", patient.maintenanceMeds, 10, 2});
    entries.push_back({"Others", patient.othersMedical, 10, 2});

    // ==========================================
    // FAMILY HISTORY
    // ==========================================

    entries.push_back({"FAMILY HISTORY", "", 14, 1});

    entries.push_back({"Bronchial Asthma", patient.bronchialAsthma, 10, 2});
    entries.push_back({"Diabetes Mellitus", patient.diabetesMellitus, 10, 2});
    entries.push_back({"Hypertension", patient.hypertension, 10, 2});
    entries.push_back({"Pulmonary Tuberculosis", patient.pulmonaryTuberculosis, 10, 2});
    entries.push_back({"Others", patient.othersFamily, 10, 2});

    // ==========================================
    // SOCIAL, ENVIRONMENTAL, PERSONAL HISTORY
    // ==========================================

    entries.push_back({"SOCIAL, ENVIRONMENTAL, PERSONAL HISTORY", "", 14, 1});

    entries.push_back({"Smoker", patient.smoker, 10, 2});
    entries.push_back({"Alcoholic Beverage Drinker",
                       patient.alcoholicBeverageDrinker, 10, 2});
    entries.push_back({"Work/Environmental Hazards",
                       patient.workEnvironmentalHazards, 10, 2});

    // ==========================================
    // OB-GYNE HISTORY
    // ==========================================

    if (patient.sex == "Female")
    {
        entries.push_back({"OB-GYNE HISTORY", "", 14, 1});

        entries.push_back({"Menarche", patient.menarche, 10, 2});
        entries.push_back({"Menstrual History", patient.menstrualHistory, 10, 2});
        entries.push_back({"Gravida", patient.gravida, 10, 2});
        entries.push_back({"Para", patient.para, 10, 2});
        entries.push_back({"Last Menstrual Period",
                           patient.lastMenstrualPeriod, 10, 2});
        entries.push_back({"Menopause", patient.menopause, 10, 2});
        entries.push_back({"Others", patient.othersOBGyne, 10, 2});
    }

    // ==========================================
    // SYMPTOM SUMMARY
    // ==========================================

    entries.push_back({"SYMPTOM SUMMARY", "", 14, 1});

    if (symptomData.summaryCompleted)
    {
        entries.push_back({"Duration", symptomData.duration, 10, 2});
        entries.push_back({"Severity", symptomData.severity, 10, 2});
        entries.push_back({"Impact on Activities", symptomData.impact, 10, 2});
        entries.push_back({"Progression", symptomData.progression, 10, 2});
        entries.push_back({"Other Symptoms", symptomData.symptoms, 10, 2});
        entries.push_back({"Warning Signs", symptomData.warningSigns, 10, 2});
        entries.push_back({"Medication/Treatment", symptomData.medications, 10, 2});
    }
    else
    {
        entries.push_back({"No symptom questionnaire has been completed.",
                           "", 10, 0});
    }

    // ==========================================
    // FORMAT PDF CONTENT
    // ==========================================

    for (size_t i = 0; i < entries.size(); ++i)
    {
        if (entries[i].type == 0)
        {
            lines.push_back({entries[i].label, entries[i].fontSize, 0});
        }
        else if (entries[i].type == 1)
        {
            lines.push_back({entries[i].label, 14, 4});

            lines.push_back({
                "------------------------------------------------------------",
                8,
                0
            });
        }
        else if (entries[i].type == 2)
        {
            string value = entries[i].value.empty()
                           ? "Not provided"
                           : entries[i].value;

            string fullText = entries[i].label + ": " + value;

            istringstream input(fullText);
            string word;
            string line;

            while (input >> word)
            {
                if (line.empty())
                {
                    line = word;
                }
                else if (line.length() + 1 + word.length() <= MAX_LINE_LENGTH)
                {
                    line += " " + word;
                }
                else
                {
                    lines.push_back({line, 10, 0});
                    line = word;
                }
            }

            if (!line.empty())
            {
                lines.push_back({line, 10, 0});
            }
        }
    }

    // ==========================================
    // ADD CONTENT TO PDF
    // ==========================================

    for (size_t i = 0; i < lines.size(); ++i)
    {
        positionY -= lines[i].spacing;

        if (positionY < PAGE_BOTTOM + 20)
        {
            pdf_append_page(pdf);
            positionY = PAGE_TOP;
        }

        pdf_add_text(pdf, NULL, lines[i].text.c_str(),
                     lines[i].fontSize,
                     LEFT_MARGIN, positionY, PDF_BLACK);

        positionY -= lines[i].fontSize + 7;
    }

    // ==========================================
    // SAVE PDF
    // ==========================================

    const int result = pdf_save(pdf, "MEDICODE_Summary.pdf");

    pdf_destroy(pdf);

    if (result >= 0)
    {
        cout << "PDF generated successfully: MEDICODE_Summary.pdf" << endl;
    }
    else
    {
        cout << "PDF generation failed." << endl;
    }
}
