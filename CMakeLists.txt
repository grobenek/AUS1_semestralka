cmake_minimum_required(VERSION 3.22)
project(Szathmary_semestralna_praca)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(
        Szathmary_semestralna_praca
        main.cpp
        criteriums/Criterium.h
        criteriums/CriteriumNazov.cpp
        criteriums/CriteriumNazov.h
        uzemna_jednotka/UzemnaJednotka.h
        structures/array/array.h
        structures/list/array_list.h
        structures/list/list.h
        structures/table/sequence_table.h
        structures/table/sorted_sequence_table.h
        structures/table/table.h
        structures/table/unsorted_sequence_table.h
        structures/vector/vector.cpp
        structures/vector/vector.h
        structures/data_item.h
        structures/structure.cpp
        structures/structure.h
        structures/structure_iterator.h
        structures/types.h
        structures/utils.cpp
        structures/utils.h

        enums/UzemnaJednotkaTyp.h structures/table/DuplicitySortedSequenceTable.h criteriums/CriteriumVzdelaniePocet.cpp criteriums/CriteriumVzdelaniePocet.h enums/VzdelanieTyp.h criteriums/CriteriumVzdelaniePodiel.cpp criteriums/CriteriumVzdelaniePodiel.h filters/Filter.h filters/FilterWithCriterium.h filters/FilterBetween.h filters/FilterEquals.h criteriums/CriteriumTyp.cpp criteriums/CriteriumTyp.h filters/CompositeFilter.h input/DataLoader.cpp input/DataLoader.h uzemna_jednotka/Obec.cpp uzemna_jednotka/Obec.h uzemna_jednotka/Okres.cpp uzemna_jednotka/Okres.h uzemna_jednotka/Kraj.cpp uzemna_jednotka/Kraj.h criteriums/CriteriumUzemnaJednotka.h filters/FilterVzdelaniePocet.h filters/FilterVzdelaniePodiel.h structures/list/ArrayListWithObject.h filters/FilterUzemnaJednotkaTyp.h filters/FilterUzemnaJednotkaPrislusnost.h criteriums/CriteriumPrislusnost.cpp criteriums/CriteriumPrislusnost.h sorting/ShellSort.h output/ConsoleOutput.h filters/FilterAnd.h filters/FilterOr.h filters/FilterAll.h)
