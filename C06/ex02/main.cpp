#include "Base.hpp"

int main ( void ) {
    Base *first = generate();
    identify(first);
    // delete(first);
    // Base *second = generate();
    identify(*first);
    // identify(*second);
    // delete(second);
    return (0);
}