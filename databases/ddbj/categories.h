#pragma once 

namespace DDBJCategory {
    enum class Type {
        SRA,
        BioSample,
        BioProject,
        Conventional,
        Bulk,
        MGA,
        Unknown
    }; 

    static inline std::string toString(Type cat) {
        switch (cat) {
            case Type::SRA: return "SRA (Sequence Read Archive)";
            case Type::BioSample: return "BioSample";
            case Type::BioProject: return "BioProject";
            case Type::Conventional: return "Conventional";
            case Type::Bulk: return "Bulk";
            case Type::MGA: return "MGA";
            default: return "Unknown (DDBJ link)";
        }
    }
}
