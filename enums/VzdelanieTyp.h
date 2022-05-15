//
// Created by Peter Szathmáry on 15/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_VZDELANIETYP_H
#define SZATHMARY_SEMESTRALNA_PRACA_VZDELANIETYP_H

/// sluzi na indexovanie pola vzdelanieUtriedene v UzemnaJednotka
/// na kazdom jednom indexe bude pocet ludi s danym vzdelanim
enum VzdelanieTyp
{
    BEZ_UKONCENEHO = 0,
    ZAKLADNE = 1,
    UCNOVSKE = 2,
    STREDNE = 3,
    VYSSIE = 4,
    VYSOKOSKOLSKE = 5,
    NEZISTENE = 6
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_VZDELANIETYP_H
