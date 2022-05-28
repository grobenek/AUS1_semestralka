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

    CompositeFilter()
    {
        this->filters = new ArrayListWithObject<Filter<ObjectType, StructureType>>;
    }

    virtual ~CompositeFilter()
    {
        delete this->filters;
    }

};



#endif //SZATHMARY_SEMESTRALNA_PRACA_COMPOSITEFILTER_H
