//
// Created by Peter Szathmáry on 17/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTERWITHCRITERIUM_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTERWITHCRITERIUM_H

#include "Filter.h"
#include "../criteriums/Criterium.h"

template<typename ObjetType, typename ValueType>
class FilterWithCriterium : public Filter<ObjetType>
{
private:
    Criterium<ObjetType, ValueType>* criterium;

public:
    explicit FilterWithCriterium(Criterium<ObjetType, ValueType>* criteriumToEvaluate);

    ~FilterWithCriterium();

    bool pass(ObjetType& object);

protected:
    virtual bool passFilter(ValueType value) = 0;
};

template<typename ObjetType, typename ValueType>
FilterWithCriterium<ObjetType, ValueType>::FilterWithCriterium(Criterium<ObjetType, ValueType>* criteriumToEvaluate)
{
    this->criterium = criteriumToEvaluate;
}

template<typename ObjetType, typename ValueType>
FilterWithCriterium<ObjetType, ValueType>::~FilterWithCriterium()
{
    delete this->criterium;
}

template<typename ObjetType, typename ValueType>
bool FilterWithCriterium<ObjetType, ValueType>::pass(ObjetType& object)
{
    return this->passFilter(criterium->evaluate(object));
}


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTERWITHCRITERIUM_H
