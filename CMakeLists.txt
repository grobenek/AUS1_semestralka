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
        structures/_logger/file_log_consumer.cpp
        structures/_logger/file_log_consumer.h
        structures/_logger/logger.cpp
        structures/_logger/logger.h
        structures/array/array.h
        structures/list/array_list.h
        structures/list/linked_list.h
        structures/list/list.h
        structures/matrix/coherent_matrix.h
        structures/matrix/incoherent_matrix.h
        structures/matrix/matrix.h
        structures/priority_queue/heap.h
        structures/priority_queue/priority_queue.h
        structures/priority_queue/priority_queue_limited_sorted_array_list.h
        structures/priority_queue/priority_queue_linked_list.h
        structures/priority_queue/priority_queue_list.h
        structures/priority_queue/priority_queue_sorted_array_list.h
        structures/priority_queue/priority_queue_two_lists.h
        structures/priority_queue/priority_queue_unsorted_array_list.h
        structures/queue/explicit_queue.h
        structures/queue/implicit_queue.h
        structures/queue/queue.h
        structures/stack/explicit_stack.h
        structures/stack/implicit_stack.h
        structures/stack/stack.h
        structures/table/sorting/bubble_sort.h
        structures/table/sorting/heap_sort.h
        structures/table/sorting/insert_sort.h
        structures/table/sorting/merge_sort.h
        structures/table/sorting/quick_sort.h
        structures/table/sorting/radix_sort.h
        structures/table/sorting/select_sort.h
        structures/table/sorting/shell_sort.h
        structures/table/sorting/shuffle.h
        structures/table/sorting/sort.h
        structures/table/binary_search_tree.h
        structures/table/hash_table.h
        structures/table/linked_table.h
        structures/table/sequence_table.h
        structures/table/sorted_sequence_table.h
        structures/table/table.h
        structures/table/treap.h
        structures/table/unsorted_sequence_table.h
        structures/tree/binary_tree.h
        structures/tree/k_way_tree.h
        structures/tree/multi_way_tree.h
        structures/tree/tree.h
        structures/vector/vector.cpp
        structures/list/double_linked_list.h
        structures/vector/vector.h
        structures/data_item.h
        structures/structure.cpp
        structures/structure.h
        structures/structure_iterator.h
        structures/types.h
        structures/utils.cpp
        structures/utils.h

        enums/UzemnaJednotkaTyp.h structures/table/DuplicitySortedSequenceTable.h criteriums/CriteriumVzdelaniePocet.cpp criteriums/CriteriumVzdelaniePocet.h enums/VzdelanieTyp.h enums/VekTyp.h criteriums/CriteriumVzdelaniePodiel.cpp criteriums/CriteriumVzdelaniePodiel.h filters/Filter.h filters/FilterWithCriterium.h filters/FilterBetween.h filters/FilterEquals.h criteriums/CriteriumTyp.cpp criteriums/CriteriumTyp.h filters/CompositeFilter.h input/DataLoader.cpp input/DataLoader.h uzemna_jednotka/Obec.cpp uzemna_jednotka/Obec.h uzemna_jednotka/Okres.cpp uzemna_jednotka/Okres.h uzemna_jednotka/Kraj.cpp uzemna_jednotka/Kraj.h criteriums/CriteriumUzemnaJednotka.h filters/FilterVzdelaniePocet.h filters/FilterVzdelaniePodiel.h structures/list/ArrayListWithObject.h filters/FilterUzemnaJednotkaTyp.h filters/FilterUzemnaJednotkaPrislusnost.h criteriums/CriteriumPrislusnost.cpp criteriums/CriteriumPrislusnost.h criteriums/CriteriumString.h sorting/ShellSort.h output/ConsoleOutput.h filters/FilterAnd.h filters/FilterOr.h filters/FilterSkuska.h)
