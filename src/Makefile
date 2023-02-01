main: main.cpp handler.o board.o
	g++ main.cpp handler.o board.o -o main -Wall
handler.o: handler.cpp handler.h board.o
	g++ -c handler.cpp -Wall
board.o: board.cpp board.h
	g++ -c board.cpp -Wall
clean:
	rm main *.o
