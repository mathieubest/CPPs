#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

class RPN {
    private:
        std::stack<std::string> stk;

    public:
        RPN();
        RPN(const RPN& copy);
        RPN& operator=(const RPN& other);
        ~RPN();

        void setExpression(const std::string& expression);
        void evaluate();
        void printStack() const;
        bool validateExpression(const std::string& expression);
        int processStack();
};

#endif
