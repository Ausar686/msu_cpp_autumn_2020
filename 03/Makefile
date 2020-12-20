COMP = g++
CFLAGS = -std=c++17 -Wall -c
LFLAGS = 
OBJECTS = matrix.o  main.o
EXECUTABLE = project

all: $(EXECUTABLE)

test: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(COMP) $(LFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(COMP) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

delete: clean
	rm $(EXECUTABLE)
