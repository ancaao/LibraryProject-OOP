//
// Created by Anca on 1/6/2023.
//

#include "../headers/SortByTitle.h"
#include "algorithm"

std::vector<Book> SortByTitle::sort(std::vector<Book> books) const {
    auto title_sort_fn = [](Book const& book1, Book const& book2) {
        return book1.getTitle() < book2.getTitle();
    };
    std::sort(begin(books), end(books), title_sort_fn);
    return books;
}
