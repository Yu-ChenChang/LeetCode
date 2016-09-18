CC=g++
CFLAGS=-std=c++0x -g -Wno-logical-op-parentheses

SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,$(BIN)/%,$(SRCS))

BIN = ../bin

all: $(PROGS)

$(BIN)/%: %.cpp
	 $(CC) $(CFLAGS) -o $@ $<
