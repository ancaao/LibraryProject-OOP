//
// Created by Anca on 2/3/2023.
//

#include "../headers/SortByYear.h"
#include <algorithm>

std::vector<Book> SortByYear::sort(std::vector<Book> books) const {
    auto year_sort_fn = [](Book const& book1, Book const& book2) {
        return book1.getYear() < book2.getYear();
    };
    std::sort(begin(books), end(books), year_sort_fn);
    return books;
}
