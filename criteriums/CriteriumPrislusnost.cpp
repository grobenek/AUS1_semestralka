// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//
// Created by Peter Szathmáry on 25/05/2022.
//

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "CriteriumPrislusnost.h"

CriteriumPrislusnost::CriteriumPrislusnost(std::string nadradenaUzemnaJednotka)
{
    this->nadradenaUzemnaJednotka = nadradenaUzemnaJednotka;
}

bool CriteriumPrislusnost::evaluate(UzemnaJednotka* const& object)
{

    if (object != nullptr)
    {
        auto* uzemnaJednotka = object;
        while (uzemnaJednotka->getVyssiUzemnyCelok() != nullptr)
        {
            if (uzemnaJednotka->getVyssiUzemnyCelok()->getOfficialTitle() == this->nadradenaUzemnaJednotka)
            {
                return true;
            } else
            {
                uzemnaJednotka = uzemnaJednotka->getVyssiUzemnyCelok();
            }
        }
        return false;
    }
    throw std::invalid_argument("NullPointer in CriteriumPrislusnost.evaluate!");
}
