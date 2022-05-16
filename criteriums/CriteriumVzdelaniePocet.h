//
// Created by Peter Szathmáry on 15/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMVZDELANIEPOCET_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMVZDELANIEPOCET_H


#include "../UzemnaJednotka/UzemnaJednotka.h"
#include "../structures/table/DuplicitySortedSequenceTable.h"
#include "Criterium.h"
#include "../enums/VzdelanieTyp.h"

class CriteriumVzdelaniePocet : public Criterium<DuplicitySortedSequenceTable < std::string, UzemnaJednotka*>*, ArrayList<UzemnaJednotka*>*>
{
private:
 int vzdelaniePocet;
 VzdelanieTyp vzdelanieTyp;

public:
    CriteriumVzdelaniePocet(int vzdelaniePocet, VzdelanieTyp vzdelanieTyp);

    ArrayList<UzemnaJednotka*>* evaluate(DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>*& object) override;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMVZDELANIEPOCET_H
