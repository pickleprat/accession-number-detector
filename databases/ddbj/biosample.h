#pragma once 
#include <iostream> 

namespace BioSample {
    enum Type {
        SAMD, 
        SAME, 
        SAMN, 
        SAMEA
    }; 

    inline std::string toString(Type bs) {
        switch(bs) {
            case Type::SAMD: return "SAMD"; 
            case Type::SAME: return "SAME"; 
            case Type::SAMN: return "SAMN"; 
            case Type::SAMEA: return "SAMEA"; 
            default: return ""; 
        }
    };  
}


