//
// Created by Peter Szathmáry on 11/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMNAZOV_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMNAZOV_H


#include "Criterium.h"
#include "../uzemna_jednotka//UzemnaJednotka.h"
#include "../structures/table/DuplicitySortedSequenceTable.h"
#include "CriteriumUzemnaJednotka.h"


class CriteriumNazov : public CriteriumUzemnaJednotka<std::string>
{
public:
    explicit CriteriumNazov();

    std::string evaluate(UzemnaJednotka* const& object) override;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMNAZOV_H
