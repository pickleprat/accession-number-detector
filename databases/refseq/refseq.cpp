#include <iostream> 
#include "refseq/refseq.h"

bool RefSeqDb::detect(const std::string& accession) {
    if (accession.size() < 5) return false; // need at least 2 letters + _ + 2 more

    std::string prefix = accession.substr(0, 3);
    char underscore = accession[2];
    if (!firstNCharsAreLetters(prefix, 2)) return false;
    if (underscore != '_') return false;

    return isValidPrefix(prefix);
}

std::string RefSeqDb::getCategory(const std::string& accession) {
    if (!detect(accession)) return "Invalid";

    std::string prefix = accession.substr(0, 3);

    for (const auto &p : PROTEIN) {
        if (prefix == p) return "PROTEIN";
    }
    for (const auto &p : MRNA) {
        if (prefix == p) return "MRNA";
    }
    for (const auto &p : GENOMIC) {
        if (prefix == p) return "Genomic";
    }
    for (const auto &p : RNA) {
        if (prefix == p) return "RNA";
    }

    return "Unknown";
}

bool RefSeqDb::isValidPrefix(const std::string& prefix) {
    for (const auto &p : PROTEIN) if (prefix == p) return true;
    for (const auto &p : MRNA) if (prefix == p) return true;
    for (const auto &p : RNA)  if (prefix == p) return true;
    for (const auto &p : GENOMIC)  if (prefix == p) return true;
    return false;
}