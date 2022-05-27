//
// Created by Peter Szathmáry on 17/05/2022.
//

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTERBETWEEN_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTERBETWEEN_H

#include "FilterWithCriterium.h"

template<typename ObjectType, typename ValueType, typename StructureType>
class FilterBetween : public FilterWithCriterium<ObjectType, ValueType, StructureType>
{
private:
    ValueType valueMax;
    ValueType valueMin;

public:
    FilterBetween(Criterium<ObjectType, ValueType>* criteriumToEvaluate, ValueType valueMin, ValueType valueMax)
            : FilterWithCriterium<ObjectType, ValueType, StructureType>(criteriumToEvaluate), valueMax(valueMax), valueMin(valueMin)
    {}

protected:
    bool passFilter(ValueType value) override
    {
     return value <= valueMax && value >= valueMin;
    }


};


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTERBETWEEN_H
