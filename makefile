CXX = g++
OBJ = main.o signal.o wave.o
TARGET = dsp

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

%.o : %.cpp
	$(CXX) -c -g -o $@ $<

main.o : main.cpp signal.cpp signal.h
signal.o : signal.cpp signal.h
wave.o : wave.cpp wave.h

.PHONY : clean
clean : 
	rm $(OBJ) $(TARGET)
