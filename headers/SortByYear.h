//
// Created by Anca on 2/3/2023.
//

#ifndef MAIN_CPP_SORTBYYEAR_H
#define MAIN_CPP_SORTBYYEAR_H

#include "../headers/SortStrategy.h"
#include "../headers/Book.h"

class SortByYear : public SortStrategy {
public:
    ~SortByYear() = default;

    std::vector<Book> sort(std::vector<Book> books) const override;
};

#endif //MAIN_CPP_SORTBYYEAR_H
