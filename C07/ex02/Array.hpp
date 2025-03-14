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
        const T &operator[](size_t index) const;
        size_t size(void) const;
};

template<typename T>
Array<T>::Array(void) : array(NULL), length(0) {}

template<typename T>
Array<T>::Array(unsigned int n): array(NULL), length(0)
{
    try{
        array = new T[n];
        length = n;
    }
    catch (std::bad_alloc&)
    {
        length = 0; 
        throw ;
    }
}

template<typename T>
Array<T>::Array(const Array<T> &obj): array(NULL), length(0)
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
        T* temp = NULL;
        try {
            if (obj.length > 0) {
                temp  = new T[obj.length];
                for (size_t i = 0; i < obj.length; i++) {
                    temp[i] = obj.array[i];
                }
            }
            delete[] this->array;
            array = temp;
            length = obj.length;
        } catch (std::bad_alloc&) {
            delete[] temp;
            throw;
        }
    }
    return (*this);
}

template<typename T>
T &Array<T>::operator[](size_t index)
{
    if (index >= length)
        throw std::out_of_range("index out of bound");
    return (array[index]);
}

template<typename T>
const T &Array<T>::operator[](size_t index) const
{
    if (index >= length)
        throw std::out_of_range("index out of bound");
    return (array[index]);
}

template<typename T>
size_t Array<T>::size(void) const
{
    return length;
}