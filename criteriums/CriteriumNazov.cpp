//
// Created by Peter Szathmáry on 11/05/2022.
//

#include "CriteriumNazov.h"

#include <utility>


std::string CriteriumNazov::evaluate(UzemnaJednotka& object)
{
    if (object.getNazov() == this->nameToEvaluate)
    {
        return object.getNazov();
    }
}

CriteriumNazov::CriteriumNazov(std::string  nameToEvaluate) : nameToEvaluate(std::move(nameToEvaluate)),
                                                              Criterium<UzemnaJednotka*, std::string>()
{}
