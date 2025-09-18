// orchestrator 
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

void greetUser() {
    std::cout << "============================================\n";
    std::cout << "          WELCOME TO ACCESSIONARY!    \n";
    std::cout << "============================================\n\n";

    std::cout << "This tool helps classify biological accession numbers\n";
    std::cout << "into their respective databases and categories.\n\n";

    std::cout << "Supported Databases:\n";
    std::cout << "  1. RefSeq (Reference Sequence Database)\n";
    std::cout << "     - RNA: NR_, XR_\n";
    std::cout << "     - mRNA: NM_, XM_\n";
    std::cout << "     - Protein: NP_, XP_, YP_, AP_, WP_\n";
    std::cout << "     - Genomic: AC_, NC_, NG_, NT_, NW_, NZ_\n\n";

    std::cout << "  2. DDBJ (DNA Data Bank of Japan)\n";
    std::cout << "     Sequence Data:\n";
    std::cout << "       - Conventional: 1 letter + 5 digits OR 2 letters + 6 digits\n";
    std::cout << "       - Bulk (WGS/TSA/TLS): 4 letters + 8 to 10 digits\n";
    std::cout << "       - MGA: 5 letters + 7 digits\n";
    std::cout << "     DBLinks:\n";
    std::cout << "       - BioSample --> Biological sample description\n";
    std::cout << "       - BioProject --> Related sequencing projects\n";
    std::cout << "       - SRA --> Raw sequence read archive\n\n";

    std::cout << "  3. PDB (Protein Data Bank)\n";
    std::cout << "     - Always 4 characters\n";
    std::cout << "     - First is a digit (1 to 9), last three are letters or digits\n\n";

    std::cout << "--------------------------------------------\n";
    std::cout << "Enter an accession number below to classify:\n";
    std::cout << "--------------------------------------------\n\n";
}



int main() {
    greetUser(); 

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
            std::cout << "Category: " << ddbj.getCategory(accession) << std::endl;
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
