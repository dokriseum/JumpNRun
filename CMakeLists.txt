cmake_minimum_required(VERSION 3.26)
project(JumpNRun)

set(CMAKE_CXX_STANDARD 14)

# Füge die Quell-Datei und die generierten Header-Dateien hinzu
add_executable(JumpNRun main.cpp pic/background.h pic/player.h pic/platform.h)

# Finde SFML-Pakete
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Linke SFML-Bibliotheken
target_link_libraries(JumpNRun sfml-graphics sfml-window sfml-system)
