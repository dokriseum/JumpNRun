cmake_minimum_required(VERSION 3.26)
project(JumpNRun)

set(CMAKE_CXX_STANDARD 14)

# Füge die Quell-Dateien hinzu
add_executable(JumpNRun main.cpp mvc/Game.cpp mvc/Player.cpp mvc/Platform.cpp)

# Füge die Header-Dateien hinzu
target_include_directories(JumpNRun PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/mvc ${CMAKE_CURRENT_SOURCE_DIR}/pic)

# Finde SFML-Pakete
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Linke SFML-Bibliotheken
target_link_libraries(JumpNRun sfml-graphics sfml-window sfml-system)
