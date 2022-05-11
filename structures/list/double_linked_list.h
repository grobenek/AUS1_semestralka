#pragma once

#include "list.h"
#include "linked_list.h"

namespace structures
{
    // implementacne tipy:
    //  - namiesto triedy List<T> mozete v triede DoubleLinkedListTestOverall<T>
    //    zdedit jednostranne zretazeny zoznam (LinkedList<T>).
    //    ak tak urobite, mozete mnoho metod odstranit a prekryt iba tie,
    //    ktore maju z pohladu obojsmerne zretazeneho zoznamu vyznam a
    //    zvysok nechat na predka.
    //  - nezabudnite si vytvorit triedu pre prvok obojstranne zretazeneho zoznamu.
    //    opat tento prvok mozete zdedit z prvku jednostranne zretazeneho zoznamu.
    //  - ak vyuzijete dedicnost, budete moct vyuzit predkove iteratory,
    //    takze ich nebudete musiet implementovat.



    template<typename T>
    class DoubleLinkedListItem : public DataItem<T>
    {
    private:

        DoubleLinkedListItem<T>* previous_;
        DoubleLinkedListItem<T>* next_;
    public:

        explicit DoubleLinkedListItem(T data);

        DoubleLinkedListItem(DoubleLinkedListItem<T> const& otherItem);

        ~DoubleLinkedListItem();

        DoubleLinkedListItem<T>* getNext();

        DoubleLinkedListItem<T>* getPrevious();

        DoubleLinkedListItem<T>* setPrevious(DoubleLinkedListItem<T>* previous);

        DoubleLinkedListItem<T>* setNext(DoubleLinkedListItem<T>* next);

    };

    template<typename T>
    DoubleLinkedListItem<T>::DoubleLinkedListItem(T data) : DataItem<T>(data), next_(nullptr), previous_(nullptr)
    {
    }

    template<typename T>
    DoubleLinkedListItem<T>::DoubleLinkedListItem(const DoubleLinkedListItem<T>& other) : DataItem<T>(other),
                                                                                          next_(other.next_),
                                                                                          previous_(other.previous_)
    {
    }

    template<typename T>
    DoubleLinkedListItem<T>::~DoubleLinkedListItem()
    {
        next_ = nullptr;
        previous_ = nullptr;
    }

    template<typename T>
    DoubleLinkedListItem<T>* DoubleLinkedListItem<T>::getNext()
    {
        return next_;
    }

    template<typename T>
    DoubleLinkedListItem<T>* DoubleLinkedListItem<T>::getPrevious()
    {
        return previous_;
    }

    template<typename T>
    DoubleLinkedListItem<T>* DoubleLinkedListItem<T>::setPrevious(DoubleLinkedListItem<T>* previous)
    {
        previous_ = previous;
    }

    template<typename T>
    DoubleLinkedListItem<T>* DoubleLinkedListItem<T>::setNext(DoubleLinkedListItem<T>* next)
    {
        next_ = next;
    }

    /// <summary> Obojstranne zretazeny zoznam. </summary>
    /// <typeparam name = "T"> Typ dat ukladanych v zozname. </typepram>
    template<typename T>
    class DoubleLinkedList : public List<T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        DoubleLinkedList();

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> DoubleLinkedListTestOverall, z ktoreho sa prevezmu vlastnosti. </param>
        DoubleLinkedList(DoubleLinkedList<T>& other);

        /// <summary> Destruktor. </summary>
        ~DoubleLinkedList();

        /// <summary> Vrati pocet prvkov v zozname. </summary>
        /// <returns> Pocet prvkov v zozname. </returns>
        size_t size() override;

        /// <summary> Priradenie struktury. </summary>
        /// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
        /// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
        Structure& assign(Structure& other) override;

        /// <summary> Porovnanie struktur. </summary>
        /// <param name="other">Struktura, s ktorou sa ma tato struktura porovnat. </param>
        /// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
        bool equals(Structure& other) override;

        /// <summary> Vrati adresou prvok na indexe. </summary>
        /// <param name = "index"> Index prvku. </param>
        /// <returns> Adresa prvku na danom indexe. </returns>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        T& at(int index) override;

        /// <summary> Prida prvok do zoznamu. </summary>
        /// <param name = "data"> Pridavany prvok. </param>
        void add(const T& data) override;

        /// <summary> Vlozi prvok do zoznamu na dany index. </summary>
        /// <param name = "data"> Pridavany prvok. </param>
        /// <param name = "index"> Index prvku. </param>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        /// <remarks> Ak je ako index zadana hodnota poctu prvkov (teda prvy neplatny index), metoda insert sa sprava ako metoda add. </remarks>
        void insert(const T& data, int index) override;

        /// <summary> Odstrani prvy vyskyt prvku zo zoznamu. </summary>
        /// <param name = "data"> Odstranovany prvok. </param>
        /// <returns> true, ak sa podarilo prvok zo zoznamu odobrat, false inak. </returns>
        bool tryRemove(const T& data) override;

        /// <summary> Odstrani zo zoznamu prvok na danom indexe. </summary>
        /// <param name = "index"> Index prvku. </param>
        /// <returns> Odstraneny prvok. </returns>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        T removeAt(int index) override;

        /// <summary> Vrati index prveho vyskytu prvku v zozname. </summary>
        /// <param name = "data"> Prvok, ktoreho index sa hlada. </param>
        /// <returns> Index prveho vyskytu prvku v zozname, ak sa prvok v zozname nenachadza, vrati -1. </returns>
        int getIndexOf(const T& data) override;

        /// <summary> Vymaze zoznam. </summary>
        void clear() override;

        /// <summary> Vrati skutocny iterator na zaciatok struktury </summary>
        /// <returns> Iterator na zaciatok struktury. </returns>
        /// <remarks> Zabezpecuje polymorfizmus. </remarks>
        Iterator <T>* getBeginIterator() override;

        /// <summary> Vrati skutocny iterator na koniec struktury </summary>
        /// <returns> Iterator na koniec struktury. </returns>
        /// <remarks> Zabezpecuje polymorfizmus. </remarks>
        Iterator <T>* getEndIterator() override;

        DoubleLinkedListItem<T>* getItemAtIndex(int index);

    private:
        size_t size_;
        DoubleLinkedListItem<T>* first_;
        DoubleLinkedListItem<T>* last_;

    private:
        class DoubleLinkListIterator : public Iterator<T>
        {
            //NEVIEM CI FUNGUJE
        private:
            DoubleLinkedListItem<T>* position_;
        public:

            explicit DoubleLinkListIterator(DoubleLinkedListItem<T>* position) : position_(position)
            {
            }

            ~DoubleLinkListIterator()
            {
                position_ = nullptr;
            }

            Iterator <T>& operator=(Iterator <T>& other)
            {
                position_ = dynamic_cast<DoubleLinkedList::DoubleLinkListIterator&>(other).position_;
                return *this;
            }

            bool operator!=(Iterator <T>& other)
            {
                return dynamic_cast<DoubleLinkedList::DoubleLinkListIterator&>(other).position_ != position_;
            }

            T operator*()
            {
                return position_->accessData();
            }

