//
// Created by Peter Szathmáry on 23/05/2022.
//

#include "Okres.h"

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

Okres::Okres(const std::string& code, const std::string& officialTitle, const std::string& mediumTitle,
             const std::string& shortTitle, const std::string& note) : UzemnaJednotka(code, officialTitle, mediumTitle,
                                                                                      shortTitle, note)
{
    this->typ = OKRES;

    this->vzdelanieUtriedene = new structures::Array<int>(8);
    this->vekUtriedene = new structures::Array<int>(202);
    this->nizsieUzemneJednotky = new ArrayListWithObject<UzemnaJednotka*>();
}

UzemnaJednotka* Okres::clone()
{
    auto* clone = new Okres(this->code, this->officialTitle, this->mediumTitle, this->shortTitle, this->note);
    if (this->vekUtriedene != nullptr && this->vzdelanieUtriedene != nullptr && this->pocetObyvatelov != 0)
    {
        clone->setVekUtriedene(new structures::Array<int>(*this->vekUtriedene));
        clone->setVzdelanieUtriedene(new structures::Array<int>(*this->getVzdelanieUtriedene()));
    }
    clone->setVyssiUzemnyCelok(this->getVyssiUzemnyCelok());
    return clone;
}

void Okres::pridajNizsiuUzemnuJednotku(UzemnaJednotka* uzemnaJednotka)
{
    auto* obec = dynamic_cast<Obec*>(uzemnaJednotka);
    if (obec != nullptr)
    {
        this->nizsieUzemneJednotky->add(obec);
        if (obec->getVzdelanieUtriedene() == nullptr && obec->getVekUtriedene() == nullptr)
        {
            return;
        }
        if (this->vzdelanieUtriedene != nullptr && this->vekUtriedene != nullptr)
        {
            for (int i = 0; i < this->getVzdelanieUtriedene()->size(); ++i)
            {
                this->vzdelanieUtriedene->at(i) += obec->getVzdelanieUtriedene()->at(i);
            }

            for (int i = 0; i < this->getVekUtriedene()->size(); ++i)
            {
                this->vekUtriedene->at(i) += obec->getVekUtriedene()->at(i);
            }
        }
    } else
    {
        throw std::invalid_argument("Nullpointer in Okres.pridajObec");
    }
}

structures::ArrayList<UzemnaJednotka*>* Okres::dajNizsieUzemneJednotky()
{
    return this->nizsieUzemneJednotky;
}
