//
// Created by Anca on 12/17/2022.
//

#include "../headers/AppException.h"

AppException::AppException(const std::string &arg) : runtime_error ("Error: " + arg) {}

WrongGender::WrongGender() : AppException("Author gender is not valid") {}


WrongYear::WrongYear() : AppException("Book publish year is not valid!") {}

WrongGenre::WrongGenre() : AppException("Book genre is not valid!") {}