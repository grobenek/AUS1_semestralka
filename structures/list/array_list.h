#pragma once

#include "list.h"
#include "../structure_iterator.h"
#include "../array/array.h"

namespace structures
{
    /// <summary> Zoznam implementovany polom. </summary>
    /// <typeparam name = "T"> Typ dat ukladanych v zozname. </typepram>
    template<typename T>
    class ArrayList : public List<T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        ArrayList();

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> ArrayList, z ktoreho sa prevezmu vlastnosti. </param>
        ArrayList(ArrayList<T>& other);

        /// <summary> Destruktor. </summary>
        ~ArrayList();

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
        Iterator<T>* getBeginIterator() override;

        /// <summary> Vrati skutocny iterator na koniec struktury </summary>
        /// <returns> Iterator na koniec struktury. </returns>
        /// <remarks> Zabezpecuje polymorfizmus. </remarks>
        Iterator<T>* getEndIterator() override;

    protected:
/// <summary> Pole s datami. </summary>
Array<T>* array_;
        /// <summary> Pocet prvkov v zozname. </summary>
        size_t size_;
    private:
        /// <summary> Rozsiri kapacitu zoznamu. </summary>
        void enlarge();

        /// <summary> Iterator pre ArrayList. </summary>
        class ArrayListIterator : public Iterator<T>
        {
        public:
            /// <summary> Konstruktor. </summary>
            /// <param name = "arrayList"> Zoznam, cez ktory iteruje. </param>
            /// <param name = "position"> Pozicia, na ktorej zacina. </param>
            ArrayListIterator(ArrayList<T>* arrayList, int position);

            /// <summary> Destruktor. </summary>
            ~ArrayListIterator();

            /// <summary> Operator priradenia. Priradi do seba hodnotu druheho iteratora. </summary>
            /// <param name = "other"> Druhy iterator. </param>
            /// <returns> Vrati seba po priradeni. </returns>
            Iterator<T>& operator=(Iterator<T>& other) override;

            /// <summary> Porovna sa s druhym iteratorom na nerovnost. </summary>
            /// <param name = "other"> Druhy iterator. </param>
            /// <returns> True, ak sa iteratory nerovnaju, false inak. </returns>
            bool operator!=(Iterator<T>& other) override;

            /// <summary> Vrati data, na ktore aktualne ukazuje iterator. </summary>
            /// <returns> Data, na ktore aktualne ukazuje iterator. </returns>
            T operator*() override;

            /// <summary> Posunie iterator na dalsi prvok v strukture. </summary>
            /// <returns> Iterator na dalsi prvok v strukture. </returns>
            /// <remarks> Zvycajne vrati seba. Ak vrati iny iterator, povodny bude automaticky zruseny. </remarks>
            Iterator<T>& operator++() override;

