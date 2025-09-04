#pragma once
#include "db.h"
#include <string>

class PDBDb : public DB {
public:
    PDBDb() = default;
    ~PDBDb() = default;

    bool detect(const std::string& accession);

private:
    bool isValidFormat(const std::string& accession);
};