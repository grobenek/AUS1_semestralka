//
// Created by Peter Szathmáry on 11/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMNAME_H
#define SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMNAME_H


#include "Criterium.h"
#include "../UzemnaJednotka.h"
#include "../structures/table/DuplicitySortedSequenceTable.h"


class CriteriumName : public Criterium<DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>*, ArrayList<UzemnaJednotka*>*>
{
private:
    std::string nameToEvaluate;
public:
    explicit CriteriumName(std::string  nameToEvaluate);

    ArrayList<UzemnaJednotka*>* evaluate(DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>*& object) override;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_CRITERIUMNAME_H