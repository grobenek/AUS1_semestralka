//
// Created by Peter Szathmáry on 15/05/2022.
//

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "CriteriumVzdelaniePocet.h"

CriteriumVzdelaniePocet::CriteriumVzdelaniePocet(VzdelanieTyp vzdelanieTyp) : vzdelanieTyp(vzdelanieTyp)
{}

int
CriteriumVzdelaniePocet::evaluate(UzemnaJednotka* const& object)
{
    if (object != nullptr)
    {
        if (object->getVzdelanieUtriedene() == nullptr)
        {
            return -1;
        }
        this->result = object->getVzdelanieUtriedene()->at(vzdelanieTyp);
        int result = object->getVzdelanieUtriedene()->at(vzdelanieTyp);

        return result;
    }
    throw std::invalid_argument("nullpointer in CriteriumVzdelaniePocet.evaluate!");
}
