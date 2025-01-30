cmake_minimum_required(VERSION 3.28)
project(LiveDraw LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp
        src/Components/UIElement.h
        src/Components/Button/Button.cpp
        src/Components/Button/Button.h
        src/Components/UICollection/UICollection.cpp
        src/Components/UICollection/UICollection.h)
target_link_libraries(main PRIVATE SFML::Graphics)
target_link_libraries(main PRIVATE Dwmapi)
