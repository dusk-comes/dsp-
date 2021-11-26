CXX = g++
CXXFLAGS = -Werror -Wextra -Wall -Wpedantic
INCLUDE = -I../../headers

SOURCEDIR = src

TARGET = dsp
SOURCES := $(wildcard $(SOURCEDIR)/*/*.cpp)
OBJECTS := $(SOURCES:cpp=o)

$(TARGET) : $(OBJECTS)
	$(CXX) $^ -o $@

$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -g -c $< -o $@

wave.o : wave.cpp
signal.o : signal.cpp

.PHONY : clean
clean :
	rm -rf $(OBJECTS)
