#pragma once
#include "db.h"
#include "ddbj/categories.h"
#include <string>
#include <vector>

class DDBJDb: public DB {
public:
    DDBJDb() = default;
    ~DDBJDb() = default;

    bool detect(const std::string& accession);
    std::string getCategory(const std::string &accession); 

private: 
    bool isConventional(const std::string& accession);
    bool isBulk(const std::string& accession);
    bool isMGA(const std::string& accession);
    bool isSRA(const std::string& accession); 
    bool isBioProject(const std::string& accession); 
    bool isBioSample(const std::string& accession); 
    bool isDBLink(const std:: string & accession); 
};