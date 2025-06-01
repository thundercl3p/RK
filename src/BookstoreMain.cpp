#include "Bookstore.h"
#include <iostream>

int main() {
    store::Bookstore store;
    
    store.addMedia(store::Book("Clean Code", "Robert Martin", 35.99, 10));
    store.addMedia(store::Movie("The Matrix", "Wachowskis", 19.99, 5));

    std::cout << "Total store balance: $" << store.totalBalance() << "\n";
    return 0;
}
