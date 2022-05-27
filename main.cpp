#include <iostream>
#include "structures/table/DuplicitySortedSequenceTable.h"
#include "criteriums/CriteriumNazov.h"
#include "criteriums/CriteriumVzdelaniePocet.h"
#include "uzemna_jednotka/Obec.h"
#include "filters/FilterVzdelaniePocet.h"
#include "filters/FilterVzdelaniePodiel.h"
#include "filters/FilterUzemnaJednotkaTyp.h"
#include "filters/FilterUzemnaJednotkaPrislusnost.h"
#include "input/DataLoader.h"

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

void spustiSa();

int main()
{
    spustiSa();
    system("leaks Szathmary_semestralna_praca");

    // musim byt vo folder build-debug
    // potom dat
    // pvs-studio-analyzer analyze
    // potom dat
    // plog-converter -a GA:1,2 -t fullhtml -o report.tasks PVS-Studio.log

    return 0;
}

void spustiSa()
{

    auto* krajeKody = new DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>();
    auto* kraje = DataLoader::nacitajKraj("kraje.csv", *krajeKody);
//    for (auto item: *krajeKody)
//    {
//        std::cout << item->getKey() << std::endl;
//    }



    auto* okresyKody = new DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>();
    auto* okresy = DataLoader::nacitajOkres("okresy.csv", *krajeKody, *okresyKody);
//    for (auto item: *okresy)
//    {
//        std::cout << item->accessData()->getOfficialTitle() << std::endl;
//    }

    auto* obceKody = new DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>();
    auto* obce = DataLoader::nacitajObce("obce.csv", *okresyKody, *obceKody);
//    for (auto item: *obceKody)
//    {
//        std::cout << item->getKey() << std::endl;
//    }

    DataLoader::nacitajVzdelanie("vzdelanie.csv", *obce, *obceKody);
    int pocitadlo = 0;
    for (auto item: *obce)
    {
        if (item->accessData()->getVzdelanieUtriedene() == nullptr)
        {
            std::cout << "Nenajdene vzdelanie pre obec : " << item->accessData()->getOfficialTitle() << std::endl;
            pocitadlo++;
            continue;
        }
        std::cout << "Vzdelanie pre obec :" << item->accessData()->getOfficialTitle() << std::endl;
        for (int i = 0; i < item->accessData()->getVzdelanieUtriedene()->size(); ++i)
        {
            std::cout << item->accessData()->getVzdelanieUtriedene()->at(i) << std::endl;
        }
        std::cout << "--------------------------------" << std::endl;
    }
    std::cout << "Nenajdene data pre: " << pocitadlo << " obci." << std::endl;


    delete obce;
    delete obceKody;
    delete kraje;
    delete okresyKody;
    delete krajeKody;
    delete okresy;
}