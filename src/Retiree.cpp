//
// Created by Anca on 12/10/2022.
//
#include "../headers/Retiree.h"
#include <numeric>

Retiree :: Retiree(const std::string& name) : Client{name} {}

std::shared_ptr<Client> Retiree::clone() const { return std::make_shared<Retiree>(*this); }

Retiree& Retiree::operator=(Retiree other) {
    swap(*this, other);
    return *this;
}

void swap(Retiree& retiree1, Retiree& retiree2) {
    using std::swap;
    swap(retiree1.name, retiree2.name);
    swap(retiree1.books, retiree2.books);
}

double Retiree::get_total()  {
    auto sum = [this](const double& accumulator, const Book& book){
        double book_price = book.getPrice();
        int n = books.size();
        double discount = 1;
        if (n >= 3 && n < 5) discount = 0.2;
        else if(n >= 5 && n<10) discount = 0.3;
        else discount = 0.4;
        return accumulator + (1 - discount) * book_price;
    };
    return std::accumulate(this->books.begin(), this->books.end(), 0.0f, sum);
}