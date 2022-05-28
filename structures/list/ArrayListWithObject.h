//
// Created by Peter Szathmáry on 25/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_ARRAYLISTWITHOBJECT_H
#define SZATHMARY_SEMESTRALNA_PRACA_ARRAYLISTWITHOBJECT_H

template<typename ObjectType>
class ArrayListWithObject : public structures::ArrayList<ObjectType>
{
public:
    ~ArrayListWithObject() override
    {
        for (int i = 0; i < this->array_->size(); ++i)
        {
            delete this->array_->at(i);
        }

        delete this->array_;

        this->array_ = nullptr;
        this->size_ = 0;
    }


};


#endif //SZATHMARY_SEMESTRALNA_PRACA_ARRAYLISTWITHOBJECT_H
