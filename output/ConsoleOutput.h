//
// Created by Peter Szathmáry on 28/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_CONSOLEOUTPUT_H
#define SZATHMARY_SEMESTRALNA_PRACA_CONSOLEOUTPUT_H


#include <string>
#include <iostream>
#include "../structures/list/array_list.h"
#include "../uzemna_jednotka/UzemnaJednotka.h"
#include "../structures/table/table.h"

class ConsoleOutput
{
public:


    static void printGeneralChoices();
    static std::string readChoiceWord();
    static std::string readChoiceRow();
    static void printPointSeachChoices();
    static void printFilterMinValue();
    static void printTypVzdelania();
    static VzdelanieTyp getTypVzdelanie(int choice);
    static void printFilterMaxValue();
    static void printFiltersChoiceKind();
    static void printFiltersChoices();
    static void printInputName();
    static void newLine();

    static void printResultChoicesTitles(structures::List<UzemnaJednotka*>& listToPrint);
    static void printResultChoicestitlesTableItem(structures::List<structures::TableItem<std::string, UzemnaJednotka *> *>& listToprint);
};

void ConsoleOutput::printGeneralChoices()
{
    std::cout << "------------------------------------" << std::endl;
    std::cout << "1. Bodove vyhladavanie" << std::endl;
    std::cout << "2. Filtrovanie" << std::endl;
    std::cout << "3. Triedenie" << std::endl;
    std::cout << std::endl;
    std::cout << "9. ukoncit aplikaciu" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

std::string ConsoleOutput::readChoiceWord()
{
    std::cout << "Zadaj moznost: > ";
    std::string choice;
    std::cin >> choice;
    std::cout << std::endl;
    return choice;
}

void ConsoleOutput::printPointSeachChoices()
{
    std::cout << "------------------------------------" << std::endl;
    std::cout << "1. vyhladat obec" << std::endl;
    std::cout << "2. vyhladat okres" << std::endl;
    std::cout << "3. vyhladat kraj" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

void ConsoleOutput::printInputName()
{
    std::cout << std::endl << "Nazov uzemnej jednotky: ";
}

void ConsoleOutput::newLine()
{
    std::cout << std::endl;
}

void ConsoleOutput::printResultChoicesTitles(structures::List<UzemnaJednotka*>& listToPrint)
{
    for (auto item: listToPrint)
    {
        std::cout << item->getOfficialTitle() << std::endl;
    }
}

void ConsoleOutput::printResultChoicestitlesTableItem(
        structures::List<structures::TableItem<std::string, UzemnaJednotka*>*>& listToprint)
{
    for (auto item: listToprint)
    {
        UzemnaJednotkaTyp typJednotky = item->accessData()->getTyp();

        switch (typJednotky)
        {

            case OBEC:
                std::cout << "Nazov obce: " << item->accessData()->getOfficialTitle() << " - " << "okres: " << item->accessData()->getVyssiUzemnyCelok()->getOfficialTitle() << " - " << "kraj: " << item->accessData()->getVyssiUzemnyCelok()->getVyssiUzemnyCelok()->getOfficialTitle() << std::endl;
                break;
            case KRAJ:
                std::cout << "Nazov kraja: " << item->accessData()->getOfficialTitle() << std::endl;
                break;
            case OKRES:
                std::cout << "Nazov okresu: " << item->accessData()->getOfficialTitle() << " - " << "kraj: " << item->accessData()->getVyssiUzemnyCelok()->getOfficialTitle() << std::endl;
                break;
            case NEZARADENA:
                break;
        }

        std::cout << "Vzdelanie: " << std::endl;
        int counter = 0;
        for (int i = 0; i < item->accessData()->getVzdelanieUtriedene()->size(); ++i)
        {
            std::string vzdelanieTyp;
            switch (counter)
            {
                case 0:
                    vzdelanieTyp = "Bez ukonceneho do 14 rokov: ";
                    break;
                case 1:
                    vzdelanieTyp = "Zakladne: ";
                    break;
                case 2:
                    vzdelanieTyp = "Ucnovske: ";
                    break;
                case 3:
                    vzdelanieTyp = "Stredne: ";
                    break;
                case 4:
                    vzdelanieTyp = "Vyssie: ";
                    break;
                case 5:
                    vzdelanieTyp = "Vysokoskolske: ";
                    break;
                case 6:
                    vzdelanieTyp = "Bez vzdelania od 15 rokov: ";
                    break;
                case 7:
                    vzdelanieTyp = "Nezistene: ";
                    break;
                default:
                    vzdelanieTyp = "ERROR";
                    break;
            }
            std::cout << vzdelanieTyp << item->accessData()->getVzdelanieUtriedene()->at(i) << " obyvatelov" << std::endl;
            counter++;
        }
        std::cout << std::endl;
    }
}

std::string ConsoleOutput::readChoiceRow()
{
    std::cout << "Zadaj moznost: > ";
    std::string choice;
    std::cin.ignore(); //dam prec ked ostali nejake znaky z predosleho citania
    std::getline(std::cin, choice); // nacitam cely riadok
    std::cout << std::endl;
    return choice;
}

void ConsoleOutput::printFiltersChoices()
{
    std::cout << "------------------------------------" << std::endl;
    std::cout << "1. FilterVzdelaniePocet" << std::endl;
    std::cout << "2. FilterVzdelaniePodiel" << std::endl;
    std::cout << "3. FilterUzemnaJednotkaPrislusnost" << std::endl;
    std::cout << "4. FilterUzemnaJednotkaTyp" << std::endl;
    std::cout << std::endl;
    std::cout << "0. Koniec zadavania filtrov" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

void ConsoleOutput::printFiltersChoiceKind()
{
    std::cout << "------------------------------------" << std::endl;
    std::cout << "1. FilterAND" << std::endl;
    std::cout << "2. FilterOR" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

void ConsoleOutput::printFilterMinValue()
{
    std::cout << "Minimalna hodnota filtrovania ";
}

void ConsoleOutput::printFilterMaxValue()
{
    std::cout << "Maximalna hodnota filtrovania ";
}

void ConsoleOutput::printTypVzdelania()
{
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "1. Bez ukonceneho vzdelania do 14 rokov" << std::endl;
    std::cout << "2. Zakladne vzdelanie" << std::endl;
    std::cout << "3. Ucnovske vzdelanie" << std::endl;
    std::cout << "4. Stredne vzdelanie" << std::endl;
    std::cout << "5. Vyssie vzdelanie" << std::endl;
    std::cout << "6. Vysokoskolske vzdelanie" << std::endl;
    std::cout << "7. Bez ukonceneho vzdelania od 15 rokov" << std::endl;
    std::cout << "8. Nezistene vzdelanie" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
}

VzdelanieTyp ConsoleOutput::getTypVzdelanie(int choice)
{
    switch (choice)
    {
        case 0:
            return BEZ_UKONCENEHO_DO_14;
        case 1:
            return ZAKLADNE;
        case 2:
            return UCNOVSKE;
        case 3:
            return STREDNE;
        case 4:
            return VYSSIE;
        case 5:
            return VYSOKOSKOLSKE;
        case 6:
            return BEZ_VZDELANIE_OD_15;
        case 7:
            return NEZISTENE;
        default:
            throw std::invalid_argument("Invalid argument in ConsoleOutput::getTypVzdelanie");
            break;
}


#endif //SZATHMARY_SEMESTRALNA_PRACA_CONSOLEOUTPUT_H
