//
// Created by Anca on 11/27/2022.
//

#include <Author.h>

std::ostream & operator<< (std::ostream& os, const Author& author) {
    os << "Name: " << author.name << ", gender: " << author.gender << ", nationality: " << author.nationality << "\n";
    return os;
}

std::vector<Author> Author::get_authors_by_name(std::vector<Author> authors_list, const std::vector<std::string>& names){
    std::vector<Author> filtered_authors;
    auto name_match_fn = [names](auto author) {
        return std::find(names.begin(), names.end(), author.getName()) != names.end();
    };
    copy_if(begin(authors_list), end(authors_list), std::back_inserter(filtered_authors), name_match_fn);
    return filtered_authors;
}

Author::Author(const std::string& name, const std::string& gender, std::string& nationality): name(name), gender(gender), nationality(nationality){
//    id_max++;
    if(gender != "male" && gender!= "female"){
        throw WrongGender();
    }
}

const std::string &Author::getName() const {
    return name;
}