        protected:
            /// <summary> Zoznam, cez ktory iteruje. </summary>
            ArrayList<T>* arrayList_;
            /// <summary> Aktualna pozicia v zozname. </summary>
            int position_;
        };
    };

    template<typename T>
    inline ArrayList<T>::ArrayList() :
            List<T>(),
            array_(new Array<T>(4)),
            size_(0)
    {
    }

    template<typename T>
    inline ArrayList<T>::ArrayList(ArrayList<T>& other) :
            List<T>(),
            array_(new Array<T>(*other.array_)), // vytvaram kopiu arrayu a velkosti
            size_(other.size_)
    {
    }

    template<typename T>
    inline ArrayList<T>::~ArrayList()
    {
        delete array_;

        array_ = nullptr;
        size_ = 0;
    }

    template<typename T>
    inline size_t ArrayList<T>::size()
    {
        return size_;
    }

    template<typename T>
    inline Structure& ArrayList<T>::assign(Structure& other)
    {
        if (this != &other)
        {
            auto& otherArrayList = dynamic_cast<ArrayList<T>&>(other);
            auto* newArray = new Array<T>(*otherArrayList.array_); // dereferencujem lebo to je pointer
            delete array_;
            array_ = newArray;
            size_ = otherArrayList.size_;
        }
        return *this;
    }

    template<typename T>
    inline bool ArrayList<T>::equals(Structure& other)
    {
        auto* otherList = dynamic_cast<ArrayList<T>*>(&other);
        if (otherList != nullptr)
        {
            if (size_ != otherList->size())
            {
                return false;
            }
            for (int i = 0; i < size_; ++i)
            {
                if (this->at(i) != otherList->at(i))
                {
                    return false;
                }
            }
            return true;
        } else
        {
            return false;
        }
    }

    template<typename T>
    inline T& ArrayList<T>::at(int index)
    {
        Utils::rangeCheckExcept(index, size_, "Invalid index!");
        return array_->at(index);
    }

    template<typename T>
    inline void ArrayList<T>::add(const T& data)
    {
        if (size_ == array_->size())
        {
            this->enlarge();
        }
        array_->at(size_) = data; // na index size si daj tie data - na posledný prvok
        size_++; // potrebujem si zväčšiť ten size
    }

    template<typename T>
    inline void ArrayList<T>::insert(const T& data, int index)
    {
        if (index == size_)
        {
            // add()
            this->add(data);
        } else
        {
            Utils::rangeCheckExcept(index, size_, "Invalid index!");
            // zmestí sa? (size_ == array_size - enlarge)
            if (size_ == array_->size())
            {
                this->enlarge();
            }

            // copy
            Array<T>::copy(*array_, index, *array_, index + 1, size_ - index);

            // vlož na index
            array_->at(index) = data;

            // zvýš veľkosť
            size_++;
        }
    }

    template<typename T>
    inline bool ArrayList<T>::tryRemove(const T& data)
    {
        int indexPrvku = this->getIndexOf(data);

        if (indexPrvku == -1)
        {
            return false;
        } else
        {
            this->removeAt(indexPrvku);
            if (this->size_ != 0)
            {
                if (this->size_ != indexPrvku)
                {
                    return this->at(indexPrvku) != data;
                } else
                {
                    return this->at(indexPrvku - 1) != data;
                }
            }
        }
    }

    template<typename T>
    inline T ArrayList<T>::removeAt(int index)
    {
        Utils::rangeCheckExcept(index, size_, "Invalid index!");

        T zmazanyPrvok = this->at(index);

        if (size_ == this->array_->size())
        {
            this->enlarge();
        }

        Array<T>::copy(*array_, index + 1, *array_, index, size_ - index - 1);

        size_--;

        return zmazanyPrvok;
    }

    template<typename T>
    inline int ArrayList<T>::getIndexOf(const T& data)
    {
        for (int i = 0; i < size_; i++)
        {
            if (this->at(i) == data)
            {
                return i;
            }
        }

        return -1;
    }

    template<typename T>
    inline void ArrayList<T>::clear()
    {
        size_ = 0; // len dam size na 0, pamat nam je jedno
    }

    template<typename T>
    inline Iterator<T>* ArrayList<T>::getBeginIterator()
    {
        return new ArrayListIterator(this, 0);
    }

    template<typename T>
    inline Iterator<T>* ArrayList<T>::getEndIterator()
    {
        return new ArrayListIterator(this, size_);
    }

    template<typename T>
    inline void ArrayList<T>::enlarge()
    {

        // vytvor nové pole
        // veľkosť dať 2*veľkosť pôvodného
        auto* newArray = new Array<T>(2 * array_->size());

        // skopíruj dáta do nového poľa - assign
        // zmaž nové, priraď pôvodné
        Array<T>::copy(*array_, 0, *newArray, 0, array_->size());
        delete array_;
        array_ = newArray;
    }

    template<typename T>
    inline ArrayList<T>::ArrayListIterator::ArrayListIterator(ArrayList<T>* arrayList, int position) :
            arrayList_(arrayList),
            position_(position)
    {
    }

    template<typename T>
    inline ArrayList<T>::ArrayListIterator::~ArrayListIterator()
    {
        arrayList_ = nullptr;
        position_ = -1;
    }

    template<typename T>
    inline Iterator<T>& ArrayList<T>::ArrayListIterator::operator=(Iterator<T>& other)
    {
        if (this != &other)
        {
            position_ = dynamic_cast<ArrayList<T>::ArrayListIterator&>(other).position_;
            //staci si kopirovat len position, je hlupost aby neukazovali na nieco ine
        }
        return *this;
    }

    template<typename T>
    inline bool ArrayList<T>::ArrayListIterator::operator!=(Iterator<T>& other)
    {
        return position_ != dynamic_cast<ArrayList<T>::ArrayListIterator&>(other).position_;
    }

    template<typename T>
    inline T ArrayList<T>::ArrayListIterator::operator*()
    {
        return arrayList_->at(position_);
    }

    template<typename T>
    inline Iterator<T>& ArrayList<T>::ArrayListIterator::operator++()
    {
        //a++ vrati povodnu hodnotu
        //++a vrati navysenu hodnotu

        position_++;
        //vraciam novu hodnotu na seba
        return *this;
    }

}