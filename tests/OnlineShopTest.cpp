#include <gtest/gtest.h>
#include "OnlineShop.h"

using online::ShoppingCart;
using online::Book;
using online::Game;
using online::Video;

TEST(OnlineShopTest, PriceVisitor) {
    ShoppingCart cart;
    cart.addItem(std::make_unique<Book>("Book", "Author", 10.0));
    cart.addItem(std::make_unique<Game>("Game", "Dev", 20.0));
    cart.addItem(std::make_unique<Video>("Video", "Director", 5.0));
    
    EXPECT_DOUBLE_EQ(cart.calculateTotal(), 35.0);
}

TEST(OnlineShopTest, DescriptionVisitor) {
    ShoppingCart cart;
    cart.addItem(std::make_unique<Book>("Design Patterns", "Erich Gamma", 49.99));
    cart.addItem(std::make_unique<Game>("The Witcher 3", "CD Projekt Red", 29.99));
    
    std::string desc = cart.generateDescription();
    
    EXPECT_TRUE(desc.find("Book: Design Patterns") != std::string::npos);
    EXPECT_TRUE(desc.find("by Erich Gamma") != std::string::npos);
    EXPECT_TRUE(desc.find("Game: The Witcher 3") != std::string::npos);
    EXPECT_TRUE(desc.find("by CD Projekt Red") != std::string::npos);
    
    EXPECT_NE(desc.find("Design Patterns"), std::string::npos);
    EXPECT_NE(desc.find("The Witcher 3"), std::string::npos);
}
