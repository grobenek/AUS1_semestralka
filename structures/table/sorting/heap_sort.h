#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures
{
	/// <summary> Triedenie Heap sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class HeapSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Heap sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
	};

	template<typename K, typename T>
	inline void HeapSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{
		bool vymena;

        for (int i = 1; i < table.size() - 1; ++i)
        {
            int aktualny = i;

            do
            {
                vymena = false;
                int otec = (aktualny - 1) / 2;

                if ((aktualny > 0) && (table.getItemAtIndex(aktualny).getKey() > table.getItemAtIndex(otec).getKey()))
                {
                    Utils::swap(table.getItemAtIndex(aktualny), table.getItemAtIndex(otec));
                    aktualny = otec;
                    vymena = true;
                }
            } while (vymena);
        }
        // vyberanie z haldy
	}

}