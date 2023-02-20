main: main.cpp handler.o board.o
	g++ main.cpp handler.o board.o easy.o hard.o -o main -Wall -g
handler.o: handler.cpp handler.h board.o easy.o hard.o
	g++ -c handler.cpp -Wall -g
easy.o: easy.cpp easy.h board.o
	g++ -c easy.cpp -Wall -g
hard.o: hard.cpp hard.h board.o
	g++ -c hard.cpp -Wall -g 
board.o: board.cpp board.h
	g++ -c board.cpp -Wall -g
clean:
	rm main *.o
