//
// Created by Peter Szathmáry on 22/05/2022.
//


#ifndef SZATHMARY_SEMESTRALNA_PRACA_COMPOSITEFILTER_H
#define SZATHMARY_SEMESTRALNA_PRACA_COMPOSITEFILTER_H

#include "Filter.h"
#include "../structures/list/array_list.h"
#include "../structures/list/ArrayListWithObject.h"

template<typename ObjectType, typename StructureType>
class CompositeFilter : public Filter<ObjectType, StructureType>
{
protected:
    ArrayListWithObject<Filter<ObjectType, StructureType>*> filters;

public:
    void registerFilter(Filter<ObjectType, StructureType>* filter)
    {
        if (filter != nullptr)
        {
            this->filters.add(filter);
        } else
        {
            throw std::invalid_argument("nullPointer in CompositeFilter.registerFilter");
        }
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



#endif //SZATHMARY_SEMESTRALNA_PRACA_COMPOSITEFILTER_H
