#include "OnlineShop.h"

namespace online {

Book::Book(std::string title, std::string author, double price)
    : title(std::move(title)), author(std::move(author)), price(price) {}

void Book::accept(ItemVisitor* visitor) {
    visitor->visit(this);
}

double Book::getPrice() const {
    return price;
}

std::string Book::getDescription() const {
    return "Book: " + title + " by " + author;
}

Game::Game(std::string title, std::string developer, double price)
    : title(std::move(title)), developer(std::move(developer)), price(price) {}

void Game::accept(ItemVisitor* visitor) {
    visitor->visit(this);
}

double Game::getPrice() const {
    return price;
}

std::string Game::getDescription() const {
    return "Game: " + title + " by " + developer;
}

Video::Video(std::string title, std::string director, double price)
    : title(std::move(title)), director(std::move(director)), price(price) {}

void Video::accept(ItemVisitor* visitor) {
    visitor->visit(this);
}

double Video::getPrice() const {
    return price;
}

std::string Video::getDescription() const {
    return "Video: " + title + " by " + director;
}

void PriceVisitor::visit(Book* book) {
    totalPrice += book->getPrice();
}

void PriceVisitor::visit(Game* game) {
    totalPrice += game->getPrice();
}

void PriceVisitor::visit(Video* video) {
    totalPrice += video->getPrice();
}

double PriceVisitor::getTotalPrice() const {
    return totalPrice;
}

void DescriptionVisitor::visit(Book* book) {
    description += book->getDescription() + "\n";
}

void DescriptionVisitor::visit(Game* game) {
    description += game->getDescription() + "\n";
}

void DescriptionVisitor::visit(Video* video) {
    description += video->getDescription() + "\n";
}

std::string DescriptionVisitor::getDescription() const {
    return description;
}

void ShoppingCart::addItem(std::unique_ptr<Item> item) {
    items.push_back(std::move(item));
}

void ShoppingCart::accept(ItemVisitor* visitor) {
    for (const auto& item : items) {
        item->accept(visitor);
    }
}

double ShoppingCart::calculateTotal() {
    PriceVisitor visitor;
    accept(&visitor);
    return visitor.getTotalPrice();
}

std::string ShoppingCart::generateDescription() {
    DescriptionVisitor visitor;
    accept(&visitor);
    return visitor.getDescription();
}

} // namespace online
