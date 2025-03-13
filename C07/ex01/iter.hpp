#pragma once
#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t len, F func) {
    for (size_t i = 0; i < len; i++) {
        func(array[i]);
    }
}