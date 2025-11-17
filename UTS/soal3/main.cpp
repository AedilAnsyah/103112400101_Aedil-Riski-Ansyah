#include <iostream>
#include "StackMahasiswa.h"

using namespace std;

int main() {
    StackMahasiswa S;
    Mahasiswa M;

    createStack(S);

    M = {"Venti", "11111", 75.7, 82.1, 65.5}; 
    Push(S, M);
    M = {"Xiao", "22222", 87.4, 88.9, 81.9}; 
    Push(S, M);
    M = {"Kazuha", "33333", 92.3, 88.8, 82.4}; 
    Push(S, M);
    M = {"Wanderer", "44444", 95.5, 85.5, 90.5}; 
    Push(S, M);
    M = {"Lynette", "55555", 77.7, 65.4, 79.9}; 
    Push(S, M);
    M = {"Chasca", "66666", 99.9, 93.6, 87.3}; 
    Push(S, M);
    View(S);

    Pop(S); 
    View(S);

    M = {"Heizou", "77777", 99.9, 88.8, 77.7};
    Update(S, 3, M); 
    View(S);

    SearchNilaiAkhir(S, 85.5, 95.5);
    MaxNilaiAkhir(S);

    return 0;
}