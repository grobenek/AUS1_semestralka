//
// Created by Peter Szathmáry on 25/05/2022.
//

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "CriteriumPrislusnost.h"

UzemnaJednotka* CriteriumPrislusnost::evaluate(UzemnaJednotka* const& object)
{
    if (object != nullptr)
    {
        return object->getVyssiUzemnyCelok();
    }
    throw std::invalid_argument("NullPointer in CriteriumPrislusnost.evaluate!");
}

CriteriumPrislusnost::CriteriumPrislusnost()
{}
