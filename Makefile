# Makefile für das Jump'n'Run-Spiel

# Compiler
CXX = g++
# Compiler-Flags
CXXFLAGS = -std=c++11 -Wall

# SFML-Bibliotheken
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Ziel-Datei
TARGET = jump_n_run

# Quell-Dateien
SRCS = main.cpp

# Objekt-Dateien
OBJS = $(SRCS:.cpp=.o)

# Ziel: Build und Link
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(SFML_LIBS)

# Objekt-Dateien erstellen
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean: Löschen der erzeugten Dateien
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
