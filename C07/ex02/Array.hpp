#pragma once
#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T *array;
        size_t length;

    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array &obj);
        ~Array();
        Array<T> &operator=(const Array<T> &obj);
        T &operator[](size_t index);
        size_t size(void) const;
};

template<typename T>
Array<T>::Array(void) : array(NULL), length(0) {}

template<typename T>
Array<T>::Array(unsigned int n)
{
    length = n;
    try{
        array = new T[n];
    }
    catch (std::bad_alloc)
    {
        std::cerr << "Bad alloc" << std::endl;
    }
}

template<typename T>
Array<T>::Array(const Array<T> &obj)
{
    *this = obj;
}

template<typename T>
Array<T>::~Array()
{
    delete[] array;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &obj)
{
    if (this != &obj)
    {
        delete[] array;
        length = obj.length;
        try {
            array = new T[length];
        } catch (std::bad_alloc) {
            std::cerr << "Bad alloc" << std::endl;
            length = 0;
            array = NULL;
        }
        for (size_t i = 0; i < length; i++) {
            array[i] = obj.array[i];
        }
    }
    return (*this);
}

template<typename T>
T &Array<T>::operator[](size_t index)
{
    if (index > length)
        throw std::exception("index out of bound");
    return (array[index]);
}

template<typename T>
size_t Array<T>::size(void) const
{
    return length;
}