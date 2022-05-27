//
// Created by Peter Szathmáry on 25/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTERUZEMNAJEDNOTKATYP_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTERUZEMNAJEDNOTKATYP_H


#include "../uzemna_jednotka/UzemnaJednotka.h"
#include "../structures/table/DuplicitySortedSequenceTable.h"
#include "FilterEquals.h"
#include "../enums/VzdelanieTyp.h"
#include "../criteriums/CriteriumTyp.h"
#include "../structures/list/ArrayListWithObject.h"

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

class FilterUzemnaJednotkaTyp : public FilterEquals<UzemnaJednotka*, UzemnaJednotkaTyp, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>>
{
public:
//    FilterVzdelaniePodiel(UzemnaJednotkaTyp value, VzdelanieTyp vzdelanieTyp)
//            : FilterEquals(value, new CriteriumTyp(vzdelanieTyp))
//    {}
    explicit FilterUzemnaJednotkaTyp(UzemnaJednotkaTyp value)
            : FilterEquals(new CriteriumTyp(), value)
    {}

protected:
    bool passFilter(UzemnaJednotkaTyp value) override
    {
        return FilterEquals::passFilter(value);
    }

    List<UzemnaJednotka*>*
    passFilterStructure(DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& structure) override
    {
        //TODO leaks v Listoch, nakolko nevedia pracovat s objektami - najdi solution
        //TODO treba spravit dalsie filtre
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


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTERUZEMNAJEDNOTKATYP_H
