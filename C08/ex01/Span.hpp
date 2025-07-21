#pragma once
#include <iostream>
#include <vector>

class Span {
    private:
        std::vector<unsigned int> Span_numbers;
        unsigned int max;
        Span();
    public:
        Span(const Span& obj);
        Span(unsigned int N);
        Span& operator=(const Span& obj);
        ~Span();
        void addNumber(unsigned int N);
        int shortestSpan();
        int longestSpan();

        void addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last);
};