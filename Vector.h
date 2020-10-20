#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>

class Vector
{
public:
    Vector() // default constructor sets size to 0
    {
        size = 0;
    }
    Vector(int s) // makes size = s, //allocates s space, // makes all entries 0
    {
        size = s;
        entries = new int[size];
        for (int i = 0; i < size; i++)
        {
            entries[i] = 0;
        }
    }
    Vector(const Vector &rhs) // copy constructor // makes self a deep copy of rhs
    {
        size = rhs.size;
        entries = new int[size];
        for (int i = 0; i < size; i++)
        {
            entries[i] = rhs.entries[i];
        }
    }
    Vector operator=(const Vector &rhs) // makes self a deep copy of rhs
    {
        int i;
        size = rhs.size;
        entries = new int[size];
        for (i = 0; i < size; i++)
        {
            entries[i] = rhs.entries[i];
        }
        return *this;
    }
    ~Vector() // default destructor
    {
        delete[] entries;
    }
    void print() // Prints out the vector
    {
        if (size == 0)
        {
            std::cout << "[]";
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                std::cout << "[";
                std::cout << entries[i];
                std::cout << "]";
            }
        }
        std::cout << "\n";
    }
    void set(int val, int pos) // if 0 <=pos<size // stores val at pos in entries
    {
        if (0 <= pos < size)
        {
            entries[pos] = val;
        }
    }

private:
    int size; //sets the # of elements used
    int *entries;
};
#endif
