# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Aedil Riski Ansyah - 103112400101</p>

## Dasar Teori
Bahasa C++ merupakan turunan dari bahasa C yang populer dan banyak dibutuhkan dalam dunia kerja [2]. Setiap program C++ memiliki struktur dasar yang terdiri dari fungsi utama int main() yang menjadi titik awal dan akhir eksekusi program [2]. Program umumnya menyertakan library atau file judul menggunakan perintah preprocessor #include <iostream> untuk dapat melakukan operasi input-output [2]. Setiap perintah atau statement di dalam C++ harus diakhiri dengan tanda titik koma (;) [2].

Dalam C++, data disimpan dalam variabel, yaitu sebuah nama untuk lokasi di memori yang nilainya dapat berubah selama program berjalan [2]. Setiap variabel harus dideklarasikan dengan tipe data tertentu, seperti int untuk bilangan bulat, float atau real untuk bilangan desimal, dan char untuk karakter tunggal [2]. Nilai yang tidak berubah selama eksekusi program disebut konstanta dan didefinisikan menggunakan kata kunci const [2]. Untuk mengelompokkan beberapa variabel dengan tipe data yang mungkin berbeda menjadi satu kesatuan, digunakan tipe data bentukan yang disebut struktur atau struct [1, 2].

Interaksi dengan pengguna dilakukan melalui perintah input dan output. Perintah cout digunakan untuk menampilkan data ke layar (output), sedangkan cin digunakan untuk menerima masukan dari keyboard (input) [2].

Logika program dibangun menggunakan operator, kondisional, dan perulangan.

* Operator adalah simbol untuk melakukan operasi, seperti operator aritmatika (+, -, *, /, %), operator relasional atau perbandingan (<, >, ==), dan operator logika (and, or) [2].

* Kondisional digunakan untuk pengambilan keputusan. Pernyataan if-else digunakan untuk memilih satu dari dua blok kode berdasarkan suatu kondisi, sedangkan switch-case digunakan untuk memilih dari banyak blok kode alternatif [2].

* Perulangan (looping) digunakan untuk menjalankan blok kode berulang kali. Struktur perulangan yang umum adalah for, while, dan do-while (atau repeat-until) [2].

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
Program ini akan menerima input dua buah integer (angka1 dan angka2) kemudian menghitung hasil penjumlahan, pengurangan, perkalian, pembagian dan modulus dari dua bilangan tersebut. Untuk pembagian hasilnya akan dibulatkan ke bawah.

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
Program ini merupakan program untuk membandingkan dua integer (angka1 dan angka2). Program ini akan membandingkan apakah angka1 lebih besar, sama dengan, atau lebih kecil dari angka2 menggunakan percabangan if-else if. Setelah itu program juga akan mengecek apakah kedua angka tidak sama (!=).

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
Program ini adalah program yang memasukkan sebuah integer (angka1) kemudian dilakukan dua proses for-loop secara terpisah. For-loop pertama akan mencetak angka dari 0 hingga satu angka sebelum angka1 (increment). For-loop kedua akan mencetak bilangan menurun dari 20 hingga satu angka setelah angka1.

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
Program ini menunjukkan perbedaan while-loop dan do-while-loop menggunakan input angka1. While-loop akan mencetak angka secara increment mulai dari 0, namun hal ini hanya berjalan jika angka1 memenuhi sebuah kondisi (i < angka1). Sedangkan do-while-loop akan mencetak angka secara increment mulai dari 11 dengan perbedaan bahwa kodenya minimal akan dijalankan satu kali sebelum kondisinya (i < angka1) diperiksa di akhir. Hal ini menyebabkan do-while-loop setidaknya akan mencetak angka 11, bahkan jika kondisi angka1 tidak terpenuhi.

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
Program ini menunjukkan penggunaan struct untuk membuat tipe data khusus raport yang menyimpan nilai dan nama. Program kemudian mendeklarasikan array bernama siswa untuk menampumg data raport dari lima siswa. Menggunakan for-loop, user diminta untuk memasukkan data nama dan nilai dari lima siswa tersebut. Setelah semua data tersimpan di array, while-loop digunakan untuk menampilkan data kelima mahasiswa tersebut.

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

Program ini merupakan program kalkulator sederhana yang inputnya berupa dua bilangan bertipe double (desimal) yaitu a dan b. Program meminta pengguna memasukkan angka a dan b kemudian menghitung hasil penjumlahan, pengurangan, perkalian dan pembagian dua bilangan tersebut. Outputnya berupa bilangan desimal dengan dua angka dibelakang koma. Program ini juga menggunakan if-else untuk mengantisipasi hasil pembagian yang tidak terdefinisi (b = 0).

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

Program ini adalah program yang mengkonversi dari angka ke tulisan untuk rentang angka 0 sampai 100. Program ini menggunakan fungsi satuan untuk mengubah digit 1-9 menjadi sebuah teks. Dalam fungsi main, input dari pengguna akan divalidasi untuk memastikan rentang angkanya sesuai dengan yang diharapkan, setelah itu program akan menggunakan if-else if untuk menentukan kategori angka seperti satuan, puluhan dan belasan. Program ini juga mengantisipasi angka khusus seperti nol, sepuluh, sebelas, dan seratus. Untuk puluhan program akan memecah angka menjadi satuan dan puluhan untuk merangkai nama bilangan yang benar.

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

Program ini adalah program untuk mencetak segitiga sama sisi terbalik dan berisi angka. Setelah meminta integer (n), program menggunakan for-loop utama secara decrement dari n hingga 0 untuk membuat setiap baris. Di setiap baris, program mencetak sejumlah spasi agar terlihat menjorok ke dalam, dan diikuti oleh deret angka menurun dari i ke 1. Bintang (*) akan digunakan sebagai pemisah, dan dilanjutkan kembali deret angka secara increment dari 1 ke i, sehingga meciptakan pola segitiga mirror.

## Kesimpulan
Dasar pemrograman C++ berpusat pada struktur program yang terdiri dari fungsi main() sebagai titik awal eksekusi dan penggunaan library melalui #include. Konsep fundamentalnya meliputi penggunaan variabel dengan tipe data spesifik (seperti int, float, char) untuk menyimpan nilai, konstanta untuk nilai tetap, dan struct untuk data yang lebih kompleks. Interaksi program dikelola melalui perintah cin (input) dan cout (output). Logika dan alur program dikendalikan oleh tiga pilar utama: operator untuk manipulasi data, pernyataan kondisional (if, switch) untuk pengambilan keputusan, dan struktur perulangan (for, while) untuk menjalankan tugas repetitif secara efisien

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>