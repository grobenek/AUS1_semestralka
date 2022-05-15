//
// Created by Peter Szathmáry on 11/05/2022.
//

#include "UzemnaJednotka.h"
#include "enums/VzdelanieTyp.h"

#include <utility>

UzemnaJednotka::UzemnaJednotka(structures::ArrayList<int>* vek, structures::ArrayList<int>* vzdelanie,
                               std::string nazov, UzemnaJednotkaTyp typ)
{
    this->vek = vek;
    this->vzdelanie = vzdelanie;
    this->nazov = std::move(nazov);
    this->typ = typ;
    this->vzdelanieUtriedene = new structures::Array<int>(8);
    this->vekUtriedene = new structures::Array<int>(202);
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

structures::Array<int>* UzemnaJednotka::getVzdelanieUtriedene() const
{
    return vzdelanieUtriedene;
}

structures::Array<int>* UzemnaJednotka::getVekUtriedene() const
{
    return vekUtriedene;
}

int UzemnaJednotka::getPocetObyvatelov() const
{
    return pocetObyvatelov;
}
