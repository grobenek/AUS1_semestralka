#pragma once

#include "priority_queue.h"
#include "priority_queue_limited_sorted_array_list.h"
#include "../list/linked_list.h"
#include <cmath>

namespace structures
{
    /// <summary> Prioritny front implementovany dvojzoznamom. </summary>
    /// <typeparam name = "T"> Typ dat ukladanych v prioritnom fronte. </typepram>
    /// <remarks> Implementacia efektivne vyuziva prioritny front implementovany utriednym ArrayList-om s obmedzenou kapacitou a LinkedList. </remarks>
    template<typename T>
    class PriorityQueueTwoLists : public PriorityQueue<T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        PriorityQueueTwoLists();

        PriorityQueueTwoLists(PriorityQueueTwoLists<T>& other);

        ~PriorityQueueTwoLists();

        /// <summary> Priradenie struktury. </summary>
        /// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
        /// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
        Structure& assign(Structure& other) override;

        /// <summary> Vrati pocet prvkov v prioritnom fronte implementovanom dvojzoznamom. </summary>
        /// <returns> Pocet prvkov v prioritnom fronte implementovanom dvojzoznamom. </returns>
        size_t size() override;

        /// <summary> Vymaze obsah prioritneho frontu implementovaneho dvojzoznamom. </summary>
        void clear() override;

        /// <summary> Vlozi prvok s danou prioritou do prioritneho frontu. </summary>
        /// <param name = "priority"> Priorita vkladaneho prvku. </param>
        /// <param name = "data"> Vkladany prvok. </param>
        void push(int priority, const T& data) override;

        /// <summary> Odstrani prvok s najvacsou prioritou z prioritneho frontu implementovaneho dvojzoznamom. </summary>
        /// <returns> Odstraneny prvok. </returns>
        /// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front implementovany dvojzoznamom prazdny. </exception>
        T pop() override;

        /// <summary> Vrati adresou prvok s najvacsou prioritou. </summary>
        /// <returns> Adresa, na ktorej sa nachadza prvok s najvacsou prioritou. </returns>
        /// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front implementovany dvojzoznamom prazdny. </exception>
        T& peek() override;

        /// <summary> Vrati prioritu prvku s najvacsou prioritou. </summary>
        /// <returns> Priorita prvku s najvacsou prioritou. </returns>
        /// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front implementovany dvojzoznamom prazdny. </exception>
        int peekPriority() override;

    private:
        /// <summary> Smernik na prioritny front ako implementovany utriednym ArrayList-om s obmedzenou kapacitou . </summary>
        /// <remarks> Z pohladu dvojzoznamu sa jedna o kratsi utriedeny zoznam. </remarks>
        PriorityQueueLimitedSortedArrayList<T>* shortList_;

        /// <summary> Smernik na dlhsi neutriedeny zoznam. </summary>
        LinkedList<PriorityQueueItem<T>*>* longList_;
    };

    template<typename T>
    PriorityQueueTwoLists<T>::PriorityQueueTwoLists() :
            shortList_(new PriorityQueueLimitedSortedArrayList<T>()),
            longList_(new LinkedList<PriorityQueueItem<T>*>())
    {
    }

    template<typename T>
    PriorityQueueTwoLists<T>::PriorityQueueTwoLists(PriorityQueueTwoLists<T>& other) :
            PriorityQueueTwoLists<T>()
    {
        assign(other);
    }

    template<typename T>
    PriorityQueueTwoLists<T>::~PriorityQueueTwoLists()
    {
        for (auto* item: *this->longList_)
        {
            delete item;
        }

        delete this->shortList_;
        delete this->longList_;

        this->shortList_ = nullptr;
        this->longList_ = nullptr;
    }

    template<typename T>
    Structure& PriorityQueueTwoLists<T>::assign(Structure& other)
    {
        if (this != &other)
        {
            auto& otherQueue = dynamic_cast<PriorityQueueTwoLists<T>&>(other);

            shortList_->clear();
            shortList_->assign(*otherQueue.shortList_);

            longList_->clear();
            for (auto item: *otherQueue.longList_)
            {
                this->longList_->add(new PriorityQueueItem<T>(*item));
            }
        }
        return *this;
    }

    template<typename T>
    size_t PriorityQueueTwoLists<T>::size()
    {
        return (this->shortList_->size() + this->longList_->size());
    }

    template<typename T>
    void PriorityQueueTwoLists<T>::clear()
    {
        this->shortList_->clear();

        for (auto* item: *this->longList_)
        {
            delete item;
        }
        this->longList_->clear();
    }

    template<typename T>
    void PriorityQueueTwoLists<T>::push(int priority, const T& data)
    {
        if (this->shortList_->size() == 1 || this->shortList_->size() == 0)
        {
            this->shortList_->pushAndRemove(priority, data);
            return;
        }

        if ((this->longList_->size() == 0 || this->shortList_->minPriority() > priority) && this->shortList_->minPriority() > priority)
        {
            auto* removedItem = this->shortList_->pushAndRemove(priority, data);

            if (removedItem != nullptr)
            {
                this->longList_->add(removedItem);
            }
        } else
        {
            this->longList_->add(new PriorityQueueItem<T>(priority, data));
        }
    }

    template<typename T>
    T PriorityQueueTwoLists<T>::pop()
    {
        if (this->shortList_->size() == 0)
        {
            throw std::logic_error("PriorityQueueTwoList shortList is empty in pop!");
        }

        T dataToRemove = this->shortList_->pop();

        if (this->shortList_->size() == 0 && this->longList_->size() != 0)
        {
            int sqrtOfLongListSize = sqrt(this->longList_->size());

            if (sqrtOfLongListSize <= 4)
            {
                this->shortList_->trySetCapacity(4);
            } else
            {
                this->shortList_->trySetCapacity(sqrtOfLongListSize);
            }

            auto* tmpList = new structures::LinkedList<PriorityQueueItem<T>*>();

            while (this->longList_->size() != 0)
            {
                auto* removedItemFromLongList = this->longList_->removeAt(0);

                auto* removedItemFromShortList = this->shortList_->pushAndRemove(removedItemFromLongList->getPriority(), removedItemFromLongList->accessData());

                if (removedItemFromShortList != nullptr)
                {
                    tmpList->add(removedItemFromShortList);
                }
                delete removedItemFromLongList;
            }
            delete this->longList_;
            this->longList_ = tmpList;
        }
        return dataToRemove;
    }

    template<typename T>
    T& PriorityQueueTwoLists<T>::peek()
    {
        if (this->size() == 0)
        {
            throw std::logic_error("PriorityQueueTwoLists is empty!");
        }
        return this->shortList_->peek();
    }

    template<typename T>
    int PriorityQueueTwoLists<T>::peekPriority()
    {
        if (this->size() == 0)
        {
            throw std::logic_error("PriorityQueueTwoLists is empty!");
        }
        return this->shortList_->peekPriority();
    }
}