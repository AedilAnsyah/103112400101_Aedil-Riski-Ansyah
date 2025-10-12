# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Aedil Riski Ansyah - 103112400101</p>

## Dasar Teori
Abstract Data Type (ADT) atau Tipe Data Abstrak adalah model matematis dari objek data yang disempurnakan dengan cara mengaitkannya dengan fungsi-fungsi yang beroperasi pada data yang bersangkutan [1]. Secara mendasar, ADT merupakan tipe data yang didefinisikan oleh pemrogram untuk mempermudah proses pemrograman serta mengakomodasi tipe-tipe data yang tidak disediakan secara spesifik oleh bahasa pemrograman yang digunakan [1]. Konsep ini memisahkan struktur penyimpanan dari perilaku tipe data yang abstrak, seperti tumpukan (Stack) atau antrian (Queue) [1]. Sebuah ADT tidak hanya menunjukkan bagaimana data diorganisir, tetapi juga mencakup operasi-operasi yang dapat dilakukan terhadap struktur data tersebut [1]. Dengan demikian, implementasi ADT dapat dipandang sebagai gabungan antara struktur data dengan operasi-operasi yang berlaku padanya [1].

Penggunaan ADT menawarkan keuntungan signifikan dalam pengembangan sistem yang bersifat modular, memungkinkan suatu sistem dikembangkan oleh beberapa orang anggota tim secara terpisah dengan tetap menjaga keterpaduan [1]. Hal ini dimungkinkan karena pemrogram yang menggunakan ADT tidak perlu mengetahui bagaimana detail implementasi internalnya [1]. Jika terjadi perubahan pada implementasi, program pengguna tidak akan terpengaruh secara keseluruhan, asalkan antarmuka ADT dengan "dunia luar" tetap dipertahankan [1]. ADT memperluas konsep User Defined Type (UDT) dengan menambahkan prinsip enkapsulasi, yang berarti ADT berisi sifat-sifat dan operasi-operasi yang bisa dilakukan terhadap kelas tersebut [1].

Dalam praktiknya, ADT diwujudkan melalui tipe data bentukan yang didefinisikan oleh pengguna (user defined data type) [1, 2]. Bahasa pemrograman C++ menyediakan mekanisme untuk ini, salah satunya melalui kata kunci struct [1, 2]. Struct adalah tipe data bentukan yang berisi kumpulan variabel yang bernaung dalam satu nama yang sama dan memiliki kaitan satu sama lain [1]. Berbeda dengan array, struct bisa memiliki variabel-variabel dengan tipe data yang berbeda [1]. Selain itu, kata kunci typedef dapat digunakan untuk membuat nama tipe data baru dari tipe data yang sudah ada, sehingga mempermudah deklarasi dalam program [1].

## Guided 

### 1. Pelajaran

pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct pelajaran{
    string nameMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif

```

pelajaran.cpp
```C++
#include <iostream>
using namespace std;
#include "pelajaran.h"

pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.nameMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel){
    cout << "Nama pelajaran : " << pel.nameMapel << endl;
    cout << "Kode : " << pel.kodeMapel << endl;
}
```

main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Strukur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

Program ini adalah sebuah contoh penerapan konsep ADT dalam C++ untuk mengelola data mata pelajaran secara terorganisir. ADT ini dipecah menjadi tiga file: pelajaran.h yang berfungsi sebagai kerangka untuk mendefinisikan struktur pelajaran dan mendeklarasikan fungsi-fungsinya, pelajaran.cpp yang berisi implementasi atau logika kerja dari fungsi-fungsi tersebut, dan main.cpp yang bertindak sebagai program utama. Pada intinya, program utama menggunakan ADT ini untuk membuat sebuah data pelajaran "Struktur Data" dengan memanggil fungsi create_pelajaran dan kemudian menampilkannya menggunakan tampil_pelajaran.


## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

mahasiswa.h
```C++
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
```
mahasiswa.cpp
```C++
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
```
main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"

int main() {
    Mahasiswa daftarMahasiswa[10];
    int jumlahMahasiswa = 0;
    inputDataMahasiswa(daftarMahasiswa, jumlahMahasiswa);
    tampilkanDataMahasiswa(daftarMahasiswa, jumlahMahasiswa);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-3/output1-soal1-modul3.png)

Program ini adalah contoh penerapan konsep ADT untuk mengelola data akademik mahasiswa secara terstruktur. Kode dipecah menjadi tiga file: mahasiswa.h yang berfungsi sebagai interface yang mendefinisikan struct Mahasiswa dan mendeklarasikan fungsi untuk input data, perhitungan nilai akhir, serta penampilan data. File mahasiswa.cpp kemudian menyediakan implementasi atau logika kerja dari fungsi-fungsi tersebut, termasuk rumus perhitungan nilai akhir dari komponen UTS, UAS, dan tugas. Terakhir, main.cpp bertindak sebagai program utama yang menggunakan ADT ini untuk membuat sebuah array mahasiswa, memanggil fungsi untuk mengisi data dari input pengguna, dan kemudian menampilkan kembali seluruh data yang telah diproses ke layar. 

### 2. Soal 2
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-3/modul3-soal2.png)

pelajaran.h
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED
using namespace std;
#include <string>

struct pelajaran {
    string namamapel;
    string kodemapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```
pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namamapel = namapel;
    p.kodemapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namamapel << endl;
    cout << "nilai : " << pel.kodemapel << endl;
}
```
main.cpp
```C++
#include <iostream>
#include "pelajaran.h" // Menggunakan ADT yang sudah dibuat

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-3/output1-soal2-modul3.png)

Program ini adalah sebuah contoh penerapan konsep ADT untuk mengelola data mata pelajaran secara terstruktur. Kode dipecah menjadi tiga file: pelajaran.h yang berfungsi sebagai interface yang mendefinisikan struct pelajaran dan mendeklarasikan fungsi-fungsinya. File pelajaran.cpp menyediakan implementasi atau logika kerja dari fungsi-fungsi tersebut. Terakhir, main.cpp bertindak sebagai program utama yang menggunakan ADT ini untuk membuat sebuah data pelajaran "Struktur Data" dengan memanggil create_pelajaran dan kemudian menampilkannya ke layar menggunakan tampil_pelajaran.

### 3. Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

matrix.h
```C++
#ifndef MATRIKS_H_INCLUDED
#define MATRIKS_H_INCLUDED

struct Matriks3x3 {
    int data[3][3];
};

void tampilkanMatriks(const Matriks3x3& matriks);
void tukarElemenMatriks(Matriks3x3* matriksA, Matriks3x3* matriksB, int baris, int kolom);
void tukarNilaiPointer(int* ptr1, int* ptr2);

#endif 
```
matrix.cpp
```C++
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
```
main.cpp
```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-3/output1-soal3-modul3.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-3/output2-soal3-modul3.png)

Program ini adalah contoh penerapan konsep ADT untuk melakukan operasi pada matriks 3x3 dan pointer. Kode dipecah menjadi tiga file: matriks.h yang mendefinisikan struct Matriks3x3 dan mendeklarasikan fungsi-fungsi untuk menampilkan matriks, menukar elemen matriks, dan menukar nilai pointer. File matriks.cpp berisi implementasi atau logika kerja dari ketiga fungsi tersebut. Terakhir, main.cpp bertindak sebagai program utama yang menggunakan ADT ini untuk menginisialisasi dua buah matriks dan dua pointer, kemudian memanggil fungsi-fungsi yang tersedia untuk mendemonstrasikan proses penukaran elemen matriks pada posisi tertentu serta penukaran nilai yang ditunjuk oleh pointer, lalu menampilkan hasilnya ke layar.

## Kesimpulan
Abstract Data Type (ADT) merupakan konsep fundamental dalam pemrograman yang menekankan enkapsulasi, yaitu menggabungkan struktur data (seperti struct untuk Mahasiswa, pelajaran, atau Matriks) dengan operasi-operasi (fungsi) yang memanipulasinya ke dalam satu unit logis. Praktik ini secara efektif memisahkan antarmuka atau spesifikasi (dideklarasikan dalam file header .h) dari implementasi atau detail kode (didefinisikan dalam file .cpp). Dengan demikian, program utama (main.cpp) dapat menggunakan ADT sebagai "komponen" siap pakai tanpa perlu mengetahui kerumitan internalnya, sehingga menghasilkan kode yang lebih terstruktur, modular, mudah dikelola, dan dapat digunakan kembali (reusable).

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>