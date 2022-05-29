
// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//
// Created by Peter Szathmáry on 18/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMTYP_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMTYP_H


#include "Criterium.h"
#include "../uzemna_jednotka/UzemnaJednotka.h"
#include "CriteriumUzemnaJednotka.h"

class CriteriumTyp : public CriteriumUzemnaJednotka<UzemnaJednotkaTyp>
{
public:
    UzemnaJednotkaTyp evaluate(UzemnaJednotka* const& object) override;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMTYP_H
