//
// Created by Peter Szathmáry on 29/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTERALL_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTERALL_H


#include "CompositeFilter.h"
#include "../uzemna_jednotka/UzemnaJednotka.h"
#include "../structures/table/DuplicitySortedSequenceTable.h"

class FilterAll : public CompositeFilter<UzemnaJednotka*, DuplicitySortedSequenceTable< std::string, UzemnaJednotka*>>
{
public:
    FilterAll() : CompositeFilter<UzemnaJednotka *, DuplicitySortedSequenceTable<std::string, UzemnaJednotka *>>()
    {}

    bool passItem(UzemnaJednotka*& object) override
    {
        return true;
    }

    List<UzemnaJednotka*>* passStructure(DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& structure) override
    {
        auto* result = new ArrayListWithObject<UzemnaJednotka*>();

        for (auto item: structure)
        {
            if (this->passItem(item->accessData()))
            {
                result->add(item->accessData()->clone());
            }
        }
        return result;
    }
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTERALL_H
