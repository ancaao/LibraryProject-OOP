//
// Created by Anca on 11/27/2022.
//
#include "../headers/Publisher.h"

std::string Publisher::getName() const { return name; }

Publisher::Publisher(const std::string& name_, const std::vector<Author>& authors_): name{name_}, authors{authors_} {}

std::ostream& operator<<(std::ostream& os, const Publisher& publisher) {
    os << "Name: " << publisher.name << "\n";
    for(const auto& author : publisher.authors)
        os << "Author: " << author << "\n";
    return os;
}