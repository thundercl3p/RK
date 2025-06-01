#pragma once

#include <string>
#include <vector>
#include <variant>

namespace store {

class Book {
public:
    Book(std::string title, std::string author, double price, int count);
    std::string getTitle() const;
    std::string getAuthor() const;
    double getPrice() const;
    int getCount() const;
    double totalValue() const;
private:
    std::string title;
    std::string author;
    double price;
    int count;
};

class Movie {
public:
    Movie(std::string title, std::string director, double price, int count);
    std::string getTitle() const;
    std::string getDirector() const;
    double getPrice() const;
    int getCount() const;
    double totalValue() const;
private:
    std::string title;
    std::string director;
    double price;
    int count;
};

using Media = std::variant<Book, Movie>;

class Bookstore {
public:
    Bookstore() = default;
    Bookstore(const Book& book, const Movie& movie, const Book& anotherBook);
    void addMedia(const Media& item);
    double totalBalance() const;
private:
    std::vector<Media> mediaItems;
};

} // namespace store
