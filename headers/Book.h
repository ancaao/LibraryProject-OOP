//
// Created by Anca on 11/27/2022.
//

#ifndef MAIN_CPP_BOOK_H
#define MAIN_CPP_BOOK_H

#include<iostream>
#include<ctime>
#include "Publisher.h"
#include "BookException.h"

enum class Genre{MIN, Fiction, Nonfiction, Drama, Poetry, Folktale, MAX};

class Book{
protected:

    std::string title;
    Author author;
    Publisher publisher;
    double price{};
    Genre genre{};
    int year{};
public:
    Book() = default;
    ~Book() = default;

    std::string getTitle() const;
    const Author &getAuthor() const;
    Genre getGenre() const;
    double getPrice() const;
    Publisher getPublisher() const;

    Book(const std::string& title_, const Author& author_, const Publisher& publisher_, double price_,
         const Genre& genre_, int year_);

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};
#endif //MAIN_CPP_BOOK_H
