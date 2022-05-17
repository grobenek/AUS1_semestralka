//
// Created by Peter Szathmáry on 17/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTER_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTER_H

template<typename ObjectType>
class Filter
{
    bool evaluate(const ObjectType& object) = 0;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTER_H
