//
// Created by Peter Szathmáry on 23/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTERVZDELANIEPOCET_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTERVZDELANIEPOCET_H

#include "FilterBetween.h"
#include "../uzemna_jednotka/UzemnaJednotka.h"
#include "../criteriums/CriteriumVzdelaniePocet.h"
#include "../structures/list/ArrayListWithObject.h"

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

class FilterVzdelaniePocet : public FilterBetween<UzemnaJednotka*, int, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>>
{
public:
    FilterVzdelaniePocet(int valueMax, int valueMin, VzdelanieTyp vzdelanieTyp)
            : FilterBetween(new CriteriumVzdelaniePocet(vzdelanieTyp), valueMin, valueMax)
    {}

protected:
    bool passFilter(int value) override
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
        if (result->isEmpty())
        {
            delete result;
            result = nullptr;
        }
        return result;
    }
};

#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTERVZDELANIEPOCET_H
