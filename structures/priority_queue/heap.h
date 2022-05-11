#pragma once

#include "priority_queue_list.h"
#include "../list/array_list.h"
#include "../utils.h"
#include <stdexcept>

namespace structures
{
    /// <summary> Prioritny front implementovany haldou. Implementujucim typom haldy je struktura ArrayList. </summary>
    /// <typeparam name = "T"> Typ dat ukladanych v prioritnom fronte. </typepram>
    template<typename T>
    class Heap : public PriorityQueueList<T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        Heap();

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> Halda, z ktorej sa prevezmu vlastnosti. </param>
        Heap(Heap<T>& other);

        /// <summary> Priradenie struktury. </summary>
        /// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
        /// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
        Structure& assign(Structure& other) override;

        /// <summary> Vlozi prvok s danou prioritou do haldy. </summary>
        /// <param name = "priority"> Priorita vkladaneho prvku. </param>
        /// <param name = "data"> Vkladany prvok. </param>
        void push(int priority, const T& data) override;

        /// <summary> Odstrani prvok s najvacsou prioritou z haldy. </summary>
        /// <returns> Odstraneny prvok. </returns>
        /// <exception cref="std::logic_error"> Vyhodena, ak je halda prazdna. </exception>
        T pop() override;

    protected:
        /// <summary> Vrati index v ArrayList-e, na ktorom sa nachadza prvok s najvacsou prioritou. </summary>
        /// <returns> Index prvku s najvacsou prioritou. </returns>
        /// <exception cref="std::logic_error"> Vyhodena, ak je ArrayList prazdny. </exception>
        int indexOfPeek() override;

    private:
        /// <summary> Vrati index v ArrayList-e, na ktorom by sa mal nachadzat otec daneho prvku. </summary>
        /// <param name = "index"> Index prvku, ktoreho otca chceme vratit. </param>
        /// <returns> Index, na ktorom ba sa mal nachadzat otec prvku. </returns>
        int getParentIndex(int index);

        /// <summary> Vrati index v ArrayList-e, na ktorom by mal mat dany prvok syna s najvacsou prioritou. </summary>
        /// <param name = "index"> Index prvku, ktoreho syna chceme vratit. </param>
        /// <returns> Index, na ktorom by sa mal nachadzat syn prvku. </returns>
        int getGreaterSonIndex(int index);
    };

    template<typename T>
    Heap<T>::Heap() :
            PriorityQueueList<T>(new ArrayList<PriorityQueueItem<T>*>())
    {
    }

    template<typename T>
    Heap<T>::Heap(Heap<T>& other) :
            Heap<T>()
    {
        assign(other);
    }

    template<typename T>
    inline Structure& Heap<T>::assign(Structure& other)
    {
        return PriorityQueueList<T>::assign(dynamic_cast<PriorityQueueList<T>&>(other));
    }

    template<typename T>
    void Heap<T>::push(int priority, const T& data)
    {
        auto* item = new PriorityQueueItem<T>(priority, data);
        this->list_->add(item);

        int indexOfParent = this->getParentIndex(this->list_->size() - 1); // prave vlozeny prvok - jeho otec
        if (indexOfParent < 0)
        {
            return;
        }
        auto* parentOfItem = this->list_->at(indexOfParent);

        while (item->getPriority() < parentOfItem->getPriority())
        {
            Utils::swap(*item, *parentOfItem); // v iteme je jeho parent a v parente je item

            indexOfParent = this->getParentIndex(indexOfParent);
            if (indexOfParent >= 0)
            {
                item = parentOfItem;
                parentOfItem = this->list_->at(indexOfParent);
            }
        }
    }

    template<typename T>
    T Heap<T>::pop()
    {
        if (this->list_->size() == 0)
        {
            throw std::logic_error("heap is empty!");
        }
        if (this->list_->size() == 1)
        {
            delete this->list_->at(0);
            this->list_->removeAt(0);
            T dataToReturn = this->list_->at(0)->accessData();
            return dataToReturn;
        }
        T dataToReturn = this->list_->at(this->indexOfPeek())->accessData();
        auto* root = this->list_->at(this->indexOfPeek());
        auto indexOfRoot = this->indexOfPeek();

        auto indexOfLastLeftItem = this->list_->size() - 1;
        auto* lastLefItem = this->list_->at(indexOfLastLeftItem);
        Utils::swap(*root, *lastLefItem); // v roote je lastLeftItem a v lastLeftItem je root ktory potrebujem vymazat
        delete this->list_->at(indexOfLastLeftItem);
        this->list_->removeAt(indexOfLastLeftItem);

        auto greaterSonIndex = this->getGreaterSonIndex(this->indexOfPeek());
        if (greaterSonIndex == -1)
        {
            return dataToReturn;
        }
        auto* greaterSon = this->list_->at(greaterSonIndex);
        while (root->getPriority() > greaterSon->getPriority())
        {
            Utils::swap(*root, *greaterSon); // v greaterSon je root ktory vymienam dalej
            indexOfRoot = greaterSonIndex;
            greaterSonIndex = this->getGreaterSonIndex(indexOfRoot);
            if (greaterSonIndex == -1)
            {
                break;
            }
            greaterSon = this->list_->at(greaterSonIndex);
        }
        return dataToReturn;
    }

    template<typename T>
    inline int Heap<T>::getParentIndex(int index)
    {
        Utils::rangeCheckExcept(index, this->list_->size(), "Invalid index at getParentIndex! Index: " + std::to_string(index));

        if (index == 0)
        {
            return -1;
        }

        if (index % 2 == 0)
        {
            return (index / 2) - 1;
        } else
        {
            return (index / 2);
        }
    }

    template<typename T>
    inline int Heap<T>::getGreaterSonIndex(int index)
    {
        //TODO hladam otca ked je parne cislo tak index / 2 -1 ak neparne tak index / 2

        //TODO lavy syn = (index*2) + 1
        //TODO pravy syn = (index*2) + 2
        Utils::rangeCheckExcept(index, this->list_->size(), "Invalid index at getGreaterSonIndex! Index: " + std::to_string(index));

        PriorityQueueItem<T>* leftSon;
        PriorityQueueItem<T>* rightSon;

        if ((index * 2) + 1 < this->list_->size())
        {
            leftSon = this->list_->at((index * 2) + 1);
        } else
        {
            leftSon = nullptr;
        }

        if ((index * 2) + 2 < this->list_->size())
        {
            rightSon = this->list_->at((index * 2) + 2);
        } else
        {
            rightSon = nullptr;
        }

        if (rightSon != nullptr && leftSon != nullptr)
        {
            if (leftSon->getPriority() < rightSon->getPriority())
            {
                return ((index * 2) + 1);
            } else
            {
                return ((index * 2) + 2);
            }
        } else if (rightSon == nullptr && leftSon != nullptr)
        {
            return ((index * 2) + 1);
        } else if (rightSon != nullptr)
        {
            return ((index * 2) + 2);
        } else
        {
            return -1;
        }
    }

    template<typename T>
    inline int Heap<T>::indexOfPeek()
    {
        if (this->list_->size() == 0)
        {
            throw std::logic_error("heap is empty!");
        }
        return 0;
    }
}