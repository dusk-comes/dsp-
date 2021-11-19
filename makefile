CXX = g++
CXXFLAGS = -Werror -Wextra -Wall -Wpedantic
OBJ = main.o signal.o wave.o
TARGET = dsp
ARTEFACTS=*.gpi

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -g -o $@ $<

main.o : main.cpp signal.cpp wave.cpp
signal.o : signal.cpp signal.h
wave.o : wave.cpp wave.h

.PHONY : clean
clean : 
	rm $(OBJ) $(TARGET) $(ARTEFACTS)
