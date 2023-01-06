//
// Created by Anca on 12/17/2022.
//

#ifndef MAIN_CPP_AUTHOREXCEPTION_H
#define MAIN_CPP_AUTHOREXCEPTION_H

#include <stdexcept>
#include <string>

class AuthorException : public std::runtime_error {
public:
    explicit AuthorException(const std::string &arg);
};

class WrongGender : public AuthorException {
public:
    WrongGender();
};

#endif //MAIN_CPP_AUTHOREXCEPTION_H
