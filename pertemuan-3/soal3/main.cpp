#include <iostream>
#include "matrix.h"
using namespace std; 

int main() {
    Matriks3x3 arrayA = {{
        {11, 12, 13},
        {14, 15, 16},
        {17, 18, 19}
    }};

    Matriks3x3 arrayB = {{
        {91, 92, 93},
        {94, 95, 96},
        {97, 98, 99}
    }};

    int nilaiX = 100;
    int nilaiY = 200;
    int* pointerX = &nilaiX;
    int* pointerY = &nilaiY;

    cout << "--- Matriks A (Sebelum ditukar) ---" << endl;
    tampilkanMatriks(arrayA);
    cout << "\n--- Matriks B (Sebelum ditukar) ---" << endl;
    tampilkanMatriks(arrayB);

    int barisTukar = 1;
    int kolomTukar = 1;
    tukarElemenMatriks(&arrayA, &arrayB, barisTukar, kolomTukar);

    cout << "Menukar elemen matriks pada posisi [" << barisTukar << "][" << kolomTukar << "]...\n";
    cout << "======\n\n";

    cout << "--- Matriks A (Setelah ditukar) ---" << endl;
    tampilkanMatriks(arrayA);
    cout << "\n--- Matriks B (Setelah ditukar) ---" << endl;
    tampilkanMatriks(arrayB);

    cout << "\n\n-----\n\n";

    cout << "Nilai awal yang ditunjuk pointer:\n";
    cout << "Pointer X menunjuk nilai: " << *pointerX << endl;
    cout << "Pointer Y menunjuk nilai: " << *pointerY << endl;

    tukarNilaiPointer(pointerX, pointerY);
    cout << "\nMenukar nilai via pointer \n\n";

    cout << "Nilai akhir yang ditunjuk pointer:\n";
    cout << "Pointer X sekarang menunjuk nilai: " << *pointerX << endl;
    cout << "Pointer Y sekarang menunjuk nilai: " << *pointerY << endl;

    return 0;
}