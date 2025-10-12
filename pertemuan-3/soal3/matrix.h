#ifndef MATRIKS_H_INCLUDED
#define MATRIKS_H_INCLUDED

struct Matriks3x3 {
    int data[3][3];
};

void tampilkanMatriks(const Matriks3x3& matriks);
void tukarElemenMatriks(Matriks3x3* matriksA, Matriks3x3* matriksB, int baris, int kolom);
void tukarNilaiPointer(int* ptr1, int* ptr2);

#endif 