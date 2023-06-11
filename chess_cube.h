#ifndef CHESS_CUBE_H
#define CHESS_CUBE_H
#include "cube.h"

class ChessCube {
    int amountOfVariations = 0;
    Cube tempCubes[8];
    Cube resultCubes[8];

public:
    ChessCube(Cube &cube1, Cube &cube2, Cube &cube3, Cube &cube4,
              Cube &cube5, Cube &cube6, Cube &cube7, Cube &cube8);
    ChessCube() {};
    ~ChessCube() {};

    Cube* getTempCubes();
    Cube* getResultCubes();
    int& getVariations();
    void showResult();
    void buildCube();
    friend bool fitBuildPosition(ChessCube& big_cube, Cube& cube, int place);
};

void permuteCube(int cube[], int index, ChessCube &chessCube);

#endif