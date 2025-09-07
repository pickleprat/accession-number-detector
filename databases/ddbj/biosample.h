#pragma once 
#include <iostream> 

namespace BioSample {
    enum Type {
        SAMD, 
        SAME, 
        SAMN
    }; 

    inline std::string toString(Type bs) {
        switch(bs) {
            case Type::SAMD: return "SAMD"; 
            case Type::SAME: return "SAME"; 
            case Type::SAMN: return "SAMN"; 
            default: return ""; 
        }
    };  
}


