//
// Created by Peter Szathmáry on 15/05/2022.
//

#ifndef SZATHMARY_SEMESTRALNA_PRACA_VZDELANIETYP_H
#define SZATHMARY_SEMESTRALNA_PRACA_VZDELANIETYP_H

/// sluzi na indexovanie pola vzdelanieUtriedene v uzemna_jednotka
/// na kazdom jednom indexe bude pocet ludi s danym vzdelanim
enum VzdelanieTyp
{
    BEZ_UKONCENEHO_DO_14 = 0,
    ZAKLADNE = 1,
    UCNOVSKE = 2,
    STREDNE = 3,
    VYSSIE = 4,
    VYSOKOSKOLSKE = 5,
    BEZ_VZDELANIE_OD_15 = 6,
    NEZISTENE = 7
};


#endif //SZATHMARY_SEMESTRALNA_PRACA_VZDELANIETYP_H
