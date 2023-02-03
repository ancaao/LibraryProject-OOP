//
// Created by Anca on 12/10/2022.
//
#include "../headers/NGO.h"
#include "../headers/Regular.h"
#include <numeric>

NGO::NGO(const std::string& name, int volunteers): Client{name}, volunteers{volunteers} {}

std::shared_ptr<Client> NGO::clone() const { return std::make_shared<NGO>(*this); }

double NGO::get_total()  {
    auto sum = [this](const double& accumulator, const Book& book){
        double book_price = book.getPrice();
        double discount;
        if (0 < volunteers && volunteers < 50) {
            discount = 0.2;
        }else if (50 <= volunteers && volunteers < 200){
            discount = 0.4;
        }else
            discount = 0.5;
        return accumulator + (1 - discount) * book_price;
    };
    return std::accumulate(this->books.begin(), this->books.end(), 0.0f, sum);
}
