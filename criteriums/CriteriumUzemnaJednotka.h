//
// Created by Peter Szathmáry on 23/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMUZEMNAJEDNOTKA_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMUZEMNAJEDNOTKA_H


#include "Criterium.h"
#include "../uzemna_jednotka/UzemnaJednotka.h"

template<typename ValueType>
class CriteriumUzemnaJednotka : public Criterium<UzemnaJednotka*, ValueType>
{
public:
    CriteriumUzemnaJednotka() = default;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMUZEMNAJEDNOTKA_H
