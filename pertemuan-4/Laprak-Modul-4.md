# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Petama)</h1>
<p align="center">Aedil Riski Ansyah - 103112400101</p>

## Dasar Teori
Linked list atau senarai berkait merupakan struktur data fundamental yang terdiri dari kumpulan data (disebut simpul atau node) yang tersusun secara sekuensial dan saling terhubung [1]. Berbeda dengan array yang ukurannya tetap, linked list bersifat dinamis, memungkinkan penambahan atau pengurangan elemen sesuai kebutuhan saat program berjalan [1]. Secara konseptual, linked list adalah rangkaian node yang dihubungkan secara linier menggunakan pointer [1]. Keunggulan utama linked list terletak pada efisiensinya saat menyisipkan atau menghapus data dibandingkan array, serta penggunaan alokasi memori dinamis yang fleksibel [1].

Setiap node dalam linked list umumnya memiliki dua bagian: medan informasi untuk menyimpan data (bisa berupa tipe data dasar atau struct) dan medan penyambung (pointer) yang berisi alamat node berikutnya dalam urutan [1, 2]. Sebuah pointer awal (sering disebut head atau first) menunjuk ke node pertama, sementara medan penyambung pada node terakhir menunjuk ke NULL untuk menandai akhir dari list [1].

Singly Linked List (SLL) adalah jenis linked list di mana setiap node hanya mempunyai satu pointer penyambung, yang secara spesifik menunjuk ke node berikutnya (next) [1]. Konsekuensinya, penelusuran (traversal) dalam SLL hanya dapat dilakukan dalam satu arah, yaitu maju dari awal ke akhir list [1]. Operasi dasar pada SLL meliputi pembuatan list kosong (CreateList), alokasi memori untuk node baru (Alokasi), dealokasi memori (Dealokasi), pengecekan kondisi kosong (IsEmpty), penyisipan node (di awal, akhir, atau tengah), penghapusan node (dari awal, akhir, tengah, atau menghapus seluruh list), penelusuran untuk menampilkan data (View/PrintInfo), dan pencarian node tertentu (Search) [1, 2]. Dalam implementasi C++, struktur node ini sering didefinisikan menggunakan struct [1, 2].

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

Program ini menerapkan singly linked list di C++ untuk mengelola data mahasiswa (nama, NIM, umur). File list.h mendefinisikan struktur data (mahasiswa, node, linkedlist) dan mendeklarasikan fungsi dasar seperti createList, alokasi, insertFirst, insertLast, insertAfter, dan printList. File list.cpp berisi implementasi detail dari fungsi tersebut, menangani logika pembuatan node, penyisipan di berbagai posisi, dan pencetakan list. Sedangkan main.cpp mendemonstrasikan cara menggunakan ADT ini dengan membuat list, mengalokasikan beberapa node mahasiswa, menyisipkannya ke dalam list menggunakan berbagai fungsi insert, dan kemudian mencetak isi akhir list tersebut.

### 2. Singly Linked List 2

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

Program C++ ini menerapkan singly linked list untuk menyimpan data mahasiswa (nama, NIM, umur). File list.h mendefinisikan struktur data (mahasiswa, node, linkedlist) dan mendeklarasikan fungsi untuk operasi dasar list, termasuk penyisipan (insertFirst, insertLast, insertAfter) dan penghapusan (delFirst, delLast, delAfter), serta fungsi utilitas seperti printList, nbList (menghitung jumlah node), dan deleteList (menghapus semua node). File list.cpp menyediakan implementasi detail untuk semua fungsi ini, mengatur logika manipulasi pointer. Program utama dalam main.cpp menggunakan ADT untuk membuat list, menambahkan beberapa node mahasiswa, mencetak list awal dan ukurannya, kemudian melakukan beberapa operasi penghapusan, mencetak list yang tersisa beserta ukurannya, dan akhirnya menghapus seluruh list lalu menampilkan kondisi akhirnya.


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

Program ini adalah contoh penerapan singly linked list untuk menyimpan data bertipe integer. File Singlylist.h mendefinisikan struktur node (ElmList) dan list (List), serta mendeklarasikan fungsi-fungsi dasar seperti CreateList (membuat list kosong), alokasi (membuat node baru), dealokasi (menghapus node), insertFirst (menambah node di awal), dan printInfo (mencetak isi list). File Singlylist.cpp berisi implementasi dari fungsi tersebut, menangani alokasi memori dan manipulasi pointer next. Program utama di main.cpp akan membuat sebuah list, mengalokasikan lima node dengan nilai integer (2, 0, 8, 12, 9), menyisipkan kelima node tersebut secara berurutan ke awal list menggunakan insertFirst, dan akhirnya mencetak isi list yang dihasilkan (yaitu 9 12 8 0 2) .

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

Program ini adalah sebuah contoh penerapan singly linked list untuk menyimpan data integer. File Singlylist.h mendefinisikan struktur node (ElmList) dan list (List), serta mendeklarasikan berbagai fungsi operasi list, termasuk pembuatan, alokasi/dealokasi memori, penyisipan (insertFirst), penghapusan (deleteFirst, deleteLast, deleteAfter), pencetakan (printInfo), penghitungan jumlah node (nbList), penghapusan seluruh list (deleteList), dan pencarian elemen (findElm). File Singlylist.cpp berisi implementasi detail dari semua fungsi tersebut. Program utama di main.cpp akan membuat list, menyisipkan elemen (9, 12, 8, 0, 2), melakukan serangkaian penghapusan (node pertama 9, node terakhir 2, dan node setelah 12 yaitu 8), mencetak list yang tersisa (12 0) beserta jumlah nodenya (2), lalu menghapus seluruh list dan menampilkan jumlah node akhir (0) .

## Kesimpulan
Singly Linked List (SLL) adalah struktur data linier dan dinamis yang terdiri dari rangkaian node. Setiap node menyimpan data (misalnya, informasi mahasiswa atau nilai integer) dan sebuah pointer tunggal (next) yang menunjuk ke node berikutnya dalam urutan. Karena hanya memiliki pointer next, penelusuran SLL hanya dapat dilakukan satu arah (maju) dari node pertama (yang ditunjuk oleh pointer First atau Head) hingga node terakhir yang ditandai dengan pointer next bernilai NULL. Operasi dasar pada SLL meliputi pembuatan list kosong, alokasi dan dealokasi memori untuk node secara dinamis, penyisipan node (di awal, akhir, atau setelah node lain), penghapusan node (dari awal, akhir, atau setelah node lain), pencetakan isi list, serta pencarian elemen.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>