//
// Created by Anca on 12/17/2022.
//

#ifndef MAIN_CPP_APPEXCEPTION_H
#define MAIN_CPP_APPEXCEPTION_H

#include <stdexcept>
#include <string>

class AppException : public std::runtime_error {
public:
    explicit AppException(const std::string &arg);
};

class WrongGender : public AppException {
public:
    WrongGender();
};

class WrongYear : public AppException {
public:
    WrongYear();
};
class WrongGenre : public AppException {
public:
    WrongGenre();
};

#endif //MAIN_CPP_APPEXCEPTION_H
