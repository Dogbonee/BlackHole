cmake_minimum_required(VERSION 3.28)
project(BlackHole)

set(SFML_DIR)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES src/main.cpp
        src/Program.cpp
        src/Program.h
        src/LightSource.cpp
        src/LightSource.h
        src/Photon.cpp
        src/Photon.h
        src/BlackHole.cpp
        src/BlackHole.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)