//
// Created by Peter Szathmáry on 15/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMVZDELANIEPODIEL_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMVZDELANIEPODIEL_H


#include "../uzemna_jednotka//UzemnaJednotka.h"
#include "../structures/table/DuplicitySortedSequenceTable.h"
#include "Criterium.h"
#include "../enums/VzdelanieTyp.h"
#include "CriteriumUzemnaJednotka.h"

class CriteriumVzdelaniePodiel : public CriteriumUzemnaJednotka<double >
{
private:
    VzdelanieTyp vzdelanieTyp;

public:
    explicit CriteriumVzdelaniePodiel(VzdelanieTyp vzdelanieTyp);

    double evaluate(UzemnaJednotka* const& object) override;

};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMVZDELANIEPODIEL_H
