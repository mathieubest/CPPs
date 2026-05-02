#include <cstdlib>
#include <limits>
#include <iomanip>
#include <iostream>

bool isDisplayableChar(char c);
bool isSpecialString(const std::string& str);
bool isIntLiteral(const std::string& str);
bool isFloatLiteral(const std::string& str);
bool isDoubleLiteral(const std::string& str);