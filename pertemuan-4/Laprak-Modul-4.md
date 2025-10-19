# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Petama)</h1>
<p align="center">Aedil Riski Ansyah - 103112400101</p>

## Dasar Teori
Abstract Data Type (ADT) atau Tipe Data Abstrak adalah model matematis dari objek data yang disempurnakan dengan cara mengaitkannya dengan fungsi-fungsi yang beroperasi pada data yang bersangkutan [1]. Secara mendasar, ADT merupakan tipe data yang didefinisikan oleh pemrogram untuk mempermudah proses pemrograman serta mengakomodasi tipe-tipe data yang tidak disediakan secara spesifik oleh bahasa pemrograman yang digunakan [1]. Konsep ini memisahkan struktur penyimpanan dari perilaku tipe data yang abstrak, seperti tumpukan (Stack) atau antrian (Queue) [1]. Sebuah ADT tidak hanya menunjukkan bagaimana data diorganisir, tetapi juga mencakup operasi-operasi yang dapat dilakukan terhadap struktur data tersebut [1]. Dengan demikian, implementasi ADT dapat dipandang sebagai gabungan antara struktur data dengan operasi-operasi yang berlaku padanya [1].

Penggunaan ADT menawarkan keuntungan signifikan dalam pengembangan sistem yang bersifat modular, memungkinkan suatu sistem dikembangkan oleh beberapa orang anggota tim secara terpisah dengan tetap menjaga keterpaduan [1]. Hal ini dimungkinkan karena pemrogram yang menggunakan ADT tidak perlu mengetahui bagaimana detail implementasi internalnya [1]. Jika terjadi perubahan pada implementasi, program pengguna tidak akan terpengaruh secara keseluruhan, asalkan antarmuka ADT dengan "dunia luar" tetap dipertahankan [1]. ADT memperluas konsep User Defined Type (UDT) dengan menambahkan prinsip enkapsulasi, yang berarti ADT berisi sifat-sifat dan operasi-operasi yang bisa dilakukan terhadap kelas tersebut [1].

Dalam praktiknya, ADT diwujudkan melalui tipe data bentukan yang didefinisikan oleh pengguna (user defined data type) [1, 2]. Bahasa pemrograman C++ menyediakan mekanisme untuk ini, salah satunya melalui kata kunci struct [1, 2]. Struct adalah tipe data bentukan yang berisi kumpulan variabel yang bernaung dalam satu nama yang sama dan memiliki kaitan satu sama lain [1]. Berbeda dengan array, struct bisa memiliki variabel-variabel dengan tipe data yang berbeda [1]. Selain itu, kata kunci typedef dapat digunakan untuk membuat nama tipe data baru dari tipe data yang sudah ada, sehingga mempermudah deklarasi dalam program [1].

## Guided 

### 1. Singly Linked List 1

list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL 

#include <iostream>
using namespace std;

struct  mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif 
```

list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

Program ini adalah sebuah contoh penerapan konsep ADT dalam C++ untuk mengelola data mata pelajaran secara terorganisir. ADT ini dipecah menjadi tiga file: pelajaran.h yang berfungsi sebagai kerangka untuk mendefinisikan struktur pelajaran dan mendeklarasikan fungsi-fungsinya, pelajaran.cpp yang berisi implementasi atau logika kerja dari fungsi-fungsi tersebut, dan main.cpp yang bertindak sebagai program utama. Pada intinya, program utama menggunakan ADT ini untuk membuat sebuah data pelajaran "Struktur Data" dengan memanggil fungsi create_pelajaran dan kemudian menampilkannya menggunakan tampil_pelajaran.

### 1. Singly Linked List 2

list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL 

#include <iostream>
using namespace std;

struct  mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif 
```

list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```

main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

Program ini adalah sebuah contoh penerapan konsep ADT dalam C++ untuk mengelola data mata pelajaran secara terorganisir. ADT ini dipecah menjadi tiga file: pelajaran.h yang berfungsi sebagai kerangka untuk mendefinisikan struktur pelajaran dan mendeklarasikan fungsi-fungsinya, pelajaran.cpp yang berisi implementasi atau logika kerja dari fungsi-fungsi tersebut, dan main.cpp yang bertindak sebagai program utama. Pada intinya, program utama menggunakan ADT ini untuk membuat sebuah data pelajaran "Struktur Data" dengan memanggil fungsi create_pelajaran dan kemudian menampilkannya menggunakan tampil_pelajaran.


## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file "Singlylist.h":
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-4/modul4-soal1-1.png)
### Kemudian buat implementasi ADT Singly Linked list pada file "Singlylist.cpp". Adapun isi data
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-4/modul4-soal1-2.png)
### Cobalah hasil implementasi ADT pada file "main.cpp"
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-4/modul4-soal1-3.png)

Singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED
#include <iostream>
#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info; 
    address next; 
};

struct List {
    address First;
};

void CreateList(List &L); 
address alokasi(infotype x); 
void dealokasi(address &P);
void insertFirst(List &L, address P); 
void printInfo(List L); 


#endif
```
Singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) { 
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x; 
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) { 
    delete P;
    P = Nil; 
}

