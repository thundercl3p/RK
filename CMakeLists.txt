cmake_minimum_required(VERSION 3.10)
project(VisitorPattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(visitor_static STATIC
    include/Document.h
    include/DocumentVisitor.h
    src/Document.cpp
    src/DocumentVisitor.cpp
    # Добавьте другие файлы по необходимости
)

add_executable(ConceptualExample ConceptualExample.cpp)
target_link_libraries(ConceptualExample visitor_static)

add_executable(BookstoreExample Bookstore.cpp)
target_link_libraries(BookstoreExample visitor_static)

add_executable(OnlineShopExample OnlineShop.cpp)
target_link_libraries(OnlineShopExample visitor_static)

enable_testing()

add_executable(DocumentTest tests/DocumentTest.cpp)
target_link_libraries(DocumentTest visitor_static)
add_test(NAME DocumentTest COMMAND DocumentTest)

add_executable(DocumentVisitorTest tests/DocumentVisitorTest.cpp)
target_link_libraries(DocumentVisitorTest visitor_static)
add_test(NAME DocumentVisitorTest COMMAND DocumentVisitorTest)

install(TARGETS visitor_static ARCHIVE DESTINATION lib)
install(TARGETS ConceptualExample BookstoreExample OnlineShopExample 
        RUNTIME DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)
