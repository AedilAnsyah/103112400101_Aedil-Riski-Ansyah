# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Aedil Riski Ansyah - 103112400101</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. ...

```C++
source code guided 1
```
penjelasan singkat guided 1

### 2. ...

```C++
source code guided 2
```
penjelasan singkat guided 2

### 3. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b;
    cout << "Masukkan angka 1: ";
    cin >> a;
    cout << "Masukkan angka 2: ";
    cin >> b;

    cout << fixed << setprecision(2);
    cout << "---------------------------------------" << endl;
    cout << "Hasil Penjumlahan " << a << " dan " << b << " = " << a+b << endl;
    cout << "Hasil Pengurangan " << a << " dan " << b << " = " << a-b << endl;
    cout << "Hasil Perkalian " << a << " dan " << b << "   = " << a*b << endl;
    if (b != 0) {
        cout << "Hasil Pembagian " << a << " dan " << b << "   = " << a/b << endl;
    } else {
        cout << "Hasil Pembagian = Tidak Terdefinisi";
    }
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan1/output1-soal1-modul1.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan1/output2-soal1-modul1.png)

penjelasan unguided 1 

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
#include <iostream>
#include <string>
using namespace std;

string satuan(int n) {
    switch (n) {
        case 1: return "satu";
        case 2: return "dua";
        case 3: return "tiga";
        case 4: return "empat";
        case 5: return "lima";
        case 6: return "enam";
        case 7: return "tujuh";
        case 8: return "delapan";
        case 9: return "sembilan";
        default: return "";
    }
}

int main() {
    int n;
    string hasil;

    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if (n < 0 || n > 100) {
        hasil = "Input harus berupa bilangan 0-100";
    } else {
        if (n == 0) {
            hasil = "nol";
        } else if (n == 10) {
            hasil = "sepuluh";    
        } else if (n == 11) {
            hasil = "sebelas";
        } else if (n == 100) {
            hasil = "seratus";
        } else if (n < 10) {
            hasil = satuan(n);
        } else if (n < 20) {
            hasil = satuan(n%10) + " belas";
        } else {
            int puluhan = n / 10;
            int sisa = n % 10;
            hasil = satuan(puluhan) + " puluh";
            if (sisa != 0) {
                hasil += " " + satuan(sisa);
            }
        }
    }

    cout << "\nAngka " << n << " dalam bentuk tulisan: " << hasil << endl;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan1/output1-soal2-modul1.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan1/output2-soal2-modul1.png)

penjelasan unguided 2

### 3. Buatlah program yang dapat memberikan input dan output sbb.
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan1/modul1-soal3.png)

```C++
#include <iostream>
using namespace std;

int main() {
    int n; 

    cout << "Input: ";
    cin >> n;
    cout << "Output: " << endl;

    for (int i = n; i >= 0; i--) {
        for (int s = 0; s < n-i;s++) {
            cout << "  ";
        }
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "* ";
        for (int k = 1; k <= i; k++) {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan1/output1-soal3-modul1.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan1/output2-soal3-modul1.png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...