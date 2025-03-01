#pragma once
#include <iostream>
#include <sstream>
#include <math.h>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);
        ScalarConverter& operator=(const ScalarConverter& obj);
    public:
        ~ScalarConverter();
        static void convert(std::string arg);
};