//
// Created by Peter Szathmáry on 17/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTEREQUALS_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTEREQUALS_H

#include "FilterWithCriterium.h"

template<typename ObjectType, typename ValueType>
class FilterEquals : public FilterWithCriterium<ObjectType, ValueType>
{
private:
    ValueType value;
public:
    FilterEquals(Criterium<ObjectType, ValueType>* criteriumToEvaluate, ValueType value) : FilterWithCriterium<ObjectType, ValueType>(
            criteriumToEvaluate), value(value)
    {}

protected:
    bool passFilter(ValueType valueToEvaluate) override
    {
        return value == valueToEvaluate;
    }
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTEREQUALS_H
