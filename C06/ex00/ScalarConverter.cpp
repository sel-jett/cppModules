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

void toChar(std::string arg) {
    
    int value;
    char value2 = -32;
    std::stringstream ss(arg);
    ss >> value;
    if (ss.fail()) {
        std::stringstream bb(arg);
        bb >> value2;
        if (bb.fail() || arg.length() != 1) {
            std::cout << "char: impossible " << std::endl;
            return;
        }
    }

    if (value2 != -32)
        std::cout << "char: '" << value2 << "'" << std::endl;
    else if (isprint(value))
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else 
        std::cout << "char: Non displayable" << std::endl;
}

void toInt(std::string arg) {
    
    int value;
    std::stringstream ss(arg);
    ss >> value;
    if (ss.fail() && arg != "+inf" && arg != "-inf" && arg != "inf") {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    
    value = atof(arg.c_str());
    
    if (arg == "+inf" || arg == "-inf" || arg == "inf") {
            std::cout << "int: " << arg << std::endl;
        return;
    }
    
    if (isnan(value)) {
        std::cout << "int: " << arg << std::endl;
        return;
    }
    
    std::cout << "int: " << value << std::endl;
}

void toFloat(std::string arg) {
    
    float value;
    std::stringstream ss(arg);
    ss >> value;
    if (ss.fail() && arg != "nan" && arg != "nanf" &&  arg != "+inf" && arg != "-inf" && 
    arg != "+inff" && arg != "-inff" && arg != "inf" && arg != "inff") {
        std::cout << "float: impossible" << std::endl;
        return;
    }
    
    value = atof(arg.c_str());
    
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
    
    double value;
    std::stringstream ss(arg);
    ss >> value;
    if (ss.fail() && arg != "nan" && arg != "nanf" && 
        arg != "+inf" && arg != "-inf" && arg != "+inff" && arg != "-inff" && arg != "inf" && arg != "inff") {
        std::cout << "double: impossible" << std::endl;
        return;
    }
    
    value = atof(arg.c_str());
    
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
    if (arg[arg.length() - 1] == 'f' && (isdigit(arg[0]) || arg[0] == '+' || arg[0] == '-') && 
    arg != "+inf" && arg != "+inff" && arg != "-inf" && arg != "-inff")
        arg = arg.substr(0, arg.length() - 1);
    toChar(arg);
    toInt(arg);
    toFloat(arg);
    toDouble(arg);
    return ;
}