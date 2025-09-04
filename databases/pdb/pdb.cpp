#include "pdb/pdb.h"
#include <cctype>

bool PDBDb::detect(const std::string& accession) {
    return isValidFormat(accession);
}

// PDB format: 4 characters
// First: numeral 1-9
// Last three: digits 0-9 or letters A-Z
bool PDBDb::isValidFormat(const std::string& accession) {
    if (accession.size() != 4) return false;

    // First character: '1'-'9'
    if (accession[0] < '1' || accession[0] > '9') return false;

    // Last three characters: 0-9 or A-Z
    for (int i = 1; i < 4; ++i) {
        char c = accession[i];
        if (!std::isdigit(static_cast<unsigned char>(c)) &&
            !(c >= 'A' && c <= 'Z')) {
            return false;
        }
    }

    return true;
}