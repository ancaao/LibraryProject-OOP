//
// Created by Anca on 1/6/2023.
//

#ifndef MAIN_CPP_SORTBYTITLE_H
#define MAIN_CPP_SORTBYTITLE_H

#include "../headers/SortStrategy.h"
#include "../headers/Book.h"

class SortByTitle : public SortStrategy {
public:
    ~SortByTitle() = default;

    std::vector<Book> sort(std::vector<Book> books) const override;
};

#endif //MAIN_CPP_SORTBYTITLE_H
