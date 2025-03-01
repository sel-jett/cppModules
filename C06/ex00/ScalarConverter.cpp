#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
    (void)obj;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor called" << std::endl;    
}

// void    toFloat(float num) {
//     if ()
// }

// void ScalarConverter::convert(std::string arg) {
//     float   flotNum = atof(arg.c_str());


// }

void toInt(std::string arg) {
    
    if (arg != "+inf" && arg != "-inf" && arg != "inf") {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    
    int value = atof(arg.c_str());
    
    if (isinf(value)) {
            std::cout << "int: " << arg << std::endl;
        return;
    }
    
    if (isnan(value)) {
        std::cout << "int: " << arg << std::endl;
        return;
    }

    std::stringstream ss(arg);
    int testValue;
    ss >> testValue;
    if (ss.fail()) {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    
    std::cout << "int: " << testValue << std::endl;
}

void toFloat(std::string arg) {
    
    if (arg != "nan" && arg != "nanf" &&  arg != "+inf" && arg != "-inf" && 
    arg != "+inff" && arg != "-inff" && arg != "inf" && arg != "inff") {
        std::cout << "float: impossible" << std::endl;
        return;
    }
    
    float value = atof(arg.c_str());
    
    if (isinf(value)) {
        std::cout << "float: " << arg << std::endl;
        return;
    }
    
    if (isnan(value)) {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    
    if (value == static_cast<int>(value))
        std::cout << "float: " << value << ".0f" << std::endl;
    else
        std::cout << "float: " << value << "f" << std::endl;
}

void toDouble(std::string arg) {
    
    if (arg != "nan" && arg != "nanf" && 
        arg != "+inf" && arg != "-inf" && arg != "+inff" && arg != "-inff" && arg != "inf" && arg != "inff") {
        std::cout << "double: impossible" << std::endl;
        return;
    }
    
    double value = atof(arg.c_str());
    
    if (isinf(value)) {
            std::cout << "double: " << arg << std::endl;
        return;
    }
    
    if (isnan(value)) {
        std::cout << "double: nan" << std::endl;
        return;
    }
    
    if (value == static_cast<int>(value))
        std::cout << "double: " << value << ".0" << std::endl;
    else
        std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(std::string arg) {
    if (arg.empty())
        return;
    if (arg[arg.length() - 1] == 'f' && arg != "nan" && arg != "nanf" &&
        arg != "+inf" && arg != "-inf" && arg != "+inff" && arg != "-inff" && arg != "inf" && arg != "inff")
        arg = arg.substr(0, arg.length() - 1);
    toInt(arg);
    toFloat(arg);
    toDouble(arg);
    return ;
}