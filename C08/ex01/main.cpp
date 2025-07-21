#include "Span.hpp"
#include <vector>
#include <iostream>

int main() {
    Span sp(10);
    std::vector<int> values;
    for (int i = 1; i <= 5; ++i)
        values.push_back(i * 10);

    sp.addNumbers(values.begin(), values.end());

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    try {
        int arr2[] = {60, 70, 80, 90, 100, 110};
        std::vector<int> more(arr2, arr2 + 6);
        sp.addNumbers(more.begin(), more.end());
    } catch (const char* msg) {
        std::cout << "Exception: " << msg << std::endl;
    }
    return 0;
}