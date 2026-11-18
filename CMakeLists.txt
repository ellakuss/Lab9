cmake_minimum_required(VERSION 3.20)
project(Lab9Variant12 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Lab9Variant12
    src/main.cpp
    src/library/Book.cpp
    src/library/Library.cpp
    src/library/ConsoleBookRepository.cpp
    src/library/ConsoleBookNotifier.cpp
    src/gilded_rose/ItemUpdater.cpp
    src/gilded_rose/Strategies.cpp
)
target_include_directories(Lab9Variant12 PRIVATE src)

add_executable(Lab9Tests
    tests/tests.cpp
    src/library/Book.cpp
    src/library/Library.cpp
    src/library/ConsoleBookRepository.cpp
    src/library/ConsoleBookNotifier.cpp
    src/gilded_rose/ItemUpdater.cpp
    src/gilded_rose/Strategies.cpp
)
target_include_directories(Lab9Tests PRIVATE src)

enable_testing()
add_test(NAME Lab9Tests COMMAND Lab9Tests)
