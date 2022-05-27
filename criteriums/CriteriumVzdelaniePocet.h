//
// Created by Peter Szathmáry on 15/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMVZDELANIEPOCET_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMVZDELANIEPOCET_H


#include "../uzemna_jednotka/UzemnaJednotka.h"
#include "../structures/table/DuplicitySortedSequenceTable.h"
#include "Criterium.h"
#include "../enums/VzdelanieTyp.h"
#include "CriteriumUzemnaJednotka.h"

class CriteriumVzdelaniePocet : public CriteriumUzemnaJednotka<int>
{
private:
 VzdelanieTyp vzdelanieTyp;

public:
    explicit CriteriumVzdelaniePocet(VzdelanieTyp vzdelanieTyp);

    int evaluate(UzemnaJednotka* const& object) override;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMVZDELANIEPOCET_H
