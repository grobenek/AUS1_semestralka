//
// Created by Peter Szathmáry on 17/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTERWITHCRITERIUM_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTERWITHCRITERIUM_H

#include "Filter.h"
#include "../criteriums/Criterium.h"
#include "../structures/list/linked_list.h"

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

template<typename ObjectType, typename ValueType, typename StructureType>
class FilterWithCriterium : public Filter<ObjectType, StructureType>
{
private:
    Criterium<ObjectType, ValueType>* criterium;

public:
    explicit FilterWithCriterium(Criterium<ObjectType, ValueType>* criteriumToEvaluate);

    ~FilterWithCriterium();

    structures::List<ObjectType>* passStructure(StructureType& structure);

protected:
    virtual bool passFilter(ValueType value) = 0;

    virtual structures::List<ObjectType>* passFilterStructure(StructureType& structure) = 0;

    bool passItem(ObjectType& object) override;
};

template<typename ObjectType, typename ValueType, typename StructureType>
FilterWithCriterium<ObjectType, ValueType, StructureType>::FilterWithCriterium(Criterium<ObjectType, ValueType>* criteriumToEvaluate)
{
    this->criterium = criteriumToEvaluate;
}

template<typename ObjectType, typename ValueType, typename StructureType>
FilterWithCriterium<ObjectType, ValueType, StructureType>::~FilterWithCriterium()
{
    delete this->criterium;
}

template<typename ObjectType, typename ValueType, typename StructureType>
bool FilterWithCriterium<ObjectType, ValueType, StructureType>::passItem(ObjectType& object)
{
     return this->passFilter(criterium->evaluate(object));
}

template<typename ObjectType, typename ValueType, typename StructureType>
structures::List<ObjectType>* FilterWithCriterium<ObjectType, ValueType, StructureType>::passStructure(StructureType& structure)
{
    auto* result = this->passFilterStructure(structure);
    return result;
}


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTERWITHCRITERIUM_H
