TARGET = react 
CXXFLAGS = -Wall -std=C++11 -Wc++11-extensions -lncurses 
CC = g++

OBJFILES = main.o Screen.o Image.o Coordinate.o Timer.o

$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJFILES)

main.o: main.cpp
	$(CC) -c main.cpp
Screen.o: Screen.cpp Screen.h
	$(CC) -c Screen.cpp
Image.o: Image.cpp Image.h
	$(CC) -c Image.cpp
Coordinate.o: Coordinate.cpp Coordinate.h
	$(CC) -c Coordinate.cpp
Timer.o: Timer.cpp Timer.h
	$(CC) -c Timer.cpp

.PHONY: clean
clean:
	rm $(OBJFILES) $(TARGET)
