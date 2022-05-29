// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//
// Created by Peter Szathmáry on 11/05/2022.
//



#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUM_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUM_H

template<typename ObjectType, typename ResultType>
class Criterium
{
protected:
    ResultType result;
public:
    virtual ResultType evaluate(const ObjectType& object) = 0;

    ResultType getResult() const
    {
        return result;
    }
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUM_H
