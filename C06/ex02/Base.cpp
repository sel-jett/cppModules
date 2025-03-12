#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* createA() {
    return new A;
}

Base* createB() {
    return new B;
}

Base* createC() {
    return new C;
}

Base * generate(void) {
    srand(static_cast<unsigned int>(time(NULL)));
    int randomObject = rand() % 3;

    typedef Base* (*createFunc)();
    static createFunc creators[] = {createA, createB, createC};
    return creators[randomObject]();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
    std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
    std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch ( ... ) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch ( ... ) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    } catch ( ... ) {}
    std::cout << "Type not known" << std::endl;
}