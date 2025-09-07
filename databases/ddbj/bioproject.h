#pragma once 
#include <string>

namespace BioProject {
    enum Type {
        PRJDA,
        PRJDZ,
        PRJEZ,
        PRJEA,
        PRJNA,
        PRJNZ
    };

    inline std::string toString(const Type bp) {
        switch (bp) {
            case Type::PRJDA: return "PRJDA";
            case Type::PRJDZ: return "PRJDZ";
            case Type::PRJEZ: return "PRJEZ";
            case Type::PRJEA: return "PRJEA";
            case Type::PRJNA: return "PRJNA";
            case Type::PRJNZ: return "PRJNZ";
            default: return "";
        }
    }
}
