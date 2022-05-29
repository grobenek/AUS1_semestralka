// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//
// Created by Peter Szathmáry on 28/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMSTRING_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMSTRING_H


#include "Criterium.h"
#include "../uzemna_jednotka/UzemnaJednotka.h"

class CriteriumString : public Criterium<UzemnaJednotka*, std::string>
{
public:
    CriteriumString()
    = default;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMSTRING_H
