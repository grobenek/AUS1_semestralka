//
// Created by Peter Szathmáry on 28/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTEROR_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTEROR_H

#include "CompositeFilter.h"

template<typename ObjectType, typename StructureType>
class FilterOr : public CompositeFilter<ObjectType, StructureType>
{
public:
    FilterOr() : CompositeFilter<ObjectType, StructureType>()
    {}

private:
    structures::List<ObjectType>* passStructure(StructureType& structure) override
    {
        auto* result = new ArrayListWithObject<ObjectType>();

        for (auto item: structure)
        {
            bool passed = true;
            for (int i = 0; i < this->filters.size(); ++i)
            {
                passed = this->filters.at(i)->passItem(item);
                if (passed)
                {
                    result->add(item);
                    break;
                }
            }
        }
        if (result->size() == 0)
        {
            delete result;
            result = nullptr;
        }
        return result;
    }

};


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTEROR_H
