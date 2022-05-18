//
// Created by Peter Szathmáry on 11/05/2022.
//

#include "CriteriumNazov.h"

#include <utility>


std::string CriteriumNazov::evaluate(UzemnaJednotka*& object)
{
    return object->getNazov();
}

CriteriumNazov::CriteriumNazov()
{
}
