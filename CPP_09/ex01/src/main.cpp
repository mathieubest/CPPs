#include "../include/RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Usage: ./RPN <\"expression\">" << std::endl;
        return 1;
    }
    RPN rpn;
    if(!rpn.validateExpression(av[1])) {
        std::cout << "Expression is not valid" << std::endl;
        return 1;
    }
    rpn.setExpression(av[1]);
    // rpn.printStack();
    rpn.evaluate();
    return 0;
}
