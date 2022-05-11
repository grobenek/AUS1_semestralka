#pragma once

#include "matrix.h"
#include <stdexcept>

namespace structures
{
    /// <summary> Implementacia matice v nesuvislej pamati. </summary>
    /// <typeparam name = "T"> Typ dat ukladanych v matici. </typepram>
    template<typename T>
    class IncoherentMatrix
            : public Matrix<T>
    {
    public:
        /// <summary>
        ///	Konstruktor. Vytvori maticu o danom pocte riadkov a stlpcov.
        /// Polozky su inicializovane na "nulovu" hodnotu typu T.
        /// </summary>
        /// <param name="rowCount"> Pocet riadkov. </param>
        /// <param name="columnCount"> Pocet stlpcov. </param>
        IncoherentMatrix(size_t rowCount, size_t columnCount);

        /// <summary> Inicializuje tuto maticu ako kopiu matice odovzdanej ako parameter. </summary>
        /// <param name = "other"> Odkaz na maticu, z ktorej sa prevezmu vlastnosti. </param>
        IncoherentMatrix(IncoherentMatrix& other);

        /// <summary> Destruktor. </summary>
        ~IncoherentMatrix();

        /// <summary>
        /// Ak je to mozne (parametrom je matica, ktora ma rovnake rozmery ako ako aktualna matica),
        /// tak skopiruje vlastnosti z matice odovzdanej ako parameter.
        /// Ak to nie je mozne, vyhodi sa vynimka.
        /// </summary>
        /// <param name = "other"> Odkaz na strukturu, z ktorej maju prebrat vlastnosti. </param>
        /// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
        Structure& assign(Structure& other) override;

        /// <summary>
        /// Ak je parametrom matica a obsah porovnavanych matic je rovnaky,
        /// tak vrati hodnotu true. V opacnom pripade vrati hodnotu false.
        /// </summary>
        /// <param name="other"> Odkaz na strukturu, s ktorou sa ma tato matica porovnat. </param>
        /// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
        bool equals(Structure& other) override;

        /// <summary> Pocet vsetkych prvkov v matici. </summary>
        /// <returns> Pocet prvkov v matici. </returns>
        size_t size() override;

        /// <summary> Vrati pocet riadkov v matici. </summary>
        /// <returns> Pocet riadkov matice. </returns>
        size_t getRowCount() override;

        /// <summary> Vrati pocet stlpcov matice. </summary>
        /// <returns> Pocet stlpcov matice. </returns>
        size_t getColumnCount() override;

        /// <summary> Vrati odkaz na prvok v danom riadku a stlpci. </summary>
        /// <param name="rowIndex"> Index riadku. </param>
        /// <param name="columnIndex"> Index stlpca. </param>
        /// <returns> Odkaz na prvok na danych indexoch. </returns>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index riadku alebo stlpca nepatri do matice. </exception>
        T& at(int rowIndex, int columnIndex) override;

    private:
        Array<Array < T>*>* rows_;
        size_t rowCount_;
        size_t columnCount_;
    };

    template<typename T>
    inline IncoherentMatrix<T>::IncoherentMatrix(size_t rowCount, size_t columnCount)
    {
        rowCount_ = rowCount;
        columnCount_ = columnCount;
        rows_ = new Array<Array<T>*>(rowCount_);

        for (int i = 0; i < rowCount_; ++i)
        {
            auto* row = new Array<T>(columnCount_);
            rows_->at(i) = row;
        }
    }

    template<typename T>
    inline IncoherentMatrix<T>::IncoherentMatrix(IncoherentMatrix& other)
    {
        rowCount_ = other.rowCount_;
        columnCount_ = other.columnCount_;

        rows_ = new Array<Array<T>*>(rowCount_);
        for (int i = 0; i < rowCount_; ++i)
        {
            auto* row = new Array<T>(columnCount_);
            row->copy(*other.rows_->at(i), 0, *row, 0, columnCount_);
            rows_->at(i) = row;
        }
    }

    template<typename T>
    inline IncoherentMatrix<T>::~IncoherentMatrix()
    {
        for (int i = 0; i < rowCount_; ++i)
        {
            delete rows_->at(i);
        }

        delete rows_;
        rows_ = nullptr;
        rowCount_ = 0;
        columnCount_ = 0;
    }

    template<typename T>
    inline Structure& IncoherentMatrix<T>::assign(Structure& other)
    {
        if (this != &other)
        {
            auto* otherMatrix = dynamic_cast<IncoherentMatrix<T>*>(&other);
            if (otherMatrix == nullptr)
            {
                throw std::runtime_error("Not assigning Matrix");
            }
            if (otherMatrix->rowCount_ == rowCount_ && otherMatrix->columnCount_ == columnCount_)
            {
                rowCount_ = otherMatrix->rowCount_;
                columnCount_ = otherMatrix->columnCount_;

                for (int i = 0; i < rowCount_; ++i)
                {
                    rows_->at(i)->assign(*otherMatrix->rows_->at(i));
                }

            } else
            {
                throw std::invalid_argument("Matrixes sizes differ!");
            }
        }
        return *this;
    }

    template<typename T>
    inline bool IncoherentMatrix<T>::equals(Structure& other)
    {
        auto* otherMatrix = dynamic_cast<IncoherentMatrix<T>*>(&other);
        if (this == &other)
        {
            return true;
        }

        if (otherMatrix != nullptr)
        {
            for (int i = 0; i < rowCount_; ++i)
            {
                if (!rows_->at(i)->equals(*otherMatrix->rows_->at(i)))
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
    inline size_t IncoherentMatrix<T>::size()
    {
        return rowCount_ * columnCount_;
    }

    template<typename T>
    inline size_t IncoherentMatrix<T>::getRowCount()
    {
        return rowCount_;
    }

    template<typename T>
    inline size_t IncoherentMatrix<T>::getColumnCount()
    {
        return columnCount_;
    }

    template<typename T>
    inline T& IncoherentMatrix<T>::at(int rowIndex, int columnIndex)
    {
        Utils::rangeCheckExcept(rowIndex, rowCount_, "Invalid row index in Incoherent_matrix.at()!");
        Utils::rangeCheckExcept(columnIndex, columnCount_, "Invalid column index in Incoherent_matrix.at()!");

        return rows_->at(rowIndex)->at(columnIndex);
    }
}