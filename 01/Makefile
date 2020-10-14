COMP = g++
CFLAGS = -std=c++17 -Wall -c
LFLAGS = 
OBJECTS = alloc.o tests.o main.o
EXECUTABLE = project

test: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(COMP) $(LFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(COMP) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
