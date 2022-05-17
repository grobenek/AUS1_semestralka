//
// Created by Peter Szathmáry on 11/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMNAZOV_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMNAZOV_H


#include "Criterium.h"
#include "../uzemna_jednotka//UzemnaJednotka.h"
#include "../structures/table/DuplicitySortedSequenceTable.h"


class CriteriumNazov : public Criterium<DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>*, ArrayList<UzemnaJednotka*>*>
{
private:
    std::string nameToEvaluate;
public:
    explicit CriteriumNazov(std::string  nameToEvaluate);

    ArrayList<UzemnaJednotka*>* evaluate(DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>*& object) override;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMNAZOV_H
