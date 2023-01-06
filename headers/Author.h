//
// Created by Anca on 11/27/2022.
//

#ifndef MAIN_CPP_AUTHOR_H
#define MAIN_CPP_AUTHOR_H

#include<iostream>
#include <vector>
#include <algorithm>
#include "AuthorException.h"

class Author{
    std::string name;
    std::string gender;
    std::string nationality;
public:
    Author() = default;
    ~Author() = default;

    friend std::ostream& operator<<(std::ostream& os, const Author& author);

    const std::string &getName() const;

    static std::vector<Author> get_authors_by_name(std::vector<Author> authors_list, const std::vector<std::string>& names);

    Author(const std::string& name, const std::string& gender, std::string& nationality);
};

#endif //MAIN_CPP_AUTHOR_H
