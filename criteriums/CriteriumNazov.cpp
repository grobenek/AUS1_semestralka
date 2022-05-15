//
// Created by Peter Szathmáry on 11/05/2022.
//

#include "CriteriumNazov.h"

#include <utility>


ArrayList<UzemnaJednotka*>* CriteriumNazov::evaluate(DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>*& object)
{
    auto* result = new ArrayList<UzemnaJednotka*>;

    for (auto item : *object)
    {
        if (item->accessData()->getNazov() == this->nameToEvaluate)
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

CriteriumNazov::CriteriumNazov(std::string  nameToEvaluate) : nameToEvaluate(std::move(nameToEvaluate)),
                                                              Criterium<DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>*, ArrayList<UzemnaJednotka*>*>()
{}
