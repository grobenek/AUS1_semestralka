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


#endif //SZATHMARY_SEMESTRALNA_PRACA_CONSOLEOUTPUT_H
