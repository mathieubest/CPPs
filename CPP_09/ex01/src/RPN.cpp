#include "../include/RPN.hpp"

#include <vector>
#include <algorithm>
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN& copy) {
    if (this != &copy) {
        this->stk = copy.stk;
    }
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->stk = other.stk;
    }
    return *this;
}

RPN::~RPN() {}

void RPN::setExpression(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    while(iss >> token) {
        stk.push(token);
    }
}

void RPN::printStack() const {
    std::stack<std::string> temp(stk);
    while(!temp.empty()) {
        std::cout << temp.top() << std::endl;
        temp.pop();
    }
}

int RPN::processStack() {
    std::string token = stk.top();
    stk.pop();

    if (token == "+" || token == "-" || token == "*" || token == "/") {
        int b = processStack();
        int a = processStack();

        if (token == "+") return a + b;
        if (token == "-") return a - b;
        if (token == "*") return a * b;
        if (token == "/") {
            if (b == 0)
                throw std::runtime_error("Division by zero");
            return a / b;
        }
    }

    return std::atoi(token.c_str());
}

void RPN::evaluate() {
    try {
        int result = processStack();
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

bool RPN::validateExpression(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    int count = 0;
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (count < 2)
                return false;
            count--;
        } else {
            count++;
        }
    }
    return (count == 1);
}
