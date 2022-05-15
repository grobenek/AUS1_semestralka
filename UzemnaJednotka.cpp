//
// Created by Peter Szathmáry on 11/05/2022.
//

#include "UzemnaJednotka.h"

#include <utility>

UzemnaJednotka::UzemnaJednotka(structures::ArrayList<int>* vek, structures::ArrayList<int>* vzdelanie,
                               std::string nazov, UzemnaJednotkaTyp typ)
{
    this->vek = vek;
    this->vzdelanie = vzdelanie;
    this->nazov = std::move(nazov);
    this->typ = typ;
}

void UzemnaJednotka::setVyssiUzemnyCelok(UzemnaJednotka* pVyssiUzemnyCelok)
{
    this->vyssiUzemnyCelok = pVyssiUzemnyCelok;
}

structures::ArrayList<int>* UzemnaJednotka::getVzdelanie() const
{
    return vzdelanie;
}

structures::ArrayList<int>* UzemnaJednotka::getVek() const
{
    return vek;
}

UzemnaJednotkaTyp UzemnaJednotka::getTyp() const
{
    return typ;
}

UzemnaJednotka* UzemnaJednotka::getVyssiUzemnyCelok() const
{
    return vyssiUzemnyCelok;
}

const std::string& UzemnaJednotka::getNazov() const
{
    return nazov;
}
