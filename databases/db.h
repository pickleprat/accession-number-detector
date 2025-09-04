#pragma once
#include <string>
#include <cctype>

class DB {
public:
    DB() = default;

    bool firstNCharsAreLetters(const std::string& str, int n) {
        if (str.size() < static_cast<size_t>(n)) return false;
        for (int i = 0; i < n; ++i)
            if (!std::isalpha(static_cast<unsigned char>(str[i]))) return false;
        return true;
    }

    bool charAtIsDigit(const std::string& str, int pos) {
        if (pos < 0 || pos >= static_cast<int>(str.size())) return false;
        return std::isdigit(static_cast<unsigned char>(str[pos]));
    }

    bool startsWith(const std::string& str, const std::string& prefix) {
        return str.rfind(prefix, 0) == 0;
    }

    bool endsWith(const std::string& str, const std::string& suffix) {
        if (suffix.size() > str.size()) return false;
        return str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
    }

    int countDigits(const std::string& str) {
        int count = 0;
        for (char c : str) {
            if (std::isdigit(static_cast<unsigned char>(c))) count++;
        }
        return count;
    }

    int countAlphabets(const std::string& str) {
        int count = 0;
        for (char c : str) {
            if (std::isalpha(static_cast<unsigned char>(c))) count++;
        }
        return count;
    }
};