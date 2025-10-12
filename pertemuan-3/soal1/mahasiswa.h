#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED
using namespace std;
#include <string>

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilai_akhir;
};

void inputDataMahasiswa(Mahasiswa mahasiswa[], int &jumlahMahasiswa);
float hitungNilaiAkhir(float uts, float uas, float tugas);
void tampilkanDataMahasiswa(const Mahasiswa mahasiswa[], int jumlahMahasiswa);

#endif 