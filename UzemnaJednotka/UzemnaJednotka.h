//
// Created by Peter Szathmáry on 11/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_UZEMNAJEDNOTKA_H
#define SZATHMARY_SEMESTRALNA_PRACA_UZEMNAJEDNOTKA_H

#include "../structures/list/array_list.h"
#include "../enums/UzemnaJednotkaTyp.h"


class UzemnaJednotka
{
protected:
    structures::ArrayList<int>* vzdelanie;
    structures::Array<int>* vzdelanieUtriedene;
    structures::ArrayList<int>* vek;
    structures::Array<int>* vekUtriedene;
    int pocetObyvatelov;
    UzemnaJednotkaTyp typ;
    UzemnaJednotka* vyssiUzemnyCelok;
    std::string nazov;
public:
    UzemnaJednotka(structures::ArrayList<int>* vek, structures::ArrayList<int>* vzdelanie, std::string nazov, UzemnaJednotkaTyp typ);
    //TODO uzemna jednotka si sama prepocita vsetky vzdelanie aj veky a ostatne veci si z nej budu tahat len vysledky
    void setVyssiUzemnyCelok(UzemnaJednotka* pVyssiUzemnyCelok);

    ~UzemnaJednotka();

    structures::ArrayList<int>* getVzdelanie() const;

    structures::ArrayList<int>* getVek() const;

    void setVzdelanieUtriedene(structures::Array<int>* pVzdelanieUtriedene);

    int getPocetObyvatelov() const;

    UzemnaJednotkaTyp getTyp() const;

    UzemnaJednotka* getVyssiUzemnyCelok() const;

    const std::string& getNazov() const;

    structures::Array<int>* getVzdelanieUtriedene() const;

    structures::Array<int>* getVekUtriedene() const;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_UZEMNAJEDNOTKA_H