void insertFirst(List &L, address P) { 
    P->next = L.First; 
    L.First = P; 
}

void printInfo(List L) { 
    address P = L.First;
    while (P != Nil) { 
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
```
main.cpp
```C++
int main() { 
    List L; 
    address P1, P2, P3, P4, P5 = Nil; 

    CreateList(L); 
    P1 = alokasi(2); 
    insertFirst(L, P1); 
    P2 = alokasi(0); 
    insertFirst(L, P2); 
    P3 = alokasi(8); 
    insertFirst(L, P3); 
    P4 = alokasi(12); 
    insertFirst(L, P4); 
    P5 = alokasi(9); 
    insertFirst(L, P5); 
    printInfo(L); 

    return 0; 
} 
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-4/output1-soal1-modul4.png)

Program ini adalah contoh penerapan konsep ADT untuk mengelola data akademik mahasiswa secara terstruktur. Kode dipecah menjadi tiga file: mahasiswa.h yang berfungsi sebagai interface yang mendefinisikan struct Mahasiswa dan mendeklarasikan fungsi untuk input data, perhitungan nilai akhir, serta penampilan data. File mahasiswa.cpp kemudian menyediakan implementasi atau logika kerja dari fungsi-fungsi tersebut, termasuk rumus perhitungan nilai akhir dari komponen UTS, UAS, dan tugas. Terakhir, main.cpp bertindak sebagai program utama yang menggunakan ADT ini untuk membuat sebuah array mahasiswa, memanggil fungsi untuk mengisi data dari input pengguna, dan kemudian menampilkan kembali seluruh data yang telah diproses ke layar. 

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList(). Output yang diharapkan :
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-4/modul4-soal2.png)

Singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED
#include <iostream>
#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address Prec);
int nbList(List L);
void deleteList(List &L);
address findElm(List L, infotype x);


#endif 
```
Singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First; 
        L.First = L.First->next; 
        P->next = Nil; 
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First->next == Nil) {
        P = L.First;
        L.First = Nil;
    } else {
        address Q = L.First;
        while (Q->next->next != Nil) {
            Q = Q->next;
        }
        P = Q->next; 
        Q->next = Nil; 
    }
}

void deleteAfter(List &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next; 
        Prec->next = P->next; 
        P->next = Nil; 
    } else {
        P = Nil; 
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P = Nil;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
```
main.cpp
```C++
#include <iostream>
#include "Singlylist.h" 
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    address P_hapus; 

    CreateList(L);
    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);

    deleteFirst(L, P_hapus);
    dealokasi(P_hapus); 
    deleteLast(L, P_hapus);
    dealokasi(P_hapus);
    address Prec = findElm(L, 12);
    if (Prec != Nil) {
        deleteAfter(L, P_hapus, Prec);
        dealokasi(P_hapus);
    }

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-4/output1-soal2-modul4.png)

Program ini adalah sebuah contoh penerapan konsep ADT untuk mengelola data mata pelajaran secara terstruktur. Kode dipecah menjadi tiga file: pelajaran.h yang berfungsi sebagai interface yang mendefinisikan struct pelajaran dan mendeklarasikan fungsi-fungsinya. File pelajaran.cpp menyediakan implementasi atau logika kerja dari fungsi-fungsi tersebut. Terakhir, main.cpp bertindak sebagai program utama yang menggunakan ADT ini untuk membuat sebuah data pelajaran "Struktur Data" dengan memanggil create_pelajaran dan kemudian menampilkannya ke layar menggunakan tampil_pelajaran.

## Kesimpulan
Abstract Data Type (ADT) merupakan konsep fundamental dalam pemrograman yang menekankan enkapsulasi, yaitu menggabungkan struktur data (seperti struct untuk Mahasiswa, pelajaran, atau Matriks) dengan operasi-operasi (fungsi) yang memanipulasinya ke dalam satu unit logis. Praktik ini secara efektif memisahkan antarmuka atau spesifikasi (dideklarasikan dalam file header .h) dari implementasi atau detail kode (didefinisikan dalam file .cpp). Dengan demikian, program utama (main.cpp) dapat menggunakan ADT sebagai "komponen" siap pakai tanpa perlu mengetahui kerumitan internalnya, sehingga menghasilkan kode yang lebih terstruktur, modular, mudah dikelola, dan dapat digunakan kembali (reusable).

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>