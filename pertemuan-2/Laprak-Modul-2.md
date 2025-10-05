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

### 1. Array 1 Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i=0; i<5; i++) {
        cout << "masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j = 0;
    while (j < 5) {
        cout << "isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
} 
```
Program ini menunjukkan operasi dasar dan output dari sebuah sebuah array di C++. Program mendeklarasikan array integer (arr) dengan ukuran lima. Kemudian for-loop digunakan untuk meminta user memasukkan lima nilai, setiap nilai yang diinput akan disimpan secara berurutan dalam setiap indeks array. Setelah semua indeks terisi, program menggunakan while-loop untuk menampilkan isi dari setiap indeks array tersebut ke layar (dari indeks 0-4). 

### 2. Array 2 Dimensi

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]) {
    for (int i = 0; i < 2; i++){
        for (int j =0; j <2;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrA[2][2] = {
        {1,2},
        {3,4}
    };
    int arrB[2][2] = {
        {2,3},
        {4,5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    // penjumlahan matriks 2x2
    for (int i = 0; i <2; i++) {
        for (int j =0; j < 2; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil Penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    // perkalian matriks 2x2
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k =0; k < 2; k++) {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil Perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
Program ini menunjukkan operasi penjumlahan dan perkalian matriks 2x2. Program ini membuat dua matriks awal (arrA dan arrB), lalu melakukan dua operasi terpisah. Pertama, menjumlahkan kedua matriks secara elemen per elemen dan menyimpan hasilnya di arrC. Kedua, mengalikan kedua matriks menggunakan algoritma perkalian matriks dan menyimpan hasilnya di arrD. Terdapat sebuah fungsi bernama tampilkanHasil yang digunakan untuk mencetak matriks hasil penjumlahan dan perkalian tersebut ke layar dengan format yang lebih rapih.

### 3. Function Procedure

```C++
#include <iostream>
using namespace std;

int cariMax(int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if(arr[i] > MAX) {
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran) {
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "total penjumlahan : " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++) {
        totalKali *= arr[i];
    }
    cout << "total perkalian : " << totalKali << endl;
}

int main() {
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran; i++) {
        cout << "masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMax(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Program ini menunjukkan penggunaan fungsi untuk melakukan beberapa operasi pada sebuah array integer yang diisi oleh user. Awalnya user akan diminta untuk memasukkan lima nilai ke dalam array. Selanjutnya program akan memanggil fungsi cariMax yang akan mencari nilai maksimum dari semua elemem array, lalu hasilnya dicetak. Terakhir, program akan memanggil prosedur operasiAritmatika yang menghitung total penjumlahan dan perkalian lalu menampilkannya.

### 4. Pointer

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a= " << a << " and b=" << b << endl;

    return 0;
}
```
Program ini menunjukkan penggunaan pointer di C++. Program utama pertama-tama menunjukkan bagaimana sebuah pointer (ptr) menyimpan alamat memori dari variabel a, dan cara mengakses nilai variabel tersebut melalui pointernya. Kemudian, program memanggil fungsi tukar dengan mengirimkan alamat memori dari variabel a dan b. Fungsi tukar ini menggunakan parameter pointer untuk secara langsung menukar nilai asli dari kedua variabel tersebut. 

### 5. Reference

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamt a (&a): " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat ref (&ref): " << &ref << endl;

    //Mengubah nilai a lewat reference
    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a= " << a << " and b=" << b << endl;

    return 0;
}
```
Program ini menunjukkan penggunaan reference di C++. Di dalam main, sebuah reference (ref) dibuat sebagai alias untuk variabel a, dan program menunjukkan bahwa keduanya berbagi nilai dan alamat memori yang sama, serta membuktikan bahwa mengubah nilai melalui ref juga akan mengubah nilai a. 

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
#include <iostream>

using namespace std;

void tampilan(int mtx[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mtx1[3][3] = {
        {1,2,4},
        {3,1,2},
        {7,5,4}
    };
    int mtx2[3][3] = {
        {3,1,7},
        {3,5,4},
        {8,1,5}
    };
    int hasil[3][3];
    cout << "\n=== HASIL PENJUMLAHAN ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = mtx1[i][j] + mtx2[i][j];
        }
    }
    tampilan(hasil);

    cout << "\n=== HASIL PENGURANGAN ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = mtx1[i][j] - mtx2[i][j];
        }
    }
    tampilan(hasil);

    cout << "\n=== HASIL PERKALIAN ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                hasil[i][j] += mtx1[i][k] * mtx2[k][j];
            }
        }
    }
    tampilan(hasil);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-2/output1-soal1-modul2.png)

