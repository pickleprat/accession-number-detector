#include "ddbj/ddbj.h"
#include "ddbj/biosample.h" 
#include "ddbj/bioproject.h" 
#include "ddbj/categories.h"
#include <cctype>

bool DDBJDb::detect(const std::string& accession) {
    return isConventional(accession) || isBulk(accession) || isMGA(accession) || isDBLink(accession);
}

bool DDBJDb:: isDBLink(const std::string & accession) {
    return isSRA(accession) || isBioSample(accession) || isBioProject(accession); 
}

bool DDBJDb::isConventional(const std::string& accession) {
    int size = accession.size();
    if (size == 6 && firstNCharsAreLetters(accession,1) && countDigits(accession) == 5)
        return true;
    if (size == 8 && firstNCharsAreLetters(accession,2) && countDigits(accession) == 6)
        return true;
    return false;
}

bool DDBJDb::isBulk(const std::string& accession) {
    int size = accession.size();  
    if(size >= 12 && size <= 14 && firstNCharsAreLetters(accession, 4) && countDigits(accession) >= 8 && countDigits(accession) <= 10) {
        return true; 
    }
    return false; 
}

bool DDBJDb::isMGA(const std::string& accession) {
    int size = accession.size();  
    if(size == 12 && firstNCharsAreLetters(accession, 5) && countDigits(accession) == 7) {
        return true; 
    }
    return false; 
}

bool DDBJDb:: isSRA(const std::string &accession) {
    int size = accession.size(); 
    if(size == 9 && firstNCharsAreLetters(accession, 3) && countDigits(accession) == 6) {
        return true;  
    }
    return false; 
}

bool DDBJDb:: isBioSample(const std::string & accession) {
    int size = accession.size(); 
    bool status = startsWith(accession, BioSample::toString(BioSample::Type::SAME)) || 
                  startsWith(accession, BioSample::toString(BioSample::Type::SAMD)) || 
                  startsWith(accession, BioSample::toString(BioSample::Type::SAMN)) || 
                  startsWith(accession, BioSample::toString(BioSample::Type::SAMEA));   

    if (size == 12 && firstNCharsAreLetters(accession, 4) && countDigits(accession) == 8 && status) {
        return true; 
    } else if (firstNCharsAreLetters(accession, 5) && countDigits(accession) == 7 && status) {
        return true; 
    } else if(countDigits(accession) < 7 || countDigits(accession) > 8) {
        std::cout << "Initials are appropriate for DDBJ Category however the number of digits are not 8 or 7.\n"; 
        return false; 
    }
    return false ; 
}

bool DDBJDb:: isBioProject(const std:: string & accession) {
    int size = accession.size(); 
    bool status = startsWith(accession, BioProject::toString(BioProject::Type::PRJDA)) ||
                  startsWith(accession, BioProject::toString(BioProject::Type::PRJDZ)) ||
                  startsWith(accession, BioProject::toString(BioProject::Type::PRJEZ)) ||
                  startsWith(accession, BioProject::toString(BioProject::Type::PRJEA)) ||
                  startsWith(accession, BioProject::toString(BioProject::Type::PRJNA)) ||
                  startsWith(accession, BioProject::toString(BioProject::Type::PRJNZ)) || 
                  startsWith(accession, BioProject::toString(BioProject::Type::PRJDB)); 

    if(size >= 9 && size <= 12 && firstNCharsAreLetters(accession, 5) && countDigits(accession) >= 4 && countDigits(accession) <= 7 && status) {
        return true; 
    } else if(status && (countDigits(accession) < 4 || countDigits(accession) > 7)) {
        std::cout << "Initials are appropriate for DDBJ Category however the number of digits are not in the 4 to 7 range." << std::endl; 
        return false; 
    }
    return false;  
}

std::string DDBJDb::getCategory(const std::string &accession) {
    if (isSRA(accession)) {
        return DDBJCategory::toString(DDBJCategory::Type::SRA);
    } else if (isBioSample(accession)) {
        return DDBJCategory::toString(DDBJCategory::Type::BioSample);
    } else if (isBioProject(accession)) {
        return DDBJCategory::toString(DDBJCategory::Type::BioProject);
    } else if (isConventional(accession)) {
        return DDBJCategory::toString(DDBJCategory::Type::Conventional);
    } else if (isBulk(accession)) {
        return DDBJCategory::toString(DDBJCategory::Type::Bulk);
    } else if (isMGA(accession)) {
        return DDBJCategory::toString(DDBJCategory::Type::MGA);
    }
    return DDBJCategory::toString(DDBJCategory::Type::Unknown);
}