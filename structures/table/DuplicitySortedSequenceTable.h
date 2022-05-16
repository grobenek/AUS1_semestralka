//
// Created by Peter Szathmáry on 15/05/2022.
//

#include "sorted_sequence_table.h"

#ifndef SZATHMARY_SEMESTRALNA_PRACA_DUPLICITYSORTEDSEQUENCETABLE_H
#define SZATHMARY_SEMESTRALNA_PRACA_DUPLICITYSORTEDSEQUENCETABLE_H

using namespace structures;

template<typename K, typename T>
class DuplicitySortedSequenceTable : public structures::SortedSequenceTable<K, T>
{
public:
    DuplicitySortedSequenceTable();

    void insert(const K& key, const T& data);

    ArrayList<TableItem<K, T>*>* findAll(const K& key);

    ~DuplicitySortedSequenceTable();

};

template<typename K, typename T>
inline void DuplicitySortedSequenceTable<K, T>::insert(const K& key, const T& data)
{

    if (this->size() == 0)
    {
        this->list_->add(new structures::TableItem<K, T>(key, data));
        return;
    }

    bool found;
    int indexOfKey = this->indexOfKey(key, 0, this->size(), found);

    try
    {
        if (this->list_->at(indexOfKey)->getKey() > key)
        {
            this->list_->insert(new structures::TableItem<K, T>(key, data), indexOfKey);
        } else
        {
            this->list_->insert(new structures::TableItem<K, T>(key, data), indexOfKey + 1);
        }
    } catch (std::out_of_range& exception)
    {
        this->list_->add(new structures::TableItem<K, T>(key, data));
    }
}

template<typename K, typename T>
inline DuplicitySortedSequenceTable<K, T>::DuplicitySortedSequenceTable() : structures::SortedSequenceTable<K, T>()
{
}

template<typename K, typename T>
inline ArrayList<TableItem<K, T>*>* DuplicitySortedSequenceTable<K, T>::findAll(const K& key)
{
    auto results = new ArrayList<TableItem<K, T>*>();
    bool found;

    int indexOfFirstFoundKey = SortedSequenceTable<K, T>::indexOfKey(key, 0, this->size(), found);

    if (found)
    {
        auto* foundItem = this->list_->at(indexOfFirstFoundKey);
        results->add(foundItem);

        int indexOfPossibleKeys = indexOfFirstFoundKey;
        ++indexOfPossibleKeys;
        foundItem = this->list_->at(indexOfPossibleKeys);
        while (foundItem->getKey() == key)
        {
            results->add(foundItem);
            ++indexOfPossibleKeys;
            if (this->list_->size() > indexOfPossibleKeys)
            {
                foundItem = this->list_->at(indexOfPossibleKeys);
            } else
            {
                break;
            }
        }
        indexOfPossibleKeys = --indexOfFirstFoundKey;
        if (this->list_->size() > indexOfPossibleKeys)
        {
            foundItem = this->list_->at(indexOfPossibleKeys);
            while (foundItem->getKey() == key)
            {
                results->add(foundItem);
                --indexOfPossibleKeys;
                if (this->list_->size() > indexOfPossibleKeys)
                {
                    foundItem = this->list_->at(indexOfPossibleKeys);
                } else
                {
                    break;
                }
            }
        }
        return results;
    }

    delete results;
    return nullptr;
}

template<typename K, typename T>
DuplicitySortedSequenceTable<K, T>::~DuplicitySortedSequenceTable()
{
    for (int i = 0; i < this->list_->size(); ++i)
    {
        delete this->list_->at(i)->accessData();
    }
}


#endif //SZATHMARY_SEMESTRALNA_PRACA_DUPLICITYSORTEDSEQUENCETABLE_H