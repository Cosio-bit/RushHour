#include <iostream>
#include "Autos.h"


int main() {
    printf("test de auto\n");
    Auto car(2, 3, 3, 1);
    car.print();

    printf("test de autos\n");
    Autos cars;
    cars.addAuto(2, 3, 3, 1);
    cars.addAuto(0, 0, 2, 0);

    cars.print();
    cars.printCarsGrid();

    printf("test de replace\n");

    Auto newCar(0, 0, 2, 0);
    cars.replaceAuto(1, &newCar);

    cars.print();
    cars.printCarsGrid();

    int amount = cars.amountOfAutos();
    cout << "Amount of autos: " << amount << endl;

    printf("test de readFile\n");
    Autos cars2;

    cars2.readFile("game1.txt", "walls1.txt");

    cars2.printCarsGrid();

    bool valid = cars2.checkValid();
    if (valid) {
        cout << "Cars placement is valid." << endl;
    } else {
        cout << "Cars placement is invalid." << endl;
    }

    bool validPosition = cars2.isValidPosition();
    if (validPosition) {
        cout << "All cars are within the bounds of the grid." << endl;
    } else {
        cout << "Some cars are out of bounds." << endl;
    }

    bool validAndDirection = cars2.checkValidAndDirection();
    if (validAndDirection) {
        cout << "Cars placement is valid, and directions are valid." << endl;
    } else {
        cout << "Cars placement or directions are invalid." << endl;
    }

    printf("test de equalAutos\n");
    Autos cars3;
    cars3.addAuto(2, 3, 3, 1);
    cars3.addAuto(0, 0, 2, 0);

    bool equal = cars.equalAutos(&cars3);
    if (equal) {
        cout << "Cars are equal." << endl;
    } else {
        cout << "Cars are not equal." << endl;
    }

    //destroying cars
    cars.~Autos();
    cars2.~Autos();
    cars3.~Autos();


    return 0;
}
