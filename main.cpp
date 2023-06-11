#include "chess_cube.h"

int main() {
    int arr1[] = {1, 0, 0, 1, 0, 1}; // Задаємо кольори сторін розгорток кубів
    int arr2[] = {1, 0, 0, 0, 1, 1}; // (We set the colors of the sides of the cube sweeps)
    int arr3[] = {0, 0, 0, 1, 0, 1};
    int arr4[] = {0, 0, 0, 1, 1, 0};
    int arr5[] = {0, 0, 0, 1, 0, 0};
    int arr6[] = {1, 1, 1, 0, 1, 0};
    int arr7[] = {1, 1, 1, 0, 0, 1};
    int arr8[] = {1, 1, 1, 0, 1, 1};


    Cube cube1 = Cube(arr1, 1);                  // Ініціалізуємо куби (Initialize the cubes)
    Cube cube2 = Cube(arr2, 2);
    Cube cube3 = Cube(arr3, 3);
    Cube cube4 = Cube(arr4, 4);
    Cube cube5 = Cube(arr5, 5);
    Cube cube6 = Cube(arr6, 6);
    Cube cube7 = Cube(arr7, 7);
    Cube cube8 = Cube(arr8, 8);
    ChessCube chessCub = ChessCube(cube1, cube2, cube3, cube4, cube5, cube6, cube7, cube8);
    cout << "Початкові куби (Initial cubes):\n";
    cube1.show();                            // Виводимо куби (We show the cubes)
    cube2.show();
    cube3.show();
    cube4.show();
    cube5.show();
    cube6.show();
    cube7.show();
    cube8.show();

    cout << endl;
    cout << "Можливі позиції для кожного куба згідно початкової розгортки (Possible positions for each cube according to the initial sweep): " << endl;
    cout << endl;
    for(int i = 0; i<8; i++){
        cout << "Номер куба (Сube id) = " << i+1 << endl;
        for(int j = 1; j<=8; j++){
            cout<< "position(" << j << "): " << boolalpha << fitPosition(chessCub.getTempCubes()[i], j) << endl;
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << "Введений куб (Input CUBE):\n";
    cout << endl;
    cout << endl;
    chessCub.buildCube();
    cout << "\nК-сть всього варіацій по зовнішній перевірці та внутрішній: "<< chessCub.getVariations()<<endl;
    cout << "\nThe number of all variations according to external inspection and internal: "<< chessCub.getVariations()<<endl;

    return 0;
}