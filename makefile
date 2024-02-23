CC=g++

exec: main.cpp Servant.o 
	$(CC) -o exec main.cpp Servant.o


clean:
	rm exec Servant.o
