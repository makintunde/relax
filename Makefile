INC_DIR = include
CFLAGS = -Wall -std=c++11 -I$(INC_DIR)
TARGETS = relax

all: $(TARGETS)

clean:
	$(RM) $(TARGETS) *.o

relax: relax.o
	g++ relax.o -o relax 

relax.o: include/relax.h
	g++  $(CFLAGS) -c src/relax.cpp