Program ini merupakan program untuk melakukan tiga operasi dasar (penjumlahan, pengurangan dan perkalian) pada dua matriks 3x3 yang telah dibuat sebelumnya (mtx1 dan mtx2). Program ini menggunakan sebuah fungsi tampilan untuk mencetak matriks hasil dengan rapi. Alur kerjanya adalah menghitung hasil setiap operasi secara berurutan, menyimpannya dalam matriks hasil, lalu langsung memanggil fungsi tampilan untuk menunjukkan hasilnya sebelum melanjutkan ke operasi berikutnya. 

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

Menggunakan pointer:
```C++
#include <iostream>

using namespace std;

void tukarP(int *pA, int *pB, int *pC) {
    int temp = *pA;
    *pA = *pB;
    *pB = *pC;
    *pC = temp;
}

int main() {
    int a, b, c;
    a = 10;
    b = 20;
    c = 30;

    cout << "Nilai awal : \na = " << a << ", b = " << b << ", c = " << c << endl;
    tukarP(&a, &b, &c);
    cout << "Nilai setelah ditukar : \na = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}
```
Menggunakan reference:
```C++
#include <iostream>

using namespace std;

void tukarR(int &rA, int &rB, int &rC) {
    int temp = rA;
    rA = rB;
    rB = rC;
    rC = temp;
}

int main() {
    int a, b, c;
    a = 10;
    b = 20;
    c = 30;

    cout << "Nilai awal : \na = " << a << ", b = " << b << ", c = " << c << endl;
    tukarR(a, b, c);
    cout << "Nilai setelah ditukar : \na = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output Pointer
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-2/output1-soal2-modul2.png)

##### Output Reference
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-2/output2-soal2-modul2.png)

Kedua program ini menunjukkan cara kerja fungsi yang sama (menukar nilai tiga variabel, b ke a, c ke b, a ke c) tetapi menggunakan dua metode yang berbeda. Program pertama menggunakan fungsi tukarP yang menerima parameter berupa pointer, sehingga saat memanggilnya, kita harus mengirimkan alamat memori dari variabel (&a, &b, &c). Program kedua menggunakan fungsi tukarR yang menerima parameter berupa reference, yang memungkinkan pemanggilan fungsi dilakukan dengan mengirimkan variabelnya secara langsung (a, b, c), meskipun pada dasarnya fungsi tetap memodifikasi nilai variabel aslinya.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut : 
### arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}
### Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini :
![Screenshot Soal 3 Modul 3](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-2/modul2-soal3.png)

```C++
#include <iostream>

using namespace std;

int cariMax(const int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int cariMin(const int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void hitungAvg(const int arr[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    double avg = total / size;
    cout << "Rata-rata array: " << avg << endl;
}

void tampilan(const int arr[], int size) {
    cout << "Isi Array: { ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << (i == size - 1 ? " " : ", ");
    }
    cout << "}" << endl;
}

int main() {
    int arr[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tampilan(arr, 10);
            break;
        case 2:
            cout << "Nilai maksimal dari array: " << cariMax(arr, 10) << endl;
            break;
        case 3:
            cout << "Nilai minimum dari array: " << cariMin(arr, 10) << endl;
            break;
        case 4:
            hitungAvg(arr, 10);
            break;           
        case 5:
            cout << "Program selesai" << endl;
        default:
            cout << "Pilihan tidak valid";
        }
    } while (pilihan != 5);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-2/output1-soal3-modul2.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-2/output2-soal3-modul2.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-2/output3-soal3-modul2.png)

Program ini merupakan aplikasi sederhana yang melakukan berbagai operasi pada sebuah array yang telah dibuat sebelumnya (arr). Program ini terdiri dari empat fungsi terpisah. Fungsi tampilan untuk mencetak isi array. Fungsi cariMax untuk menemukan nilai terbesar. Fungsi cariMin untuk menemukan nilai terkecil. Fungsi hitungAvg untuk menghitung rata-rata. Di dalam fungsi main, terdapat sebuah do-while loop yang digunakan untuk terus menampilkan menu kepada user, lalu sebuah switch-case akan memanggil fungsi yang sesuai berdasarkan pilihan input user sampai user memilih opsi keluar dari program 

## Kesimpulan
Perumusan dasar teori C++ berpusat pada tiga konsep fundamental yaitu array sebagai struktur data untuk koleksi nilai sejenis, pointer untuk manipulasi alamat memori secara langsung, dan fungsi sebagai pilar pemrograman modular, dengan penekanan pada metode pemanggilan parameter seperti call-by-pointer dan call-by-reference. Penerapan praktis dari prinsip-prinsip ini kemudian didemonstrasikan melalui analisis serangkaian kode C++. Contoh-contoh tersebut mengilustrasikan spektrum implementasi dari operasi dasar seperti input-output array, kalkulasi matriks, hingga perbandingan fungsional antara pointer dan referensi. Puncaknya, analisis ini mengarah pada pemahaman sebuah program menu interaktif yang utuh, yang secara efektif mengintegrasikan semua konsep yang telah dibahas, fungsi, dan struktur kontrol untuk menciptakan sebuah aplikasi fungsional.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>