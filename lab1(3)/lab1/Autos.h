#include <iostream>
#include <fstream> // para trabajar con archivos
#include <string> // para tener objetos de arreglos de char de largo autoincrementable
#include <sstream> // para trabajar con streams de strings
#define HORIZONTAL 1
#define VERTICAL 0

using namespace std;

class Auto {
    public:
        Auto(int x, int y, int largo, int dir);
        void print();

        int x;
        int y;
        int largo;
        int dir;
};

class Autos {
    public:
        Autos();
        ~Autos();
        // methods
        void addAuto(int x, int y, int largo, int dir);
        void addAuto(Auto *auto1);
        void printCarsGrid();
        void replaceAuto(int i, Auto *auto1);
        void print();
        void readFile(std::string carsFile, std::string wallsFile);
        int amountOfAutos();
        bool checkValid();
        bool isValidPosition();
        bool checkValidAndDirection();
        bool equalAutos(Autos *autos1);
        Auto *getAuto(int i);
        // instance variables
        Auto *autos[18];
        int count;
};

/*
Asumimos que el archivo tiene la siguiente estructura:
- por cada linea terminada en "\n" se define un auto
- cada auto se define por tres numeros separados por espacio: x y largo dir
- x e y son las coordenadas del inicio del auto
- largo es la cantidad de casillas que ocupa el auto: 2 o 3
- dir es la direccion del auto: 0 (horizontal) o 1 (vertical) 

otras observaciones
- el tablero es de 6x6
- el auto rojo siempre esta en la fila 2
- las casillas que ocupa un auto comienzan en (x,y), si es horizontal terminan en (x+largo-1,y), si es vertical terminan en (x,y+largo-1).
*/

