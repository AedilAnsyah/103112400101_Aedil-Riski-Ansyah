# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Aedil Riski Ansyah - 103112400101</p>

## Dasar Teori
Linked list atau senarai berkait merupakan struktur data fundamental yang terdiri dari kumpulan data (disebut simpul atau node) yang tersusun secara sekuensial dan saling terhubung [1]. Berbeda dengan array yang ukurannya tetap, linked list bersifat dinamis, memungkinkan penambahan atau pengurangan elemen sesuai kebutuhan saat program berjalan [1]. Secara konseptual, linked list adalah rangkaian node yang dihubungkan secara linier menggunakan pointer [1]. Keunggulan utama linked list terletak pada efisiensinya saat menyisipkan atau menghapus data dibandingkan array, serta penggunaan alokasi memori dinamis yang fleksibel [1].

Setiap node dalam linked list umumnya memiliki dua bagian: medan informasi untuk menyimpan data (bisa berupa tipe data dasar atau struct) dan medan penyambung (pointer) yang berisi alamat node berikutnya dalam urutan [1, 2]. Sebuah pointer awal (sering disebut head atau first) menunjuk ke node pertama, sementara medan penyambung pada node terakhir menunjuk ke NULL untuk menandai akhir dari list [1].

Singly Linked List (SLL) adalah jenis linked list di mana setiap node hanya mempunyai satu pointer penyambung, yang secara spesifik menunjuk ke node berikutnya (next) [1]. Konsekuensinya, penelusuran (traversal) dalam SLL hanya dapat dilakukan dalam satu arah, yaitu maju dari awal ke akhir list [1]. Operasi dasar pada SLL meliputi pembuatan list kosong (CreateList), alokasi memori untuk node baru (Alokasi), dealokasi memori (Dealokasi), pengecekan kondisi kosong (IsEmpty), penyisipan node (di awal, akhir, atau tengah), penghapusan node (dari awal, akhir, tengah, atau menghapus seluruh list), penelusuran untuk menampilkan data (View/PrintInfo), dan pencarian node tertentu (Search) [1, 2]. Dalam implementasi C++, struktur node ini sering didefinisikan menggunakan struct [1, 2].

## Guided 

### 1. Singly Linked List

listBuah.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
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
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

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

Program C++ ini adalah implementasi dari Abstract Data Type (ADT) Singly Linked List yang dirancang khusus untuk mengelola data buah, yang mencakup nama, jumlah, dan harga. Program ini dibagi menjadi tiga file yaitu listBuah.h yang berisi semua deklarasi struktur data (buah, node, linkedlist) dan prototipe fungsi, listBuah.cpp yang berisi implementasi detail dari semua fungsi tersebut, termasuk operasi dasar seperti create, alokasi, insert (first, last, after), delete (first, last, after), print, serta fungsi lanjutan seperti update (first, last, after) dan searching (berdasarkan data, alamat, dan rentang harga), dan main.cpp yang bertindak sebagai program utama untuk mendemonstrasikan penggunaan ADT tersebut. Dalam main.cpp, program secara berurutan melakukan inisialisasi list, menambahkan lima data buah, melakukan beberapa operasi update data, menguji berbagai fungsi pencarian, kemudian menghapus beberapa node, dan akhirnya menghapus keseluruhan list hingga kosong.


## Unguided 

### Buatlah ADT Singly Linked list sebagai berikut di dalam file “ListAngka.h” :
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-5/modul5-soalA.png)
### kemudian buatlah implementasi function & procedure tersebut pada file “listAngka.cpp”
### kemudian lakukan hal berikut pada file “main.cpp”
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-5/modul5-soalB.png)
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-5/modul5-soalC.png)
### Output yang diharapkan :
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-5/modul5-soalD.png)

### 1. Buatlah procedure updateFirst, updateLast, dan updateAfter dengan rincian sebagai berikut :
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-5/modul5-soal1-2.png)

### Kemudian pada “main.cpp” lakukanlah :
### ➢ Update data 40 menjadi 50
### ➢ Update data 8 menjadi 29
### ➢ Update data 33 menjadi 45
### ➢ Update data 18 menjadi 20
### ➢ Tampilkan seluruh list setelah diupdate
### Output yang diharapkan :
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-5/modul5-soal1-2.png)

### 2. Buatlah procedure SearchByData, SearchByAddress, dan SearchByRange dengan rincian sebagai berikut :
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-5/modul5-soal2-1.png)

### Kemudian pada “main.cpp” lakukanlah :
### ➢ Mencari data nilai 20
### ➢ Mencari data nilai 55
### ➢ Mencari data alamat nodeB
### ➢ Mencari data alamat nodeA
### ➢ Mencari data dengan nilai minimal 40
### Output yang diharapkan :
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-5/modul5-soal2-2.png)

