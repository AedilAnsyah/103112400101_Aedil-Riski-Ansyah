# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Aedil Riski Ansyah - 103112400101</p>

## Dasar Teori
Dalam struktur data, Queue (antrian) didefinisikan sebagai jenis struktur data linier [2] yang meniru antrian orang dalam kehidupan nyata, misalnya saat menunggu pelayanan di bank atau membeli karcis [2]. Operasi pada queue didasarkan pada prinsip FIFO (First In First Out) [1, 2]. Prinsip FIFO berarti elemen data yang pertama kali masuk ke dalam antrian adalah elemen yang pertama kali akan keluar, diambil, atau dilayani [1, 2]. Berbeda dari stack yang beroperasi di satu ujung, queue memiliki dua sisi: penambahan elemen baru selalu dilakukan di bagian paling belakang (disebut Rear atau Tail), sementara pengambilan atau pelayanan elemen selalu dilakukan di bagian paling depan (disebut Front atau Head) [2].
Dua operasi paling fundamental pada queue adalah Enqueue dan Dequeue [1]. Operasi Enqueue berfungsi untuk menambahkan atau memasukkan elemen baru ke dalam antrian [1], di mana elemen ini akan selalu menempati posisi paling belakang (Tail) [2]. Sebaliknya, operasi Dequeue berfungsi untuk mengeluarkan atau menghapus satu elemen dari dalam antrian [1], dan elemen yang diambil selalu yang berada pada posisi terdepan (Head) [2]. Selain dua operasi inti tersebut, umumnya terdapat pula fungsi Create() untuk inisialisasi antrian (seringkali dengan mengatur Head dan Tail ke -1) [2], IsEmpty() untuk memeriksa apakah antrian kosong [2], dan IsFull() untuk memeriksa apakah antrian sudah penuh [2]. Queue dapat diimplementasikan menggunakan berbagai cara, termasuk Linear Array dan Circular Array [1], atau dengan deklarasi struct yang dikombinasikan dengan array [2].

## Guided 

### 1. Queue Menggunakan Linked List

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);   
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

queue.cpp
```C++
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```

main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```

Program ini adalah implementasi dari struktur data queue (antrian) dalam C++ yang menggunakan pendekatan singly linked list. Strukturnya dibagi menjadi tiga file: queue.h sebagai file header, queue.cpp sebagai file implementasi, dan main.cpp sebagai program utama (driver) untuk menguji queue. File header queue.h mendefinisikan struktur Node, yang berisi string nama dan pointer next, serta struktur queue yang mengelola antrian dengan dua pointer: head (depan) dan tail (belakang). File queue.cpp menyediakan logika untuk fungsi-fungsi queue. CreateQueue menginisialisasi head dan tail ke nullptr. enQueue menambahkan elemen baru di akhir antrian (pada tail), sementara deQueue menghapus elemen dari awal antrian (pada head), dengan penanganan khusus untuk memastikan tail juga menjadi nullptr jika antrian menjadi kosong. File main.cpp adalah program yang menjalankan dan menguji fungsionalitas queue. Pertama, sebuah queue Q dibuat dan diinisialisasi. Program kemudian memanggil enQueue sebanyak enam kali, menambahkan nama "dhimas", "Arvin", "Rizal", "Hafizh", "Fathur", dan "Atha" secara berurutan. Setelah itu, viewQueue dipanggil untuk mencetak isi queue, yang menampilkan keenam nama tersebut. Selanjutnya, program memanggil deQueue sebanyak empat kali. Sesuai prinsip FIFO (First In First Out), ini akan menghapus empat nama pertama yang dimasukkan ("dhimas", "Arvin", "Rizal", dan "Hafizh"). Program kemudian memanggil viewQueue lagi untuk menampilkan isi queue yang tersisa, yaitu "Fathur" dan "Atha". Terakhir, clearQueue dipanggil untuk menghapus semua elemen yang tersisa sebelum program berakhir.

### 2. Queue Menggunakan Array

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

queue.cpp
```C++
#include "queue2.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

main.cpp
```C++
#include "queue2.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```

