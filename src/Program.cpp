#include "Bookstore.h"
#include "OnlineShop.h"
#include <iostream>

void demonstrateBookstore() {
    store::Book cBook{"C", "Dennis Ritchie", 11.99, 12};
    store::Book javaBook{"Java", "James Gosling", 17.99, 21};
    store::Movie movieTarantino{"Once upon a time in Hollywood", "Quentin Tarantino", 6.99, 3};

    store::Bookstore bookstore{cBook, movieTarantino, javaBook};
    bookstore.addMedia(store::Book{"C++", "Bjarne Stroustrup", 16.99, 4});
    
    double balance = bookstore.totalBalance();
    std::cout << "Total value of Bookstore: " << balance << std::endl;
}

void demonstrateOnlineShop() {
    online::ShoppingCart cart;
    cart.addItem(std::make_unique<online::Book>("Design Patterns", "Erich Gamma", 49.99));
    cart.addItem(std::make_unique<online::Game>("The Witcher 3", "CD Projekt Red", 29.99));
    cart.addItem(std::make_unique<online::Video>("Inception", "Christopher Nolan", 9.99));

    std::cout << "Shopping Cart Contents:\n" << cart.generateDescription();
    std::cout << "Total Price: $" << cart.calculateTotal() << std::endl;
}

int main() {
    std::cout << "=== Bookstore Demonstration ===\n";
    demonstrateBookstore();
    
    std::cout << "\n=== Online Shop Demonstration ===\n";
    demonstrateOnlineShop();
    
    return 0;
}
