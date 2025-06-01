cmake_minimum_required(VERSION 3.10)
project(VisitorPattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(GTest REQUIRED)
include(GoogleTest)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(visitor_static STATIC
    src/Document.cpp
    src/DocumentVisitor.cpp
    src/Bookstore.cpp
    src/OnlineShop.cpp
)

add_executable(ConceptualExample src/ConceptualExample.cpp)
target_link_libraries(ConceptualExample visitor_static)

add_executable(BookstoreExample src/BookstoreMain.cpp)
target_link_libraries(BookstoreExample visitor_static)

add_executable(OnlineShopExample src/OnlineShopMain.cpp)
target_link_libraries(OnlineShopExample visitor_static)

add_executable(Program src/Program.cpp)
target_link_libraries(Program visitor_static)

add_executable(DocumentTest tests/DocumentTest.cpp)
target_link_libraries(DocumentTest visitor_static GTest::GTest GTest::Main)
gtest_discover_tests(DocumentTest)

add_executable(DocumentVisitorTest tests/DocumentVisitorTest.cpp)
target_link_libraries(DocumentVisitorTest visitor_static GTest::GTest GTest::Main)
gtest_discover_tests(DocumentVisitorTest)

add_executable(BookstoreTest tests/BookstoreTest.cpp)
target_link_libraries(BookstoreTest visitor_static GTest::GTest GTest::Main)
gtest_discover_tests(BookstoreTest)

add_executable(OnlineShopTest tests/OnlineShopTest.cpp)
target_link_libraries(OnlineShopTest visitor_static GTest::GTest GTest::Main)
gtest_discover_tests(OnlineShopTest)

install(TARGETS visitor_static 
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(TARGETS 
    ConceptualExample 
    BookstoreExample 
    OnlineShopExample 
    Program
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)
