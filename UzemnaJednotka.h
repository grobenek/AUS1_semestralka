//
// Created by Peter Szathmáry on 11/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_UZEMNAJEDNOTKA_H
#define SZATHMARY_SEMESTRALNA_PRACA_UZEMNAJEDNOTKA_H

#include "structures/list/array_list.h"
#include "enums/UzemnaJednotkaTyp.h"


class UzemnaJednotka
{
protected:
    structures::ArrayList<int>* vzdelanie;
    structures::ArrayList<int>* vek;
    UzemnaJednotkaTyp typ;
    UzemnaJednotka* vyssiUzemnyCelok;
    std::string nazov;
public:
    UzemnaJednotka(structures::ArrayList<int>* vek, structures::ArrayList<int>* vzdelanie, std::string nazov, UzemnaJednotkaTyp typ);
    void setVyssiUzemnyCelok(UzemnaJednotka* pVyssiUzemnyCelok);
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_UZEMNAJEDNOTKA_H
