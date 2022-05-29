
// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//
// Created by Peter Szathmáry on 17/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_FILTER_H
#define SZATHMARY_SEMESTRALNA_PRACA_FILTER_H

template<typename ObjectType, typename StructureType>
class Filter
{

public:
    virtual bool passItem(ObjectType& object) = 0;

    virtual structures::List<ObjectType>* passStructure(StructureType& structure) = 0;

    virtual ~Filter() = default;
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_FILTER_H
