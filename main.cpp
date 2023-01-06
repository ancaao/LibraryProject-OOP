#include<fstream>
#include<map>
#include<string>
#include "headers/Author.h"
#include "headers/Publisher.h"
#include "headers/Book.h"
#include "headers/Library.h"
#include "headers/Student.h"
#include "headers/NGO.h"
#include "headers/Retiree.h"
#include "headers/AuthorException.h"
#include "headers/BookException.h"
#include "headers/Regular.h"


void read_Author(std::ifstream &fauthor, std::vector<Author> &authors){

    fauthor.open ("database/authors.in");
    if (!fauthor.is_open()) std::cerr << "Error in opening the file" << std::endl;
    else{
        while(fauthor.good()){
            std::string name, gender, nationality;
            std::getline(fauthor, name, ',');
            std::getline(fauthor, gender, ',');
            std::getline(fauthor, nationality, '\n');
            if(fauthor.eof()) break;

            try{
                authors.emplace_back(name, gender, nationality);
            } catch (AuthorException &error) {
                std::cout << error.what() << '\n';
            }
        }
    }

//    for(auto const & i : author) std::cout  << i << "\n";
}

void read_Publisher(std::ifstream &fpublisher, std::vector<Publisher> &publishers, std::vector<Author> const &authors_list){

    fpublisher.open ("database/publishers.in");
    if (!fpublisher.is_open()) std::cerr << "Error in opening the file" << std::endl;
    else{
        while(fpublisher.good()){
            std::string name, author_name, buffer;
            int authors_count;
            std::vector <std::string> author_names;
            std::getline(fpublisher, name, ',');
//        std::cout << "name: " << name << std::endl;
            std::getline(fpublisher, buffer, ',');
//        std::cout << "nr: " << buffer << std::endl;
            authors_count = std::stoi(buffer);

            while(authors_count) {
                if (authors_count != 1) {
                    std::getline(fpublisher, author_name, ',');
                } else {
                    std::getline(fpublisher, author_name, '\n');
                }
//            std::cout << "author: " << author_name << std::endl;
                author_names.push_back(author_name);
                authors_count--;
            }
            publishers.push_back(Publisher(name, Author::get_authors_by_name(authors_list, author_names)));
            if(fpublisher.eof()) break;

            author_names.clear();
        }
    }

    for(auto const & i : publishers) std::cout  << i << "\n";
}

void read_book(std::ifstream &fbook, std::vector<Book> &books, std::vector<Author> &authors_list, std::vector<Publisher> &publisher_list){

    fbook.open ("database/books.in");
    if (!fbook.is_open()) std::cerr << "Error in opening the file" << std::endl;
    else{
        while(fbook.good()){
            std::string title, author_name, publisher_name;
            std::map<std::string, Genre> pairs = { {"Fiction" , Genre::Fiction} , {"Nonfiction" , Genre::Nonfiction}, {"Drama" , Genre::Drama}, {"Folktale" , Genre::Folktale}, {"Poetry" , Genre::Poetry} };
            double price;
            Genre genre;
            int year;
            std::getline(fbook, title, ',');
            std::getline(fbook, author_name, ',');
            std::getline(fbook, publisher_name, ',');

            std::string aux;
            std::getline(fbook, aux, ',');

            price = std::stod(aux);

            try{
                std::getline(fbook, aux, ',');
                genre = pairs.at(aux);
            }catch(const std::out_of_range& e){
                (void)e;
                throw WrongGender();
            }

            std::getline(fbook, aux, '\n');
            year = stoi(aux);

            auto author = Author::get_authors_by_name(authors_list, {author_name}).front();

            auto publisher = *std::find_if(publisher_list.begin(), publisher_list.end(), [publisher_name](auto publisher)
            { return publisher_name == publisher.getName(); });

            books.push_back(
                    Book(title,
                         author,
                         publisher,
                         price,
                         genre,
                         year
                    )
            );
        }
    }

//    for(auto const & i : books) std::cout  << i << "\n";
}

int main() {
    std::vector<Author> authors;
    std::vector<Publisher> publishers;
    std::vector<Book> books;

    std::ifstream fauthor;
    std::ifstream fpublisher;
    std::ifstream fbook;

    read_Author(fauthor, authors);
    read_Publisher(fpublisher, publishers, authors);
    read_book(fbook, books, authors, publishers);

    Library carturesti("Carturesti", books);

    Regular normal("Mihai");
    normal.add_to_cart(*carturesti.find("Ion"));
    carturesti.add_client(normal);

    Student de_la_poli("mmmm");
    de_la_poli.add_to_cart(*carturesti.find("Cartile junglei"));
    de_la_poli.add_to_cart(*carturesti.find("Povestea lui Harap-Alb"));
    carturesti.add_client(de_la_poli);

    NGO ASMI("ASMI", 250);
    ASMI.add_to_cart(*carturesti.find("Jack si vrejul de fasole"));
    carturesti.add_client(ASMI);

    Retiree baba("Monica");
    baba.add_to_cart(*carturesti.find("Jack si vrejul de fasole"));
    baba.add_to_cart(*carturesti.find("Jack si vrejul de fasole"));
    baba.add_to_cart(*carturesti.find("Jack si vrejul de fasole"));
    carturesti.add_client(baba);

    std::cout << "Totalul de plata pentru client: " << normal.get_total() << std::endl;
    std::cout << "Totalul de plata pentru student: " << de_la_poli.get_total() << std::endl;
    std::cout << "Totalul de plata pentru ONG: " << ASMI.get_total() << std::endl;
    std::cout << "Totalul de plata pentru pensionar: " <<baba.get_total() <<std::endl;

    carturesti.get_details(&ASMI);

    std::vector<Book> books_ = carturesti.find_by_word("ion");
    std::cout << "Cartile care contin sirul de caractere introdus sunt: \n";
    for(auto const & i : books_) std::cout  << i << "\n";

    double total_sales = carturesti.get_total_sales();
    std::cout << total_sales << "\n\n";

    std::cout << "Cartile gasite din genul cautat sunt: " << std::endl;
    std::vector<Book> Fiction_books = carturesti.filter_by_genre(Genre::Fiction);
    for (const Book& book: Fiction_books) std::cout << book <<"\n";

    return 0;
}
