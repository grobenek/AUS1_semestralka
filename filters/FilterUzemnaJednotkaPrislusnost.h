
// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//
// Created by Peter Szathmáry on 25/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTERUZEMNAJEDNOTKAPRISLUSNOST_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTERUZEMNAJEDNOTKAPRISLUSNOST_H


#include <utility>

#include "../uzemna_jednotka/UzemnaJednotka.h"
#include "../structures/table/DuplicitySortedSequenceTable.h"
#include "FilterEquals.h"
#include "../structures/list/ArrayListWithObject.h"
#include "../criteriums/CriteriumPrislusnost.h"

class FilterUzemnaJednotkaPrislusnost
: public FilterEquals<UzemnaJednotka*, bool, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>>
{
public:
    explicit FilterUzemnaJednotkaPrislusnost(std::string nazovNadradenejUzemnejJednotky)
    : FilterEquals(new CriteriumPrislusnost(nazovNadradenejUzemnejJednotky), true)
    {}

protected:
    bool passFilter(bool valueToEvaluate) override
    {
        return FilterEquals::passFilter(valueToEvaluate);
    }

    List<UzemnaJednotka*>*
    passFilterStructure(DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& structure) override
    {
        auto* result = new ArrayListWithObject<UzemnaJednotka*>();

        for (auto* item: structure)
        {
            if (this->passItem(item->accessData()))
            {
                auto* newItem = item->accessData()->clone();
                result->add(newItem);
            }
        }

        return result;

    }
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTERUZEMNAJEDNOTKAPRISLUSNOST_H
