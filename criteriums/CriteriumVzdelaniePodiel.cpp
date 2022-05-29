

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//
// Created by Peter Szathmáry on 15/05/2022.
//

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "CriteriumVzdelaniePodiel.h"

CriteriumVzdelaniePodiel::CriteriumVzdelaniePodiel(VzdelanieTyp vzdelanieTyp) : vzdelanieTyp(vzdelanieTyp)
{}

double
CriteriumVzdelaniePodiel::evaluate(UzemnaJednotka* const& object)
{
    if (object != nullptr)
    {
        if (object->getVzdelanieUtriedene() == nullptr)
        {
            return -1.0;
        }

        double result = (1.0 * object->getVzdelanieUtriedene()->at(vzdelanieTyp) / object->getPocetObyvatelov()) *
                        100;
        this->result = result;
        return result;
    }
    throw std::invalid_argument("nullpointer in criteriumVzdelaniePodiel.evaluate!");
}