### 3. Lakukanlah operasi aritmetika penjumlahan, pengurangan, dan perkalian terhadap semua data yang ada didalam list tersebut! Untuk penjumlahan nilai awal adalah 0, untuk pengurangan nilai awal adalah nilai node pertama (first), untuk perkalian nilai awal adalah 1.

### Output yang diharapkan :
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-5/modul5-soal3.png)

listAngka.h
```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
#include <cstddef> 

using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka Angka;
    address Next;
};

struct linkedList {
    address First;
};

void CreateList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &node);

void insertFirst(linkedList &L, address nodeBaru);
void insertLast(linkedList &L, address nodeBaru);
void insertAfter(linkedList &L, address nodeBaru, address nodePrev);

void delAfter(linkedList &L, address &nodeHapus, address nodePrev);
void printList(linkedList L);
int nbList(linkedList L);

void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address nodePrev);

void SearchByData(linkedList L, dataAngka data);
void SearchByAddress(linkedList L, address node);
void SearchByRange(linkedList L, dataAngka nilaiMin);

#endif
```

listAngka.cpp
```C++
#include "ListAngka.h"

void CreateList(linkedList &L) {
    L.First = NULL;
}

address alokasi(dataAngka x) {
    address P = new node;
    P->Angka = x;
    P->Next = NULL;
    return P;
}

void dealokasi(address &node) {
    delete node;
    node = NULL;
}

void printList(linkedList L) {
    address P = L.First;
    while (P != NULL) {
        cout << P->Angka << " - ";
        P = P->Next;
    }
    cout << endl;
}

void insertFirst(linkedList &L, address nodeBaru) {
    nodeBaru->Next = L.First;
    L.First = nodeBaru;
}

void insertLast(linkedList &L, address nodeBaru) {
    if (L.First == NULL) {
        insertFirst(L, nodeBaru);
    } else {
        address P = L.First;
        while (P->Next != NULL) {
            P = P->Next;
        }
        P->Next = nodeBaru;
    }
}

void insertAfter(linkedList &L, address nodeBaru, address nodePrev) {
    if (nodePrev != NULL) {
        nodeBaru->Next = nodePrev->Next;
        nodePrev->Next = nodeBaru;
    }
}

int nbList(linkedList L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        count++;
        P = P->Next;
    }
    return count;
}

void delAfter(linkedList &L, address &nodeHapus, address nodePrev) {
    if (nodePrev != NULL && nodePrev->Next != NULL) {
        nodeHapus = nodePrev->Next;
        nodePrev->Next = nodeHapus->Next;
        nodeHapus->Next = NULL;
    } else {
        nodeHapus = NULL;
    }
}

void updateFirst(linkedList &L) {
    if (L.First == NULL) {
        cout << "List kosong, tidak ada data untuk diupdate." << endl;
        return;
    }
    dataAngka newData;
    cout << "masukkan update data node pertama : ";
    cin >> newData;
    L.First->Angka = newData;
    cout << "Data Berhasil Diupdate!" << endl;
}

void updateLast(linkedList &L) {
    if (L.First == NULL) {
        cout << "List kosong, tidak ada data untuk diupdate." << endl;
        return;
    }
    
    address P = L.First;
    while (P->Next != NULL) {
        P = P->Next;
    }
    
    dataAngka newData;
    cout << "masukkan update data node terakhir : ";
    cin >> newData;
    P->Angka = newData;
    cout << "Data Berhasil Diupdate!" << endl;
}

void updateAfter(linkedList &L, address nodePrev) {
    if (nodePrev == NULL || nodePrev->Next == NULL) {
        cout << "Node_prev tidak valid atau tidak ada node setelahnya." << endl;
        return;
    }
    
    dataAngka newData;
    cout << "masukkan update data node setelah node " << nodePrev->Angka << " : ";
    cin >> newData;
    nodePrev->Next->Angka = newData;
    cout << "Data Berhasil Diupdate!" << endl;
}

void SearchByData(linkedList L, dataAngka data) {
    address P = L.First;
    int pos = 1;
    bool found = false;
    
    while (P != NULL) {
        if (P->Angka == data) {
            cout << "Data " << data << " ditemukan pada posisi ke-" << pos << "!" << endl;
            found = true;
            break;
        }
        P = P->Next;
        pos++;
    }
    
    if (!found) {
        cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
    }
}

void SearchByAddress(linkedList L, address nodeCari) {
    address P = L.First;
    int pos = 1;
    bool found = false;
    
    while (P != NULL) {
        if (P == nodeCari) {
            cout << "Node ditemukan pada posisi ke-" << pos << "!" << endl;
            cout << "Alamat node : " << P << endl;
            found = true;
            break;
        }
        P = P->Next;
        pos++;
    }
    
    if (!found) {
        cout << "Node dengan alamat " << nodeCari << " tidak ditemukan dalam list!" << endl;
    }
}

void SearchByRange(linkedList L, dataAngka nilaiMin) {
    cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
    address P = L.First;
    int pos = 1;
    bool found = false;
    
    while (P != NULL) {
        if (P->Angka > nilaiMin) {
            cout << "Data ditemukan pada posisi ke-" << pos << ", nilai : " << P->Angka << endl;
            found = true;
        }
        P = P->Next;
        pos++;
    }
    
    if (!found) {
        cout << "Tidak ada data yang ditemukan diatas nilai " << nilaiMin << endl;
    }
}
```

