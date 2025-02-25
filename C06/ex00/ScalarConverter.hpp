#pragma once
#include <iostream>

class ScalarConverter {
    public :
        ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);
        ScalarConverter& operator=(const ScalarConverter& obj);
        ~ScalarConverter();
        static void convert(std::string arg);
};