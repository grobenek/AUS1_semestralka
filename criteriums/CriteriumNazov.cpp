// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//
// Created by Peter Szathmáry on 11/05/2022.
//

#include "CriteriumNazov.h"

#include <utility>

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

std::string CriteriumNazov::evaluate(UzemnaJednotka* const& object)
{
    if (object != nullptr)
    {
        this->result = object->getOfficialTitle();
        return object->getOfficialTitle();
    }
    throw std::invalid_argument("nullpointer in CriteriumNazov.evaluate!");
}

CriteriumNazov::CriteriumNazov()
= default;
