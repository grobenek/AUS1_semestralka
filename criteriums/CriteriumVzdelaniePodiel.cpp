//
// Created by Peter Szathmáry on 15/05/2022.
//

#include "CriteriumVzdelaniePodiel.h"

CriteriumVzdelaniePodiel::CriteriumVzdelaniePodiel(int vzdelaniePocet, VzdelanieTyp vzdelanieTyp) : vzdelaniePocet(
        vzdelaniePocet), vzdelanieTyp(vzdelanieTyp)
{}

ArrayList<UzemnaJednotka*>*
CriteriumVzdelaniePodiel::evaluate(DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>*& object)
{
    auto* result = new ArrayList<UzemnaJednotka*>;

    for (auto item: *object)
    {
        if ((item->accessData()->getVzdelanieUtriedene()->at(vzdelanieTyp) / item->accessData()->getPocetObyvatelov()) *
            100 == vzdelaniePocet)
        {
            result->add(item->accessData());
        }
    }

    if (result->size() == 0)
    {
        delete result;
        return nullptr;
    }

    return result;
}
