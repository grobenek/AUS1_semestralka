// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#pragma once

#include "../list/array_list.h"
#include "../list/ArrayListWithObject.h"
#include "sequence_table.h"


// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

namespace structures
{

    /// <summary> Utriedena sekvencna tabulka. </summary>
    /// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
    /// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
    template<typename K, typename T>
    class SortedSequenceTable : public SequenceTable<K, T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        SortedSequenceTable();

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> SortedSequenceTable, z ktorej sa prevezmu vlastnosti. </param>
        SortedSequenceTable(SortedSequenceTable<K, T>& other);

        /// <summary> Priradenie struktury. </summary>
        /// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
        /// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
        Structure& assign(Structure& other) override;

        /// <summary> Porovnanie struktur. </summary>
        /// <param name="other">Struktura, s ktorou sa ma tato struktura porovnat. </param>
        /// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
        bool equals(Structure& other) override;

        /// <summary> Vlozi data s danym klucom do tabulky. </summary>
        /// <param name = "key"> Kluc vkladanych dat. </param>
        /// <param name = "data"> Vkladane data. </param>
        /// <exception cref="std::logic_error"> Vyhodena, ak tabulka uz obsahuje data s takymto klucom. </exception>
        void insert(const K& key, const T& data) override;

    protected:
        /// <summary> Najde prvok tabulky s danym klucom. </summary>
        /// <param name = "key"> Hladany kluc. </param>
        /// <returns> Prvok tabulky s danym klucom, ak neexistuje, vrati nullptr. </returns>
        TableItem<K, T>* findTableItem(const K& key) override;

    protected:
        /// <summary> Najde index prvku s danym klucom. Kontroluje rozsah [indexStart, indexEnd). Pracuje na principe bisekcie. </summary>
        /// <param name = "key"> Hladany kluc. </param>
        /// <param name = "indexStart"> Pociatocny index prehladavanej sekvencie. </param>
        /// <param name = "indexEnd"> Koncovy index prehladavanej sekvencie. </param>
        /// <param name = "found"> Vystupny parameter, ktory indikuje, ci sa kluc nasiel. </param>
        /// <returns> Index prvku s danym klucom. Ak sa kluc v tabulke nenachadza, vrati index, kde by sa mal prvok s takym klucom nachadzat. </returns>
        int indexOfKey(K key, int indexStart, int indexEnd, bool& found);
    };

    template<typename K, typename T>
    inline SortedSequenceTable<K, T>::SortedSequenceTable() :
            SequenceTable<K, T>(new ArrayList<TableItem<K, T>*>())
    {
    }

    template<typename K, typename T>
    inline SortedSequenceTable<K, T>::SortedSequenceTable(SortedSequenceTable<K, T>& other) :
            SortedSequenceTable()
    {
        assign(other);
    }

    template<typename K, typename T>
    inline Structure& SortedSequenceTable<K, T>::assign(Structure& other)
    {
        return SequenceTable<K, T>::assignSequenceTable(dynamic_cast<SortedSequenceTable<K, T>&>(other));
    }

    template<typename K, typename T>
    inline bool SortedSequenceTable<K, T>::equals(Structure& other)
    {
        return Table<K, T>::equalsTable(dynamic_cast<SortedSequenceTable<K, T>*>(&other));
    }

    template<typename K, typename T>
    inline void SortedSequenceTable<K, T>::insert(const K& key, const T& data)
    {
        if (this->size() == 0)
        {
            this->list_->add(new TableItem<K, T>(key, data));
            return;
        }

        bool found;
        int indexOfKey = this->indexOfKey(key, 0, this->size(), found);

        if (found)
        {
            throw std::logic_error("Key already exists in SortedSequenceTable!");
        } else
        {
            try
            {
                if (this->list_->at(indexOfKey)->getKey() > key)
                {
                    this->list_->insert(new TableItem<K, T>(key, data), indexOfKey);
                } else
                {
                    this->list_->insert(new TableItem<K, T>(key, data), indexOfKey + 1);
                }
            } catch (std::out_of_range& exception)
            {
                this->list_->add(new TableItem<K, T>(key, data));
            }
        }
    }

    template<typename K, typename T>
    inline TableItem<K, T>* SortedSequenceTable<K, T>::findTableItem(const K& key)
    {
        bool found;

        int indexOfItem = this->indexOfKey(key, 0, this->size(), found);

        if (found)
        {
            return this->list_->at(indexOfItem);
        } else
        {
            return nullptr;
        }
    }

    template<typename K, typename T>
    inline int SortedSequenceTable<K, T>::indexOfKey(K key, int indexStart, int indexEnd, bool& found)
    {
        if (indexEnd > this->size())
        {
            throw std::logic_error("Invalid end index in indexOfKey in SortedSequenceTable! End index: " + std::to_string(indexEnd));
        }

        if (indexStart == this->size())
        {
            found = false;
            return this->size();
        }

        int middle = (indexStart + indexEnd) / 2;

        if (this->list_->at(middle)->getKey() == key)
        {
            found = true;
            return middle;
        } else
        {
            if (indexStart == indexEnd)
            {
                found = false;
                if (key > this->list_->at(middle)->getKey())
                {
                    return middle + 1;
                } else
                {
                    return middle;
                }
            } else if (this->list_->at(middle)->getKey() < key)
            {
                indexStart = middle + 1;
                return this->indexOfKey(key, indexStart, indexEnd, found);
            } else
            {
                indexEnd = middle;
                return this->indexOfKey(key, indexStart, indexEnd, found);
            }
        }
    }
}