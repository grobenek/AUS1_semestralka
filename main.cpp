#include <iostream>
#include "structures/table/DuplicitySortedSequenceTable.h"
#include "criteriums/CriteriumNazov.h"
#include "criteriums/CriteriumVzdelaniePocet.h"

void spustiSa();

int main()
{
    spustiSa();
    system("leaks Szathmary_semestralna_praca");
    return 0;
}

void spustiSa()
{
    auto* duplicityTable = new DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>();

    auto* prva = new UzemnaJednotka(nullptr, nullptr, "1", OBEC);
    auto* druha = new UzemnaJednotka(nullptr, nullptr, "2", OBEC);
    auto* array = new structures::Array<int>(8);
    for (int i = 0; i < 8; ++i)
    {
        array->at(i) = 10;
    }
    druha->setVzdelanieUtriedene(array);
    auto* tretia = new UzemnaJednotka(nullptr, nullptr, "1", OBEC);
    auto* stvrta = new UzemnaJednotka(nullptr, nullptr, "3", OBEC);
    auto* piata = new UzemnaJednotka(nullptr, nullptr, "0", OBEC);


    duplicityTable->insert("1", prva);
    duplicityTable->insert("2", druha);
    duplicityTable->insert("1", tretia);
    duplicityTable->insert("3", stvrta);
    duplicityTable->insert("0", piata);


    std::cout << "Size: " << duplicityTable->size() << std::endl;

    std::cout << "Items in table:" << std::endl;
    for (auto item: *duplicityTable)
    {
        std::cout << item->accessData()->getNazov() << std::endl;
    }

    std::cout << "Found keys:" << std::endl;

    std::string keyToFind = "1";
    std::cout << "Trying to find item with key " << keyToFind << std::endl;
    auto* results = duplicityTable->findAll(keyToFind);

    if (results != nullptr)
    {
        for (int i = 0; i < results->size(); ++i)
        {
            std::cout << results->at(i)->accessData()->getNazov() << std::endl;
        }
    } else
    {
        std::cout << "No keys were found!" << std::endl;
    }

    std::cout << "ContainsKey num. 1?" << std::endl;
    std::cout << duplicityTable->containsKey("1") << std::endl;



    delete results;
    delete duplicityTable;
}