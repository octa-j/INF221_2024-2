# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Source files
SOURCES = main.cpp fuerza_bruta.cpp progra_dinamica.cpp costos.cpp

# Object files (replace .cpp with .o in SOURCES)
OBJECTS = $(SOURCES:.cpp=.o)

# Executable name
EXECUTABLE = ex

# Rule to build the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
