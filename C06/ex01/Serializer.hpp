#pragma once
#include <iostream>
#include <stdint.h>


typedef struct t_Data {
    int i;
} Data;

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& obj);
        Serializer& operator=(const Serializer& obj);
    public:
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};