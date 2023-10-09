#include <iostream>
#include <fstream> // para trabajar con archivos
#include <string> // para tener objetos de arreglos de char de largo autoincrementable
#include <sstream> // para trabajar con streams de strings
#include "Autos.h"

using namespace std;

Auto::Auto(int x, int y, int largo, int dir) {
    this->x = x;
    this->y = y;
    this->largo = largo;
    this->dir = dir;
}

void Auto::print() {
    cout << "x: "<< x << " y: " << y << " largo: " << largo << " dir: " << dir << endl;
}

Autos::Autos() {
    this->count = 0;
    for (int i=0; i<18; i++) {
        this->autos[i] = nullptr;
    }

}

Autos::~Autos() {
    for (int i = 0; i < this->amountOfAutos(); i++) {
        delete this->autos[i];
    }
}


bool Autos::equalAutos(Autos *autos1) {
    if (this->count != autos1->count) {
        return false;
    }
    for (int i=0; i<this->count; i++) {
        if (this->autos[i]->x != autos1->autos[i]->x || this->autos[i]->y != autos1->autos[i]->y || this->autos[i]->largo != autos1->autos[i]->largo || this->autos[i]->dir != autos1->autos[i]->dir) {
            return false;
        }
    }
    return true;
}

void Autos::addAuto(int x, int y, int largo, int dir) {
    this->autos[this->count] = new Auto(x,y,largo,dir);
    this->count++;
}

void Autos::addAuto(Auto *auto1) {
    this->autos[this->count] = auto1;
    this->count++;
}


void Autos::replaceAuto(int i, Auto *auto1)
{
    this->autos[i] = auto1;
}

void Autos::print() {
    for (int i=0; i<this->count; i++) {
        this->autos[i]->print();
    }
}

int Autos::amountOfAutos(){
    //cuenta la cantidad de autos
    for(int i=0; i<18; i++){
        if(this->autos[i] == nullptr){
            return i;
        }
    }
    return 18;
}

Auto *Autos::getAuto(int i){
    return this->autos[i];
}


void Autos::readFile(std::string carsFile, std::string wallsFile){
    //creo un objeto autos
    int x, y, largo, dir;
    int **data = new int*[18]; // 18 es el maximo de autos. 3 por fila (de largo 2) x 6 filas
    ifstream file(carsFile); // es un stream de "FileInput" desde un archivo. 
    string line; // es un objeto que representa un arreglo de char que es auto ajustable.
    int count=0; // cuenta la cantidad de autos (uno por linea)
    while (getline(file, line)) { // lee una linea del archivo y la guarda en "line". Si no hay mas lineas, sale del while(retorna false).
        count++;
        cout << line << endl;
        stringstream charStream; // es un stream de "StringInput" desde un string.
        charStream << line; // guarda el string en el stream
        charStream >> x >> y >> largo >> dir; // lee los datos del stream y los guarda en las variables. Notar que como es un input stream se usa la operacion inversa a <<, que es >>. Automaticamente lee el tipo de dato de cada variable.
        cout << "x: "<< x << " y: " << y << " largo: " << largo << " dir: " << dir << endl; // imprimimos de vuelta todo. Aqui deben crear sus objetos de auto, y guardarlos en en State.
        //crea un objeto auto y lo guarda en autos
        this->addAuto(x,y,largo,dir);
    }
    file.close(); // cerramos el archivo
    cout << "Cantidad de autos: " << count << endl << endl;

/*
    // ahora leemos las paredes
    int numberWalls = 0;
    int walls[36][36]; // 36 es el maximo de paredes. 6 filas x 6 columnas
    for (int i=0; i<36; i++) {
        for (int j=0; j<36; j++) {
            walls[i][j] = 0; // inicializamos todo en 0
        }
    }
    file.open(wallsFile);
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
            stringstream charStream;
            charStream << line;
            charStream >> x >> y;
            cout << "x: "<< x << " y: " << y << endl;
            walls[x][y] = 1; // guardamos la pared en la matriz
            numberWalls++;
        }
    } else {
        cout << "No hay paredes" << endl;       
    }
    cout << "Cantidad de paredes: " << numberWalls << endl << endl;
*/
    return;
}

void Autos::printCarsGrid(){
    printf("Cars grid:\n");
    // Crear una matriz para representar el grid
    const int width = 6; // Ancho del grid
    const int height = 6; // Alto del grid
    char grid[width][height];

    // Inicializar la matriz con espacios en blanco
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            grid[i][j] = '0';
        }
    }

    // Iterar sobre los autos
    for (int i = 0; i < this->count; i++) {
        Auto* auto1 = this->getAuto(i);
        int x = auto1->x;
        int y = auto1->y;
        int largo = auto1->largo;
        int dir = auto1->dir;

        // Iterar sobre la longitud del auto
        for (int j = 0; j < largo; j++) {
            // Asignar el número del auto en la posición correspondiente en la matriz
            grid[x][y] = '0' + i+1;

            // Actualizar las coordenadas según la dirección
            if (dir == HORIZONTAL) { // Horizontal
                x++;
            } else if (dir == VERTICAL) { // Vertical
                y++;
            }
        }
    }

    // Imprimir el grid
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}


bool Autos::checkValid() {
    //only 1 car can be in the same position
    for (int i = 0; i < this->count; i++) {
        for (int j = i + 1; j < this->count; j++) {
            if (this->getAuto(i)->x == this->getAuto(j)->x && this->getAuto(i)->y == this->getAuto(j)->y) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if a positions are within the maze boundaries  wich is a 6x6 grid
bool Autos::isValidPosition() {
    for (int i = 0; i < this->count; i++) {
        if (this->getAuto(i)->x < 0 || this->getAuto(i)->x >= 6 || this->getAuto(i)->y < 0 || this->getAuto(i)->y >= 6) {
            return false;
        }
    }
    return true;
    
}

// Function to check if the cars are valid and have a valid direction
bool Autos::checkValidAndDirection() {
    const int width = 6; // Ancho del grid
    const int height = 6; // Alto del grid
    bool visited[width][height] = {false};

    for (int i = 0; i < this->count; i++) {
        Auto* auto1 = this->getAuto(i);
        int x = auto1->x;
        int y = auto1->y;
        int largo = auto1->largo;
        int dir = auto1->dir;

        //create a list for each car with the positions it occupies
        for (int j = 0; j < largo; j++) {
            if (visited[x][y]) {
                return false;
            }
            visited[x][y] = true;

            // Actualizar las coordenadas según la dirección
            if (dir == HORIZONTAL) { // Horizontal
                x++;
            } else if (dir == VERTICAL) { // Vertical
                y++;
            }

            //check if the car is within the maze boundaries
            if (x < 0 || x >= 6 || y < 0 || y >= 6) {
                return false;
            }
        }
    }
    return true;
}
