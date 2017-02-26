EXECUTABLE = creatures
SOURCES = creature.cpp
SOURCES += barbarian.cpp
SOURCES += utilities.cpp
SOURCES += medusa.cpp
SOURCES += vampire.cpp
SOURCES += blue_men.cpp
SOURCES += harry_potter.cpp

#HEADERS = $(SOURCES:.cpp=.hpp)

MAIN_METHOD_FILE = main_creature.cpp
SOURCES += $(MAIN_METHOD_FILE)
OBJECTS = $(SOURCES:.cpp=.o)

#SOURCES += $(HEADERS)

#comment out unless using precompiled headers
REMOVE_HEADERS =
#REMOVE_HEADERS += *.gch

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -c -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = 

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)
	
$(OBJECTS): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES)
	
clean:
	rm *o $(REMOVE_HEADERS) $(EXECUTABLE)
