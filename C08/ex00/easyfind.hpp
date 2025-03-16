#pragma once
#include <iostream>

template <typename T>
void easyfind(T container, int occ) {
    typename T::iterator it = find(container.begin(), container.end(), occ);
    if (it == container.end())
        throw std::string("Not found!!");
    std::cout << "foundddd" << std::endl;
}