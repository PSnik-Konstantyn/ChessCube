#include "chess_cube.h"

ChessCube::ChessCube(Cube &cube1, Cube &cube2, Cube &cube3, Cube &cube4,
                     Cube &cube5, Cube &cube6, Cube &cube7, Cube &cube8) {
    tempCubes[0] = cube1;
    tempCubes[1] = cube2;
    tempCubes[2] = cube3;
    tempCubes[3] = cube4;
    tempCubes[4] = cube5;
    tempCubes[5] = cube6;
    tempCubes[6] = cube7;
    tempCubes[7] = cube8;

    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            tempCubes[i].getCanFit()[j] = fitPosition(tempCubes[i], j+1);
        }
    }

}

Cube* ChessCube::getTempCubes(){ return tempCubes; }
Cube* ChessCube::getResultCubes(){ return resultCubes; }
int& ChessCube::getVariations(){ return amountOfVariations;}


void ChessCube::showResult() {
    cout<<"Результат куба (Cube Result):"<<endl;
    cout << "          ---------" << endl;
    cout<<"          | "<<get_char(resultCubes[0].getTop())<<" | "<<get_char(resultCubes[1].getTop())<<" | "<<endl;
    cout << "          ---------" << endl;
    cout<<"          | "<<get_char(resultCubes[2].getTop())<<" | "<<get_char(resultCubes[3].getTop())<<" | "<<endl;

    cout << "  ---------------------------------" << endl;
    cout<<"  | "<<get_char(resultCubes[0].getLeft())<<" | "<<get_char(resultCubes[2].getLeft())<<" | "<<get_char(resultCubes[2].getFront())<<" | "<<get_char(resultCubes[3].getFront())<<" | "<<get_char(resultCubes[3].getRight())<<" | "<<get_char(resultCubes[1].getRight())<<" | "<<get_char(resultCubes[1].getBack())<<" | "<<get_char(resultCubes[0].getBack())<<" | "<<endl;
    cout<<"  | "<<get_char(resultCubes[4].getLeft())<<" | "<<get_char(resultCubes[6].getLeft())<<" | "<<get_char(resultCubes[6].getFront())<<" | "<<get_char(resultCubes[7].getFront())<<" | "<<get_char(resultCubes[7].getRight())<<" | "<<get_char(resultCubes[5].getRight())<<" | "<<get_char(resultCubes[5].getBack())<<" | "<<get_char(resultCubes[4].getBack())<<" | "<<endl;

    cout << "  ---------------------------------" << endl;
    cout<<"          | "<<get_char(resultCubes[6].getBottom())<<" | "<<get_char(resultCubes[7].getBottom())<<" | "<<endl;
    cout << "          ---------" << endl;
    cout<<"          | "<<get_char(resultCubes[4].getBottom())<<" | "<<get_char(resultCubes[5].getBottom())<<" | "<<endl;
    cout << "          ---------" << endl;
}

