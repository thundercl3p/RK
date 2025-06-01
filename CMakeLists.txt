cmake_minimum_required(VERSION 3.10)
project(VisitorPattern)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_library(VisitorStatic STATIC
    include/Bookstore/Book.hpp
    include/Bookstore/Movie.hpp
    include/Bookstore/Bookstore.hpp
    include/OnlineShop/Element.hpp
    include/OnlineShop/Visitor.hpp
    include/OnlineShop/ShoppingBasket.hpp
    include/ConceptualExample/VisitorBase.hpp
    include/ConceptualExample/ElementBase.hpp
)

add_executable(VisitorApp app/main.cpp)
target_link_libraries(VisitorApp PRIVATE VisitorStatic)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(BookstoreTests tests/BookstoreTests.cpp)
target_link_libraries(BookstoreTests PRIVATE VisitorStatic GTest::GTest GTest::Main)
gtest_discover_tests(BookstoreTests)

add_executable(OnlineShopTests tests/OnlineShopTests.cpp)
target_link_libraries(OnlineShopTests PRIVATE VisitorStatic GTest::GTest GTest::Main)
gtest_discover_tests(OnlineShopTests)

add_executable(ConceptualTests tests/ConceptualExampleTests.cpp)
target_link_libraries(ConceptualTests PRIVATE VisitorStatic GTest::GTest GTest::Main)
gtest_discover_tests(ConceptualTests)

set(CPACK_GENERATOR "DEB")
include(CPack)
