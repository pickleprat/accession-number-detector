#include "ddbj/ddbj.h"
#include <cctype>

bool DDBJDb::detect(const std::string& accession) {
    return isConventional(accession) || isBulk(accession) || isMGA(accession);
}

bool DDBJDb::isConventional(const std::string& accession) {
    int len = accession.size();
    if (len == 6 && firstNCharsAreLetters(accession,1) && countDigits(accession) == 5)
        return true;
    if (len == 8 && firstNCharsAreLetters(accession,2) && countDigits(accession) == 6)
        return true;
    return false;
}

bool DDBJDb::isBulk(const std::string& accession) {
    int letters = countAlphabets(accession);
    int digits = countDigits(accession);
    return (letters == 4) && (digits >= 8 && digits <= 10);
}

bool DDBJDb::isMGA(const std::string& accession) {
    return (countAlphabets(accession) == 5 && countDigits(accession) == 7);
}
