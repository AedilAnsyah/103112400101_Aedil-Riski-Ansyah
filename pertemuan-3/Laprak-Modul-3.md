# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Aedil Riski Ansyah - 103112400101</p>

## Dasar Teori
### A. Array 
Array adalah tipe data terstruktur yang terdiri dari kumpulan elemen dengan tipe data yang sama dan menggunakan satu nama variabel [1, 2]. Array bersifat homogen, artinya semua elemennya harus memiliki tipe data yang identik [1], dan bersifat statis, yang berarti alokasi memorinya memiliki batasan yang telah ditentukan [1]. Setiap elemen data dalam array dapat diakses secara acak melalui indeksnya, yang merupakan penanda posisi unik untuk setiap elemen, di mana elemen pertama selalu dimulai dari indeks 0 [2].

Jenis-jenis array meliputi:

* Array Satu Dimensi: Dikenal juga sebagai vektor, ini adalah bentuk array paling dasar yang terdiri dari satu larik data saja [1, 2]. Deklarasinya adalah tipe_data nama_var[ukuran]; [2].

* Array Dua Dimensi: Sering diibaratkan seperti matriks atau tabel, karena terdiri dari baris dan kolom yang diakses menggunakan dua indeks [1, 2]. Deklarasinya adalah tipe_data nama_array[jumlah_baris][jumlah_kolom]; [2].

* Array Multi-Dimensi: Merupakan array yang memiliki lebih dari dua indeks, digunakan untuk merepresentasikan data dalam ruang yang lebih kompleks [1, 2].

### B. Pointer
Semua data program disimpan dalam memori komputer (RAM), di mana setiap sel memori memiliki alamat yang unik [2]. Pointer adalah variabel khusus yang tidak berisi nilai data, melainkan menyimpan alamat memori dari variabel lain [2]. Dengan menunjuk ke alamat variabel lain, pointer dapat mengakses dan memanipulasi nilai dari variabel tersebut [2].

Pointer dideklarasikan dengan menambahkan tanda asteris (*) sebelum nama variabel, seperti tipe_data *nama_pointer; [2]. Ada dua operator penting yang digunakan bersama pointer:

* Operator Address-Of (&): Disebut juga operator dereference, digunakan untuk mendapatkan alamat memori dari suatu variabel [2].

* Operator Reference (*): Digunakan untuk mengakses nilai yang ada di alamat memori yang ditunjuk oleh pointer [2].

Terdapat hubungan yang erat antara pointer dan array, di mana nama sebuah array pada dasarnya berfungsi sebagai pointer yang menunjuk ke elemen pertamanya [2].

### C. Fungsi dan Prosedur
Fungsi adalah blok kode terstruktur yang dirancang untuk melakukan tugas spesifik, memungkinkan program dipecah menjadi modul-modul yang lebih kecil dan mudah dikelola [2]. Pendekatan ini disebut pemrograman modular dan mendukung metode divide-and-conquer [2]. Setiap program C++ minimal memiliki satu fungsi, yaitu main(), yang menjadi titik awal dan akhir eksekusi program [2].

Di C++, prosedur dikenal sebagai fungsi void, yaitu fungsi yang melakukan tugas tertentu tetapi tidak mengembalikan nilai (return value) [2]. Sebaliknya, fungsi yang mengembalikan nilai harus mendeklarasikan tipe data dari nilai yang akan dikembalikan [2].

Parameter atau masukan dapat dilewatkan ke fungsi melalui beberapa cara:

* Pemanggilan dengan Nilai (Call by Value): Metode ini menyalin nilai dari parameter aktual ke parameter formal. Perubahan yang terjadi pada parameter di dalam fungsi tidak akan memengaruhi variabel aslinya di luar fungsi [2].

* Pemanggilan dengan Pointer (Call by Pointer): Dengan melewatkan alamat memori dari variabel aktual, fungsi dapat secara langsung mengubah nilai dari variabel asli tersebut [2].

