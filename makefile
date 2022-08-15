#cpp compiler & linker
CPP	 		:= g++
AR			:= ar

#Binary program
TARGET 		:= libdsp.a
DSP			:= dsp

#The directories, sources, objects, libraries, dependencies
SRCDIR		:= src
INCDIR		:= inc /usr/include/alsa
BUILDDIR	:= obj
LIBDIR		:= lib
BINDIR		:= bin
RESDIR		:= res
SRCEXT		:= cpp
DEPEXT		:= d
OBJEXT		:= o

#Compiler's options
CXXFLAGS 	:= -Werror -Wextra -Wall -Wpedantic -g
INC 		:= $(addprefix -I, $(INCDIR))
LIB 		:= $(patsubst lib%.a, -l%, $(TARGET))
LIB			+= -lasound			#external libraries

#Ar's options
ARFLAGS 	:= -rusUv

#------------------------------------------------------------------
#JUST CONTEMPLATE AN ACTION BELOW
#------------------------------------------------------------------
SOURCES 	:= $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS		:= $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Default Make
all: $(LIBDIR)/$(TARGET) $(BINDIR)/$(DSP)

clean:
	rm -rf $(BUILDDIR) $(LIBDIR) $(BINDIR)

plot:
	./bin/plot.sh *.gpi

run:
	./bin/dsp

#Pull in dependecy info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

#Create library
$(LIBDIR)/$(TARGET): $(OBJECTS) | $(LIBDIR)
	$(AR) $(ARFLAGS) $@ $^

#Compile source
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INC) -MMD -MP -c -o $@ $<

#Compile executable
$(BUILDDIR)/$(DSP).$(OBJEXT) :
	$(CXX) $(CXXFLAGS) $(INC) -c $(DSP).$(SRCEXT) -o $@

#Link executable
$(BINDIR)/$(DSP): $(BUILDDIR)/$(DSP).$(OBJEXT) | $(BINDIR)
	$(CXX) -o $@ $< -L$(LIBDIR) $(LIB)
	@cp $(RESDIR)/* $(BINDIR)

$(LIBDIR):
	@mkdir -p $@

$(BINDIR):
	@mkdir -p $@

.PHONY: all, clean, $(BINDIR), $(LIBDIR)
