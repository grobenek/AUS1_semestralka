
// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//
// Created by Peter Szathmáry on 25/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMPRISLUSNOST_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMPRISLUSNOST_H


#include "CriteriumUzemnaJednotka.h"

class CriteriumPrislusnost : public CriteriumUzemnaJednotka<bool>
{
private:
    std::string nadradenaUzemnaJednotka;
public:
    CriteriumPrislusnost(std::string nadradenaUzemnaJednotka);

private:
public:
    bool evaluate(UzemnaJednotka* const& object) override;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMPRISLUSNOST_H
