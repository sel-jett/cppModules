#pragma once
#include <iostream>
#include <vector>

template <typename T>
int easyfind(T container, int occ) {
    typename T::iterator it = container.begin();
    typename T::iterator end = container.end();
    
    while (it != end) {
        if (*it == occ) {
            return occ;
        }
        ++it;
    }
    throw std::string("Not found!!");
}