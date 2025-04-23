BIN=main
SRCDIR=src
OBJDIR=build

CXX=g++
OPT=-O0
DEPFLAGS=-MP -MD
CXXFLAGS=-g -Wall -std=c++17 -fpermissive $(OPT) $(DEPFLAGS)
CPPFILES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(CPPFILES))
DEPFILES=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.d,$(CPPFILES))

ifeq ($(OS),Windows_NT)
	RM = rmdir /s /q
	MKDIR = if not exist "$(OBJDIR)" mkdir "$(OBJDIR)"
	RUN = $(OBJDIR)\$(BIN).exe
else
	RM = rm -rf
	MKDIR = mkdir -p $(OBJDIR)
	RUN = ./$(OBJDIR)/$(BIN)
endif

all: $(OBJDIR)/$(BIN)

$(OBJDIR)/$(BIN): $(OBJECTS)
	$(CXX) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(MKDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: all
	$(RUN)

clean:
	$(RM) $(OBJDIR)

-include $(DEPFILES)

.PHONY: all run clean
