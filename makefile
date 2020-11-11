CC=g++
DEPS = aika.h
 

game: main.cpp aika.cpp
	$(CC) -o game main.cpp aika.cpp