/*
*   Суть методу в тому, що він маючи у масиві *resultCubes[]*                                             (The essence of the method is that having *resultCubes[]* in the array)
*   перший куб неважливо якого id (або розгортки, включаючи те,                                           (first cube no matter what id (or sweeps, including )
*   що деякі розгортки фізично не можуть встати на позицію навіть по зовнішньому малюнку)                 (that some sweeps physically cannot get into position even according to the external drawing) )
*   Намагається даний йому *Сube& cube* підставити у вказаний *int place*                                 (It tries to substitute the given *Sube& cube* into the specified *int place*)
*   Логічно що не маючи в *resultCubes[]* заданих кубів на позиціях 4, 6, 7.                              (It is logical that without having in *resultCubes[]* given cubes at positions 4, 6, 7.)
*   Ми не можемо почати перевертання куба і підстановки його під внутрішні сторони (позицій 4, 6, 7).     (We cannot start flipping the cube and substituting it under the inner sides (positions 4, 6, 7). )
*/
bool fitBuildPosition(ChessCube& big_cube, Cube& cube, int place) {
    int const ROTATE_AMOUNT = 4;
    switch(place){
        case 2:
            for(int k = 0; k<ROTATE_AMOUNT; k++){
                if( (big_cube.resultCubes[0].getRight() == cube.getLeft())
                    && ((cube.getTop()==1)&&(cube.getRight()==0)&&(cube.getBack()==0)) ) return true;
                cube.swapVertical2();
                for(int i = 0; i<ROTATE_AMOUNT; i++){
                    if( (big_cube.resultCubes[0].getRight() == cube.getLeft())
                        && ((cube.getTop()==1)&&(cube.getRight()==0)&&(cube.getBack()==0)) ) return true;
                    cube.swapVertical();
                    for(int j = 0; j<ROTATE_AMOUNT; j++){
                        if( (big_cube.resultCubes[0].getRight() == cube.getLeft())
                            && ((cube.getTop()==1)&&(cube.getRight()==0)&&(cube.getBack()==0)) ) return true;
                        cube.swapHorizontal();
                    }
                }
            }
            break;
        case 3:
            for(int k = 0; k<ROTATE_AMOUNT; k++){
                if( (big_cube.resultCubes[0].getFront() == cube.getBack())
                    && ((cube.getTop()==1)&&(cube.getFront()==1)&&(cube.getLeft()==0)) ) return true;
                cube.swapVertical2();
                for(int i = 0; i<ROTATE_AMOUNT; i++){
                    if( (big_cube.resultCubes[0].getFront() == cube.getBack())
                        && ((cube.getTop()==1)&&(cube.getFront()==1)&&(cube.getLeft()==0)) ) return true;
                    cube.swapVertical();
                    for(int j = 0; j<ROTATE_AMOUNT; j++){
                        if( (big_cube.resultCubes[0].getFront() == cube.getBack())
                            && ((cube.getTop()==1)&&(cube.getFront()==1)&&(cube.getLeft()==0)) ) return true;
                        cube.swapHorizontal();
                    }
                }
            }
            break;
        case 4:
            for(int k = 0; k<ROTATE_AMOUNT; k++){
                if(     ((big_cube.resultCubes[1].getFront()==cube.getBack())
                         && (big_cube.resultCubes[2].getRight()==cube.getLeft()))
                        && ((cube.getTop()==0)&&(cube.getFront()==0)&&(cube.getRight()==1)) ) return true;
                cube.swapVertical2();
                for(int i = 0; i<ROTATE_AMOUNT; i++){
                    if(     ((big_cube.resultCubes[1].getFront()==cube.getBack())
                             &&(big_cube.resultCubes[2].getRight()==cube.getLeft()))
                            && ((cube.getTop()==0)&&(cube.getFront()==0)&&(cube.getRight()==1)) ) return true;
                    cube.swapVertical();
                    for(int j = 0; j<ROTATE_AMOUNT; j++){
                        if(     ((big_cube.resultCubes[1].getFront()==cube.getBack())
                                 &&(big_cube.resultCubes[2].getRight()==cube.getLeft()))
                                && ((cube.getTop()==0)&&(cube.getFront()==0)&&(cube.getRight()==1)) ) return true;
                        cube.swapHorizontal();
                    }
                }
            }
            break;
        case 5:
            for(int k = 0; k<ROTATE_AMOUNT; k++){
                if( (big_cube.resultCubes[0].getBottom()==cube.getTop())
                    &&((cube.getBottom()==0)&&(cube.getLeft()==0)&&(cube.getBack()==0)) ) return true;
                cube.swapVertical2();
                for(int i = 0; i<ROTATE_AMOUNT; i++){
                    if( (big_cube.resultCubes[0].getBottom()==cube.getTop())
                        &&((cube.getBottom()==0)&&(cube.getLeft()==0)&&(cube.getBack()==0)) ) return true;
                    cube.swapVertical();
                    for(int j = 0; j<ROTATE_AMOUNT; j++){
                        if( (big_cube.resultCubes[0].getBottom()==cube.getTop())
                            &&((cube.getBottom()==0)&&(cube.getLeft()==0)&&(cube.getBack()==0)) ) return true;
                        cube.swapHorizontal();
                    }
                }
            }
            break;
        case 6:
            for(int k = 0; k<ROTATE_AMOUNT; k++){
                if(     ((big_cube.resultCubes[1].getBottom() == cube.getTop())
                         &&(big_cube.resultCubes[4].getRight()==cube.getLeft()))
                        &&((cube.getRight()==1)&&(cube.getBack()==1)&&(cube.getBottom()==1)) ) return true;
                cube.swapVertical2();
                for(int i = 0; i<ROTATE_AMOUNT; i++){
                    if(     ((big_cube.resultCubes[1].getBottom() == cube.getTop())
                             &&(big_cube.resultCubes[4].getRight()==cube.getLeft()))
                            &&((cube.getRight()==1)&&(cube.getBack()==1)&&(cube.getBottom()==1)) ) return true;
                    cube.swapVertical();
                    for(int j = 0; j<ROTATE_AMOUNT; j++){
                        if(     ((big_cube.resultCubes[1].getBottom() == cube.getTop())
                                 &&(big_cube.resultCubes[4].getRight()==cube.getLeft()))
                                &&((cube.getRight()==1)&&(cube.getBack()==1)&&(cube.getBottom()==1)) ) return true;
                        cube.swapHorizontal();
                    }
                }
            }
            break;
        case 7:
            for(int k = 0; k<ROTATE_AMOUNT; k++){
                if(     ((big_cube.resultCubes[2].getBottom()==cube.getTop())
                         &&(big_cube.resultCubes[4].getFront()==cube.getBack()))
                        &&((cube.getFront()==0)&&(cube.getLeft()==1)&&(cube.getBottom()==1)) ) return true;
                cube.swapVertical2();
                for(int i = 0; i<ROTATE_AMOUNT; i++){
                    if(     ((big_cube.resultCubes[2].getBottom()==cube.getTop())
                             &&(big_cube.resultCubes[4].getFront()==cube.getBack()))
                            &&((cube.getFront()==0)&&(cube.getLeft()==1)&&(cube.getBottom()==1)) ) return true;
                    cube.swapVertical();
                    for(int j = 0; j<ROTATE_AMOUNT; j++){
                        if(     ((big_cube.resultCubes[2].getBottom()==cube.getTop())
                                 &&(big_cube.resultCubes[4].getFront()==cube.getBack()))
                                &&((cube.getFront()==0)&&(cube.getLeft()==1)&&(cube.getBottom()==1)) ) return true;
                        cube.swapHorizontal();
                    }
                }
            }
            break;
        case 8:
            for(int k = 0; k<ROTATE_AMOUNT; k++){
                if(     ((big_cube.resultCubes[3].getBottom()==cube.getTop())
                         &&(big_cube.resultCubes[5].getFront()==cube.getBack())
                         &&(big_cube.resultCubes[6].getRight()==cube.getLeft()))
                        &&((cube.getFront()==1)&&(cube.getRight()==0)&&(cube.getBottom()==0)) ) return true;
                cube.swapVertical2();
                for(int i = 0; i<ROTATE_AMOUNT; i++){
                    if(     ((big_cube.resultCubes[3].getBottom()==cube.getTop())
                             &&(big_cube.resultCubes[5].getFront()==cube.getBack())
                             &&(big_cube.resultCubes[6].getRight()==cube.getLeft()))
                            &&((cube.getFront()==1)&&(cube.getRight()==0)&&(cube.getBottom()==0)) ) return true;
                    cube.swapVertical();
                    for(int j = 0; j<ROTATE_AMOUNT; j++){
                        if(     ((big_cube.resultCubes[3].getBottom()==cube.getTop())
                                 &&(big_cube.resultCubes[5].getFront()==cube.getBack())
                                 &&(big_cube.resultCubes[6].getRight()==cube.getLeft()))
                                &&((cube.getFront()==1)&&(cube.getRight()==0)&&(cube.getBottom()==0)) ) return true;
                        cube.swapHorizontal();
                    }
                }
            }
            break;
    }
    return false;
}


