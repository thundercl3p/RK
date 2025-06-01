#include "OnlineShop.h"
#include <iostream>
#include <memory>

int main() {
    online::ShoppingCart cart;
    
    cart.addItem(std::make_unique<online::Book>("Design Patterns", "Erich Gamma", 45.99));
    cart.addItem(std::make_unique<online::Game>("The Witcher 3", "CD Projekt Red", 29.99));
    cart.addItem(std::make_unique<online::Video>("Inception", "Christopher Nolan", 14.99));

    std::cout << "Items in cart:\n";
    std::cout << cart.generateDescription() << "\n";
    std::cout << "Total price: $" << cart.calculateTotal() << "\n";

    return 0;
}
