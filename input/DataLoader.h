//
// Created by Peter Szathmáry on 22/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_DATALOADER_H
#define SZATHMARY_SEMESTRALNA_PRACA_DATALOADER_H

#include "../structures/table/DuplicitySortedSequenceTable.h"
#include "../uzemna_jednotka/UzemnaJednotka.h"

class DataLoader
{
private:
public:
    explicit DataLoader();

    static DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>* nacitajObce(const std::string& fileName, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& okresyKody, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& obceKody);

    static DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>* nacitajOkres(const std::string& fileName, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& krajeKody, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& okresyKody);

    static DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>* nacitajKraj(const std::string& fileName, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& krajeKody);

    static void nacitajVzdelanie(const std::string& fileName, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& obce, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& obceKody);

    static void nacitajVek(const std::string& fileName, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& obce, DuplicitySortedSequenceTable<std::string, UzemnaJednotka*>& obceKody);

};


#endif //SZATHMARY_SEMESTRALNA_PRACA_DATALOADER_H
