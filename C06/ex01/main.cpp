#include "Serializer.hpp"

int main ( void ) {
    Data numbersss;
    numbersss.i = 42;
    uintptr_t first =  Serializer::serialize(&numbersss);
    Data *second =  Serializer::deserialize(first);
    std::cout << "the ruler of the world : " << second->i << std::endl;
    return (0);
}