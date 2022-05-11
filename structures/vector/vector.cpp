#include "vector.h"
#include "../utils.h"
#include <cstdlib>
#include <cstring>

namespace structures
{
    Vector::Vector(size_t size) :
            memory_(std::calloc(size, 1)),
            size_(size)
    {
    }

    Vector::Vector(Vector& other) :
            Vector(other.size_)
    {
        std::memcpy(memory_, other.memory_, other.size_);
    }

    Vector::~Vector()
    {
        std::free(memory_);

        memory_ = nullptr;
        size_ = 0; // pre ucely debugovania to vycisti aj pamat pri free
    }

    size_t Vector::size()
    {
        return size_;
    }

    Structure& Vector::assign(Structure& other)
    {
        if (this != &other)
        {
            //pretypujem structure na vector
            Vector& otherVector = dynamic_cast<Vector&>(other);
            //vytvori novu pamat s velkostou otherVector
            size_ = otherVector.size_;
            memory_ = std::realloc(memory_, otherVector.size_);
            std::memcpy(memory_, otherVector.memory_, otherVector.size_);
        }
        return *this;
    }

    bool Vector::equals(Structure& other)
    {
        if (this != &other)
        {
            //dal som tu pointre, lebo to nespadne, ale vrati nullptr ak pretypovavam zle
            Vector* otherVector = dynamic_cast<Vector*>(&other); // dynamic cast je na castovanie v ramci dedicnosti a struktur
            if (otherVector == nullptr)
            {
                return false;
            }

            return this->size_ == otherVector->size_ &&
                   std::memcmp(this->memory_, otherVector->memory_, size_) ==
                   0; // porovnavam ci su pamata rovnake cez xor, ak su 0 su rovnake, inac nie
        } else
        {
            return true;
        }
    }

    byte& Vector::operator[](int index)
    {
        return this->at(index);
    }

    //dereference vs pointer POZRI
    byte& Vector::at(int index)
    {
        Utils::rangeCheckExcept(index, size_, "Invalid index!");//skontroluje ci je index spravny, inac vyhodi vynimku
        byte* firstByte = reinterpret_cast<byte*>(memory_); // brutalny cast, pretypuje stale, nic nekontroluje
        return *(firstByte + index);
    }

    // ak je & pri type, vravi ze ide o referenciu a ak je pri vyraze tak hovori o adrese
    void Vector::copy(Vector& src, int srcStartIndex, Vector& dest, int destStartIndex, int length)
    {
        Utils::rangeCheckExcept(srcStartIndex, src.size_, "Memory leak from source vector!");
        Utils::rangeCheckExcept(destStartIndex, dest.size_, "Memory leak from destination vector!");
        Utils::rangeCheckExcept(srcStartIndex + length, src.size() + 1, "Invalid index from source vector!");
        Utils::rangeCheckExcept(destStartIndex + length, dest.size() + 1, "Invalid index from destination vector!");


        if (&src == &dest &&
            std::abs(srcStartIndex - destStartIndex) < length) // porovnavam adresy aby som zistil ci su rovnake
        {
            std::memmove(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
        } else
        {
            std::memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
        }
    }

    byte* Vector::getBytePointer(int index)
    {
        Utils::rangeCheckExcept(index, size_, "Invalid index!");//skontroluje ci je index spravny, inac vyhodi vynimku
        byte* firstByte = reinterpret_cast<byte*>(memory_); // brutalny cast, pretypuje stale, nic nekontroluje
        return (firstByte + index);
    }
}