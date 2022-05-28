//
// Created by Peter Szathmáry on 28/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTERAND_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTERAND_H


#include "CompositeFilter.h"

template<typename ObjectType, typename StructureType>
class FilterAnd : public CompositeFilter<ObjectType, StructureType>
{
public:
    FilterAnd() : CompositeFilter<ObjectType, StructureType>()
    {
    }

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
                if (!passed)
                {
                    break;
                }
            }
            result->add(item);
        }
        if (result->size() == 0)
        {
            delete result;
            result = nullptr;
        }
        return result;
    }
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTERAND_H
