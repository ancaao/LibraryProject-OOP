//
// Created by Anca on 12/9/2022.
//

#ifndef UNTITLED1_CLIENT_H
#define UNTITLED1_CLIENT_H
#include<iostream>
#include "../headers/Book.h"
#include <algorithm>
#include <memory>
#include<utility>

class Client{
protected:
    std::string name;
    std::vector<Book> books;
public:
    Client() = default;
    Client(const std::string& name_);

    virtual ~Client() = 0;
    virtual std::shared_ptr<Client> clone() const = 0;
    const std::string &getName() const;

    void add_to_cart(const Book& book);
    virtual double get_total() = 0;
};

#endif //UNTITLED1_CLIENT_H
