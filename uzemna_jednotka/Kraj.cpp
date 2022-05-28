//
// Created by Peter Szathmáry on 23/05/2022.
//

#include "Kraj.h"

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

Kraj::Kraj(const std::string& code, const std::string& officialTitle, const std::string& mediumTitle,
           const std::string& shortTitle, const std::string& note) : UzemnaJednotka(code, officialTitle, mediumTitle,
                                                                                    shortTitle, note)
{
    this->typ = KRAJ;

    this->vzdelanieUtriedene = new structures::Array<int>(8);
    this->vekUtriedene = new structures::Array<int>(202);
    this->nizsieUzemneJednotky = new ArrayListWithObject<UzemnaJednotka*>;
}

UzemnaJednotka* Kraj::clone()
{
    auto* clone = new Kraj(this->code, this->officialTitle, this->mediumTitle, this->shortTitle, this->note);
    clone->setVyssiUzemnyCelok(this->getVyssiUzemnyCelok());
    return clone;
}

void Kraj::pridajNizsiuUzemnuJednotku(UzemnaJednotka* uzemnaJednotka)
{
    auto* okres = dynamic_cast<Okres*>(uzemnaJednotka);
    if (okres != nullptr)
    {
        this->nizsieUzemneJednotky->add(okres);

        if (this->vzdelanieUtriedene != nullptr && this->vekUtriedene != nullptr)
        {
            for (int i = 0; i < this->getVzdelanieUtriedene()->size(); ++i)
            {
                this->vzdelanieUtriedene->at(i) += okres->getVzdelanieUtriedene()->at(i);
            }

            for (int i = 0; i < this->getVekUtriedene()->size(); ++i)
            {
                this->vekUtriedene->at(i) += okres->getVekUtriedene()->at(i);
            }
        }
    } else
    {
        throw std::invalid_argument("nullPointer in Okres.pridajOkres");
    }
}

structures::ArrayList<UzemnaJednotka*>* Kraj::dajNizsieUzemneJednotky()
{
    return this->nizsieUzemneJednotky;
}
