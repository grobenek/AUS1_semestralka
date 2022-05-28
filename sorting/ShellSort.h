//
// Created by Peter Szathmáry on 28/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_SHELLSORT_H
#define SZATHMARY_SEMESTRALNA_PRACA_SHELLSORT_H

#include <cmath>
#include "../uzemna_jednotka/UzemnaJednotka.h"
#include "../criteriums/Criterium.h"

template<typename TypeToSort>
class ShellSort
{
private:
    static void shellSort(structures::List<UzemnaJednotka*>& listToSort,
                          Criterium<UzemnaJednotka*, TypeToSort>* criterium, bool zostupne, int krok);

public:
    static void sort(structures::List<UzemnaJednotka*>& listToSort,
                     Criterium<UzemnaJednotka*, TypeToSort>* criterium, bool zostupne);
};

template<typename TypeToSort>
void
ShellSort<TypeToSort>::shellSort(structures::List<UzemnaJednotka*>& listToSort,
                                 Criterium<UzemnaJednotka*, TypeToSort>* criterium, bool zostupne, int krok)
{
    for (int delta = 0; delta < krok; delta++)
    {
        for (int i = delta; i < listToSort.size(); i += krok)
        {
            int j = i;
            if (!zostupne)
            {
                while (j - krok >= delta && criterium->evaluate(listToSort.at(j)) < criterium->evaluate(listToSort.at(j - krok)))
                {
                    structures::Utils::swap(listToSort.at(j), listToSort.at(j - krok));
                    j -= krok;
                }
            }
            else {
                while (j - krok >= delta && criterium->evaluate(listToSort.at(j)) > criterium->evaluate(listToSort.at(j - krok))) {
                    structures::Utils::swap(listToSort.at(j), listToSort.at(j - krok));
                    j -= krok;
                }
            }
        }
        if (krok > 1) {
            shellSort(listToSort, criterium, zostupne, krok - 1);
        }
    }
}

template<typename TypeToSort>
void ShellSort<TypeToSort>::sort(structures::List<UzemnaJednotka*>& listToSort,
                                 Criterium<UzemnaJednotka*, TypeToSort>* criterium, bool zostupne)
{
    int krok = ceil(log10(listToSort.size()));
    shellSort(listToSort, criterium, zostupne, krok);
}


#endif //SZATHMARY_SEMESTRALNA_PRACA_SHELLSORT_H
