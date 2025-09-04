#include <iostream>
#include <string>
#include "databases/db.h"
#include "databases/refspec/refspec.h"
#include "databases/ddbj/ddbj.h"
#include "databases/pdb/pdb.h"

enum DBType {
    REFSPEC = 1,
    DDBJ,
    PDB,
    KEGG,
    UNKNOWN
};

int main() {
    std::cout << "Welcome to the accession number classifier!" << std::endl;

    std::string accession;
    std::cout << "Enter an accession number: ";
    std::cin >> accession;

    // Create detector objects
    RefSpecDb refspec;
    DDBJDb ddbj;
    PDBDb pdb;

    DBType dbType = UNKNOWN;

    if (refspec.detect(accession)) {
        dbType = REFSPEC;
    } else if (ddbj.detect(accession)) {
        dbType = DDBJ;
    } else if (pdb.detect(accession)) {
        dbType = PDB;
    }
    // else if (kegg.detect(accession)) {
    //     dbType = KEGG;
    // }

    switch (dbType) {
        case REFSPEC:
            std::cout << accession << " belongs to RefSeq Database." << std::endl;
            std::cout << "Category: " << refspec.getCategory(accession) << std::endl;
            break;
        case DDBJ:
            std::cout << accession << " belongs to DDBJ Database." << std::endl;
            break;
        case PDB:
            std::cout << accession << " belongs to PDB Database." << std::endl;
            break;
        case KEGG:
            std::cout << accession << " belongs to KEGG Database." << std::endl;
            break;
        default:
            std::cout << accession << " does not match any known database." << std::endl;
            break;
    }

    return 0;
}
