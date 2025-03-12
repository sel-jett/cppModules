#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

class Base
{
    public:
        virtual ~Base();
};
Base * generate(void);
void identify(Base* p);
void identify(Base& p);