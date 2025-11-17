#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

const int MAX = 6;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

bool isEmpty(const StackMahasiswa& S);
bool isFull(const StackMahasiswa& S);
void createStack(StackMahasiswa& S);
void Push(StackMahasiswa& S, Mahasiswa M); 
void Pop(StackMahasiswa& S); 
void Update(StackMahasiswa& S, int posisi, Mahasiswa M); 
void View(const StackMahasiswa& S);
void SearchNilaiAkhir(const StackMahasiswa& S, float NilaiAkhirMin, float NilaiAkhirMax);

void MaxNilaiAkhir(const StackMahasiswa& S);
float getNilaiAkhir(Mahasiswa M);

#endif 