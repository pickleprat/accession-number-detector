#include <iostream>
#include <string>
#include "databases/db.h"
#include "databases/refseq/refseq.h"
#include "databases/ddbj/ddbj.h"
#include "databases/pdb/pdb.h"

enum DBType {
    REFSEQ = 1,
    DDBJ,
    PDB,
    UNKNOWN
};


int main() {
    std::cout << "Welcome to the accession number classifier!" << std::endl;

    std::string accession;
    std::cout << "Enter an accession number: ";
    std::cin >> accession;

    RefSeqDb refseq;
    DDBJDb ddbj;
    PDBDb pdb;

    DBType dbType = UNKNOWN;

    if (refseq.detect(accession)) {
        dbType = REFSEQ;
    } else if (ddbj.detect(accession)) {
        dbType = DDBJ;
    } else if (pdb.detect(accession)) {
        dbType = PDB;
    }

    switch (dbType) {
        case REFSEQ:
            std::cout << accession << " belongs to RefSeq Database." << std::endl;
            std::cout << "Category: " << refseq.getCategory(accession) << std::endl;
            break;

        case DDBJ:
            std::cout << accession << " belongs to DDBJ Database." << std::endl;

            // drill down into DDBJ subcategories
            if (ddbj.isSRA(accession)) {
                std::cout << "Type: SRA (Sequence Read Archive)" << std::endl;
            } else if (ddbj.isBioSample(accession)) {
                std::cout << "Type: BioSample" << std::endl;
            } else if (ddbj.isBioProject(accession)) {
                std::cout << "Type: BioProject" << std::endl;
            } else if (ddbj.isConventional(accession)) {
                std::cout << "Type: Conventional" << std::endl;
            } else if (ddbj.isBulk(accession)) {
                std::cout << "Type: Bulk" << std::endl;
            } else if (ddbj.isMGA(accession)) {
                std::cout << "Type: MGA" << std::endl;
            } else {
                std::cout << "Type: Unknown (DDBJ link)" << std::endl;
            }
            break;

        case PDB:
            std::cout << accession << " belongs to PDB Database." << std::endl;
            break;

        default:
            std::cout << accession << " does not match any known database." << std::endl;
            break;
    }

    return 0;
}
