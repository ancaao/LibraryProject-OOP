//
// Created by Anca on 1/6/2023.
//

#ifndef MAIN_CPP_BOOKBUILDER_H
#define MAIN_CPP_BOOKBUILDER_H

#include<string>
#include "../headers/Book.h"

class BookBuilder {
private:
    Book book;
public:
    BookBuilder();
    BookBuilder& addTitle(const std::string& title);
    BookBuilder& addAuthor(const Author &author);
    BookBuilder& addPublisher(const Publisher &publisher);
    BookBuilder& addPrice(const double price);
    BookBuilder& addGenre(const Genre genre);
    BookBuilder& addYear(const int year);
    Book build();
};

#endif //MAIN_CPP_BOOKBUILDER_H
