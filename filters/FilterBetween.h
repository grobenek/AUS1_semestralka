//
// Created by Peter Szathmáry on 17/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTERBETWEEN_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTERBETWEEN_H

#include "FilterWithCriterium.h"

template<typename ObjectType, typename ValueType>
class FilterBetween : public FilterWithCriterium<ObjectType, ValueType>
{
private:
    ValueType valueMax;
    ValueType valueMin;

public:
    FilterBetween(Criterium<ObjectType, ValueType>* criteriumToEvaluate, ValueType valueMax, ValueType valueMin)
            : FilterWithCriterium<ObjectType, ValueType>(criteriumToEvaluate), valueMax(valueMax), valueMin(valueMin)
    {}

protected:
    bool passFilter(ValueType value) override
    {
     return value <= valueMax && value >= valueMin;
    }
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTERBETWEEN_H
