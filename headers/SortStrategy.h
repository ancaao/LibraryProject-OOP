//
// Created by Anca on 1/6/2023.
//

#ifndef MAIN_CPP_SORTSTRATEGY_H
#define MAIN_CPP_SORTSTRATEGY_H

#include<iostream>
#include "Book.h"

class SortStrategy {
public:
    SortStrategy() = default;
    virtual ~SortStrategy() = 0;

    virtual std::vector<Book> sort(std::vector<Book> books) const = 0;
};



#endif //MAIN_CPP_SORTSTRATEGY_H
