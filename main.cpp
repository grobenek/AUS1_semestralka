#include <iostream>
#include "structures/table/DuplicitySortedSequenceTable.h"

int main()
{
    auto* duplicityTable = new DuplicitySortedSequenceTable<int, int>();

    duplicityTable->insert(1, 1);
    duplicityTable->insert(2, 2);
    duplicityTable->insert(1, 1);

    std::cout << duplicityTable->size() << std::endl;

    system("leaks Szathmary_semestralna_praca");
    return 0;
}
