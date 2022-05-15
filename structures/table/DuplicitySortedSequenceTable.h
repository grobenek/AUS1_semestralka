//
// Created by Peter Szathmáry on 15/05/2022.
//

#include "sorted_sequence_table.h"

#ifndef SZATHMARY_SEMESTRALNA_PRACA_DUPLICITYSORTEDSEQUENCETABLE_H
#define SZATHMARY_SEMESTRALNA_PRACA_DUPLICITYSORTEDSEQUENCETABLE_H

#endif //SZATHMARY_SEMESTRALNA_PRACA_DUPLICITYSORTEDSEQUENCETABLE_H
using namespace structures;

template<typename T, typename K>
class DuplicitySortedSequenceTable : public structures::SortedSequenceTable<T, K>
{
public:
    DuplicitySortedSequenceTable();

    void insert(const K& key, const T& data) override;

    void tryFind(K& key, T& data);

protected:
    ArrayList<TableItem<K, T>*> findTableItems(const K& key);
};

template<typename T, typename K>
void DuplicitySortedSequenceTable<T, K>::insert(const K& key, const T& data)
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

template<typename T, typename K>
void DuplicitySortedSequenceTable<T, K>::tryFind(K& key, T& data)
{

}

template<typename T, typename K>
DuplicitySortedSequenceTable<T, K>::DuplicitySortedSequenceTable() : structures::SortedSequenceTable<K, T>()
{
}

template<typename T, typename K>
ArrayList<TableItem<K, T>*> DuplicitySortedSequenceTable<T, K>::findTableItems(const K& key)
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
           results->add(found);
           ++indexOfPossibleKeys;
           foundItem = this->list_->at(indexOfPossibleKeys);
        }

        foundItem = this->list_->at(indexOfFirstFoundKey);
        while (foundItem->getKey() == key)
        {
            results->add(found);
            --indexOfPossibleKeys;
            foundItem = this->list_->at(indexOfPossibleKeys);
        }
        return results;
    }

    delete results;
    return nullptr;
}

