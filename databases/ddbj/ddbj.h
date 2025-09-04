#pragma once
#include "db.h"
#include <string>
#include <vector>

class DDBJDb: public DB {
public:
    DDBJDb() = default;
    ~DDBJDb() = default;

    bool detect(const std::string& accession);

private:
    bool isConventional(const std::string& accession);
    bool isBulk(const std::string& accession);
    bool isMGA(const std::string& accession);
};