//
// Created by Peter Szathmáry on 15/05/2022.
//

#include "CriteriumVzdelaniePodiel.h"

CriteriumVzdelaniePodiel::CriteriumVzdelaniePodiel(VzdelanieTyp vzdelanieTyp) : vzdelanieTyp(vzdelanieTyp)
{}

double
CriteriumVzdelaniePodiel::evaluate(UzemnaJednotka*& object)
{
    int result = (object->getVzdelanieUtriedene()->at(vzdelanieTyp) / object->getPocetObyvatelov()) *
                 100;
    return result;
}
