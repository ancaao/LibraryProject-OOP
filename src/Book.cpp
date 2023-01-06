//
// Created by Anca on 11/27/2022.
//
#include "../headers/Book.h"

std::string Book::getTitle() const { return title; }

Genre Book::getGenre() const { return genre; }

double Book::getPrice() const { return price; }

Publisher Book::getPublisher() const { return publisher; }

Book::Book(const std::string& title_, const Author& author_, const Publisher& publisher_,double price_,
     const Genre& genre_, int year_) : title{title_}, author{author_},
                                       publisher{publisher_},
                                       price{price_}, genre{genre_},
                                       year{year_} {

    time_t t = time(nullptr);
    std::tm *const pTInfo = localtime(&t);

    int CurrentYear = 1900 + pTInfo->tm_year;

    if(year > CurrentYear)
        throw WrongYear();

    if(genre <= Genre::MIN || genre >= Genre::MAX)
        throw WrongGenre();
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Title: " << book.title << ", Author - " << book.author <<
       "Publisher - " << book.publisher.getName() << ", Price: " << book.price <<
       ", Genre: " << static_cast<int>(book.genre) << ", Year: " << book.year << "\n";
    return os;
}

const Author &Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

void Book::setTitle(const std::string &title_) {
    Book::title = title_;
}

void Book::setAuthor(const Author &author_) {
    Book::author = author_;
}

void Book::setPublisher(const Publisher &publisher_) {
    Book::publisher = publisher_;
}

void Book::setPrice(double price_) {
    Book::price = price_;
}

void Book::setGenre(Genre genre_) {
    Book::genre = genre_;
}

void Book::setYear(int year_) {
    Book::year = year_;
}
