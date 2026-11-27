#pragma once

#ifndef SYMPTOMDATA_H
#define SYMPTOMDATA_H

#include <string>

struct SymptomData
{
    std::string concern;
    std::string duration;
    std::string severity;
    std::string impact;
    std::string progression;
    std::string warningSigns;
    std::string symptoms;
    std::string medications;
    std::string concern_summary;
    std::string additionalNotes;
    
    bool summaryCompleted = false;
};

#endif