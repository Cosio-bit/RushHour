FLAGS = -g


runMain: main
	./main

runTestAutos: TestAutos
	./TestAutos

main: Autos.o Stack.o  main.cpp State.o Operation.o Maze.o
	g++ ${FLAGS} Autos.o State.o Stack.o Operation.o Maze.o main.cpp -o main 

TestAutos: TestAutos.o Autos.o 
	g++ ${FLAGS} -o TestAutos TestAutos.o Autos.o


TestAutos.o: TestAutos.cpp Autos.h Operation.h State.h Stack.h Maze.h
	g++ ${FLAGS} -c TestAutos.cpp
Maze.o: Maze.cpp Maze.h
	g++ ${FLAGS} -c Maze.cpp
Stack.o: State.o Stack.cpp Stack.h
	g++ ${FLAGS} -c Stack.cpp
State.o: State.cpp State.h
	g++ ${FLAGS} -c State.cpp
Operation.o: Operation.cpp Operation.h
	g++ ${FLAGS} -c Operation.cpp
Autos.o: Autos.cpp Autos.h
	g++ ${FLAGS} -c Autos.cpp
clean:
	rm -rf *.o main