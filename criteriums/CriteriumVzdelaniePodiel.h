//
// Created by Peter Szathmáry on 15/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMVZDELANIEPODIEL_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMVZDELANIEPODIEL_H


#include "../UzemnaJednotka/UzemnaJednotka.h"
#include "../structures/table/DuplicitySortedSequenceTable.h"
#include "Criterium.h"
#include "../enums/VzdelanieTyp.h"

class CriteriumVzdelaniePodiel : public Criterium<DuplicitySortedSequenceTable < std::string, UzemnaJednotka*>*, ArrayList<UzemnaJednotka*>*>
{
private:
    int vzdelaniePocet;
    VzdelanieTyp vzdelanieTyp;

public:
    CriteriumVzdelaniePodiel(int vzdelaniePocet, VzdelanieTyp vzdelanieTyp);

    ArrayList<UzemnaJednotka*>* evaluate(DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>*& object) override;

};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMVZDELANIEPODIEL_H
