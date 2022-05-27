
// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//
// Created by Peter Szathmáry on 22/05/2022.
//

#include <string>
#include <fstream>
#include <sstream>
#include "DataLoader.h"
#include "../uzemna_jednotka/Kraj.h"

DataLoader::DataLoader()
= default;

DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>* DataLoader::nacitajObce(const std::string& fileName, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& okresyKody, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& obceKody)
{
    auto* obce = new DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>;
    std::fstream read;
    read.open(fileName, std::ios::in);

    if (!read)
    {
        delete obce;
        throw std::invalid_argument("No such file named " + fileName);
    }

    std::string word;
    int wordCounter = -1;
    auto* arrayListOfWords = new structures::Array<std::string>(5);
    Obec* novaObec = nullptr;

    getline(read, word); // Precitam 1. riadok, kde su len vysvetlivky

    while (getline(read, word, ';'))
    {
        if (wordCounter == 5)
        {
            novaObec = new Obec(arrayListOfWords->at(0), arrayListOfWords->at(1), arrayListOfWords->at(2), arrayListOfWords->at(3), arrayListOfWords->at(4),
                                nullptr, nullptr);

            auto* novaObecClone = novaObec->clone();

            std::string resultOfStringSplit = novaObecClone->getCode();

            resultOfStringSplit = resultOfStringSplit.substr(3, 3); // ziskam cislo obce

            novaObecClone->setVyssiUzemnyCelok(okresyKody.find(resultOfStringSplit));
            novaObecClone->getVyssiUzemnyCelok()->pridajNizsiuUzemnuJednotku(novaObecClone->clone());

            obceKody.insert(novaObecClone->getCode(), novaObecClone->clone());
            obce->insert(novaObecClone->getOfficialTitle(), novaObecClone);
            delete novaObec;
            wordCounter = 0;
        }
        if (wordCounter == -1)
        {
            wordCounter++;
            continue;
        }
        arrayListOfWords->at(wordCounter) = word;
        wordCounter++;
    }

    novaObec = new Obec(arrayListOfWords->at(0), arrayListOfWords->at(1), arrayListOfWords->at(2), arrayListOfWords->at(3), arrayListOfWords->at(4),
                        nullptr, nullptr);

    auto* novaObecClone = novaObec->clone();

    std::string resultOfStringSplit = novaObecClone->getCode();

    resultOfStringSplit = resultOfStringSplit.substr(3, 3); // ziskam cislo obce

    novaObecClone->setVyssiUzemnyCelok(okresyKody.find(resultOfStringSplit));
    novaObecClone->getVyssiUzemnyCelok()->pridajNizsiuUzemnuJednotku(novaObecClone->clone());

    obceKody.insert(novaObecClone->getCode(), novaObecClone->clone());
    obce->insert(novaObecClone->getOfficialTitle(), novaObecClone);
    delete novaObec;



    delete arrayListOfWords;
    return obce;
}

DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>* DataLoader::nacitajKraj(const std::string& fileName,
                                                                                    DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& krajeKody)
{
    auto* kraje = new DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>;
    std::fstream read;
    read.open(fileName, std::ios::in);

    if (!read)
    {
        delete kraje;
        throw std::invalid_argument("No such file named " + fileName);
    }

    std::string word;
    int wordCounter = -1; // aby som vedel accessovat pole bez nejakych problemov
    auto* arrayListOfWords = new structures::Array<std::string>(5);
    Kraj* novyKraj;

    getline(read, word); // Precitam 1. riadok, kde su len vysvetlivky

    while (getline(read, word, ';'))
    {
        if (wordCounter == 5)
        {
            novyKraj = new Kraj(arrayListOfWords->at(0), arrayListOfWords->at(1), arrayListOfWords->at(2),
                                arrayListOfWords->at(3), arrayListOfWords->at(4));
            auto* novyKrajClone = novyKraj->clone();

            std::string resultOfStringSplit = novyKrajClone->getNote();

            resultOfStringSplit = resultOfStringSplit.substr(8, resultOfStringSplit.size());
            resultOfStringSplit = resultOfStringSplit.substr(0, 2); // ziskam zo stringu len potrebne cislo

            krajeKody.insert(resultOfStringSplit, novyKrajClone->clone());
            kraje->insert(novyKrajClone->getOfficialTitle(), novyKrajClone);
            delete novyKraj;
            wordCounter = 0;
        }
        if (wordCounter == -1)
        {
            wordCounter++;
            continue;
        }
        arrayListOfWords->at(wordCounter) = word;
        wordCounter++;
    }
    //kvoli poslednemu zaznamu
    novyKraj = new Kraj(arrayListOfWords->at(0), arrayListOfWords->at(1), arrayListOfWords->at(2),
                        arrayListOfWords->at(3), arrayListOfWords->at(4));
    auto* novyKrajClone = novyKraj->clone();

    std::string resultOfStringSplit = novyKrajClone->getNote();

    resultOfStringSplit = resultOfStringSplit.substr(8, resultOfStringSplit.size());
    resultOfStringSplit = resultOfStringSplit.substr(0, 2); // ziskam zo stringu len potrebne cislo

    if (resultOfStringSplit == "**")
    {
        resultOfStringSplit = "ZZ";
    }

    krajeKody.insert(resultOfStringSplit, novyKrajClone->clone());
    kraje->insert(novyKrajClone->getOfficialTitle(), novyKrajClone);
    delete novyKraj;

    delete arrayListOfWords;

    return kraje;
}

DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>* DataLoader::nacitajOkres(const std::string& fileName,
                                                                                     DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& krajeKody,
                                                                                     DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& okresyKody)
{
    auto* okresy = new DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>;
    std::fstream read;
    read.open(fileName, std::ios::in);

    if (!read)
    {
        delete okresy;
        throw std::invalid_argument("No such file named " + fileName);
    }

    std::string word;
    int wordCounter = -1;
    auto* arrayListOfWords = new structures::Array<std::string>(5);
    Okres* novyOkres;

    getline(read, word); // Precitam 1. riadok, kde su len vysvetlivky

    while (getline(read, word, ';'))
    {
        if (wordCounter == 5)
        {
            novyOkres = new Okres(arrayListOfWords->at(0), arrayListOfWords->at(1), arrayListOfWords->at(2),
                                  arrayListOfWords->at(3), arrayListOfWords->at(4));
            auto* novyOkresClone = novyOkres->clone();

            std::string resultOfStringSplit = novyOkresClone->getCode();

            std::string resultOfStringSplitOkres = resultOfStringSplit.substr(3, 5); // kod obce
            if (resultOfStringSplit == "SKZZZ")
            {
                resultOfStringSplitOkres = "ZZZ";
            }

            resultOfStringSplit = resultOfStringSplit.substr(3, 2); // ziskam zo stringu len potrebne cislo aby som zistil kraj

            novyOkresClone->setVyssiUzemnyCelok(krajeKody.find(resultOfStringSplit));
            novyOkresClone->getVyssiUzemnyCelok()->pridajNizsiuUzemnuJednotku(novyOkresClone->clone());


            okresyKody.insert(resultOfStringSplitOkres, novyOkresClone->clone());
            okresy->insert(novyOkresClone->getOfficialTitle(), novyOkresClone);
            delete novyOkres;
            wordCounter = 0;
        }
        if (wordCounter == -1)
        {
            wordCounter++;
            continue;
        }
        arrayListOfWords->at(wordCounter) = word;
        wordCounter++;
    }

    novyOkres = new Okres(arrayListOfWords->at(0), arrayListOfWords->at(1), arrayListOfWords->at(2),
                          arrayListOfWords->at(3), arrayListOfWords->at(4));
    auto* novyOkresClone = novyOkres->clone();

    std::string resultOfStringSplit = novyOkresClone->getCode();

    resultOfStringSplit = resultOfStringSplit.substr(3, 5);
    resultOfStringSplit = resultOfStringSplit.substr(0, 2); // ziskam zo stringu len potrebne cislo

    novyOkresClone->setVyssiUzemnyCelok(krajeKody.find(resultOfStringSplit));
    novyOkresClone->getVyssiUzemnyCelok()->pridajNizsiuUzemnuJednotku(novyOkresClone->clone());


    okresyKody.insert(resultOfStringSplit, novyOkresClone->clone());
    okresy->insert(novyOkresClone->getOfficialTitle(), novyOkresClone);
    delete novyOkres;

    delete arrayListOfWords;
    return okresy;
}

void DataLoader::nacitajVzdelanie(const std::string& fileName,
                                  DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& obce,
                                  DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& obceKody)
{
    std::fstream read;
    read.open(fileName, std::ios::in);

    if (!read)
    {
        throw std::invalid_argument("No such file named " + fileName);
    }

    std::string word;
    int wordCounter = 0;
    auto* arrayListOfWords = new structures::Array<std::string>(10);

    getline(read, word); // Precitam 1. riadok, kde su len vysvetlivky

    while (getline(read, word))
    {

        std::string delimiter = ";";
        size_t pos = 0;
        std::string token;
        while ((pos = word.find(delimiter)) != std::string::npos) {
            token = word.substr(0, pos);
            arrayListOfWords->at(wordCounter) = token;
            word.erase(0, pos + delimiter.length());
            wordCounter++;
        }
        arrayListOfWords->at(9) = word.substr(0, word.size() - 1);

        if (wordCounter == 9)
        {
            std::string kodObce = arrayListOfWords->at(0);

            auto nazovObceNaHladanie = obceKody.find(kodObce)->getOfficialTitle();
            auto* najdeneObce = obce.findAll(nazovObceNaHladanie);
            Obec* najdenaObec;
            for (auto item: *najdeneObce)
            {
                if (item->accessData()->getCode() == kodObce)
                {
                 najdenaObec = dynamic_cast<Obec*>(item->accessData());
                 break;
                }
            }
            auto* vzdelanie = new structures::Array<int>(8);


            for (int i = 0; i < 8; ++i)
            {
                vzdelanie->at(i) = std::stoi(arrayListOfWords->at(i + 2)); //zmena zo str na int
            }

            najdenaObec->setVzdelanieUtriedene(new structures::Array<int>(*vzdelanie));
            delete vzdelanie;
            delete najdeneObce;
            wordCounter = 0;
        }
    }


    delete arrayListOfWords;
}

void
DataLoader::nacitajVek(const std::string& fileName, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& obce,
                       DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& obceKody)
{
    std::fstream read;
    read.open(fileName, std::ios::in);

    if (!read)
    {
        throw std::invalid_argument("No such file named " + fileName);
    }

    std::string word;
    int wordCounter = 0;
    auto* arrayListOfWords = new structures::Array<std::string>(204);

    getline(read, word); // Precitam 1. riadok, kde su len vysvetlivky

    while (getline(read, word))
    {

        std::string delimiter = ";";
        size_t pos = 0;
        std::string token;
        while ((pos = word.find(delimiter)) != std::string::npos) {
            token = word.substr(0, pos);
            arrayListOfWords->at(wordCounter) = token;
            word.erase(0, pos + delimiter.length());
            wordCounter++;
        }
        arrayListOfWords->at(9) = word.substr(0, word.size() - 1);

        if (wordCounter == 203)
        {
            std::string kodObce = arrayListOfWords->at(0);

            auto nazovObceNaHladanie = obceKody.find(kodObce)->getOfficialTitle();
            auto* najdeneObce = obce.findAll(nazovObceNaHladanie);
            Obec* najdenaObec;
            for (auto item: *najdeneObce)
            {
                if (item->accessData()->getCode() == kodObce)
                {
                    najdenaObec = dynamic_cast<Obec*>(item->accessData());
                    break;
                }
            }
            auto* vek = new structures::Array<int>(8);


            for (int i = 0; i < 8; ++i)
            {
                vek->at(i) = std::stoi(arrayListOfWords->at(i + 2)); //zmena zo str na int
            }

            najdenaObec->setVekUtriedene(new structures::Array<int>(*vek));
            delete vek;
            delete najdeneObce;
            wordCounter = 0;
        }
    }


    delete arrayListOfWords;
}
