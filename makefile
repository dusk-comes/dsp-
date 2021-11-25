CXX = g++
CXXFLAGS = -Werror -Wextra -Wall -Wpedantic
INCLUDE = -I./headers/wave

SOURCEDIR = src
BUILDDIR = build

TARGET = dsp
SOURCES = $(wildcard $(SOURCEDIR)/*/*.cpp)
OBJECTS = $(patsubst src/%/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))
ARTEFACTS=*.gpi #maybe should be deleted in later

all : dir $(BUILDDIR)/$(TARGET)

dir :
	mkdir -p $(BUILDDIR)


$(BUILDDIR)/$(TARGET) : $(OBJECTS)
	$(CXX) $^ -o $@

$(OBJECTS) : $(BUILDDIR)/%.o : $(SOURCES)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -g $< -o $@ 

main.o : main.cpp signal.cpp wave.cpp
signal.o : signal.cpp signal.h
wave.o : wave.cpp wave.h

.PHONY : clean
clean : 
	rm -rf $(BUILDDIR) $(ARTEFACTS)
