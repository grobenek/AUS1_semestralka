//
// Created by Peter Szathmáry on 17/05/2022.
//

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTEREQUALS_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTEREQUALS_H

#include "FilterWithCriterium.h"

template<typename ObjectType, typename ValueType, typename StructureType>
class FilterEquals : public FilterWithCriterium<ObjectType, ValueType, StructureType>
{
private:
    ValueType value;
public:
    FilterEquals(Criterium<ObjectType, ValueType>* criteriumToEvaluate, ValueType value) : FilterWithCriterium<ObjectType, ValueType, StructureType>(
            criteriumToEvaluate), value(value)
    {}

protected:
    bool passFilter(ValueType valueToEvaluate) override
    {
        return value == valueToEvaluate;
    }
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTEREQUALS_H
