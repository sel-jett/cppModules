#pragma once
#include <iostream>

template <typename T>
int easyfind(T container, int occ) {
    typename T::iterator it = find(container.begin(), container.end(), occ);
    if (it == container.end())
        throw std::string("Not found!!");
    return occ;
}