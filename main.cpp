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
#include "filters/CompositeFilter.h"
#include "filters/FilterAnd.h"
#include "filters/FilterOr.h"

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

                int choiceOfPointSearchInt;
                try
                {
                    choiceOfPointSearchInt =  std::stoi(choiceOfPointSearch);
                } catch (std::invalid_argument& exception)
                {
                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                    break;
                }
                switch (choiceOfPointSearchInt)
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
                    default:
                    {
                        std::cout << "Zle zadana moznost!" << std::endl;
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                //filtrovanie
                ConsoleOutput::printFiltersChoiceKind();
                std::string choiceOfFilterKind = ConsoleOutput::readChoiceWord();

                int choiceOfFiltersKindInt;
                try
                {
                    choiceOfFiltersKindInt =  std::stoi(choiceOfFilterKind);
                } catch (std::invalid_argument& exception)
                {
                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                    break;
                }
                CompositeFilter<UzemnaJednotka*, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>>* filter = nullptr;
                switch (choiceOfFiltersKindInt)    // vyberam vhodny typ filtra
                {
                    case 1:
                    {
                        filter = new FilterAnd();
                        break;
                    }
                    case 2:
                    {
                        filter = new FilterOr();
                        break;
                    }
                    default:
                    {
                        std::cout << "Pozor, musis zadat cislo!" << std::endl;
                        break;
                    }
                }
                if (filter == nullptr)
                {
                    delete obce;
                    delete obceKody;
                    delete kraje;
                    delete okresyKody;
                    delete krajeKody;
                    delete okresy;
                    return;
                }
                std::string choiceOfFilters;
                do
                {
                    ConsoleOutput::printFiltersChoices();
                    choiceOfFilters = ConsoleOutput::readChoiceWord();

                    int choiceOfFiltersInt;
                    try
                    {
                        choiceOfFiltersInt =  std::stoi(choiceOfFilters);
                    } catch (std::invalid_argument& exception)
                    {
                        std::cout << "Pozor, musis zadat cislo!" << std::endl;
                        continue;
                    }

                    switch (choiceOfFiltersInt)
                    {
                        case 1:
                        {
                            ConsoleOutput::printFilterMinValue();
                            std::string minValue = ConsoleOutput::readChoiceWord();
                            ConsoleOutput::printFilterMaxValue();
                            std::string maxValue = ConsoleOutput::readChoiceWord();

                            int minValueInt;
                            try
                            {
                                minValueInt =  std::stoi(minValue);
                            } catch (std::invalid_argument& exception)
                            {
                                std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                break;
                            }

                            int maxValueInt;
                            try
                            {
                                maxValueInt =  std::stoi(maxValue);
                            } catch (std::invalid_argument& exception)
                            {
                                std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                break;
                            }

                            ConsoleOutput::printTypVzdelania();
                            std::string typVzdelanie = ConsoleOutput::readChoiceWord();

                            int typVzdelanieInt;
                            try
                            {
                                typVzdelanieInt = std::stoi(typVzdelanie);
                            } catch (std::invalid_argument& exception)
                            {
                                std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                break;
                            }

                            try
                            {
                                filter->registerFilter(new FilterVzdelaniePocet(minValueInt, maxValueInt, ConsoleOutput::getTypVzdelanie(typVzdelanieInt)));
                            } catch (std::invalid_argument& exception)
                            {
                                std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                break;
                            }
                            break;
                        }
                        case 2:
                        {
                            ConsoleOutput::printFilterMinValue();
                            std::string minValue = ConsoleOutput::readChoiceWord();
                            ConsoleOutput::printFilterMaxValue();
                            std::string maxValue = ConsoleOutput::readChoiceWord();

                            double minValueDouble;
                            try
                            {
                                minValueDouble =  std::stoi(minValue);
                            } catch (std::invalid_argument& exception)
                            {
                                std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                break;
                            }

                            double maxValueDouble;
                            try
                            {
                                maxValueDouble =  std::stoi(maxValue);
                            } catch (std::invalid_argument& exception)
                            {
                                std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                break;
                            }

                            ConsoleOutput::printTypVzdelania();
                            std::string typVzdelanie = ConsoleOutput::readChoiceWord();

                            int typVzdelanieInt;
                            try
                            {
                                typVzdelanieInt = std::stoi(typVzdelanie);
                            } catch (std::invalid_argument& exception)
                            {
                                std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                break;
                            }

                            try
                            {
                                filter->registerFilter(new FilterVzdelaniePodiel(minValueDouble, maxValueDouble, ConsoleOutput::getTypVzdelanie(typVzdelanieInt)));
                            } catch (std::invalid_argument& exception)
                            {
                                std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                break;
                            }
                            break;
                        }
                        case 3:
                        {
                            std::cout << "Nazov vyssej uzemnej jednotky: ";
                            std::string nazovUzemnejJednotky = ConsoleOutput::readChoiceRow();

                            filter->registerFilter(new FilterUzemnaJednotkaPrislusnost(nazovUzemnejJednotky));
                            break;
                        }
                        case 4:
                        {
                            ConsoleOutput::printUzemnaJednotkaTyp();
                            std::string typUzemnejJednotkyChoice = ConsoleOutput::readChoiceRow();

                            int typUzemnejJednotkyInt;
                            try
                            {
                                typUzemnejJednotkyInt = std::stoi(typUzemnejJednotkyChoice);
                            } catch (std::invalid_argument& exception)
                            {
                                std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                break;
                            }

                            try
                            {
                                filter->registerFilter(new FilterUzemnaJednotkaTyp(ConsoleOutput::getUzemnaJednotkaTyp(typUzemnejJednotkyInt)));
                            } catch (std::invalid_argument& exception)
                            {
                                std::cout << "Zle zadana moznost!" << std::endl;
                                break;
                            }
                            break;
                        }
                        case 0:
                        {
                            if (filter->getSizeOfFilters() != 0 && filter != nullptr)
                            {

                                ConsoleOutput::printUzemnaJednotkaTyp();
                                std::string typUzemnejJednotkyChoice = ConsoleOutput::readChoiceRow();

                                int typUzemnejJednotkyInt;
                                try
                                {
                                    typUzemnejJednotkyInt = std::stoi(typUzemnejJednotkyChoice);
                                } catch (std::invalid_argument& exception)
                                {
                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                    break;
                                }
                                List<UzemnaJednotka*>* result = nullptr;
                                switch (typUzemnejJednotkyInt)
                                {
                                    case 1:
                                    {
                                        result = filter->passStructure(*obce);
                                        break;
                                    }
                                    case 2:
                                    {
                                        result = filter->passStructure(*okresy);
                                        break;
                                    }
                                    case 3:
                                    {
                                        result = filter->passStructure(*kraje);
                                        break;
                                    }
                                    default:
                                    {
                                        delete filter;
                                        filter = nullptr;
                                        std::cout << "Zle zadana moznost!" << std::endl;
                                        continue;
                                    }
                                }

//                                auto* result = filter->passStructure(*obce); //TODO spravit vypisy criterii
                                if (result == nullptr)
                                {
                                    std::cout << "Ziadne najdene zhody!" << std::endl;
                                    break;
                                }
                                ConsoleOutput::printResultChoicesTitles(*result, false, false);
                                delete result;
                                delete filter;
                                filter = nullptr;
                            }
                            delete filter; //TODO leaky v CompositeFilter, vola sa konstruktor abstraktnej triedy
                            filter = nullptr;
                            break;
                        }
                        default:
                        {
                            std::cout << "Zle zadana moznost!" << std::endl;
                            continue;
                        }
                    }
                } while (choiceOfFilters != "0");

                break;
            }
            case 3:
            {
                //TODO triedenie
                ConsoleOutput::printUseFilterChoice();
                std::string choiceUseFilter = ConsoleOutput::readChoiceWord();

                int choiceUseFilterInt;
                try
                {
                    choiceUseFilterInt = std::stoi(choiceUseFilter);
                } catch (std::invalid_argument& exception)
                {
                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                    break;
                }
                switch (choiceUseFilterInt)
                {
                    case 1:
                    {
                        //nacitanie a pouzitie filtrov

                        break;
                    }
                    case 2:
                    {
                        break;
                    }
                    default:
                        std::cout << "Zle zadana moznost!" << std::endl;
                        break;
                }
                //rozhodnutie o aku uzemnu jednotku sa jedna

                break;
                //TODO koniec case 3
            }
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