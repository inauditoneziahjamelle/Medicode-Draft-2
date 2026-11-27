#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "pdfgenerator.h"
#include "PDFgen/pdfgen.h"

using namespace std;

namespace
{
    struct RowItem
    {
        string label;
        string value;
    };

    struct SectionTable
    {
        string title;
        vector<RowItem> rows;
        string fullWidthNote;
    };

    vector<string> wrapTextToWidth(const string &text,
                                   double maxWidth,
                                   double fontSize)
    {
        // Approximate average character width for Helvetica (~0.50 * fontSize)
        const double avgCharWidth = fontSize * 0.50;
        const size_t maxChars = max<size_t>(1, static_cast<size_t>(maxWidth / avgCharWidth));

        vector<string> wrappedLines;
        istringstream input(text);
        string word;
        string currentLine;

        while (input >> word)
        {
            if (word.length() > maxChars)
            {
                if (!currentLine.empty())
                {
                    wrappedLines.push_back(currentLine);
                    currentLine.clear();
                }

                size_t pos = 0;
                while (pos < word.length())
                {
                    wrappedLines.push_back(word.substr(pos, maxChars));
                    pos += maxChars;
                }
            }
            else if (currentLine.empty())
            {
                currentLine = word;
            }
            else if (currentLine.length() + 1 + word.length() <= maxChars)
            {
                currentLine += " " + word;
            }
            else
            {
                wrappedLines.push_back(currentLine);
                currentLine = word;
            }
        }

        if (!currentLine.empty())
        {
            wrappedLines.push_back(currentLine);
        }

        if (wrappedLines.empty())
        {
            wrappedLines.push_back("");
        }

        return wrappedLines;
    }

    void drawSectionHeader(pdf_doc *pdf,
                           double &positionY,
                           double leftX,
                           double tableWidth,
                           const string &title)
    {
        const double headerHeight = 22.0;
        const uint32_t headerFill = PDF_RGB(178, 34, 34);
        const uint32_t borderColor = PDF_RGB(64, 64, 64);

        // PDFgen y coordinates start at the bottom of the rectangle
        double rectBottomY = positionY - headerHeight;

        pdf_add_filled_rectangle(pdf, NULL, leftX, rectBottomY,
                                 tableWidth, headerHeight,
                                 0.8, headerFill, borderColor);

        pdf_add_text(pdf, NULL, title.c_str(), 11.0,
                     leftX + 8.0, rectBottomY + 7.0, PDF_WHITE);

        positionY = rectBottomY;
    }

    void drawTableRow(pdf_doc *pdf,
                      double &positionY,
                      double pageBottom,
                      double pageTop,
                      double leftX,
                      double labelColWidth,
                      double valueColWidth,
                      const string &sectionTitle,
                      const RowItem &row,
                      bool alternateShade)
    {
        const double fontSize = 10.0;
        const double lineHeight = 13.0;
        const double cellPadY = 6.0;
        const double cellPadX = 7.0;
        const double tableWidth = labelColWidth + valueColWidth;

        string safeValue = row.value.empty() ? "Not provided" : row.value;

        vector<string> labelLines = wrapTextToWidth(
            row.label, labelColWidth - (2.0 * cellPadX), fontSize);
        vector<string> valueLines = wrapTextToWidth(
            safeValue, valueColWidth - (2.0 * cellPadX), fontSize);

        size_t maxLines = max(labelLines.size(), valueLines.size());
        double rowHeight = (maxLines * lineHeight) + (2.0 * cellPadY);

        if (positionY - rowHeight < pageBottom)
        {
            pdf_append_page(pdf);
            positionY = pageTop;
            drawSectionHeader(pdf, positionY, leftX, tableWidth,
                              sectionTitle + " (Continued)");
        }

        double rowBottomY = positionY - rowHeight;
        uint32_t borderColor = PDF_RGB(140, 140, 140);

        if (alternateShade)
        {
            uint32_t stripeColor = PDF_RGB(253, 242, 242);
            pdf_add_filled_rectangle(pdf, NULL, leftX, rowBottomY,
                                     tableWidth, rowHeight,
                                     0.0, stripeColor, stripeColor);
        }

        // Outer box & vertical column divider
        pdf_add_rectangle(pdf, NULL, leftX, rowBottomY,
                          tableWidth, rowHeight, 0.6, borderColor);
        pdf_add_line(pdf, NULL,
                     leftX + labelColWidth, rowBottomY,
                     leftX + labelColWidth, positionY,
                     0.6, borderColor);

        // Label text (top-aligned inside cell)
        double textY = positionY - cellPadY - fontSize;
        for (size_t i = 0; i < labelLines.size(); ++i)
        {
            pdf_add_text(pdf, NULL, labelLines[i].c_str(), fontSize,
                         leftX + cellPadX, textY, PDF_BLACK);
            textY -= lineHeight;
        }

        // Value text (top-aligned inside cell)
        textY = positionY - cellPadY - fontSize;
        for (size_t i = 0; i < valueLines.size(); ++i)
        {
            pdf_add_text(pdf, NULL, valueLines[i].c_str(), fontSize,
                         leftX + labelColWidth + cellPadX, textY, PDF_BLACK);
            textY -= lineHeight;
        }

        positionY = rowBottomY;
    }

