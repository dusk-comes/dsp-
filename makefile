CXX = g++
CXXFLAGS = -Werror -Wextra -Wall -Wpedantic -MMD -MP
INCLUDES = -I$(HEADERDIR)

HEADERDIR := ./headers
SOURCEDIR := ./src

SOURCES := $(wildcard $(SOURCEDIR)/*/*.cpp)
SOURCES += main.cpp
DEPENDS := $(SOURCES:.cpp=.d)
OBJECTS := $(SOURCES:.cpp=.o)
TARGET = dsp

-include $(DEPENDS)

$(TARGET) : $(OBJECTS)
	$(CXX) $^ -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -g -c $< -o $@


.PHONY : clean
clean :
	rm -rf $(TARGET) $(OBJECTS) $(DEPENDS)
