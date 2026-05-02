#include "../include/Utils.hpp"

bool isDisplayableChar(char c) {
    return (c >= 32 && c <= 126);
}

bool isSpecialString(const std::string& str) {
    if (str == "-inf" || str == "+inf" || str == "nan" ||
        str == "-inff" || str == "+inff" || str == "nanf") {
        return true;
    } else {
        return false;
    }
}

bool isFloatLiteral(const std::string& str) {
    if (str[str.length() - 1] != 'f') {
        return false;
    }
    std::string num = str.substr(0, str.length() - 1);
    char *endptr;
    std::strtof(num.c_str(), &endptr);
    if (*endptr == '\0') {
        return true;
    } else {
        return false;
    }
}

bool isDoubleLiteral(const std::string& str) {
    if (str.find('.') == std::string::npos) {
        return false;
    }
    char *endptr;
    std::strtod(str.c_str(), &endptr);
    if (*endptr == '\0') {
        return true;
    } else {
        return false;
    }
}

bool isIntLiteral(const std::string& str) {
    char *endptr;
    std::strtol(str.c_str(), &endptr, 10);
    if (*endptr == '\0') {
        return true;
    } else {
        return false;
    }
}
