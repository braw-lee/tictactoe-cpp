main: main.cpp handler.o board.o
	g++ main.cpp handler.o board.o easy.o -o main -Wall -g
handler.o: handler.cpp handler.h board.o easy.o
	g++ -c handler.cpp -Wall
easy.o: easy.cpp easy.h board.o
	g++ -c easy.cpp -Wall
board.o: board.cpp board.h
	g++ -c board.cpp -Wall
clean:
	rm main *.o