Program ini adalah implementasi dari struktur data queue (antrian) dalam C++ yang menggunakan array statis dengan ukuran MAKSIMAL 5, berbeda dari implementasi linked list dinamis. Strukturnya dibagi menjadi tiga file: queue.h (header), queue.cpp (implementasi), dan main.cpp (program utama). File header mendefinisikan struct queue yang berisi array string nama serta dua pointer integer, head dan tail, untuk melacak bagian depan dan belakang antrian. File queue.cpp berisi logika fungsi, dan yang menarik, file ini memuat (dalam bentuk komentar) tiga strategi implementasi queue berbasis array. Versi yang aktif dan tidak dikomentari adalah "Implementasi 1" (Queue Linear Statis). Dalam implementasi yang aktif ini, CreateQueue menginisialisasi head dan tail ke -1. Fungsi enQueue menambahkan elemen baru ke tail; jika queue kosong, head dan tail diatur ke 0, jika tidak, hanya tail yang bertambah. Fungsi isFull bekerja dengan memeriksa apakah tail telah mencapai indeks terakhir array (MAKSIMAL - 1). Bagian paling khas dari implementasi ini adalah deQueue. Fungsi ini selalu menghapus data dari head (yang selalu berada di indeks 0), kemudian menggunakan loop for untuk menggeser semua elemen yang tersisa satu posisi ke depan (ke kiri) untuk mengisi celah. Setelah pergeseran, tail dikurangi. Jika queue menjadi kosong (tail menjadi -1), head dan tail di-reset ke -1.File main.cpp menguji implementasi ini. Program membuat queue, lalu mencoba enQueue sebanyak enam nama. Lima nama pertama ("dhimas" hingga "Fathur") berhasil masuk. Upaya keenam untuk menambahkan "Daffa" gagal karena isFull mengembalikan true, sehingga program mencetak "Queue sudah penuh!". Program kemudian menampilkan isi queue (5 nama). Setelah itu, deQueue dipanggil empat kali, yang secara berurutan menghapus "dhimas", "Arvin", "Rizal", dan "Hafizh", di mana setiap pemanggilan menggeser sisa elemen. Terakhir, viewQueue dipanggil lagi, hanya menampilkan satu nama yang tersisa, yaitu "Fathur". 


## Unguided 

### 1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-8/modul8-soal1-1.png)
### Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-8/modul8-soal1-2.png)
### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).
### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

ketiga soal menggunakan file header (queue.h) dan file utama (main.cpp) yang sama
queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using infotype = int;

