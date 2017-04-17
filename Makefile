CC=g++
CFLAGS=-lglut -lGL -lGLU

hellomake: Main.cpp
	$(CC) -o sceneGL Main.cpp $(CFLAGS)
