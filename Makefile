CC=g++
CFLAGS=-g -Wno-logical-op-parentheses

SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,%,$(SRCS))

all: $(PROGS)

%: %.cpp
	 $(CC) $(CFLAGS) -o $@ $<