const int MAKSIMAL = 5;
struct Queue {
    infotype info[MAKSIMAL];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(const Queue &Q);
bool isFullQueue(const Queue &Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(const Queue &Q);

#endif
```

queue1.cpp untuk soal 1
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q) {
    return Q.tail == -1;
}

bool isFullQueue(const Queue &Q) {
    return Q.tail == MAKSIMAL - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh, enqueue dibatalkan." << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0; 
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong, dequeue dibatalkan." << endl;
        return -1; 
    } else {
        infotype x = Q.info[Q.head]; 

        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        
        Q.tail--; 

        if (isEmptyQueue(Q)) {
            Q.head = -1; 
        }
        
        return x; 
    }
}

void printInfo(const Queue &Q) {
    cout << " " << Q.head << " - " << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

queue2.cpp untuk soal 2
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q) {
    return (Q.head == -1 || Q.head > Q.tail);
}

bool isFullQueue(const Queue &Q) {
    return Q.tail == MAKSIMAL - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh, enqueue dibatalkan." << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0; 
            Q.tail = 0; 
        } else {
            Q.tail++; 
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong, dequeue dibatalkan." << endl;
        return -1; 
    } else {
        infotype x = Q.info[Q.head]; 
        Q.head++; 
        if (isEmptyQueue(Q)) {
            CreateQueue(Q); 
        }
        
        return x; 
    }
}

void printInfo(const Queue &Q) {
    cout << " " << Q.head << " - " << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

queue3.cpp untuk soal 3
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q) {
    return Q.tail == -1; 
}

bool isFullQueue(const Queue &Q) {
    return (Q.tail + 1) % MAKSIMAL == Q.head;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh, enqueue dibatalkan." << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0; 
            Q.tail = 0; 
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong, dequeue dibatalkan." << endl;
        return -1; 
    } else {
        infotype x = Q.info[Q.head]; 
        if (Q.head == Q.tail) {
            CreateQueue(Q); 
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL;
        }
        
        return x; 
    }
}

void printInfo(const Queue &Q) {
    cout << " " << Q.head << " - " << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) {
                break;
            }
            i = (i + 1) % MAKSIMAL;
        }
        cout << endl;
    }
}
```

main.cpp 
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Queue Q;
    CreateQueue(Q);
    cout << "---------------------------------" << endl;
    cout << "<< H - T | Queue info >>" << endl;
    cout << "---------------------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); 
    printInfo(Q); 
    enqueue(Q, 2); 
    printInfo(Q); 
    enqueue(Q, 7); 
    printInfo(Q);

    dequeue(Q); 
    printInfo(Q); 
    dequeue(Q); 
    printInfo(Q); 
    dequeue(Q); 
    printInfo(Q); 

    return 0;
}
```

### Output Unguided :

##### Output soal 1, 2, 3
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-8/output1-soal123-modul8.png)

Program-program ini menunjukkan tiga cara berbeda untuk mengimplementasikan struktur data Queue (antrian) menggunakan array statis di C++. Inti dari semua program ini adalah file header queue.h dan file utama main.cpp. File queue.h bertindak sebagai "kontrak" atau Abstract Data Type (ADT) yang mendefinisikan struktur Queue (terdiri dari array info berukuran 5, head, dan tail) serta semua fungsi yang harus ada, seperti CreateQueue, enqueue, dan dequeue. File main.cpp adalah program penguji (driver) yang sama untuk ketiga implementasi. Program ini membuat queue, menambah (enqueue) tiga angka (5, 2, 7), lalu menghapus (dequeue) tiga angka tersebut, sambil mencetak status queue setelah setiap operasi.

queue1.cpp mengimplementasikan Alternatif 1 (Head diam, Tail bergerak). Dalam metode ini, head selalu dianggap berada di indeks 0. Saat enqueue, data ditambahkan ke posisi tail, dan tail bertambah. Saat dequeue, data diambil dari head (indeks 0), lalu sebuah loop for dijalankan untuk menggeser semua elemen yang tersisa satu posisi ke kiri untuk mengisi kekosongan di indeks 0. tail kemudian dikurangi. Meskipun logikanya sederhana, metode ini sangat tidak efisien untuk dequeue karena operasi pergeseran memiliki kompleksitas waktu O(n), yang berarti semakin banyak elemen, semakin lambat proses dequeue.

queue2.cpp mengimplementasikan Alternatif 2 (Head bergerak, Tail bergerak). Ini adalah queue linear yang lebih efisien. Saat enqueue, tail bergerak ke kanan. Saat dequeue, data diambil dari posisi head, dan head hanya digeser ke kanan (increment), tanpa ada pergeseran elemen. Ini membuat operasi dequeue menjadi sangat cepat (O(1)). Namun, kelemahannya adalah "ruang terbuang" (wasted space). Slot array yang telah ditinggalkan oleh head tidak dapat digunakan kembali. Jika Anda enqueue 5 elemen lalu dequeue 5 elemen, queue akan kosong (isEmpty benar), tetapi juga isFull (karena tail ada di akhir array), sehingga tidak bisa diisi lagi.

queue3.cpp mengimplementasikan Alternatif 3 (Head dan Tail berputar), yang dikenal sebagai Circular Queue. Ini adalah implementasi yang paling efisien dan umum digunakan untuk queue berbasis array. Kedua pointer, head dan tail, bergerak menggunakan operasi modulo (% MAKSIMAL). Ini memungkinkan tail untuk "melompat" kembali ke indeks 0 setelah mencapai indeks 4 (jika indeks 0 kosong), dan head melakukan hal yang sama. Metode ini secara efektif menggunakan semua slot array tanpa ada ruang terbuang dan mempertahankan operasi enqueue dan dequeue yang sangat cepat (O(1)). Logika isFull dan printInfo di sini sedikit lebih kompleks untuk menangani kasus di mana tail mungkin "membungkus" dan memiliki nilai indeks yang lebih kecil dari head.

## Kesimpulan
Queue (Antrian) adalah sebuah struktur data linier fundamental yang beroperasi berdasarkan prinsip FIFO (First In First Out) , di mana elemen yang pertama kali dimasukkan adalah elemen yang pertama kali akan dikeluarkan atau dilayani. Berbeda dari stack, operasi queue terjadi di dua ujung terpisah: operasi penyisipan (disebut Enqueue) dilakukan di bagian belakang (disebut Tail atau Rear), dan operasi pengambilan (disebut Dequeue) dilakukan di bagian depan (disebut Head atau Front). Sebagai sebuah Abstract Data Type (ADT), queue dapat diimplementasikan dengan dua cara utama: secara statis menggunakan array (baik sebagai Linear Array maupun Circular Array ) dengan variabel integer untuk melacak indeks head dan tail , atau secara dinamis menggunakan pointer (linked list). Dalam aplikasi praktis, queue sangat penting untuk mengelola antrian secara adil, seperti yang ditunjukkan dalam implementasi sistem antrian pasien online berbasis web untuk mencegah kecurangan dan ketidakteraturan.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
</br>[2] Gunawan, R., Yuana, H., & Kirom, S. (2023). IMPLEMENTASI METODE QUEUE PADA SISTEM ANTRIAN ONLINE BERBASIS WEB STUDI KASUS UPTD PUSKESMAS SANANWETAN. Blitar: Universitas Islam Balitar Blitar.