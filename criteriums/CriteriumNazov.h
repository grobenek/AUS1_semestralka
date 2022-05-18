//
// Created by Peter Szathmáry on 11/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMNAZOV_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMNAZOV_H


#include "Criterium.h"
#include "../uzemna_jednotka//UzemnaJednotka.h"
#include "../structures/table/DuplicitySortedSequenceTable.h"


class CriteriumNazov : public Criterium<UzemnaJednotka*, std::string>
{
private:
    std::string nameToEvaluate;
public:
    explicit CriteriumNazov(std::string  nameToEvaluate);

    std::string evaluate(UzemnaJednotka*& object) override;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMNAZOV_H
