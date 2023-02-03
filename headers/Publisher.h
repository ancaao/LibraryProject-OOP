//
// Created by Anca on 11/27/2022.
//

#ifndef MAIN_CPP_PUBLISHER_H
#define MAIN_CPP_PUBLISHER_H

#include<iostream>
#include<vector>
#include "../headers/Author.h"

class Publisher{
    std::string name;
    std::vector<Author> authors;
public:
    Publisher() = default;
    ~Publisher() = default;

    std::string getName() const;

    Publisher(const std::string& name_, const std::vector<Author>& authors_);

/*    Publisher(const Publisher& other) : name{other.name},authors{other.authors}  {
        std::cout << "Constr de copiere Publisher\n";
    }*/
/*    Publisher& operator=(const Publisher& other) {
        std::cout << "Operator= de copiere Publisher\n\n";
        name = other.name;
        authors = other.authors;
        return *this;
    }*/

    friend std::ostream& operator<<(std::ostream& os, const Publisher& publisher);
};
#endif //MAIN_CPP_PUBLISHER_H
