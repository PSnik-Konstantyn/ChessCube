#ifndef CUBE_H
#define CUBE_H
#include <iostream>
using namespace std;

class Cube {
    int side[6];
    int id;
    bool canFit[8];
    // Here explanations about numbers and sides in little cubes(sweeps of cubes):
    // Ось пояснення щодо чисел і сторін у маленьких кубиках (розгортки кубиків):
    // index -> side
    // 0 - down
    // 1 - top
    // 2 - left
    // 3 - front
    // 4 - right
    // 5 - back
    /*
    *    0-white color (білий колір)
    *    #-black color (чорний колір)
    *
    *    0-white color in array,
    *    1-black color in array, when we initialized it  (чорний колір в масиві, котрий ми ініціалізували)
    *
    *    Here we explain, how we initialized cube sides use numbers:
    *    Тут ми пояснюємо, як ми ініціалізували сторони куба за допомогою чисел:
    *
    *    0     #            1
    *   0#00  #0##        2-3-4-5
    *    #     #            0
    *
    */
public:

    Cube(int arr[], int index);
    Cube(){};
    ~Cube(){};

    int getFront();
    int getBack();
    int getLeft();
    int getRight();
    int getTop();
    int getBottom();
    void show();
    bool* getCanFit(){ return canFit; }
    void showFit();

    void swapHorizontal();
    void swapVertical();
    void swapVertical2();
};
char get_char(int num);
bool fitPosition(Cube& cube, int place);

#endif