            Iterator <T>& operator++()
            {
                position_ = position_->getNext();
                return *this;
            }
        };
    };

    template<typename T>
    inline DoubleLinkedList<T>::DoubleLinkedList() : size_(0),
                                                     first_(nullptr),
                                                     last_(nullptr)
    {
    }

    template<typename T>
    inline DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList<T>& other) : DoubleLinkedList()
    {
        assign(other);
    }

    template<typename T>
    inline DoubleLinkedList<T>::~DoubleLinkedList()
    {
        clear();
    }

    template<typename T>
    inline size_t DoubleLinkedList<T>::size()
    {
        return size_;
    }

    template<typename T>
    inline Structure& DoubleLinkedList<T>::assign(Structure& other)
    {
        if (this != &other)
        {
            auto& otherList = dynamic_cast<DoubleLinkedList<T>&>(other);
            this->clear();
            DoubleLinkedListItem<T>* otherItem = otherList.first_;
            //prejdem cely list a priradim data
            while (otherItem != nullptr)
            {
                add(otherItem->accessData());
                otherItem = otherItem->getNext();
            }
        }
        return *this;
    }

    template<typename T>
    inline bool DoubleLinkedList<T>::equals(Structure& other)
    {
        if (this == &other)
        {
            return true;
        }
        if (size_ != other.size())
        {
            return false;
        }
        auto* otherList = dynamic_cast<DoubleLinkedList<T>*>(&other);
        if (otherList == nullptr)
        {
            return false;
        }

        auto thisIterator = this->begin();
        auto otherIterator = otherList->begin();
        auto thisEndIterator = this->end();

        while (thisIterator != thisEndIterator)
        {
            if (*thisIterator != *otherIterator)
            {
                return false;
            }
            ++thisIterator;
            ++otherIterator;
        }
        return true;
    }

    template<typename T>
    inline T& DoubleLinkedList<T>::at(int index)
    {
        return getItemAtIndex(index)->accessData();
    }

    template<typename T>
    inline void DoubleLinkedList<T>::add(const T& data)
    {
        auto* newItem = new DoubleLinkedListItem<T>(data);

        if (first_ == nullptr && last_ == nullptr)
        {
            // ak je prazdny, len nastavim pointre
            first_ = newItem;
            last_ = newItem;
        } else
        {
            // ak nie je prazdny, poslednemu nastavim pointer na pridany Prvok a last_ nastavim na pridany prvok
            newItem->setPrevious(last_);
            last_->setNext(newItem);
            last_ = newItem;
        }
        size_++;
    }

    template<typename T>
    inline void DoubleLinkedList<T>::insert(const T& data, int index)
    {
        //staci len == size_, lebo ratam od 1, ak mam size_ 0, nemam tam nic
        if (index == size_)
        {
            //vkladam na koniec
            add(data);
        } else
        {
            Utils::rangeCheckExcept(index, size_, "Invalid index in LinkedList.insert");
            auto* newItem = new DoubleLinkedListItem<T>(data);
            if (index == 0)
            {
                //vkladam na zaciatok
                first_->setPrevious(newItem);
                newItem->setNext(first_);
                first_ = newItem;
            } else
            {
                auto* currentItemAtIndex = getItemAtIndex(index);
                newItem->setPrevious(currentItemAtIndex->getPrevious());
                newItem->setNext(currentItemAtIndex);

                newItem->getPrevious()->setNext(newItem);
                newItem->getNext()->setPrevious(newItem);
                // TODO prerob nejak inac
            }
            size_++;
        }
    }

    template<typename T>
    inline bool DoubleLinkedList<T>::tryRemove(const T& data)
    {
        int indexPrvku = this->getIndexOf(data);

        if (indexPrvku == -1)
        {
            return false;
        } else
        {
            this->removeAt(indexPrvku);
            return this->at(indexPrvku) != data;
        }
    }

    template<typename T>
    inline T DoubleLinkedList<T>::removeAt(int index)
    {
        //skontroluj ci to mas dobre
        Utils::rangeCheckExcept(index, size_, "Invalid index at LinkedList.removeAt, index");
        DoubleLinkedListItem<T>* itemToDelete = getItemAtIndex(index);

        if (size_ == 1)
        {
            itemToDelete = first_;
            first_ = nullptr;
            last_ = nullptr;
        } else
        {
            if (index == 0)
            {
                itemToDelete = first_;
                first_ = first_->getNext();
                first_->setPrevious(nullptr);
            } else
            {
                itemToDelete->getPrevious()->setNext(itemToDelete->getNext());


                if (itemToDelete == last_)
                {
                    last_ = itemToDelete->getPrevious();
                } else
                {
                    itemToDelete->getNext()->setPrevious(itemToDelete->getPrevious());
                }
            }
        }

        T data = itemToDelete->accessData();
        delete itemToDelete;
        size_--;

        return data;
    }

    template<typename T>
    inline int DoubleLinkedList<T>::getIndexOf(const T& data)
    {
        int index = 0;
        for (T element: *this)
        {
            if (element == data)
            {
                return index;
            }
            ++index;
        }
        return -1;
    }

    template<typename T>
    inline void DoubleLinkedList<T>::clear()
    {
        DoubleLinkedListItem<T>* item = first_;

        while (item != nullptr)
        {
            DoubleLinkedListItem<T>* nextItem = item->getNext();
            delete item;
            item = nextItem;
        }
        size_ = 0;
        first_ = nullptr;
        last_ = nullptr;
    }

    template<typename T>
    inline Iterator <T>* DoubleLinkedList<T>::getBeginIterator()
    {
        return new DoubleLinkListIterator(first_);
    }

    template<typename T>
    inline Iterator <T>* DoubleLinkedList<T>::getEndIterator()
    {
        return new DoubleLinkListIterator(nullptr);
    }

    template<typename T>
    DoubleLinkedListItem<T>* DoubleLinkedList<T>::getItemAtIndex(int index)
    {
        Utils::rangeCheckExcept(index, size_, "Invalid index in LinkedListItem.getItemAtIndex!");
        bool iteratingFromStart = true;

        DoubleLinkedListItem<T>* item = first_;

        if (index > (size_) / 2)
        {
            iteratingFromStart = false;
            item = last_;
        }

        if (iteratingFromStart)
        {
            for (int i = 0; i < index; ++i)
            {
                item = item->getNext();
            }
        } else
        {
            //TODO neviem ci funguje
            for (int i = 0; i > size_ - (index - 1); ++i)
            {
                item = item->getPrevious();
            }
        }
        return item;
    }
}