* Pemanggilan dengan Referensi (Call by Reference): Serupa dengan call by pointer, metode ini juga melewatkan alamat variabel, sehingga memungkinkan modifikasi nilai variabel asli, namun dengan sintaks pemanggilan yang lebih sederhana [2].

## Guided 

### 1. List

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


Program ini menunjukkan operasi dasar dan output dari sebuah sebuah array di C++. Program mendeklarasikan array integer (arr) dengan ukuran lima. Kemudian for-loop digunakan untuk meminta user memasukkan lima nilai, setiap nilai yang diinput akan disimpan secara berurutan dalam setiap indeks array. Setelah semua indeks terisi, program menggunakan while-loop untuk menampilkan isi dari setiap indeks array tersebut ke layar (dari indeks 0-4). 


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
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-2/output1-soal1-modul3.png)

Program ini merupakan program untuk melakukan tiga operasi dasar (penjumlahan, pengurangan dan perkalian) pada dua matriks 3x3 yang telah dibuat sebelumnya (mtx1 dan mtx2). Program ini menggunakan sebuah fungsi tampilan untuk mencetak matriks hasil dengan rapi. Alur kerjanya adalah menghitung hasil setiap operasi secara berurutan, menyimpannya dalam matriks hasil, lalu langsung memanggil fungsi tampilan untuk menunjukkan hasilnya sebelum melanjutkan ke operasi berikutnya. 

### 2. ![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-3/modul3-soal2.png)

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
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-2/output1-soal2-modul3.png)

Kedua program ini menunjukkan cara kerja fungsi yang sama (menukar nilai tiga variabel, b ke a, c ke b, a ke c) tetapi menggunakan dua metode yang berbeda. Program pertama menggunakan fungsi tukarP yang menerima parameter berupa pointer, sehingga saat memanggilnya, kita harus mengirimkan alamat memori dari variabel (&a, &b, &c). Program kedua menggunakan fungsi tukarR yang menerima parameter berupa reference, yang memungkinkan pemanggilan fungsi dilakukan dengan mengirimkan variabelnya secara langsung (a, b, c), meskipun pada dasarnya fungsi tetap memodifikasi nilai variabel aslinya.

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
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-2/output1-soal3-modul3.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-2/output2-soal3-modul3.png)

Program ini merupakan aplikasi sederhana yang melakukan berbagai operasi pada sebuah array yang telah dibuat sebelumnya (arr). Program ini terdiri dari empat fungsi terpisah. Fungsi tampilan untuk mencetak isi array. Fungsi cariMax untuk menemukan nilai terbesar. Fungsi cariMin untuk menemukan nilai terkecil. Fungsi hitungAvg untuk menghitung rata-rata. Di dalam fungsi main, terdapat sebuah do-while loop yang digunakan untuk terus menampilkan menu kepada user, lalu sebuah switch-case akan memanggil fungsi yang sesuai berdasarkan pilihan input user sampai user memilih opsi keluar dari program 

## Kesimpulan
Perumusan dasar teori C++ berpusat pada tiga konsep fundamental yaitu array sebagai struktur data untuk koleksi nilai sejenis, pointer untuk manipulasi alamat memori secara langsung, dan fungsi sebagai pilar pemrograman modular, dengan penekanan pada metode pemanggilan parameter seperti call-by-pointer dan call-by-reference. Penerapan praktis dari prinsip-prinsip ini kemudian didemonstrasikan melalui analisis serangkaian kode C++. Contoh-contoh tersebut mengilustrasikan spektrum implementasi dari operasi dasar seperti input-output array, kalkulasi matriks, hingga perbandingan fungsional antara pointer dan referensi. Puncaknya, analisis ini mengarah pada pemahaman sebuah program menu interaktif yang utuh, yang secara efektif mengintegrasikan semua konsep yang telah dibahas, fungsi, dan struktur kontrol untuk menciptakan sebuah aplikasi fungsional.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>