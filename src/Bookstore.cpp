#include "Bookstore.h"
#include <iostream>

namespace store {

Book::Book(std::string title, std::string author, double price, int count)
    : title(std::move(title)), author(std::move(author)), price(price), count(count) {}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
double Book::getPrice() const { return price; }
int Book::getCount() const { return count; }
double Book::totalValue() const { return price * count; }

Movie::Movie(std::string title, std::string director, double price, int count)
    : title(std::move(title)), director(std::move(director)), price(price), count(count) {}

std::string Movie::getTitle() const { return title; }
std::string Movie::getDirector() const { return director; }
double Movie::getPrice() const { return price; }
int Movie::getCount() const { return count; }
double Movie::totalValue() const { return price * count; }

Bookstore::Bookstore(const Book& book, const Movie& movie, const Book& anotherBook) {
    mediaItems.emplace_back(book);
    mediaItems.emplace_back(movie);
    mediaItems.emplace_back(anotherBook);
}

void Bookstore::addMedia(const Media& item) {
    mediaItems.push_back(item);
}

double Bookstore::totalBalance() const {
    double total = 0.0;
    for (const auto& item : mediaItems) {
        std::visit([&total](const auto& media) {
            total += media.totalValue();
        }, item);
    }
    return total;
}

} // namespace store
