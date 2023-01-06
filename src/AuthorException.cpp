//
// Created by Anca on 12/17/2022.
//

#include "../headers/AuthorException.h"

AuthorException::AuthorException(const std::string &arg) : runtime_error ("Author error: " + arg) {}

WrongGender::WrongGender() : AuthorException("Author gender is not valid") {}