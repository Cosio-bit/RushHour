#include <iostream>
#include "Stack.h"
#include "Operation.h"


//class Operation;
using namespace std;

class Maze {
    public:
        Maze(int size);
        ~Maze();
        State *solve(State *initialState); // algorithmo A*
        void setFinal(int x, int y);
        bool isFinal(State* state);
        int heuristic(State* state, int finalx, int finaly);
        
    private:
        Operation op[6];
        int mazeSize;
        int **maze;
        int finalx;
        int finaly;
};

