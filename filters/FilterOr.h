
// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//
// Created by Peter Szathmáry on 28/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTEROR_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTEROR_H


#include "../uzemna_jednotka/UzemnaJednotka.h"
#include "../structures/table/DuplicitySortedSequenceTable.h"
#include "CompositeFilter.h"

class FilterOr : public CompositeFilter<UzemnaJednotka*, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>>
{
public:
    FilterOr() : CompositeFilter<UzemnaJednotka *, DuplicitySortedSequenceTable<std::string, UzemnaJednotka *>>()
    {}

    bool passItem(UzemnaJednotka*& object) override
    {
        bool passed = true;
        for (int i = 0; i < this->filters->size(); ++i)
        {
            passed = this->filters->at(i)->passItem(object);
            if (passed)
            {
                return true;
            }
        }
        return false;
    }

private:
    List<UzemnaJednotka*>* passStructure(DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& structure) override
    {
        auto* results = new ArrayListWithObject<UzemnaJednotka*>();

        bool passed = true;
        for (auto item: structure)
        {
            passed = this->passItem(item->accessData());
            if (passed)
            {
                results->add(item->accessData());
            }
        }
        if (results->size() == 0)
        {
            delete results;
            results = nullptr;
        }
        return results;
    }
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTEROR_H
