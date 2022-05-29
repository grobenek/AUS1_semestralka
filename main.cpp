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
#include "filters/FilterAll.h"

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
                                ConsoleOutput::printResultChoicesTitles(*result);
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
                        List<UzemnaJednotka*>* result = nullptr;
                        //nacitanie a pouzitie filtrov
                        {
                            //filtrovanie
                            ConsoleOutput::printFiltersChoiceKind();
                            std::string choiceOfFilterKind = ConsoleOutput::readChoiceWord();

                            int choiceOfFiltersKindInt;
                            try
                            {
                                choiceOfFiltersKindInt = std::stoi(choiceOfFilterKind);
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
                                    choiceOfFiltersInt = std::stoi(choiceOfFilters);
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
                                            minValueInt = std::stoi(minValue);
                                        } catch (std::invalid_argument& exception)
                                        {
                                            std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                            break;
                                        }

                                        int maxValueInt;
                                        try
                                        {
                                            maxValueInt = std::stoi(maxValue);
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
                                            filter->registerFilter(new FilterVzdelaniePocet(minValueInt, maxValueInt,
                                                                                            ConsoleOutput::getTypVzdelanie(
                                                                                                    typVzdelanieInt)));
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
                                            minValueDouble = std::stoi(minValue);
                                        } catch (std::invalid_argument& exception)
                                        {
                                            std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                            break;
                                        }

                                        double maxValueDouble;
                                        try
                                        {
                                            maxValueDouble = std::stoi(maxValue);
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
                                            filter->registerFilter(
                                                    new FilterVzdelaniePodiel(minValueDouble, maxValueDouble,
                                                                              ConsoleOutput::getTypVzdelanie(
                                                                                      typVzdelanieInt)));
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

                                        filter->registerFilter(
                                                new FilterUzemnaJednotkaPrislusnost(nazovUzemnejJednotky));
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
                                            filter->registerFilter(new FilterUzemnaJednotkaTyp(
                                                    ConsoleOutput::getUzemnaJednotkaTyp(typUzemnejJednotkyInt)));
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
                                            //TODO reuslt
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
                        }
                        if (result != nullptr)
                        {
                         //TODO moznosti podla coho triedit
                            ConsoleOutput::printTriedenieAko();
                            std::string triedenieAko = ConsoleOutput::readChoiceWord();

                            int triedenieAkoInt;
                            try
                            {
                                triedenieAkoInt = std::stoi(triedenieAko);
                            } catch (std::invalid_argument& exception)
                            {
                                std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                break;
                            }

                            switch (triedenieAkoInt)
                            {
                                case 1:
                                {
                                    //vzostupne
                                    ConsoleOutput::printTriedenieCriteriumChoice();
                                    std::string triedenieKriterium = ConsoleOutput::readChoiceWord();

                                    int triedenieKriteriumInt;
                                    try
                                    {
                                        triedenieKriteriumInt = std::stoi(triedenieKriterium);
                                    } catch (std::invalid_argument& exception)
                                    {
                                        std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                        break;
                                    }
                                    switch (triedenieKriteriumInt)
                                    {
                                        case 1:
                                        {
                                            //vzostupne
                                            auto* criterium = new CriteriumNazov();
                                            ShellSort<std::string>::sort(*result, criterium, false);
                                            delete criterium;
                                            ConsoleOutput::printResultChoicesTitles(
                                                    *result); //TODO vypisy treba spravit len pre dane kriteria!!
                                            delete result;
                                            break;
                                        }
                                        case 2:
                                        {
                                            ConsoleOutput::printTypVzdelania();
                                            std::string typVzdelania = ConsoleOutput::readChoiceWord();

                                            int typVzdelaniaInt;
                                            try
                                            {
                                                typVzdelaniaInt = std::stoi(typVzdelania);
                                            } catch (std::invalid_argument& exception)
                                            {
                                                std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                break;
                                            }

                                            auto* criterium = new CriteriumVzdelaniePocet(ConsoleOutput::getTypVzdelanie(typVzdelaniaInt));
                                            ShellSort<int>::sort(*result, criterium, false);
                                            delete criterium;
                                            ConsoleOutput::printResultChoicesTitles(
                                                    *result); //TODO vypisy treba spravit len pre dane kriteria!!
                                            delete result;
                                            break;
                                        }
                                        case 3:
                                        {
                                            ConsoleOutput::printTypVzdelania();
                                            std::string typVzdelania = ConsoleOutput::readChoiceWord();

                                            int typVzdelaniaInt;
                                            try
                                            {
                                                typVzdelaniaInt = std::stoi(typVzdelania);
                                            } catch (std::invalid_argument& exception)
                                            {
                                                std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                break;
                                            }

                                            auto* criterium = new CriteriumVzdelaniePodiel(ConsoleOutput::getTypVzdelanie(typVzdelaniaInt));
                                            ShellSort<double>::sort(*result, criterium, false);
                                            delete criterium;
                                            ConsoleOutput::printResultChoicesTitles(
                                                    *result); //TODO vypisy treba spravit len pre dane kriteria!!
                                            delete result;
                                            break;
                                        }
                                    }
                                    break;
                                }
                                case 2:
                                {
                                    //zostupne
                                    ConsoleOutput::printTriedenieCriteriumChoice();
                                    std::string triedenieKriterium = ConsoleOutput::readChoiceWord();

                                    int triedenieKriteriumInt;
                                    try
                                    {
                                        triedenieKriteriumInt = std::stoi(triedenieKriterium);
                                    } catch (std::invalid_argument& exception)
                                    {
                                        std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                        break;
                                    }
                                    switch (triedenieKriteriumInt)
                                    {
                                        case 1:
                                        {
                                            auto* criterium = new CriteriumNazov();
                                            ShellSort<std::string>::sort(*result, criterium, true);
                                            delete criterium;
                                            ConsoleOutput::printResultChoicesTitles(
                                                    *result); //TODO vypisy treba spravit len pre dane kriteria!!
                                            delete result;
                                            break;
                                        }
                                        case 2:
                                        {
                                            ConsoleOutput::printTypVzdelania();
                                            std::string typVzdelania = ConsoleOutput::readChoiceWord();

                                            int typVzdelaniaInt;
                                            try
                                            {
                                                typVzdelaniaInt = std::stoi(typVzdelania);
                                            } catch (std::invalid_argument& exception)
                                            {
                                                std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                break;
                                            }

                                            auto* criterium = new CriteriumVzdelaniePocet(ConsoleOutput::getTypVzdelanie(typVzdelaniaInt));
                                            ShellSort<int>::sort(*result, criterium, true);
                                            delete criterium;
                                            ConsoleOutput::printResultChoicesTitles(
                                                    *result); //TODO vypisy treba spravit len pre dane kriteria!!
                                            delete result;
                                            break;
                                        }
                                        case 3:
                                        {
                                            ConsoleOutput::printTypVzdelania();
                                            std::string typVzdelania = ConsoleOutput::readChoiceWord();

                                            int typVzdelaniaInt;
                                            try
                                            {
                                                typVzdelaniaInt = std::stoi(typVzdelania);
                                            } catch (std::invalid_argument& exception)
                                            {
                                                std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                break;
                                            }

                                            auto* criterium = new CriteriumVzdelaniePodiel(ConsoleOutput::getTypVzdelanie(typVzdelaniaInt));
                                            ShellSort<double>::sort(*result, criterium, true);
                                            delete criterium;
                                            ConsoleOutput::printResultChoicesTitles(
                                                    *result); //TODO vypisy treba spravit len pre dane kriteria!!
                                            delete result;
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                        }

                        //TODO koniec filtrov
                        break;
                    }
                    case 2:
                    {
                        // ktory typ uzemnej jednotky?
                        ConsoleOutput::printTriedenieAko();
                        std::string triedenieAko = ConsoleOutput::readChoiceWord();

                        int triedenieAkoInt;
                        try
                        {
                            triedenieAkoInt = std::stoi(triedenieAko);
                        } catch (std::invalid_argument& exception)
                        {
                            std::cout << "Pozor, musis zadat cislo!" << std::endl;
                            break;
                        }

                        switch (triedenieAkoInt)
                        {
                            case 1:
                            {
                                //vzostupne
                                ConsoleOutput::printUzemnaJednotkaTyp();
                                std::string triedenieUzemnaJednotkaTyp = ConsoleOutput::readChoiceWord();

                                int triedenieUzemnaJednotkaTypInt;
                                try
                                {
                                    triedenieUzemnaJednotkaTypInt = std::stoi(triedenieAko);
                                } catch (std::invalid_argument& exception)
                                {
                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                    break;
                                }

                                switch (triedenieUzemnaJednotkaTypInt)
                                {
                                    case 1:
                                    {
                                        //obec
                                        ConsoleOutput::printTriedenieCriteriumChoice();
                                        std::string triedenieCriteriumChoice = ConsoleOutput::readChoiceWord();

                                        int triedenieCriteriumChoiceInt;
                                        try
                                        {
                                            triedenieCriteriumChoiceInt = std::stoi(triedenieCriteriumChoice);
                                        } catch (std::invalid_argument& exception)
                                        {
                                            std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                            break;
                                        }

                                        switch (triedenieCriteriumChoiceInt)
                                        {
                                            case 1:
                                            {
                                                //nazov
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*obce);
                                                auto* criterium = new CriteriumNazov();
                                                ShellSort<std::string>::sort(*result, criterium, false);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                            }
                                            case 2:
                                            {
                                                //pocet
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*obce);

                                                ConsoleOutput::printTypVzdelania();
                                                std::string vzdelanieTypChoice = ConsoleOutput::readChoiceWord();

                                                int vzdelanieTypChoiceInt;
                                                try
                                                {
                                                    vzdelanieTypChoiceInt = std::stoi(vzdelanieTypChoice);
                                                } catch (std::invalid_argument& exception)
                                                {
                                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                    break;
                                                }

                                                auto* criterium = new CriteriumVzdelaniePocet(ConsoleOutput::getTypVzdelanie(vzdelanieTypChoiceInt));
                                                ShellSort<int>::sort(*result, criterium, false);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                            }
                                            case 3:
                                            {
                                                //podiel
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*obce);

                                                ConsoleOutput::printTypVzdelania();
                                                std::string vzdelanieTypChoice = ConsoleOutput::readChoiceWord();

                                                int vzdelanieTypChoiceInt;
                                                try
                                                {
                                                    vzdelanieTypChoiceInt = std::stoi(vzdelanieTypChoice);
                                                } catch (std::invalid_argument& exception)
                                                {
                                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                    break;
                                                }

                                                auto* criterium = new CriteriumVzdelaniePodiel(ConsoleOutput::getTypVzdelanie(vzdelanieTypChoiceInt));
                                                ShellSort<double>::sort(*result, criterium, false);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                    case 2:
                                    {
                                        //okres
                                        ConsoleOutput::printTriedenieCriteriumChoice();
                                        std::string triedenieCriteriumChoice = ConsoleOutput::readChoiceWord();

                                        int triedenieCriteriumChoiceInt;
                                        try
                                        {
                                            triedenieCriteriumChoiceInt = std::stoi(triedenieCriteriumChoice);
                                        } catch (std::invalid_argument& exception)
                                        {
                                            std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                            break;
                                        }

                                        switch (triedenieCriteriumChoiceInt)
                                        {
                                            case 1:
                                            {
                                                //nazov
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*okresy);
                                                auto* criterium = new CriteriumNazov();
                                                ShellSort<std::string>::sort(*result, criterium, false);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                            }
                                            case 2:
                                            {
                                                //pocet
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*okresy);

                                                ConsoleOutput::printTypVzdelania();
                                                std::string vzdelanieTypChoice = ConsoleOutput::readChoiceWord();

                                                int vzdelanieTypChoiceInt;
                                                try
                                                {
                                                    vzdelanieTypChoiceInt = std::stoi(vzdelanieTypChoice);
                                                } catch (std::invalid_argument& exception)
                                                {
                                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                    break;
                                                }

                                                auto* criterium = new CriteriumVzdelaniePocet(ConsoleOutput::getTypVzdelanie(vzdelanieTypChoiceInt));
                                                ShellSort<int>::sort(*result, criterium, false);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                            }
                                            case 3:
                                            {
                                                //podiel
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*okresy);

                                                ConsoleOutput::printTypVzdelania();
                                                std::string vzdelanieTypChoice = ConsoleOutput::readChoiceWord();

                                                int vzdelanieTypChoiceInt;
                                                try
                                                {
                                                    vzdelanieTypChoiceInt = std::stoi(vzdelanieTypChoice);
                                                } catch (std::invalid_argument& exception)
                                                {
                                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                    break;
                                                }

                                                auto* criterium = new CriteriumVzdelaniePodiel(ConsoleOutput::getTypVzdelanie(vzdelanieTypChoiceInt));
                                                ShellSort<double>::sort(*result, criterium, false);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                    case 3:
                                    {
                                        //kraj
                                        ConsoleOutput::printTriedenieCriteriumChoice();
                                        std::string triedenieCriteriumChoice = ConsoleOutput::readChoiceWord();

                                        int triedenieCriteriumChoiceInt;
                                        try
                                        {
                                            triedenieCriteriumChoiceInt = std::stoi(triedenieCriteriumChoice);
                                        } catch (std::invalid_argument& exception)
                                        {
                                            std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                            break;
                                        }

                                        switch (triedenieCriteriumChoiceInt)
                                        {
                                            case 1:
                                            {
                                                //nazov
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*kraje);
                                                auto* criterium = new CriteriumNazov();
                                                ShellSort<std::string>::sort(*result, criterium, false);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                            }
                                            case 2:
                                            {
                                                //pocet
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*kraje);

                                                ConsoleOutput::printTypVzdelania();
                                                std::string vzdelanieTypChoice = ConsoleOutput::readChoiceWord();

                                                int vzdelanieTypChoiceInt;
                                                try
                                                {
                                                    vzdelanieTypChoiceInt = std::stoi(vzdelanieTypChoice);
                                                } catch (std::invalid_argument& exception)
                                                {
                                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                    break;
                                                }

                                                auto* criterium = new CriteriumVzdelaniePocet(ConsoleOutput::getTypVzdelanie(vzdelanieTypChoiceInt));
                                                ShellSort<int>::sort(*result, criterium, false);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                            }
                                            case 3:
                                            {
                                                //podiel
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*kraje);

                                                ConsoleOutput::printTypVzdelania();
                                                std::string vzdelanieTypChoice = ConsoleOutput::readChoiceWord();

                                                int vzdelanieTypChoiceInt;
                                                try
                                                {
                                                    vzdelanieTypChoiceInt = std::stoi(vzdelanieTypChoice);
                                                } catch (std::invalid_argument& exception)
                                                {
                                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                    break;
                                                }

                                                auto* criterium = new CriteriumVzdelaniePodiel(ConsoleOutput::getTypVzdelanie(vzdelanieTypChoiceInt));
                                                ShellSort<double>::sort(*result, criterium, false);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                }
                                break;
                            }
                            case 2:
                            {
                                //zostupne
                                ConsoleOutput::printUzemnaJednotkaTyp();
                                std::string triedenieUzemnaJednotkaTyp = ConsoleOutput::readChoiceWord();

                                int triedenieUzemnaJednotkaTypInt;
                                try
                                {
                                    triedenieUzemnaJednotkaTypInt = std::stoi(triedenieAko);
                                } catch (std::invalid_argument& exception)
                                {
                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                    break;
                                }

                                switch (triedenieUzemnaJednotkaTypInt)
                                {
                                    case 1:
                                    {
                                        //obec
                                        ConsoleOutput::printTriedenieCriteriumChoice();
                                        std::string triedenieCriteriumChoice = ConsoleOutput::readChoiceWord();

                                        int triedenieCriteriumChoiceInt;
                                        try
                                        {
                                            triedenieCriteriumChoiceInt = std::stoi(triedenieCriteriumChoice);
                                        } catch (std::invalid_argument& exception)
                                        {
                                            std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                            break;
                                        }

                                        switch (triedenieCriteriumChoiceInt)
                                        {
                                            case 1:
                                            {
                                                //nazov
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*obce);
                                                auto* criterium = new CriteriumNazov();
                                                ShellSort<std::string>::sort(*result, criterium, true);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                            }
                                            case 2:
                                            {
                                                //pocet
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*obce);

                                                ConsoleOutput::printTypVzdelania();
                                                std::string vzdelanieTypChoice = ConsoleOutput::readChoiceWord();

                                                int vzdelanieTypChoiceInt;
                                                try
                                                {
                                                    vzdelanieTypChoiceInt = std::stoi(vzdelanieTypChoice);
                                                } catch (std::invalid_argument& exception)
                                                {
                                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                    break;
                                                }

                                                auto* criterium = new CriteriumVzdelaniePocet(ConsoleOutput::getTypVzdelanie(vzdelanieTypChoiceInt));
                                                ShellSort<int>::sort(*result, criterium, true);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                            }
                                            case 3:
                                            {
                                                //podiel
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*obce);

                                                ConsoleOutput::printTypVzdelania();
                                                std::string vzdelanieTypChoice = ConsoleOutput::readChoiceWord();

                                                int vzdelanieTypChoiceInt;
                                                try
                                                {
                                                    vzdelanieTypChoiceInt = std::stoi(vzdelanieTypChoice);
                                                } catch (std::invalid_argument& exception)
                                                {
                                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                    break;
                                                }

                                                auto* criterium = new CriteriumVzdelaniePodiel(ConsoleOutput::getTypVzdelanie(vzdelanieTypChoiceInt));
                                                ShellSort<double>::sort(*result, criterium, true);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                    case 2:
                                    {
                                        //okres
                                        ConsoleOutput::printTriedenieCriteriumChoice();
                                        std::string triedenieCriteriumChoice = ConsoleOutput::readChoiceWord();

                                        int triedenieCriteriumChoiceInt;
                                        try
                                        {
                                            triedenieCriteriumChoiceInt = std::stoi(triedenieCriteriumChoice);
                                        } catch (std::invalid_argument& exception)
                                        {
                                            std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                            break;
                                        }

                                        switch (triedenieCriteriumChoiceInt)
                                        {
                                            case 1:
                                            {
                                                //nazov
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*okresy);
                                                auto* criterium = new CriteriumNazov();
                                                ShellSort<std::string>::sort(*result, criterium, true);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                            }
                                            case 2:
                                            {
                                                //pocet
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*okresy);

                                                ConsoleOutput::printTypVzdelania();
                                                std::string vzdelanieTypChoice = ConsoleOutput::readChoiceWord();

                                                int vzdelanieTypChoiceInt;
                                                try
                                                {
                                                    vzdelanieTypChoiceInt = std::stoi(vzdelanieTypChoice);
                                                } catch (std::invalid_argument& exception)
                                                {
                                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                    break;
                                                }

                                                auto* criterium = new CriteriumVzdelaniePocet(ConsoleOutput::getTypVzdelanie(vzdelanieTypChoiceInt));
                                                ShellSort<int>::sort(*result, criterium, true);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                            }
                                            case 3:
                                            {
                                                //podiel
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*okresy);

                                                ConsoleOutput::printTypVzdelania();
                                                std::string vzdelanieTypChoice = ConsoleOutput::readChoiceWord();

                                                int vzdelanieTypChoiceInt;
                                                try
                                                {
                                                    vzdelanieTypChoiceInt = std::stoi(vzdelanieTypChoice);
                                                } catch (std::invalid_argument& exception)
                                                {
                                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                    break;
                                                }

                                                auto* criterium = new CriteriumVzdelaniePodiel(ConsoleOutput::getTypVzdelanie(vzdelanieTypChoiceInt));
                                                ShellSort<double>::sort(*result, criterium, true);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                    case 3:
                                    {
                                        //kraj
                                        ConsoleOutput::printTriedenieCriteriumChoice();
                                        std::string triedenieCriteriumChoice = ConsoleOutput::readChoiceWord();

                                        int triedenieCriteriumChoiceInt;
                                        try
                                        {
                                            triedenieCriteriumChoiceInt = std::stoi(triedenieCriteriumChoice);
                                        } catch (std::invalid_argument& exception)
                                        {
                                            std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                            break;
                                        }

                                        switch (triedenieCriteriumChoiceInt)
                                        {
                                            case 1:
                                            {
                                                //nazov
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*kraje);
                                                auto* criterium = new CriteriumNazov();
                                                ShellSort<std::string>::sort(*result, criterium, true);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                            }
                                            case 2:
                                            {
                                                //pocet
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*kraje);

                                                ConsoleOutput::printTypVzdelania();
                                                std::string vzdelanieTypChoice = ConsoleOutput::readChoiceWord();

                                                int vzdelanieTypChoiceInt;
                                                try
                                                {
                                                    vzdelanieTypChoiceInt = std::stoi(vzdelanieTypChoice);
                                                } catch (std::invalid_argument& exception)
                                                {
                                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                    break;
                                                }

                                                auto* criterium = new CriteriumVzdelaniePocet(ConsoleOutput::getTypVzdelanie(vzdelanieTypChoiceInt));
                                                ShellSort<int>::sort(*result, criterium, true);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                            }
                                            case 3:
                                            {
                                                //podiel
                                                auto* filter = new FilterAll();
                                                auto* result = filter->passStructure(*kraje);

                                                ConsoleOutput::printTypVzdelania();
                                                std::string vzdelanieTypChoice = ConsoleOutput::readChoiceWord();

                                                int vzdelanieTypChoiceInt;
                                                try
                                                {
                                                    vzdelanieTypChoiceInt = std::stoi(vzdelanieTypChoice);
                                                } catch (std::invalid_argument& exception)
                                                {
                                                    std::cout << "Pozor, musis zadat cislo!" << std::endl;
                                                    break;
                                                }

                                                auto* criterium = new CriteriumVzdelaniePodiel(ConsoleOutput::getTypVzdelanie(vzdelanieTypChoiceInt));
                                                ShellSort<double>::sort(*result, criterium, true);
                                                ConsoleOutput::printResultChoicesTitles(*result);

                                                delete filter;
                                                delete result;
                                                delete criterium;
                                                break;
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                }
                                break;
                            }
                        }
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