//
// Created by Peter Szathmáry on 11/05/2022.
//



#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUM_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUM_H

template<typename ObjectType, typename ResultType>
class Criterium
{
public:
    virtual ResultType evaluate(const ObjectType& object) = 0;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUM_H
