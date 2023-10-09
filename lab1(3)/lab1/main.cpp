#include <iostream>
#include "Maze.h"

void readfileandsolve(const std::string& gameFile, const std::string& wallsFile) {
    Autos *autos = new Autos(); 
    autos->readFile(gameFile, wallsFile); // Corrected object creation

    Maze maze(6);
    maze.setFinal(2, 4);
    ///   maze.addCars(autos);
    autos->printCarsGrid();


    State *initial=new State(nullptr);

    //aqui guardas los autos en el estado, sino esta no funciona nada
    initial->autos = autos;
    initial->autos->print();
    

    State* solution1 = maze.solve(initial); // Solve using the maze object
    initial->autos->printCarsGrid();

    if (solution1 != nullptr) {
        solution1->autos->printCarsGrid();
    } else {
        cout << "No solution found" << endl;
    }

}

int main() {
    // Rest of your main function remains unchanged

    // Call the encapsulated function with the file names
    readfileandsolve("game1.txt", "walls1.txt");
    return 0;
}
