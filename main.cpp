#include <iostream>
#include "structures/table/DuplicitySortedSequenceTable.h"
#include "criteriums/CriteriumName.h"

int main()
{
    auto* duplicityTable = new DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>();

    auto* prva = new UzemnaJednotka(nullptr, nullptr, "1", OBEC);
    auto* druha = new UzemnaJednotka(nullptr, nullptr, "2", OBEC);
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
    auto* results = duplicityTable->findTableItems(keyToFind);

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


    std::string nameToEvaluate = "1";
    auto* criteriumName = new CriteriumName(nameToEvaluate);

    auto* resultsOfCriterium = criteriumName->evaluate(duplicityTable);

    std::cout << "Results of criteriumName with name: " << nameToEvaluate << std::endl;

    for (int i = 0; i < resultsOfCriterium->size(); ++i)
    {
        std::cout << resultsOfCriterium->at(i)->getNazov() << std::endl;
    }

    delete criteriumName;

    system("leaks Szathmary_semestralna_praca");
    return 0;
}
