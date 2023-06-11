#include "cube.h"


char get_char(int num) {
    if (num == 1) {
        return 'B';
    } else {
        return 'W';
    }
}

Cube::Cube(int arr[], int index) {
    for (int i = 0; i < 6; i++) {
        side[i] = arr[i];
    }
    id = index;

    for(int i = 0; i<8; i++)
        canFit[i] = false;
}


int Cube::getFront() {
    return side[3];
}

int Cube::getBack() {
    return side[5];
}

int Cube::getLeft() {
    return side[2];
}

int Cube::getRight() {
    return side[4];
}

int Cube::getTop() {
    return side[1];
}

int Cube::getBottom() {
    return side[0];
}

void Cube::show() {
    cout << "Розгортка куба номер (Sweep cube number {B-black, W-white} ):" << id << endl;
    cout << "     ---" << endl;
    cout << "     |" << get_char(getTop()) << "|\n";
    cout << "-----------------" << endl;
    cout << "| " << get_char(getLeft())
         << " | " << get_char(getFront())
         << " | " << get_char(getRight())
         << " | "<< get_char(getBack())
         << " |   \n";
    cout << "-----------------" << endl;
    cout << "     |" << get_char(getBottom()) << "|\n";
    cout << "     ---" << endl;
}


void Cube::swapHorizontal() {
    int previous;
    int current;
    previous = getBottom();
    current = getFront();
    side[3] = previous;
    previous = current;
    current = getTop();
    side[1] = previous;
    previous = current;
    current = getBack();
    side[5] = previous;
    side[0] = current;
}

void Cube::swapVertical() {
    int previous;
    int current;
    previous = getLeft();
    current = getFront();
    side[3] = previous;
    previous = current;
    current = getRight();
    side[4] = previous;
    previous = current;
    current = getBack();
    side[5] = previous;
    side[2] = current;
}

void Cube::swapVertical2() {
    int previous;
    int current;
    previous = getTop();
    current = getLeft();
    side[2] = previous;
    previous = current;
    current = getBottom();
    side[0] = previous;
    previous = current;
    current = getRight();
    side[4] = previous;
    side[1] = current;
}


void Cube::showFit(){
    for(int i = 0; i<8; i++){
        cout<<"position("<<i+1<<") "<< boolalpha <<canFit[i]<<endl;
    }
}