main.cpp
```C++
#include <iostream>
#include "ListAngka.h" 

using namespace std;

int main() {
    linkedList L;
    CreateList(L);
    
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF;
    
    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);
    
    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);
    
    address nodeHapus;
    delAfter(L, nodeHapus, nodeC); 
    dealokasi(nodeHapus); 
    
    cout << "Output yang diharapkan :" << endl;
    printList(L);
    cout << "------------------------------------------" << endl << endl;
    cout << "Kemudian Lakukanlah hal dibawah ini :" << endl << endl;
   
    updateFirst(L); 
    updateAfter(L, nodeD); 
    updateLast(L); 
    
    updateAfter(L, nodeF); 
    
    cout << endl;
    printList(L); 
    cout << "------------------------------------------" << endl << endl;

    SearchByData(L, 20);
    SearchByData(L, 55);
    
    address nodeG = alokasi(999); 
    SearchByAddress(L, nodeG);
    SearchByAddress(L, nodeA);
    
    dealokasi(nodeG); 
    cout << endl;
    SearchByRange(L, 40);
    cout << "------------------------------------------" << endl << endl;
    long long totalPenjumlahan = 0;
    long long totalPerkalian = 1;
    long long totalPengurangan = 0;
    
    address P = L.First;

    while (P != NULL) {
        totalPenjumlahan += P->Angka;
        P = P->Next;
    }
    cout << "Total penjumlahan : " << totalPenjumlahan << endl;

    if (L.First != NULL) {
        totalPengurangan = L.First->Angka; 
        P = L.First; 
        while (P != NULL) {
            totalPengurangan -= P->Angka; 
            P = P->Next;
        }
    }
    cout << "Total pengurangan : " << totalPengurangan << endl;

    P = L.First; 
    while (P != NULL) {
        totalPerkalian *= P->Angka;
        P = P->Next;
    }
    cout << "Total perkalian : " << totalPerkalian << endl;

    return 0;
}
```
### Output Unguided :

##### Output soal 1, 2, 3
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-5/output1-soal1-modul5.png)

Program ini adalah contoh penerapan singly linked list untuk menyimpan data bertipe integer. File Singlylist.h mendefinisikan struktur node (ElmList) dan list (List), serta mendeklarasikan fungsi-fungsi dasar seperti CreateList (membuat list kosong), alokasi (membuat node baru), dealokasi (menghapus node), insertFirst (menambah node di awal), dan printInfo (mencetak isi list). File Singlylist.cpp berisi implementasi dari fungsi tersebut, menangani alokasi memori dan manipulasi pointer next. Program utama di main.cpp akan membuat sebuah list, mengalokasikan lima node dengan nilai integer (2, 0, 8, 12, 9), menyisipkan kelima node tersebut secara berurutan ke awal list menggunakan insertFirst, dan akhirnya mencetak isi list yang dihasilkan (yaitu 9 12 8 0 2) .

## Kesimpulan
Singly linked list (SLL) adalah struktur data linier dan dinamis yang terdiri dari rangkaian node. Setiap node menyimpan data (misalnya, informasi mahasiswa atau nilai integer) dan sebuah pointer tunggal (next) yang menunjuk ke node berikutnya dalam urutan. Karena hanya memiliki pointer next, penelusuran SLL hanya dapat dilakukan satu arah (maju) dari node pertama (yang ditunjuk oleh pointer First atau Head) hingga node terakhir yang ditandai dengan pointer next bernilai NULL. Operasi dasar pada SLL meliputi pembuatan list kosong, alokasi dan dealokasi memori untuk node secara dinamis, penyisipan node (di awal, akhir, atau setelah node lain), penghapusan node (dari awal, akhir, atau setelah node lain), pencetakan isi list, serta pencarian elemen.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>