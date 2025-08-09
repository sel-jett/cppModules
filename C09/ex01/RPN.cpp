#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        mystack = other.mystack;
    }
    return *this;
}

RPN::~RPN() {}

void RPN::calculateRpn(char *str) {
    char *expr = strtok(str, " ");
    while (expr) {
        // std::cout << "expr: " << expr << std::endl;
        if (isdigit(*expr)) {
                std::stringstream ss(expr);
                int num;
                ss >> num;
                mystack.push(num);
        }
        else if (*expr == '+') {
            if (mystack.size() < 2) {
                std::cout << "Error" << std::endl;
                return;
            }
            int num1 = mystack.top();
            mystack.pop();
            int num2 = mystack.top();
            mystack.pop();
            mystack.push(num1 + num2);
        }
        else if (*expr == '-') {
            if (mystack.size() < 2) {
                std::cout << "Error" << std::endl;
                return;
            }
            int num3 = mystack.top();
            mystack.pop();
            int num4 = mystack.top();
            mystack.pop();
            
            mystack.push(num4 - num3);
        }
        else if (*expr == '*') {
            if (mystack.size() < 2) {
                std::cout << "Error" << std::endl;
                return;
            }
            int num5 = mystack.top();
            mystack.pop();
            int num6 = mystack.top();
            mystack.pop();
            mystack.push(num6 * num5);
        }
        else if (*expr == '/') {
            if (mystack.size() < 2) {
                std::cout << "Error" << std::endl;
                return;
            }
            int num7 = mystack.top();
            mystack.pop();
            int num8 = mystack.top();
            mystack.pop();
            mystack.push(num8 / num7);
        }
        else {
            std::cout << "Error" << std::endl;
            return;
        }
        expr = strtok(NULL, " ");
    }
    if (mystack.size() != 1) {
        std::cout << "Error" << std::endl;
        return;
    }
    std::cout << "Result: " << mystack.top() << std::endl;
}