bool fitPosition(Cube& cube, int place) {
    int const rotate_amount = 4;
    switch(place){
        case 1:
            for(int k = 0; k<rotate_amount && !(cube.getTop() == 0 && cube.getBack() == 1 && cube.getLeft() == 1); k++){
                cube.swapVertical2();
                for (int i = 0; (i < rotate_amount) && !(cube.getTop() == 0 && cube.getBack() == 1 && cube.getLeft() == 1); i++) {
                    cube.swapVertical();
                    for (int j = 0; (j < rotate_amount) && !(cube.getTop() == 0 && cube.getBack() == 1 && cube.getLeft() == 1); j++) {
                        cube.swapHorizontal();
                    }
                }
            }
            if (cube.getTop() == 0 && cube.getBack() == 1 && cube.getLeft() == 1){ return true; }
            break;
        case 2:
            for(int k = 0; k<rotate_amount && !(cube.getTop() == 1 && cube.getBack() == 0 && cube.getRight() == 0); k++){
                cube.swapVertical2();
                for (int i = 0; (i < rotate_amount) && !(cube.getTop() == 1 && cube.getBack() == 0 && cube.getRight() == 0); i++) {
                    cube.swapVertical();
                    for (int j = 0; (j < rotate_amount) && !(cube.getTop() == 1 && cube.getBack() == 0 && cube.getRight() == 0); j++) {
                        cube.swapHorizontal();
                    }
                }
            }
            if (cube.getTop() == 1 && cube.getBack() == 0 && cube.getRight() == 0){ return true; }
            break;
        case 3:
            for(int k = 0; k<rotate_amount && !(cube.getTop() == 1 && cube.getFront() == 1 && cube.getLeft() == 0); k++){
                cube.swapVertical2();
                for (int i = 0; (i < rotate_amount) && !(cube.getTop() == 1 && cube.getFront() == 1 && cube.getLeft() == 0); i++) {
                    cube.swapVertical();
                    for (int j = 0; (j < rotate_amount) && !(cube.getTop() == 1 && cube.getFront() == 1 && cube.getLeft() == 0); j++) {
                        cube.swapHorizontal();
                    }
                }
            }
            if (cube.getTop() == 1 && cube.getFront() == 1 && cube.getLeft() == 0){ return true; }
            break;
        case 4:
            for(int k = 0; k<rotate_amount && !(cube.getTop() == 0 && cube.getFront() == 0 && cube.getRight() == 1); k++){
                cube.swapVertical2();
                for (int i = 0; (i < rotate_amount) && !(cube.getTop() == 0 && cube.getFront() == 0 && cube.getRight() == 1); i++) {
                    cube.swapVertical();
                    for (int j = 0; (j < rotate_amount) && !(cube.getTop() == 0 && cube.getFront() == 0 && cube.getRight() == 1); j++) {
                        cube.swapHorizontal();
                    }
                }
            }
            if (cube.getTop() == 0 && cube.getFront() == 0 && cube.getRight() == 1){ return true; }
            break;
        case 5:
            for(int k = 0; k<rotate_amount && !(cube.getBottom() == 0 && cube.getLeft() == 0 && cube.getBack() == 0); k++){
                cube.swapVertical2();
                for (int i = 0; (i < rotate_amount) && !(cube.getBottom() == 0 && cube.getLeft() == 0 && cube.getBack() == 0); i++) {
                    cube.swapVertical();
                    for (int j = 0; (j < rotate_amount) && !(cube.getBottom() == 0 && cube.getLeft() == 0 && cube.getBack() == 0); j++) {
                        cube.swapHorizontal();
                    }
                }
            }
            if (cube.getBottom() == 0 && cube.getLeft() == 0 && cube.getBack() == 0){ return true; }
            break;
        case 6:
            for(int k = 0; k<rotate_amount && !(cube.getRight() == 1 && cube.getBack() == 1 && cube.getBottom() == 1); k++){
                cube.swapVertical2();
                for (int i = 0; (i < rotate_amount) && !(cube.getRight() == 1 && cube.getBack() == 1 && cube.getBottom() == 1); i++) {
                    cube.swapVertical();
                    for (int j = 0; (j < rotate_amount) && !(cube.getRight() == 1 && cube.getBack() == 1 && cube.getBottom() == 1); j++) {
                        cube.swapHorizontal();
                    }
                }
            }
            if (cube.getRight() == 1 && cube.getBack() == 1 && cube.getBottom() == 1){ return true; }
            break;
        case 7:
            for(int k = 0; k<rotate_amount && !(cube.getFront() == 0 && cube.getLeft() == 1 && cube.getBottom() == 1); k++){
                cube.swapVertical2();
                for (int i = 0; (i < rotate_amount) && !(cube.getFront() == 0 && cube.getLeft() == 1 && cube.getBottom() == 1); i++) {
                    cube.swapVertical();
                    for (int j = 0; (j < rotate_amount) && !(cube.getFront() == 0 && cube.getLeft() == 1 && cube.getBottom() == 1); j++) {
                        cube.swapHorizontal();
                    }
                }
            }
            if (cube.getFront() == 0 && cube.getLeft() == 1 && cube.getBottom() == 1){ return true; }
            break;
        case 8:
            for(int k = 0; k<rotate_amount && !(cube.getFront() == 1 && cube.getRight() == 0 && cube.getBottom() == 0); k++){
                cube.swapVertical2();
                for (int i = 0; (i < rotate_amount) && !(cube.getFront() == 1 && cube.getRight() == 0 && cube.getBottom() == 0); i++) {
                    cube.swapVertical();
                    for (int j = 0; (j < rotate_amount) && !(cube.getFront() == 1 && cube.getRight() == 0 && cube.getBottom() == 0); j++) {
                        cube.swapHorizontal();
                    }
                }
            }
            if (cube.getFront() == 1 && cube.getRight() == 0 && cube.getBottom() == 0){ return true; }
            break;
    }
    return false;
}