#include "Span.hpp"

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

// int Span::shortestSpan() {

// }

// int Span::longestSpan() {

// }