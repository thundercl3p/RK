#include "Bookstore/Book.hpp"
#include "Bookstore/Movie.hpp"
#include <gtest/gtest.h>

TEST(BookTest, BasicProperties) {
    Book book("C", "Dennis Ritchie", 11.99, 12);
    EXPECT_EQ(book.getTitle(), "C");
    EXPECT_EQ(book.getAuthor(), "Dennis Ritchie");
    EXPECT_DOUBLE_EQ(book.getPrice(), 11.99);
    EXPECT_EQ(book.getCount(), 12);
}

TEST(MovieTest, BasicProperties) {
    Movie movie("Spectre", "Sam Mendes", 8.99, 6);
    EXPECT_EQ(movie.getTitle(), "Spectre");
    EXPECT_EQ(movie.getDirector(), "Sam Mendes");
    EXPECT_DOUBLE_EQ(movie.getPrice(), 8.99);
    EXPECT_EQ(movie.getCount(), 6);
}
