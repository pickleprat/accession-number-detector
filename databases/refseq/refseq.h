#pragma once

// Path to the base class header (adjust if your layout differs).
// From databases/refseq/refseq.h -> root db.h is at ../../db.h
#include "db.h"

#include <string>
#include <vector>

/*
 * RefSeq detector (RefSeq-style accessions)
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
 * (in refseq.cpp) should use the helper functions provided by DB.
 */


class RefSeqDb : public DB {
public:
    RefSeqDb() = default;
    ~RefSeqDb() = default;

    // Returns true if accession matches RefSeq format
    bool detect(const std::string& accession);

    std::string getCategory(const std::string& accession);

private:
    static inline const std::vector<std::string> RNA = {"NR_", "XR_"};
    static inline const std::vector<std::string> MRNA = {"NM_", "XM_"};
    static inline const std::vector<std::string> GENOMIC = { "AC_", "NC_", "NG_", "NT_", "NW_", "NZ_"};
    static inline const std::vector<std::string> PROTEIN = { "AP_", "NP_", "YP_", "XP_", "WP_"};

    bool isValidPrefix(const std::string& prefix);
};
