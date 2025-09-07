#include "ddbj/ddbj.h"
#include "ddbj/biosample.h" 
#include "ddbj/bioproject.h" 
#include <cctype>

bool DDBJDb::detect(const std::string& accession) {
    return isConventional(accession) || isBulk(accession) || isMGA(accession);
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
    if(size >= 12 && size <= 14 && firstNCharsAreLetters(accession, 4) && countAlphabets(accession) >= 8 && countAlphabets(accession) <= 10) {
        return true; 
    }
    return false; 
}

bool DDBJDb::isMGA(const std::string& accession) {
    int size = accession.size();  
    if(size == 12 && firstNCharsAreLetters(accession, 5) && countAlphabets(accession) == 7) {
        return true; 
    }
    return false; 
}

bool DDBJDb:: isSRA(const std::string &accession) {
    int size = accession.size(); 
    if(size == 9 && firstNCharsAreLetters(accession, 3) && countAlphabets(accession) == 6) {
        return true;  
    }
    return false; 
}

bool DDBJDb:: isBioSample(const std::string & accession) {
    int size = accession.size(); 
    bool status = startsWith(accession, BioSample::toString(BioSample::Type::SAME)) || 
                  startsWith(accession, BioSample::toString(BioSample::Type::SAMD)) || 
                  startsWith(accession, BioSample::toString(BioSample::Type::SAMN));   

    if(size == 12 && firstNCharsAreLetters(accession, 4) && countAlphabets(accession) == 8 && status) {
        return true; 
    }
    return false; 
}

bool DDBJDb:: isBioProject(const std:: string & accession) {
    int size = accession.size(); 
    bool status = startsWith(accession, BioProject::toString(BioProject::Type::PRJDA)) ||
                  startsWith(accession, BioProject::toString(BioProject::Type::PRJDZ)) ||
                  startsWith(accession, BioProject::toString(BioProject::Type::PRJEZ)) ||
                  startsWith(accession, BioProject::toString(BioProject::Type::PRJEA)) ||
                  startsWith(accession, BioProject::toString(BioProject::Type::PRJNA)) ||
                  startsWith(accession, BioProject::toString(BioProject::Type::PRJNZ));

    if(size == 10 && firstNCharsAreLetters(accession, 10) && countAlphabets(accession) && status) {
        return true;  
    }

    return false; 
}