    void drawNoteRow(pdf_doc *pdf,
                     double &positionY,
                     double pageBottom,
                     double pageTop,
                     double leftX,
                     double tableWidth,
                     const string &sectionTitle,
                     const string &note)
    {
        const double fontSize = 10.0;
        const double lineHeight = 13.0;
        const double cellPadY = 7.0;
        const double cellPadX = 8.0;

        vector<string> noteLines = wrapTextToWidth(
            note, tableWidth - (2.0 * cellPadX), fontSize);
        double rowHeight = (noteLines.size() * lineHeight) + (2.0 * cellPadY);

        if (positionY - rowHeight < pageBottom)
        {
            pdf_append_page(pdf);
            positionY = pageTop;
            drawSectionHeader(pdf, positionY, leftX, tableWidth,
                              sectionTitle + " (Continued)");
        }

        double rowBottomY = positionY - rowHeight;
        uint32_t borderColor = PDF_RGB(140, 140, 140);

        pdf_add_rectangle(pdf, NULL, leftX, rowBottomY,
                          tableWidth, rowHeight, 0.6, borderColor);

        double textY = positionY - cellPadY - fontSize;
        for (size_t i = 0; i < noteLines.size(); ++i)
        {
            pdf_add_text(pdf, NULL, noteLines[i].c_str(), fontSize,
                         leftX + cellPadX, textY, PDF_BLACK);
            textY -= lineHeight;
        }

        positionY = rowBottomY;
    }
} // namespace

