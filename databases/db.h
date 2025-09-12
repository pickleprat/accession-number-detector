#pragma once
#include <string>
#include <cctype>

class DB {
public:
    DB() = default;

    bool firstNCharsAreLetters(const std::string& str, int n) {
        if (str.size() < static_cast<size_t>(n)) return false;
        for (int i = 0; i < n; ++i)
            if (!std::isalpha(str[i])) return false;
        return true;
    }

    bool startsWith(const std::string& str, const std::string& prefix) {
        return str.rfind(prefix, 0) == 0;
    }

    int countDigits(const std::string& str) {
        int count = 0;
        for (char c : str) {
            if (std::isdigit((c))) count++;
        }
        return count;
    }
};