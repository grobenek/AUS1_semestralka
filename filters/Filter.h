//
// Created by Peter Szathmáry on 17/05/2022.
//

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTER_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTER_H

template<typename ObjectType, typename StructureType>
class Filter
{
    virtual bool passItem(ObjectType& object) = 0;

    virtual structures::List<ObjectType>* passStructure(StructureType& structure) = 0;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTER_H
