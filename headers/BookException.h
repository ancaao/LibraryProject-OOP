//
// Created by Anca on 12/19/2022.
//

#ifndef MAIN_CPP_BOOKEXCEPTION_H
#define MAIN_CPP_BOOKEXCEPTION_H

#include <stdexcept>
#include <string>

class BookException : public std::runtime_error {
public:
    explicit BookException(const std::string &arg);
};

class WrongYear : public BookException {
public:
    WrongYear();
};
class WrongGenre : public BookException {
public:
    WrongGenre();
};

#endif //MAIN_CPP_BOOKEXCEPTION_H
