CPP_FLAGS='-std=c++11'

main: main.o
	g++ ${CPP_FLAGS} main.o -o main
main.0: main.cpp smartptr
	g++ ${CPP_FLAGS} -c main.cpp
	
.PHONY : clean

clean:
	-rm main main.o

