CC=g++
CFLAGS=-g -Wno-logical-op-parentheses

SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,$(BIN)/%,$(SRCS))

BIN = ../bin

all: $(PROGS)

$(BIN)/%: %.cpp
	 $(CC) $(CFLAGS) -o $@ $<
