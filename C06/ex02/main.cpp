#include "Base.hpp"


int main ( void ) {
    Base *first = generate();
    identify(first);
    // Base *second = generate();
    identify(*first);
    delete(first);
    // identify(*second);
    // delete(second);
    return (0);
}