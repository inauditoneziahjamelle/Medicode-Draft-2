#pragma once

#include <string>

struct PatientData
{
    std::string patientID;
    std::string patient;
    std::string symptom; 
    std::string name;
    std::string age;
    std::string sex;
    std::string address;
    std::string civilStatus;

    std::string historyPresentIllness;
    std::string operations;
    std::string immunizations;
    std::string allergies;
    std::string hospitalizations;
    std::string maintenanceMeds;
    std::string othersMedical;

    std::string bronchialAsthma;
    std::string diabetesMellitus;
    std::string hypertension;
    std::string pulmonaryTuberculosis;
    std::string othersFamily;

    std::string smoker;
    std::string alcoholicBeverageDrinker;
    std::string workEnvironmentalHazards;

    std::string menarche;
    std::string menstrualHistory;
    std::string gravida;
    std::string para;
    std::string lastMenstrualPeriod;
    std::string menopause;
    std::string othersOBGyne;

    bool profileCompleted = false;
};