//
// Created by Peter Szathmáry on 23/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_OKRES_H
#define SZATHMARY_SEMESTRALNA_PRACA_OKRES_H


#include "UzemnaJednotka.h"
#include "Obec.h"

class Okres : public UzemnaJednotka
{
public:
    UzemnaJednotka* clone() override;

public:
    Okres(const std::string& code, const std::string& officialTitle, const std::string& mediumTitle,
          const std::string& shortTitle, const std::string& note);

    void pridajNizsiuUzemnuJednotku(UzemnaJednotka* uzemnaJednotka) override;

    ArrayListWithObject<UzemnaJednotka*>* dajNizsieUzemneJednotky() override;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_OKRES_H
