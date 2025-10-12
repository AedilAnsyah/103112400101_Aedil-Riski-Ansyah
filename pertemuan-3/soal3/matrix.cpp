#include "matrix.h"
#include <iostream>
#include <iomanip>
using namespace std; 

void tampilkanMatriks(const Matriks3x3& matriks) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << setw(4) << matriks.data[i][j];
        }
        cout << endl;
    }
}

void tukarElemenMatriks(Matriks3x3* matriksA, Matriks3x3* matriksB, int baris, int kolom) {
    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        int temp = matriksA->data[baris][kolom];
        matriksA->data[baris][kolom] = matriksB->data[baris][kolom];
        matriksB->data[baris][kolom] = temp;
    }
}

void tukarNilaiPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}