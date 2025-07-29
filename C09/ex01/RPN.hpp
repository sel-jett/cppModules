#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>

class RPN {
    private:
        std::stack<int> mystack;
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        void calculateRpn(char *str);
};