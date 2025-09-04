#pragma once

// Path to the base class header (adjust if your layout differs).
// From databases/refspec/refspec.h -> root db.h is at ../../db.h
#include "db.h"

#include <string>
#include <vector>

/*
 * RefSpec detector (RefSeq-style accessions)
 *
 * Typical RefSeq accession examples:
 *   NM_000546   (curated mRNA)
 *   NP_000537   (curated protein)
 *   NR_XXXXX    (non-coding RNA)
 *   XM_XXXXX    (predicted mRNA)
 *   XP_XXXXX    (predicted protein)
 *   NG_XXXXX    (genomic)
 *
 * This class inherits from DB and implements detect(). The implementation
 * (in refspec.cpp) should use the helper functions provided by DB.
 */


class RefSpecDb : public DB {
public:
    RefSpecDb() = default;
    ~RefSpecDb() = default;

    // Returns true if accession matches RefSeq format
    bool detect(const std::string& accession);

    std::string getCategory(const std::string& accession);

private:
    static inline const std::vector<std::string> CURATED = {"NM", "NP", "NR"};
    static inline const std::vector<std::string> PREDICTED = {"XM", "XR", "XP"};
    static inline const std::vector<std::string> GENOMIC = {"NG"};

    bool isValidPrefix(const std::string& prefix);
};
