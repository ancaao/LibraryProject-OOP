//
// Created by Anca on 11/27/2022.
//

#ifndef MAIN_CPP_LIBRARY_H
#define MAIN_CPP_LIBRARY_H

#include "Book.h"
#include "Client.h"
#include "SortStrategy.h"
#include <algorithm>

template <typename T>
class Library;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Library<T>& library);

template <typename T>
class Library{
    T name;
    std::vector<Book> books;
    std::vector<std::shared_ptr<Client>> clients;
    std::unique_ptr<SortStrategy> strategy;
public:
    Library() = default;
    ~Library() = default;

    void add_client(const Client& client);

    auto find(const std::string& title) const {
        auto title_match_fn = [title](auto book) {
            return book.getTitle() == title;
        };

        auto it = find_if(begin(books), end(books), title_match_fn);
        if (it == end(books)) {
            std::cout << "Book unavailable\n";
        }
//        else std::cout << "Book available\n";
        return it;
    }

    std::vector <Book> find_by_word(const std::string& word){
        std::vector<Book> list;
        std::string word_lower_case;
        std::transform(word.begin(), word.end(), word_lower_case.begin(), ::tolower);

        auto word_match_fn = [word](auto book) {
            std::string author_name = book.getAuthor().getName();
            std::transform(author_name.begin(), author_name.end(), author_name.begin(), ::tolower);

            size_t found = author_name.find(word);
            if( found != std::string::npos)
                return true;

            std::string title = book.getTitle();
            std::transform(title.begin(), title.end(), title.begin(), ::tolower);

            found = title.find(word);
            if( found != std::string::npos)
                return true;
            return false;
        };

        auto it = begin(books);

        while (it != end(books)) {
            it = find_if(it, end(books), word_match_fn);
            if (it != end(books)) {
                list.push_back(*it);
                it++;
            }
        }

        if (list.empty()) {
            std::cout << "Books not found\n";
        }

        return list;
    }

    void get_details(Client* client);

    void set_sort_strategy(std::unique_ptr<SortStrategy> &&strategy);

    double get_total_sales();

    std::vector<Book> filter_by_genre(Genre genre) const;

    Library(const T& name_, const std::vector<Book>& books_);

    friend std::ostream& operator<< <>(std::ostream& os, const Library<T>& library);
};
#endif //MAIN_CPP_LIBRARY_H
