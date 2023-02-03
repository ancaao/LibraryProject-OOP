//
// Created by Anca on 1/6/2023.
//
#include "../headers/BookBuilder.h"

BookBuilder::BookBuilder() {}

BookBuilder& BookBuilder::addTitle(const std::string &title) {
    book.setTitle(title);
    return *this;
}
BookBuilder& BookBuilder::addAuthor(const Author &author) {
    book.setAuthor(author);
    return *this;
}
BookBuilder& BookBuilder::addPrice(const double price) {
    book.setPrice(price);
    return *this;
}
BookBuilder& BookBuilder::addPublisher(const Publisher &publisher) {
    book.setPublisher(publisher);
    return *this;
}
BookBuilder& BookBuilder::addYear(const int year) {
    book.setYear(year);
    return *this;
}
BookBuilder& BookBuilder::addGenre(const Genre genre) {
    book.setGenre(genre);
    return *this;
}
Book BookBuilder::build(){
    return book;
}
