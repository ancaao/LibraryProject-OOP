//
// Created by Anca on 12/9/2022.
//
#include "../headers/Student.h"
#include <numeric>

Student :: Student(const std::string& name) : Client{name} {}

std::shared_ptr<Client> Student::clone() const { return std::make_shared<Student>(*this); }

double Student::get_total()  {
    auto sum = [](const double& accumulator, const Book& book){
        double book_price = book.getPrice();

        double discount = 1;
        if (book.getPublisher().getName() == "Nemira") {
            discount = 0.2;
        }
        return accumulator + (1 - discount) * book_price;
    };
    return std::accumulate(this->books.begin(), this->books.end(), 0.0f, sum);
}
