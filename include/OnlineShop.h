#pragma once

#include <memory>
#include <string>
#include <vector>

namespace online {

class ItemVisitor;

class Item {
public:
    virtual ~Item() = default;
    virtual void accept(ItemVisitor* visitor) = 0;
    virtual double getPrice() const = 0;
    virtual std::string getDescription() const = 0;
};

class Book : public Item {
public:
    Book(std::string title, std::string author, double price);
    void accept(ItemVisitor* visitor) override;
    double getPrice() const override;
    std::string getDescription() const override;
private:
    std::string title;
    std::string author;
    double price;
};

class Game : public Item {
public:
    Game(std::string title, std::string developer, double price);
    void accept(ItemVisitor* visitor) override;
    double getPrice() const override;
    std::string getDescription() const override;
private:
    std::string title;
    std::string developer;
    double price;
};

class Video : public Item {
public:
    Video(std::string title, std::string director, double price);
    void accept(ItemVisitor* visitor) override;
    double getPrice() const override;
    std::string getDescription() const override;
private:
    std::string title;
    std::string director;
    double price;
};

class ItemVisitor {
public:
    virtual ~ItemVisitor() = default;
    virtual void visit(Book* book) = 0;
    virtual void visit(Game* game) = 0;
    virtual void visit(Video* video) = 0;
};

class PriceVisitor : public ItemVisitor {
public:
    void visit(Book* book) override;
    void visit(Game* game) override;
    void visit(Video* video) override;
    double getTotalPrice() const;
private:
    double totalPrice = 0.0;
};

class DescriptionVisitor : public ItemVisitor {
public:
    void visit(Book* book) override;
    void visit(Game* game) override;
    void visit(Video* video) override;
    std::string getDescription() const;
private:
    std::string description;
};

class ShoppingCart {
public:
    void addItem(std::unique_ptr<Item> item);
    void accept(ItemVisitor* visitor);
    double calculateTotal();
    std::string generateDescription();
private:
    std::vector<std::unique_ptr<Item>> items;
};

} // namespace online
