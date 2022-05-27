//
// Created by Peter Szathmáry on 22/05/2022.
//


#ifndef SZATHMARY_SEMESTRALNA_PRACA_COMPOSITEFILTER_H
#define SZATHMARY_SEMESTRALNA_PRACA_COMPOSITEFILTER_H

#include "Filter.h"
#include "../structures/list/array_list.h"

template<typename ObjectType>
class CompositeFilter : public Filter<ObjectType>
{
protected:
    structures::ArrayList<Filter<ObjectType>*> filters;

public:
    void registerFilter(Filter<ObjectType>* filter)
    {
        if (filter != nullptr)
        {
            this->filters.add(filter);
        } else
        {
            throw std::invalid_argument("nullPointer in CompositeFilter.registerFilter");
        }
    }


};



#endif //SZATHMARY_SEMESTRALNA_PRACA_COMPOSITEFILTER_H