void generatepatientpdf(const PatientData &patient,
                        const SymptomData &symptomData)
{
    const double PAGE_TOP = 790.0;
    const double PAGE_BOTTOM = 50.0;
    const double LEFT_MARGIN = 45.0;
    const double TABLE_WIDTH = PDF_A4_WIDTH - (2.0 * LEFT_MARGIN);
    const double LABEL_COL_WIDTH = 185.0;
    const double VALUE_COL_WIDTH = TABLE_WIDTH - LABEL_COL_WIDTH;

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
    // TITLE BANNER
    // ==========================================

    pdf_add_text(pdf, NULL, "MEDICODE", 22.0,
                 LEFT_MARGIN, positionY - 22.0, PDF_BLACK);
    pdf_add_text(pdf, NULL, "PATIENT SUMMARY", 13.0,
                 LEFT_MARGIN, positionY - 40.0, PDF_RGB(64, 64, 64));
    pdf_add_line(pdf, NULL,
                 LEFT_MARGIN, positionY - 48.0,
                 LEFT_MARGIN + TABLE_WIDTH, positionY - 48.0,
                 1.2, PDF_RGB(178, 34, 34));

    positionY -= 62.0;

    // ==========================================
    // BUILD SECTION TABLES
    // ==========================================

    vector<SectionTable> sections;

    SectionTable patientInfo;
    patientInfo.title = "PATIENT INFORMATION";
    patientInfo.rows = {
        {"Patient ID", patient.patientID},
        {"Name", patient.name},
        {"Age", patient.age},
        {"Sex", patient.sexChoice},
        {"Address", patient.address},
        {"Civil Status", patient.civilStatus}
    };
    sections.push_back(patientInfo);

    SectionTable hpi;
    hpi.title = "HISTORY OF PRESENT ILLNESS";
    hpi.rows = {
        {"History of Present Illness", patient.historyPresentIllness}
    };
    sections.push_back(hpi);

    SectionTable pmh;
    pmh.title = "PAST MEDICAL HISTORY";
    pmh.rows = {
        {"Operations", patient.operations},
        {"Immunizations", patient.immunizations},
        {"Allergies", patient.allergies},
        {"Hospitalizations", patient.hospitalizations},
        {"Maintenance Medications", patient.maintenanceMeds},
        {"Others", patient.othersMedical}
    };
    sections.push_back(pmh);

    SectionTable familyHistory;
    familyHistory.title = "FAMILY HISTORY";
    familyHistory.rows = {
        {"Bronchial Asthma", patient.bronchialAsthma},
        {"Diabetes Mellitus", patient.diabetesMellitus},
        {"Hypertension", patient.hypertension},
        {"Pulmonary Tuberculosis", patient.pulmonaryTuberculosis},
        {"Others", patient.othersFamily}
    };
    sections.push_back(familyHistory);

    SectionTable socialHistory;
    socialHistory.title = "SOCIAL, ENVIRONMENTAL, PERSONAL HISTORY";
    socialHistory.rows = {
        {"Smoker", patient.smoker},
        {"Alcoholic Beverage Drinker", patient.alcoholicBeverageDrinker},
        {"Work/Environmental Hazards", patient.workEnvironmentalHazards}
    };
    sections.push_back(socialHistory);

    if (patient.sexChoice == "Female")
    {
        SectionTable obGyne;
        obGyne.title = "OB-GYNE HISTORY";
        obGyne.rows = {
            {"Menarche", patient.menarche},
            {"Menstrual History", patient.menstrualHistory},
            {"Gravida", patient.gravida},
            {"Para", patient.para},
            {"Last Menstrual Period", patient.lastMenstrualPeriod},
            {"Menopause", patient.menopause},
            {"Others", patient.othersOBGyne}
        };
        sections.push_back(obGyne);
    }

    SectionTable symptomSection;
    symptomSection.title = "SYMPTOM SUMMARY";
    if (symptomData.summaryCompleted)
    {
        symptomSection.rows = {
            {"Duration", symptomData.duration},
            {"Severity", symptomData.severity},
            {"Impact on Activities", symptomData.impact},
            {"Progression", symptomData.progression},
            {"Other Symptoms", symptomData.symptoms},
            {"Warning Signs", symptomData.warningSigns},
            {"Medication/Treatment", symptomData.medications},
            {"Additional Notes", symptomData.additionalNotes}
        };
    }
    else
    {
        symptomSection.fullWidthNote = "No symptom questionnaire has been completed.";
    }
    sections.push_back(symptomSection);

    // ==========================================
    // RENDER TABLES TO PDF
    // ==========================================

    for (size_t s = 0; s < sections.size(); ++s)
    {
        // Keep header attached to at least one row when possible
        if (positionY - 46.0 < PAGE_BOTTOM)
        {
            pdf_append_page(pdf);
            positionY = PAGE_TOP;
        }

        drawSectionHeader(pdf, positionY, LEFT_MARGIN, TABLE_WIDTH,
                          sections[s].title);

        if (!sections[s].fullWidthNote.empty())
        {
            drawNoteRow(pdf, positionY, PAGE_BOTTOM, PAGE_TOP,
                        LEFT_MARGIN, TABLE_WIDTH,
                        sections[s].title, sections[s].fullWidthNote);
        }
        else
        {
            for (size_t r = 0; r < sections[s].rows.size(); ++r)
            {
                drawTableRow(pdf, positionY, PAGE_BOTTOM, PAGE_TOP,
                             LEFT_MARGIN, LABEL_COL_WIDTH, VALUE_COL_WIDTH,
                             sections[s].title, sections[s].rows[r],
                             (r % 2 == 1));
            }
        }

        positionY -= 14.0;
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