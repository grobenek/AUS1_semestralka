//
// Created by Peter Szathmáry on 23/05/2022.
//

#include "Obec.h"

#include <utility>

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

Obec::Obec(const std::string& code, const std::string& officialTitle,
           const std::string& mediumTitle, const std::string& shortTitle, const std::string& note,
           structures::Array<int>* pVzdelanieUtriedene, structures::Array<int>* pVekUtriedene)
        : UzemnaJednotka(code, officialTitle, mediumTitle, shortTitle,
                         note)
{
    this->typ = OBEC;
    this->vzdelanieUtriedene = pVzdelanieUtriedene;
    this->vekUtriedene = pVekUtriedene;

    if (this->vzdelanieUtriedene != nullptr)
    {
        for (int i = 0; i < this->vzdelanieUtriedene->size(); ++i)
        {
            this->pocetObyvatelov += this->vzdelanieUtriedene->at(i);
        }
    }
}

UzemnaJednotka* Obec::clone()
{
    Obec* obecClone;
    if (this->vzdelanieUtriedene != nullptr && this->vekUtriedene != nullptr)
    {
        obecClone = new Obec(this->code, this->officialTitle, this->mediumTitle, this->shortTitle, this->note,
                             new structures::Array<int>(*this->vzdelanieUtriedene),
                             new structures::Array<int>(*this->vekUtriedene));
    } else
    {
        obecClone = new Obec(this->code, this->officialTitle, this->mediumTitle, this->shortTitle, this->note,
                             nullptr,
                             nullptr);
    }
    obecClone->setVyssiUzemnyCelok(this->getVyssiUzemnyCelok());
    return obecClone;
}

void Obec::pridajNizsiuUzemnuJednotku(UzemnaJednotka* uzemnaJednotka)
{
    throw std::logic_error("pridajNizsiuUzemnuJednotku in Obec is not implemented!");
}

structures::ArrayList<UzemnaJednotka*>* Obec::dajNizsieUzemneJednotky()
{
    throw std::logic_error("dajNizsieUzemneJednotky in Obec is not implemented!");
}
