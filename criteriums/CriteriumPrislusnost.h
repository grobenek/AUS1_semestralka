//
// Created by Peter Szathmáry on 25/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMPRISLUSNOST_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMPRISLUSNOST_H


#include "CriteriumUzemnaJednotka.h"
#include "CriteriumString.h"

class CriteriumPrislusnost : public CriteriumString
{
public:
    CriteriumPrislusnost();

private:
public:
    std::string evaluate(UzemnaJednotka* const& object) override;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMPRISLUSNOST_H
