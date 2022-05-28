//
// Created by Peter Szathmáry on 25/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTERVZDELANIEPODIEL_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTERVZDELANIEPODIEL_H


#include "FilterBetween.h"
#include "../uzemna_jednotka/UzemnaJednotka.h"
#include "../structures/table/DuplicitySortedSequenceTable.h"
#include "../enums/VzdelanieTyp.h"
#include "../criteriums/CriteriumVzdelaniePodiel.h"
#include "../structures/list/ArrayListWithObject.h"

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

class FilterVzdelaniePodiel : public FilterBetween<UzemnaJednotka*, double, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>>
{
public:
    FilterVzdelaniePodiel(double valueMin, double valueMax, VzdelanieTyp vzdelanieTyp)
            : FilterBetween(new CriteriumVzdelaniePodiel(vzdelanieTyp), valueMin, valueMax)
    {}

protected:
    bool passFilter(double value) override
    {
        return FilterBetween::passFilter(value);
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


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTERVZDELANIEPODIEL_H
