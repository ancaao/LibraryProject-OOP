//
// Created by Anca on 12/19/2022.
//
#include <Regular.h>
#include<numeric>

Regular::Regular(const std::string &name) : Client{name} {}

std::shared_ptr<Client> Regular::clone() const { return std::make_shared<Regular>(*this); }

double Regular::get_total() {
    auto sum = [](const float& accumulator, const Book& book){
        return accumulator + book.getPrice();
    };
    return std::accumulate(this->books.begin(), this->books.end(), 0.0f, sum);
}