#cpp compiler & linker
CPP	 		:= g++
AR			:= ar

#Binary program
TARGET 		:= libdsp.a
DSP			:= dsp

#The directories, sources, objects, libraries, dependencies
SRCDIR		:= src
INCDIR		:= inc
BUILDDIR	:= obj
LIBDIR		:= lib
BINDIR		:= bin
RESDIR		:= res
SRCEXT		:= cpp
DEPEXT		:= d
OBJEXT		:= o

#Compiler's options
CXXFLAGS 	:= -Werror -Wextra -Wall -Wpedantic
INC 		:= -I$(INCDIR)
LIB 		:= $(patsubst lib%.a, -l%, $(TARGET))

#Ar's options
ARFLAGS 	:= -rusUv

#------------------------------------------------------------------
#JUST CONTEMPLATE AN ACTION BELOW
#------------------------------------------------------------------
SOURCES 	:= $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS		:= $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Default Make
all: directories $(LIBDIR)/$(TARGET) $(BINDIR)/$(DSP)

directories:
	@mkdir -p $(LIBDIR)
	@mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR) $(LIBDIR) $(BINDIR)

#Pull in dependecy info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

#Create library
$(LIBDIR)/$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

#Compile source
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INC) -MMD -MP -c -o $@ $<

#Build a Main Program
$(BINDIR)/$(DSP) : $(DSP).$(SRCEXT) | $(BINDIR)
	$(CXX) $(CXXFLAGS) $(INC) -L$(LIBDIR) $(LIB) -c -o $@ $<
	@cp $(RESDIR)/* $(BINDIR)

$(BINDIR):
	@mkdir $@

resources:

.PHONY: all, directories, clean, resources, $(BINDIR)
