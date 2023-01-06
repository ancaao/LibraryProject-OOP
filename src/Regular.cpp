//
// Created by Anca on 12/19/2022.
//
#include "../headers/Regular.h"
#include<numeric>

Regular::Regular(const std::string &name) : Client{name} {}

std::shared_ptr<Client> Regular::clone() const { return std::make_shared<Regular>(*this); }

Regular& Regular::operator=(Regular other) {
    swap(*this, other);
    return *this;
}

void swap(Regular& regular1, Regular& regular2) {
    using std::swap;
    swap(regular1.name, regular2.name);
    swap(regular1.books, regular2.books);
}

double Regular::get_total() {
    auto sum = [](const float& accumulator, const Book& book){
        return accumulator + book.getPrice();
    };
    return std::accumulate(this->books.begin(), this->books.end(), 0.0f, sum);
}