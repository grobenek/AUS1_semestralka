//
// Created by Peter Szathmáry on 23/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_OBEC_H
#define SZATHMARY_SEMESTRALNA_PRACA_OBEC_H


#include "../structures/list/array_list.h"
#include "UzemnaJednotka.h"

class Obec : public UzemnaJednotka
{
public:
    Obec(const std::string& code, const std::string& officialTitle,
         const std::string& mediumTitle, const std::string& shortTitle, const std::string& note,
         structures::Array<int>* pVzdelanieUtriedene, structures::Array<int>* pVekUtriedene);

public:
    UzemnaJednotka* clone() override;

private:
    void pridajNizsiuUzemnuJednotku(UzemnaJednotka* uzemnaJednotka) override;

public:
    structures::ArrayList<UzemnaJednotka*>* dajNizsieUzemneJednotky() override;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_OBEC_H
