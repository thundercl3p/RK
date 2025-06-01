#include <gtest/gtest.h>
#include "Bookstore.h"

TEST(BookstoreTest, TotalBalanceCalculation) {
    store::Book book1{"Test Book", "Author", 10.0, 2};
    store::Movie movie{"Test Movie", "Director", 5.0, 3};
    store::Book book2{"Second Book", "Author", 7.5, 4};
    
    store::Bookstore store{book1, movie, book2};
    EXPECT_DOUBLE_EQ(store.totalBalance(), 65.0);
    
    store.addMedia(store::Book{"Another Book", "Author", 15.0, 1});
    EXPECT_DOUBLE_EQ(store.totalBalance(), 80.0);
}

TEST(BookstoreTest, AddMedia) {
    store::Book book{"Dummy Book", "Author", 0.0, 0};
    store::Movie movie{"Dummy Movie", "Director", 0.0, 0};
    
    store::Bookstore store{book, movie, book};
    EXPECT_DOUBLE_EQ(store.totalBalance(), 0.0);
    
    store.addMedia(store::Book{"Test", "Author", 10.0, 1});
    EXPECT_DOUBLE_EQ(store.totalBalance(), 10.0);
    
    store.addMedia(store::Movie{"Test", "Director", 5.0, 2});
    EXPECT_DOUBLE_EQ(store.totalBalance(), 20.0);
}
