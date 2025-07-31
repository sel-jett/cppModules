#include "Span.hpp"
#include <algorithm>

Span::Span() {}

Span::Span(unsigned int N): max(N) {
}

Span::Span(const Span& obj): max(obj.max) {
    Span_numbers = obj.Span_numbers;
}

Span& Span::operator=(const Span& obj) {
    if (this != &obj) {
        max = obj.max;
        Span_numbers = obj.Span_numbers;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(unsigned int number) {
    if (Span_numbers.size() >= max)
        throw "you've reached the limit for the numbers";
    Span_numbers.push_back(number);
}

size_t Span::shortestSpan() {
    if (Span_numbers.size() < 2)
        throw "no span can be found";
    std::sort(Span_numbers.begin(), Span_numbers.end());
    unsigned int starting_Span = Span_numbers[1] - Span_numbers[0];

    for (unsigned int i = 0; i < Span_numbers.size() - 1; i++) {
        if (Span_numbers[i + 1] - Span_numbers[i] < starting_Span)
            starting_Span = Span_numbers[i + 1] - Span_numbers[i];
    }
    return starting_Span;
}

size_t Span::longestSpan() {
    if (Span_numbers.size() < 2)
        throw "no span can be found";

    std::sort(Span_numbers.begin(), Span_numbers.end());
    return Span_numbers[Span_numbers.size() - 1] - Span_numbers[0];
}


void Span::addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    size_t rangeSize = std::distance(first, last);
    if (Span_numbers.size() + rangeSize > max)
        throw "you've reached the limit for the numbers";
    Span_numbers.insert(Span_numbers.end(), first, last);
}