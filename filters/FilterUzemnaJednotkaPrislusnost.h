//
// Created by Peter Szathmáry on 25/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTERUZEMNAJEDNOTKAPRISLUSNOST_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTERUZEMNAJEDNOTKAPRISLUSNOST_H


#include "../uzemna_jednotka/UzemnaJednotka.h"
#include "../structures/table/DuplicitySortedSequenceTable.h"
#include "FilterEquals.h"
#include "../structures/list/ArrayListWithObject.h"
#include "../criteriums/CriteriumPrislusnost.h"

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

class FilterUzemnaJednotkaPrislusnost
        : public FilterEquals<UzemnaJednotka*, UzemnaJednotka*, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>>
{
public:
    explicit FilterUzemnaJednotkaPrislusnost(UzemnaJednotka* value)
    : FilterEquals(new CriteriumPrislusnost(), value)
    {}

protected:
    bool passFilter(UzemnaJednotka* valueToEvaluate) override
    {
        return FilterEquals::passFilter(valueToEvaluate);
    }

    List<UzemnaJednotka*>*
    passFilterStructure(DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& structure) override
    {
    }
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTERUZEMNAJEDNOTKAPRISLUSNOST_H
