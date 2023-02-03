//
// Created by Anca on 12/9/2022.
//
#include "../headers/Client.h"
#include<numeric>

Client::Client(const std::string& name_) : name{name_} {}
Client::~Client() = default;

void Client:: add_to_cart(const Book& book) {
    books.push_back(book);
}

const std::string &Client::getName() const {
    return name;
}
