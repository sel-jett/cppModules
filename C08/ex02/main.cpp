#include "MutantStack.hpp"

int main()
{
    // Subject test
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    // my test

    MutantStack<int> mstack2;
    mstack2.push(1);
    mstack2.push(2);
    mstack2.push(3);
    mstack2.push(4);
    mstack2.push(5);
    MutantStack<int>::reverse_iterator rit = mstack2.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack2.rend();
    std::cout << "Reverse iterator test" << std::endl;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    MutantStack<int>::const_iterator cit = mstack2.begin();
    MutantStack<int>::const_iterator cite = mstack2.end();
    std::cout << "Const iterator test" << std::endl;
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }
    MutantStack<int>::const_reverse_iterator crit = mstack2.rbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack2.rend();
    std::cout << "Const Reverse iterator test" << std::endl;
    while (crit != crite)
    {
        std::cout << *crit << std::endl;
        ++crit;
    }

    std::cout << "Simple Iterator test" << std::endl;
    
    MutantStack<int> mstack3(mstack2);
    MutantStack<int>::iterator it3 = mstack3.begin();
    MutantStack<int>::iterator ite3 = mstack3.end();
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }

    return 0;
}