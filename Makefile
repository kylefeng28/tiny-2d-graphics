CC = gcc
CXX = g++
RM = rm

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CPPFLAGS = -Wall -g -O0
    LDFLAGS = -g
    LDLIBS =
else
    CPPFLAGS = -Wall -O3
    LDFLAGS =
    LDLIBS =
endif


OUT = main
SRCS = main.cpp tga.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(OUT) $(OBJS) $(LDLIBS) 

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c $<

.PHONY: clean
clean:
	$(RM) $(OBJS)

.PHONY: distclean
distclean: clean
	$(RM) $(OUT)
