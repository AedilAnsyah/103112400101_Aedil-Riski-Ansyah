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

### 1. Operator

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;
    
    // penjumlahan 
    cout << "Penjumlahan: " << angka1 + angka2 << "\n";
    // pengurangan
    cout << "Pengurangan: " << angka1 - angka2 << "\n";
    // perkalian
    cout << "Perkalian: " << angka1 * angka2 << "\n";
    // pembagian
    cout << "Pembagian: " << angka1 / angka2 << "\n";
    // Modulus
    cout << "Modulus: " << angka1 % angka2 << "\n";
    return 0;
} 
```
Program ini akan menerima input dua buah integer (angka1 dan angka2) kemudian menghitung hasil penjumlahan, pengurangan, perkalian, pembagian dan modulus dari dua bilangan tersebut. Untuk pembagian hasilnya akan dibulatkan ke bawah.

### 2. Percabangan

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;
    
    if (angka1 > angka2) {
        cout << angka1 << " lebih besar dari " << angka2 << endl;
    } else if (angka1 == angka2) {
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka2 > angka1) {
        cout << angka1 << " lebih kecil dari " << angka2 << endl;
    }
    if (angka1 != angka2) {
        cout << angka1 << " tidak sama dengan " << angka2 << endl;
    }
}
```
Program ini merupakan program untuk membandingkan dua integer (angka1 dan angka2). Program ini akan membandingkan apakah angka1 lebih besar, sama dengan, atau lebih kecil dari angka2 menggunakan percabangan if-else if. Setelah itu program juga akan mengecek apakah kedua angka tidak sama (!=).

### 3. Perulangan For

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka: ";
    cin >> angka1;

    for (int i = 0; i < angka1; i++){
        cout << i << " - ";
    }

    cout << endl;
    for (int i = 20; i > angka1; i--){
        cout << i << " - ";
    }
    cout << endl;
    return 0;
}
```
Program ini adalah program yang memasukkan sebuah integer (angka1) kemudian dilakukan dua proses for-loop secara terpisah. For-loop pertama akan mencetak angka dari 0 hingga satu angka sebelum angka1 (increment). For-loop kedua akan mencetak bilangan menurun dari 20 hingga satu angka setelah angka1.

### 4. Perulangan While

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1;
    cout << "Masukkan angka: ";
    cin >> angka1;

    int i = 0;
    int j = 11;

    while (i < angka1) {
        cout << i << " - ";
        i++;
    }

    cout << endl;

    do {
        cout << j << " - ";
        j++;
    } while (j < angka1);

    return 0;
}
```
Program ini menunjukkan perbedaan while-loop dan do-while-loop menggunakan input angka1. While-loop akan mencetak angka secara increment mulai dari 0, namun hal ini hanya berjalan jika angka1 memenuhi sebuah kondisi (i < angka1). Sedangkan do-while-loop akan mencetak angka secara increment mulai dari 11 dengan perbedaan bahwa kodenya minimal akan dijalankan satu kali sebelum kondisinya (i < angka1) diperiksa di akhir. Hal ini menyebabkan do-while-loop setidaknya akan mencetak angka 11, bahkan jika kondisi angka1 tidak terpenuhi.

### 5. Struct

```C++
#include <iostream>
using namespace std;

int main() {
    const int jumlah = 5;

    struct raport {
        char nama[5];
        int nilai;
    };

    raport siswa[jumlah] = {};

    for (int i = 0; i < jumlah; i++) {
        cout << " masukkan nama siswa : " << siswa[i].nama;
        cin >> siswa[i].nama;
        cout << " masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
    }
    int i = 0;
    while (i < jumlah) {
        cout << "Nama " << siswa[i].nama << endl;
        cout << "Nilai " << siswa[i].nilai << endl;
        i++;
    }

    return 0;
}
```
Program ini menunjukkan penggunaan struct untuk membuat tipe data khusus raport yang menyimpan nilai dan nama. Program kemudian mendeklarasikan array bernama siswa untuk menampumg data raport dari lima siswa. Menggunakan for-loop, user diminta untuk memasukkan data nama dan nilai dari lima siswa tersebut. Setelah semua data tersimpan di array, while-loop digunakan untuk menampilkan data kelima mahasiswa tersebut.

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
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-1/output1-soal1-modul1.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-1/output2-soal1-modul1.png)

Program ini merupakan program kalkulator sederhana yang inputnya berupa dua bilangan bertipe double (desimal) yaitu a dan b. Program meminta pengguna memasukkan angka a dan b kemudian menghitung hasil penjumlahan, pengurangan, perkalian dan pembagian dua bilangan tersebut. Outputnya berupa bilangan desimal dengan dua angka dibelakang koma. Program ini juga menggunakan if-else untuk mengantisipasi hasil pembagian yang tidak terdefinisi (b = 0).

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
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-1/output1-soal2-modul1.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-1/output2-soal2-modul1.png)

Program ini adalah program yang mengkonversi dari angka ke tulisan untuk rentang angka 0 sampai 100. Program ini menggunakan fungsi satuan untuk mengubah digit 1-9 menjadi sebuah teks. Dalam fungsi main, input dari pengguna akan divalidasi untuk memastikan rentang angkanya sesuai dengan yang diharapkan, setelah itu program akan menggunakan if-else if untuk menentukan kategori angka seperti satuan, puluhan dan belasan. Program ini juga mengantisipasi angka khusus seperti nol, sepuluh, sebelas, dan seratus. Untuk puluhan program akan memecah angka menjadi satuan dan puluhan untuk merangkai nama bilangan yang benar.

### 3. Buatlah program yang dapat memberikan input dan output sbb.
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-1/modul1-soal3.png)

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
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-1/output1-soal3-modul1.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-1/output2-soal3-modul1.png)

Program ini adalah program untuk mencetak segitiga sama sisi terbalik dan berisi angka. Setelah meminta integer (n), program menggunakan for-loop utama secara decrement dari n hingga 0 untuk membuat setiap baris. Di setiap baris, program mencetak sejumlah spasi agar terlihat menjorok ke dalam, dan diikuti oleh deret angka menurun dari i ke 1. Bintang (*) akan digunakan sebagai pemisah, dan dilanjutkan kembali deret angka secara increment dari 1 ke i, sehingga meciptakan pola segitiga mirror.

## Kesimpulan
Dasar pemrograman C++ berpusat pada struktur program yang terdiri dari fungsi main() sebagai titik awal eksekusi dan penggunaan library melalui #include. Konsep fundamentalnya meliputi penggunaan variabel dengan tipe data spesifik (seperti int, float, char) untuk menyimpan nilai, konstanta untuk nilai tetap, dan struct untuk data yang lebih kompleks. Interaksi program dikelola melalui perintah cin (input) dan cout (output). Logika dan alur program dikendalikan oleh tiga pilar utama: operator untuk manipulasi data, pernyataan kondisional (if, switch) untuk pengambilan keputusan, dan struktur perulangan (for, while) untuk menjalankan tugas repetitif secara efisien

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>