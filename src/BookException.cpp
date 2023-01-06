//
// Created by Anca on 12/19/2022.
//
#include "../headers/BookException.h"


BookException::BookException(const std::string &arg) : runtime_error ("Book error: " + arg) {}

WrongYear::WrongYear() : BookException("Book publish year is not valid!") {}

WrongGenre::WrongGenre() : BookException("Book genre is not valid!") {}