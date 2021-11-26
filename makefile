HEADERDIR := ./headers
SOURCEDIR := ./src
LIBDIR := ./lib

TARGET := libdsp.a
DSP := dsp

SOURCES := $(wildcard $(SOURCEDIR)/*/*.cpp)
DEPENDS := $(SOURCES:.cpp=.d)
OBJECTS := $(sort $(SOURCES:.cpp=.o))

CXX = g++
CXXFLAGS = -Werror -Wextra -Wall -Wpedantic -MMD -MP
INCLUDES = -I$(HEADERDIR)
INCLUDELIBS = -L$(LIBDIR)
LIBS = $(patsubst lib%.a, -l%, $(TARGET))

AR = ar
ARFLAGS = -rusUv

-include $(DEPENDS)

$(LIBDIR)/$(TARGET) : $(OBJECTS) | $(LIBDIR)
	$(AR) $(ARFLAGS) $@ $^

$(LIBDIR) :
	mkdir $@

$(DSP) : $(DSP).o | $(LIBDIR)/$(TARGET)
	$(CXX) -g -o $@ $< -L$(LIBDIR) $(LIBS)

$(DSP).o : $(DSP).cpp
	$(CXX) $(INCLUDES) -o $@ -g -c $<

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -g -c $< -o $@


.PHONY : clean
clean :
	@rm -rf $(LIBDIR) $(OBJECTS) $(DEPENDS) $(DSP)

.PHONY : print
print :
	@echo $(please)
