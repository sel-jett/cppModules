#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Serializer& Serializer::operator=(const Serializer& obj)
{
    (void)obj;
    return (*this);
}

Serializer::~Serializer()
{
    std::cout << "Destructor called" << std::endl;    
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t ptr) {
    return reinterpret_cast<Data*>(ptr);
}