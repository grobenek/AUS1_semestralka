//
// Created by Peter Szathmáry on 11/05/2022.
//

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifndef SZATHMARY_SEMESTRALNA_PRACA_UZEMNAJEDNOTKA_H
#define SZATHMARY_SEMESTRALNA_PRACA_UZEMNAJEDNOTKA_H

#include <utility>

#include "../structures/list/array_list.h"
#include "../enums/UzemnaJednotkaTyp.h"
#include "../structures/list/ArrayListWithObject.h"


class UzemnaJednotka
{
protected:
    int pocetObyvatelov = 0;
    UzemnaJednotkaTyp typ;
    UzemnaJednotka* vyssiUzemnyCelok = nullptr;

    structures::Array<int>* vzdelanieUtriedene = nullptr;
    structures::Array<int>* vekUtriedene = nullptr;

    structures::ArrayList<UzemnaJednotka*>* nizsieUzemneJednotky = nullptr;

    std::string code;
    std::string officialTitle;
    std::string mediumTitle;
    std::string shortTitle;
    std::string note;

public:

    UzemnaJednotka(std::string code, std::string officialTitle, std::string mediumTitle,
                   std::string shortTitle, std::string note) : code(std::move(code)),
                                                               officialTitle(std::move(officialTitle)),
                                                               mediumTitle(std::move(mediumTitle)),
                                                               shortTitle(std::move(shortTitle)), note(std::move(note))
    {
        this->typ = NEZARADENA;
    }

    virtual void pridajNizsiuUzemnuJednotku(UzemnaJednotka* uzemnaJednotka) = 0;

    virtual structures::ArrayList<UzemnaJednotka*>* dajNizsieUzemneJednotky() = 0;

    virtual ~UzemnaJednotka()
    {
        delete this->vzdelanieUtriedene;
        delete this->vekUtriedene;
        delete this->nizsieUzemneJednotky;
    }

    virtual UzemnaJednotka* clone() = 0;


    structures::Array<int>* getVzdelanieUtriedene() const
    {
        return this->vzdelanieUtriedene;
    }

    structures::Array<int>* getVekUtriedene() const
    {
        return vekUtriedene;
    }

    const std::string& getCode() const
    {
        return code;
    }

    const std::string& getOfficialTitle() const
    {
        return officialTitle;
    }

    void setVzdelanieUtriedene(structures::Array<int>* pVzdelanieUtriedene)
    {
        delete this->vzdelanieUtriedene;
        UzemnaJednotka::vzdelanieUtriedene = pVzdelanieUtriedene;
        this->pocetObyvatelov = 0;
        for (int i = 0; i < pVzdelanieUtriedene->size(); ++i)
        {
            this->getVyssiUzemnyCelok()->getVzdelanieUtriedene()->at(i) += pVzdelanieUtriedene->at(i);
            this->getVyssiUzemnyCelok()->getVyssiUzemnyCelok()->getVzdelanieUtriedene()->at(i) += pVzdelanieUtriedene->at(i);
            this->pocetObyvatelov += pVzdelanieUtriedene->at(i);
        }
    }

    void setVekUtriedene(structures::Array<int>* pVekUtriedene)
    {
        delete this->vekUtriedene;
        UzemnaJednotka::vekUtriedene = pVekUtriedene;
        this->pocetObyvatelov = 0;
        for (int i = 0; i < pVekUtriedene->size() - 2; ++i)
        {
            this->getVyssiUzemnyCelok()->getVekUtriedene()->at(i) += pVekUtriedene->at(i + 2);
            this->getVyssiUzemnyCelok()->getVyssiUzemnyCelok()->getVekUtriedene()->at(i) += pVekUtriedene->at(i + 2);
            this->pocetObyvatelov += pVekUtriedene->at(i);
        }
    }

    const std::string& getMediumTitle() const
    {
        return mediumTitle;
    }

    const std::string& getShortTitle() const
    {
        return shortTitle;
    }

    const std::string& getNote() const
    {
        return note;
    }

    int getPocetObyvatelov() const
    {
        return pocetObyvatelov;
    }

    UzemnaJednotkaTyp getTyp() const
    {
        return typ;
    }

    UzemnaJednotka* getVyssiUzemnyCelok() const
    {
        return vyssiUzemnyCelok;
    }

    void setVyssiUzemnyCelok(UzemnaJednotka* pVyssiUzemnyCelok)
    {
        UzemnaJednotka::vyssiUzemnyCelok = pVyssiUzemnyCelok;
    }
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_UZEMNAJEDNOTKA_H
