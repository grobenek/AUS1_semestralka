//
// Created by Peter Szathmáry on 15/05/2022.
//

#include "CriteriumVzdelaniePocet.h"

CriteriumVzdelaniePocet::CriteriumVzdelaniePocet(VzdelanieTyp vzdelanieTyp) : vzdelanieTyp(vzdelanieTyp)
{}

int
CriteriumVzdelaniePocet::evaluate(UzemnaJednotka& object)
{
    int result = object.getVzdelanieUtriedene()->at(vzdelanieTyp);

    return result;
}
