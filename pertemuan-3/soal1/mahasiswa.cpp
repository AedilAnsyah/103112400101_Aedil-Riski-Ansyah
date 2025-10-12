#include "mahasiswa.h"
#include <iostream>
using namespace std;

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

void inputDataMahasiswa(Mahasiswa mahasiswa[], int &jumlahMahasiswa) {
    cout << "Jumlah mahasiswa (max 10): ";
    cin >> jumlahMahasiswa;

    if (jumlahMahasiswa > 10) {
        jumlahMahasiswa = 10;
        cout << "Jumlah maksimal 10. Data akan diambil untuk 10 mahasiswa" << endl;
    }

    for (int i = 0; i < jumlahMahasiswa; ++i) {
        cout << "\nMasukkan data untuk mahasiswa ke-" << i + 1 << ":" << endl;
        cout << "Nama: ";
        cin.ignore(); 
        getline(cin, mahasiswa[i].nama);
        cout << "NIM: ";
        cin >> mahasiswa[i].nim;
        cout << "Nilai UTS: ";
        cin >> mahasiswa[i].uts;
        cout << "Nilai UAS: ";
        cin >> mahasiswa[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mahasiswa[i].tugas;
        mahasiswa[i].nilai_akhir = hitungNilaiAkhir(mahasiswa[i].uts, mahasiswa[i].uas, mahasiswa[i].tugas);
    }
}

void tampilkanDataMahasiswa(const Mahasiswa mahasiswa[], int jumlahMahasiswa) {
    cout << "\n\n--- Data Mahasiswa ---" << endl;
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        cout << "Mahasiswa ke-" << i + 1 << ":\n";
        cout << "Nama        : " << mahasiswa[i].nama << endl;
        cout << "NIM         : " << mahasiswa[i].nim << endl;
        cout << "Nilai UTS   : " << mahasiswa[i].uts << endl;
        cout << "Nilai UAS   : " << mahasiswa[i].uas << endl;
        cout << "Nilai Tugas : " << mahasiswa[i].tugas << endl;
        cout << "Nilai Akhir : " << mahasiswa[i].nilai_akhir << endl;
    }
}