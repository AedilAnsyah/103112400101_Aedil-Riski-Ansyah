#include <iostream>
#include "mahasiswa.h"

int main() {
    Mahasiswa daftarMahasiswa[10];
    int jumlahMahasiswa = 0;
    inputDataMahasiswa(daftarMahasiswa, jumlahMahasiswa);
    tampilkanDataMahasiswa(daftarMahasiswa, jumlahMahasiswa);
    return 0;
}