void permuteCube(int cube[], int index, ChessCube &chessCube) {
    if (index == 8) {

        for (int i = 0; i < 8; i++) {
            //1 2 3 4 5 6 7 8
            Cube currentCube = chessCube.getTempCubes()[cube[i]-1];
            if (!(fitPosition(currentCube, i+1))) {
                return;
            }
        }

        fitPosition(chessCube.getTempCubes()[cube[0] - 1], 1);
        fitPosition(chessCube.getTempCubes()[cube[1] - 1], 2);
        fitPosition(chessCube.getTempCubes()[cube[2] - 1], 3);
        fitPosition(chessCube.getTempCubes()[cube[3] - 1], 4);
        fitPosition(chessCube.getTempCubes()[cube[4] - 1], 5);
        fitPosition(chessCube.getTempCubes()[cube[5] - 1], 6);
        fitPosition(chessCube.getTempCubes()[cube[6] - 1], 7);
        fitPosition(chessCube.getTempCubes()[cube[7] - 1], 8);
        bool wasFixed;

        // фіксую 1-ший куб з комбінації на 1шу позицію (I fix the 1st cube from the combination to the 1st position)
        chessCube.getResultCubes()[0] = chessCube.getTempCubes()[cube[0] - 1];

        // Перевіряю + перевертаю 2-ий куб з комбінації під позицію 2 (I check + flip 2nd cube from the combination under position 2)
        wasFixed = fitBuildPosition(chessCube, chessCube.getTempCubes()[cube[1] - 1], 2);
        if(!wasFixed)
            return;
        chessCube.getResultCubes()[1] = chessCube.getTempCubes()[cube[1] - 1];

        // Перевіряю + перевертаю 3-ій куб з комбінації під позицію 3 (I check + flip the 3rd cube from the combination to position 3)
        wasFixed = fitBuildPosition(chessCube, chessCube.getTempCubes()[cube[2] - 1], 3);
        if(!wasFixed)
            return;
        chessCube.getResultCubes()[2] = chessCube.getTempCubes()[cube[2] - 1];

        // Перевіряю + перевертаю 4-ий куб з комбінації під позицію 4 (I check + flip the 4th cube from the combination under position 4)
        wasFixed = fitBuildPosition(chessCube, chessCube.getTempCubes()[cube[3] - 1], 4);
        if(!wasFixed)
            return;
        chessCube.getResultCubes()[3] = chessCube.getTempCubes()[cube[3] - 1];

        // Перевіряю + перевертаю 5-ий куб з комбінації під позицію 5 (I check + flip the 5th cube from the combination under position 5)
        wasFixed = fitBuildPosition(chessCube, chessCube.getTempCubes()[cube[4] - 1], 5);
        if(!wasFixed)
            return;
        chessCube.getResultCubes()[4] = chessCube.getTempCubes()[cube[4] - 1];

        // Перевіряю + перевертаю 6-ий куб з комбінації під позицію 6 (I check + flip the 6th cube from the combination under position 6)
        wasFixed = fitBuildPosition(chessCube, chessCube.getTempCubes()[cube[5] - 1], 6);
        if(!wasFixed)
            return;
        chessCube.getResultCubes()[5] = chessCube.getTempCubes()[cube[5] - 1];

        // Перевіряю + перевертаю 7-ий куб з комбінації під позицію 7 (I check + flip the 7th cube from the combination under position 7)
        wasFixed = fitBuildPosition(chessCube, chessCube.getTempCubes()[cube[6] - 1], 7);
        if(!wasFixed)
            return;
        chessCube.getResultCubes()[6] = chessCube.getTempCubes()[cube[6] - 1];

        // Перевіряю + перевертаю 8-ий куб з комбінації під позицію 8 (I check + flip the 8th cube from the combination under position 8)
        wasFixed = fitBuildPosition(chessCube, chessCube.getTempCubes()[cube[7] - 1], 8);
        if(!wasFixed)
            return;
        chessCube.getResultCubes()[7] = chessCube.getTempCubes()[cube[7] - 1];

        for (int i = 0; i < 8; i++) {
            std::cout << cube[i] << " ";
        }
        std::cout << std::endl;

        chessCube.showResult();
        cout << endl;
        cout << endl;
        chessCube.getVariations()++;
        return;
    }

    for (int i = 1; i <= 8; i++) {
        bool isValid = true;
        // Перевірити, чи така комбінація вже існує в кубі
        for (int j = 0; j < index; j++) {
            if (cube[j] == i) {
                isValid = false;
                break;
            }
        }
        if (isValid) {

            cube[index] = i;
            permuteCube(cube, index + 1, chessCube);
        }
    }
}

void ChessCube::buildCube(){
    int cube[] ={1,2,3,4,5,6,7,8};
    permuteCube(cube, 0, *this);
}