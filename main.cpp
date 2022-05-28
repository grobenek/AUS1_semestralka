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
#include "sorting/ShellSort.h"
#include "output/ConsoleOutput.h"

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


    auto* okresyKody = new DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>();
    auto* okresy = DataLoader::nacitajOkres("okresy.csv", *kraje, *krajeKody, *okresyKody);
//    for (auto item: *okresy)
//    {
//        std::cout << item->accessData()->getOfficialTitle() << std::endl;
//    }

    auto* obceKody = new DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>();
    auto* obce = DataLoader::nacitajObce("obce.csv", *okresy, *okresyKody, *obceKody);
//    for (auto item: *obceKody)
//    {
//        std::cout << item->getKey() << std::endl;
//    }

    DataLoader::nacitajVzdelanie("vzdelanie.csv", *obce, *obceKody);
//    int pocitadlo = 0;
//    for (auto item: *obce)
//    {
//        if (item->accessData()->getVzdelanieUtriedene() == nullptr)
//        {
//            std::cout << "Nenajdene vzdelanie pre obec : " << item->accessData()->getOfficialTitle() << std::endl;
//            pocitadlo++;
//            continue;
//        }
//        std::cout << "Vzdelanie pre obec :" << item->accessData()->getOfficialTitle() << std::endl;
//        for (int i = 0; i < item->accessData()->getVzdelanieUtriedene()->size(); ++i)
//        {
//            std::cout << item->accessData()->getVzdelanieUtriedene()->at(i) << std::endl;
//        }
//        std::cout << "--------------------------------" << std::endl;
//    }
//    std::cout << "Nenajdene data pre: " << pocitadlo << " obci." << std::endl;


    DataLoader::nacitajVek("vek.csv", *obce, *obceKody);
//    int pocitadloVek = 0;
//    for (auto item: *obce)
//    {
//        if (item->accessData()->getVekUtriedene() == nullptr)
//        {
//            std::cout << "Nenajdene vek pre obec : " << item->accessData()->getOfficialTitle() << std::endl;
//            pocitadloVek++;
//            continue;
//        }
//        std::cout << "Vek pre obec :" << item->accessData()->getOfficialTitle() << std::endl;
//        for (int i = 0; i < item->accessData()->getVekUtriedene()->size(); ++i)
//        {
//            std::cout << item->accessData()->getVekUtriedene()->at(i) << std::endl;
//        }
//        std::cout << "--------------------------------" << std::endl;
//    }
//    std::cout << "Nenajdene data pre: " << pocitadloVek << " obci." << std::endl;
//
//
//    for (auto item: *okresy)
//    {
//        std::cout << item->accessData()->getOfficialTitle() << " - ";
//        for (int i = 0; i < item->accessData()->getVyssiUzemnyCelok()->getVekUtriedene()->size(); ++i)
//        {
//            std::cout << item->accessData()->getVyssiUzemnyCelok()->getVekUtriedene()->at(i) << " ";
//        }
//        std::cout << std::endl;
//    }

    //TODO skusit filtre, spravit triedenie a ovladanie pomocou konzole - inspirovat sa AUS console


    //TODO spravit prislusnost aj pre vyssie uzemne jednotky
//    auto* filterPrislusnost = new FilterUzemnaJednotkaPrislusnost("Okres Trebišov");
//
//    auto* resultOfFilterPocet = filterPrislusnost->passStructure(*obce);
//
//    ShellSort<int>::sort(*resultOfFilterPocet, new CriteriumVzdelaniePocet(VYSOKOSKOLSKE), true);
//    for (auto item: *resultOfFilterPocet)
//    {
//        std::cout << item->getVyssiUzemnyCelok()->getOfficialTitle() << " : " << item->getOfficialTitle() << " - " << item->getVzdelanieUtriedene()->at(VYSOKOSKOLSKE) << std::endl;
//    }


    bool run = true;
    std::cout << "Vitaj v semestralnej aplikacii Petra szathmaryho!" << std::endl;
    do
    {
        ConsoleOutput::printGeneralChoices();
        std::string choice = ConsoleOutput::readChoiceWord();

        int numberChoice;
        try
        {
            numberChoice = std::stoi(choice);
        } catch (std::invalid_argument& exception)
        {
            std::cout << "Pozor, musis zadat cislo!" << std::endl;
            continue;
        }
        switch (numberChoice)
        {
            case 1:
            { // bodove filtrovanie
                ConsoleOutput::printPointSeachChoices();
                std::string choiceOfPointSearch = ConsoleOutput::readChoiceWord();

                switch (std::stoi(choiceOfPointSearch))
                {
                    case 1: //obce
                    {
                        std::cout << "priklad: Topoľčany" << std::endl << "Zadavat s diakritikou a velkymi pismenami!" << std::endl;
                        ConsoleOutput::printInputName();
                        std::string choiceOfPointSeachUzemnaJednotka = ConsoleOutput::readChoiceRow();
                        ConsoleOutput::newLine();


                        auto* results = obce->findAll(choiceOfPointSeachUzemnaJednotka);
                        if (results == nullptr)
                        {
                            std::cout << "Nenajdena ziadna zhoda!" << std::endl;
                            break;
                        }
                        ConsoleOutput::printResultChoicestitlesTableItem(*results);
                        delete results;
                        break;
                    }
                    case 2:
                    {
                        std::cout << "priklad: Okres Senec" << std::endl << "Zadavat s diakritikou a velkymi pismenami!" << std::endl;
                        ConsoleOutput::printInputName();
                        std::string choiceOfPointSeachUzemnaJednotka = ConsoleOutput::readChoiceRow();
                        ConsoleOutput::newLine();


                        auto* results = okresy->findAll(choiceOfPointSeachUzemnaJednotka);
                        if (results == nullptr)
                        {
                            std::cout << "Nenajdena ziadna zhoda!" << std::endl;
                            break;
                        }
                        ConsoleOutput::printResultChoicestitlesTableItem(*results);
                        delete results;
                        break;
                    }
                    case 3:
                    {
                        std::cout << "priklad: Žilinský kraj" << std::endl << "Zadavat s diakritikou a velkymi pismenami!" << std::endl;
                        ConsoleOutput::printInputName();
                        std::string choiceOfPointSeachUzemnaJednotka = ConsoleOutput::readChoiceRow();
                        ConsoleOutput::newLine();


                        auto* results = kraje->findAll(choiceOfPointSeachUzemnaJednotka);
                        if (results == nullptr)
                        {
                            std::cout << "Nenajdena ziadna zhoda!" << std::endl;
                            break;
                        }
                        ConsoleOutput::printResultChoicestitlesTableItem(*results);
                        delete results;
                        break;
                    }
                }
                break;
            }
            case 2:
                break;
            case 9:
                run = false;
                break;
            default:
                std::cout << "Zle zadana moznost!" << std::endl;
                break;
        }
    } while (run);






    delete obce;
    delete obceKody;
    delete kraje;
    delete okresyKody;
    delete krajeKody;
    delete okresy;
}