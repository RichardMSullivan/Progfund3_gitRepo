# Makefile for building Graphics demo on command line
FILES 	= $(wildcard src/*.cpp) $(wildcard lib/*.cpp)
OBJS	= $(FILES:.cpp=.o)
TARGET 	= Lab1 

ifeq ($(OS), Windows_NT)
	EXT = .exe
	RUN = $(TARGET)
	RM	= del
	CFLAGS = -Iinclude
	LFLAGS =
	LFLAGS +=
	CXX = g++
	DOBJS = $(subst /,\,$(OBJS))
else
	EXT =
	RM 	= rm -f
	RUN = ./$(TARGET)
	CXX = g++
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
	    CFLAGS =
		LFLAGS = 
	endif
	ifeq ($(UNAME_S), Darwin)
		CFLAGS = -Iinclude
		LFLAGS =
	endif
	DOBJS = $(OBJS)
endif

.PHONY: all
all:	$(TARGET)$(EXT)

$(TARGET)$(EXT):	$(OBJS)
	g++ -std=c++11 -o $(TARGET)$(EXT) $(OBJS) $(LFLAGS)

%.o:	%.cpp
	g++ -std=c++11 -c $< -o $@ $(CFLAGS)

.PHONY: run
run:	$(TARGET)$(EXT)
		$(RUN)

.PHONY: clean
clean:
	$(RM) $(TARGET)$(EXT) $(DOBJS)


.PHONY: vim
vim:
	vim $(FILES) $(wildcard ./include/*.h) $(wildcard ./include/*.cpp)
