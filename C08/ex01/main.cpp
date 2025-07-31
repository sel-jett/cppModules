#include "Span.hpp"
#include <vector>
#include <iostream>

int main() {
    Span sp(10);
    std::vector<int> values;
    for (int i = 1; i <= 5; ++i)
        values.push_back(i * 10);

    try {
        sp.addNumbers(values.begin(), values.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const char* msg) {
        std::cout << "Exception: " << msg << std::endl;
    }

    try {
        int arr2[] = {600, 70, 80, 90, 100, 170};
        std::vector<int> more(arr2, arr2 + 5);
        sp.addNumbers(more.begin(), more.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const char* msg) {
        std::cout << "Exception: " << msg << std::endl;
    }

    return 0;
}