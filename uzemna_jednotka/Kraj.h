//
// Created by Peter Szathmáry on 23/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_KRAJ_H
#define SZATHMARY_SEMESTRALNA_PRACA_KRAJ_H


#include "UzemnaJednotka.h"
#include "Okres.h"

class Kraj : public UzemnaJednotka
{
public:
    UzemnaJednotka* clone() override;

public:
    Kraj(const std::string& code, const std::string& officialTitle, const std::string& mediumTitle,
         const std::string& shortTitle, const std::string& note);

    void pridajNizsiuUzemnuJednotku(UzemnaJednotka* uzemnaJednotka) override;

    structures::ArrayList<UzemnaJednotka*>* dajNizsieUzemneJednotky() override;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_KRAJ_H
