// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//
// Created by Peter Szathmáry on 18/05/2022.
//

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "CriteriumTyp.h"

UzemnaJednotkaTyp CriteriumTyp::evaluate(UzemnaJednotka* const& object)
{
    this->result = object->getTyp();
    return object->getTyp();
}

