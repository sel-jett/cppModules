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

int Span::shortestSpan() {
    if (Span_numbers.size() < 2)
        throw "no span can be found";

    unsigned int shortestDistance = Span_numbers[1] - Span_numbers[0];
    if (Span_numbers[0] > Span_numbers[1])
        shortestDistance = Span_numbers[0] - Span_numbers[1];
    
    for (size_t i = 0; i < Span_numbers.size(); i++) {
        for (size_t j = i + 1; j < Span_numbers.size(); j++) {
            unsigned int diff;
            if (Span_numbers[i] > Span_numbers[j])
                diff = Span_numbers[i] - Span_numbers[j];
            else
                diff = Span_numbers[j] - Span_numbers[i];
            
            if (diff < shortestDistance)
                shortestDistance = diff;
        }
    }
    return shortestDistance;
}

int Span::longestSpan() {
    if (Span_numbers.size() < 2)
        throw "no span can be found";

    unsigned int min = Span_numbers[0];
    unsigned int max = Span_numbers[0];
    
    for (size_t i = 1; i < Span_numbers.size(); i++) {
        if (Span_numbers[i] < min)
            min = Span_numbers[i];
        if (Span_numbers[i] > max)
            max = Span_numbers[i];
    }
    
    return max - min;
}


void Span::addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    size_t rangeSize = std::distance(first, last);
    if (Span_numbers.size() + rangeSize > max)
        throw "you've reached the limit for the numbers";
    Span_numbers.insert(Span_numbers.end(), first, last);
}