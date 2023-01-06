//
// Created by Anca on 11/27/2022.
//
#include "../headers/Library.h"
#include "../headers/Student.h"
#include "../headers/NGO.h"
#include "../headers/Retiree.h"

template <typename T>
void Library<T>::add_client(const Client& client){
    clients.push_back(client.clone());
}

template <typename T>
void Library<T>::set_sort_strategy(std::unique_ptr<SortStrategy> &&strategy_) {
    strategy = std::move(strategy_);
}

template <typename T>
std::vector<Book> Library<T>::filter_by_genre(Genre genre) const {
    std::vector<Book> new_books;
    auto genre_match_fn = [genre](auto book) {
        return book.getGenre() == genre;
    };
    copy_if(begin(books), end(books), std::back_inserter(new_books), genre_match_fn);
    return new_books;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Library<T>& library) {
    os << "Library - " << "Name: " << library.name  << "\n";

    if (library.strategy) {
        std::vector<Book> sorted_books = library.strategy->sort(library.books);
        for(const auto& book : sorted_books)
            os << "Book - " << book << "\n";
    } else {
        for(const auto& book : library.books)
            os << "Book - " << book << "\n";
    }

    return os;
}

template <typename T>
void Library<T>::get_details(Client* client){
    if(auto* student = dynamic_cast <Student*>(client)) {
        std::cout << "Clientul " << student->getName() << " are reducere 20% la cartile de la editura Nemira" << std::endl;
    } else if(auto* ngo = dynamic_cast <NGO*>(client)) {
        std::cout << "Clientul " << ngo->getName() << " are reducere la toate cumparaturile in functie de numarul de voluntari" << std::endl;
    } else if(auto* retiree = dynamic_cast <Retiree*>(client)) {
        std::cout << "Clientul " << retiree->getName() << " are reducere la intregul cos in functie de numarul de carti cumparate" << std::endl;
    } else {
        std::cout << "Tipul clientului nu este valid!";
    }

    std::cout<< "Valoare cumparaturilor este in valoare de " << client->get_total() << std::endl;
}

template <typename T>
double Library<T>::get_total_sales() {
    double sum = 0.0;
    for (auto &client : clients) {
        sum += client->get_total();
    }

    return sum;
}

template <typename T>
Library<T>::Library(const T& name_, const std::vector<Book>& books_) : name{name_}, books{books_} {}

template class Library<std::string>;

template std::ostream& operator<< <>(std::ostream& os, const Library<std::string>& library);
