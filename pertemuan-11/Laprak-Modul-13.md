# <h1 align="center">Laporan Praktikum Modul  13 - Multi Linked List</h1>
<p align="center">Aedil Riski Ansyah - 103112400101</p>

## Dasar Teori
Multi-Linked List adalah variasi dari struktur data linked list di mana setiap node memiliki lebih dari satu pointer untuk menunjuk ke node lain, berbeda dengan singly linked list yang hanya memiliki satu pointer [1]. Dalam struktur ini, setiap node dapat menampung beberapa field data dan beberapa field tautan, yang memungkinkan terbentuknya struktur data yang lebih kompleks daripada sekadar urutan linear [1]. Secara spesifik, sebuah node dalam multi-linked list sering kali memiliki struktur yang mencakup field data, satu tautan yang menunjuk ke node berikutnya dalam list utama, dan dua atau lebih tautan yang menunjuk ke list lain yang disebut sebagai sublist [2]. Struktur hierarkis ini terdiri dari node utama dan subnode, di mana node utama memiliki tautan ke kepala (head) dari sublist yang berasosiasi dengannya [2].

Salah satu motivasi utama penggunaan struktur ini adalah efisiensinya dalam menangani penyisipan dan penghapusan data dibandingkan dengan array, karena operasi tersebut hanya melibatkan pembaruan alamat pointer tanpa perlu menggeser elemen data lain [1]. Selain itu, linked list menawarkan penggunaan memori yang efisien karena bersifat dinamis, yang berarti memori dapat dialokasikan dan dealokasi kapan saja selama eksekusi program [1]. Namun, operasi penghapusan pada struktur ini memerlukan algoritma khusus; misalnya, saat sebuah node dihapus, prosedur destructor harus menelusuri dan menghapus seluruh subnode yang terhubung dengannya untuk mencegah kebocoran memori [2]. Di sisi lain, kelemahan dari struktur ini adalah akses ke elemen tertentu membutuhkan waktu lebih lama dibandingkan array karena tidak adanya indeks, sehingga diperlukan proses penelusuran (traversal) melewati node-node sebelumnya [1].

## Guided 

### 1. Multi Linked List

mll.h
```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

mll.cpp
```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```

main.cpp
```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```

Program ini merupakan implementasi dari struktur data Multi-Linked List (MLL) variasi Doubly Linked List untuk mengelola data menu restoran. Struktur data ini terdiri dari dua jenis list yang saling terhubung: List Induk (Parent) dan List Anak (Child). List Induk digunakan untuk menyimpan kategori makanan (seperti "Makanan Berat", "Minuman", "Dessert") di mana setiap simpul (node) parent memiliki pointer next dan prev serta sebuah list di dalamnya yang disebut L_Anak. Sementara itu, List Anak menyimpan detail item makanan (ID, nama, dan harga) yang terkait dengan kategori induknya. Dengan kata lain, setiap kategori (Parent) memiliki daftar menu makanannya sendiri (Child), membentuk hubungan hierarkis satu-ke-banyak (one-to-many). Fungsionalitas dasar program mencakup manajemen memori dan operasi penyisipan data. Fungsi Alokasi (alokasiNodeParent dan alokasiNodeChild) bertugas memesan memori baru untuk node dan menginisialisasi nilainya. Saat sebuah node parent dibuat, list anak di dalamnya otomatis diinisialisasi agar siap menampung data. Untuk menambahkan data, program menyediakan fungsi Insert (First, Last, dan After) baik untuk parent maupun child. Pada fungsi main, demonstrasi dilakukan dengan membuat tiga kategori utama, lalu mengisi setiap kategori dengan beberapa menu makanan spesifik menggunakan pointer yang merujuk ke parent yang bersangkutan.

Selain penyisipan, program ini menangani operasi pencarian, pembaruan, dan penghapusan data yang cukup kompleks karena struktur bersarangnya. Fungsi Pencarian (findChildByID) dan Update (updateDataChildByID) menggunakan logika perulangan bersarang (nested loop): program akan menelusuri setiap parent, dan untuk setiap parent, program akan menelusuri seluruh child di dalamnya untuk menemukan ID yang dicari. Fitur Penghapusan (Delete) dirancang dengan keamanan memori; ketika sebuah node parent dihapus (misalnya menggunakan deleteFirstParent atau deleteLastParent), program secara otomatis memanggil fungsi hapusListAnak terlebih dahulu untuk menghapus semua node child yang ada di dalamnya sebelum menghapus parent itu sendiri. Hal ini mencegah terjadinya kebocoran memori (memory leak). Terakhir, program memiliki fungsi Tampil Data (printStrukturMLL) yang memvisualisasikan seluruh hierarki menu. Fungsi ini akan mencetak data kategori (parent), kemudian langsung mencetak daftar makanan (child) di bawah kategori tersebut sebelum berpindah ke kategori berikutnya. Di dalam main.cpp, seluruh alur ini diuji secara berurutan: mulai dari inisialisasi list, penambahan data kategori dan makanan, pencarian data, pengubahan data (update harga/nama), hingga penghapusan item dan kategori, yang diakhiri dengan menampilkan sisa data untuk memastikan logika program berjalan dengan benar.


## Unguided 

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h” :
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-11/modul13-soal1-1.png)
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-11/modul13-soal1-2.png)
### Kemudian buatlah implementasi ADT Multi Linked List tersebut pada file “MultiLL.cpp”
### Kemudian pada file “main.cpp” lakukan operasi INSERT sebagaimana sehingga bentuk dari multi linked listnya seperti ini :
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-11/modul13-soal1-3.png)
### Setelah melakukan INSERT, lakukan operasi PRINT dengan memanggil prosedur
### printMLLStructure().
### (Lampirkan screenshot output hasil print pada laporan)
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-11/modul13-soal1-4.png)

MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};
struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot; 
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};
struct listChild {
    NodeChild first;
    NodeChild last;
};
struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child; 
};
struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev); 

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteListChild(listChild &LChild); 
void printMLLStructure(listParent LParent);

#endif
```

MultiLL.cpp
```C++
#include "MultiLL.h"

bool isEmptyParent(listParent LParent) {
    return LParent.first == NULL;
}

bool isEmptyChild(listChild LChild) {
    return LChild.first == NULL;
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child); 
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        deleteListChild(P->L_Child);
        
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = LParent.first->next;
            LParent.first->prev = NULL;
            P->next = NULL;
        }
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent P = NPrev->next;
        deleteListChild(P->L_Child);

        NPrev->next = P->next;
        if (P->next != NULL) {
            P->next->prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        P->next = NULL;
        P->prev = NULL;
        deallocNodeParent(P);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild C = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = LChild.first->next;
            LChild.first->prev = NULL;
            C->next = NULL;
        }
        deallocNodeChild(C);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild C = NPrev->next;
        NPrev->next = C->next;
        if (C->next != NULL) {
            C->next->prev = NPrev;
        } else {
            LChild.last = NPrev;
        }
        C->next = NULL;
        C->prev = NULL;
        deallocNodeChild(C);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent LParent) {
    if (isEmptyParent(LParent)) {
        cout << "List Parent Kosong" << endl;
        return;
    }

    NodeParent P = LParent.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "   ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "   Nama Golongan : " << P->isidata.namaGolongan << endl;

        if (isEmptyChild(P->L_Child)) {
            cout << "   (tidak ada child)" << endl;
        } else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << "   - Child " << j << " :" << endl;
                cout << "       ID Hewan : " << C->isidata.idHewan << endl;
                cout << "       Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "       Habitat : " << C->isidata.habitat << endl;
                cout << "       Ekor : " << C->isidata.ekor << endl;
                cout << "       Bobot : " << C->isidata.bobot << endl;
                
                C = C->next;
                j++;
            }
        }
        cout << "----------------------" << endl;
        P = P->next;
        i++;
    }
}
```

main.cpp 
```C++
#include "MultiLL.h" 

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P3);
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);
    NodeParent P5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P5);

    NodeChild C1_1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertLastChild(P1->L_Child, C1_1);
    NodeChild C1_2 = allocNodeChild("AV002", "Bebek", "Air", true, 2.0);
    insertLastChild(P1->L_Child, C1_2);
    NodeChild C2_1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200.0);
    insertLastChild(P2->L_Child, C2_1);
    NodeChild C2_2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160.0);
    insertLastChild(P2->L_Child, C2_2);
    NodeChild C2_3 = allocNodeChild("M002", "Kucing", "Darat", true, 4.0);
    insertLastChild(P2->L_Child, C2_3);
    NodeChild C4_1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(P4->L_Child, C4_1);

    printMLLStructure(LP);
    return 0;
}
```

### Output Unguided 1:

##### Output soal 1
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-11/output1-soal1-modul13.png)
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-11/output2-soal1-modul13.png)

Program ini membangun sistem klasifikasi hewan menggunakan struktur data Multi-Linked List bertipe Doubly Linked List, yang menciptakan hierarki dua tingkat layaknya folder dalam komputer. Tingkat utama adalah "List Parent" yang berisi kategori golongan (seperti Aves atau Mamalia), di mana setiap node kategori ini memiliki wadah internal ("List Child") untuk menyimpan daftar hewan spesifik (seperti Cendrawasih atau Harimau). Desain ini memungkinkan setiap kategori induk mengelola anggotanya secara independen, sementara penggunaan double pointer (next dan prev) memberikan fleksibilitas untuk menelusuri data baik secara maju maupun mundur di kedua tingkatan list. Secara operasional, program mensimulasikan pengisian database dengan terlebih dahulu menyusun node kategori (G001-G005), lalu menyisipkan data hewan ke dalam kategori yang relevan menggunakan fungsi penyisipan akhir (insertLast). Program ini juga menerapkan manajemen memori yang ketat: mekanisme penghapusan (delete) dirancang secara rekursif, di mana penghapusan sebuah kategori induk akan otomatis memicu pembersihan seluruh data hewan di dalamnya terlebih dahulu untuk mencegah kebocoran memori (memory leak). Proses ini diakhiri dengan fungsi cetak yang melakukan penelusuran menyeluruh (nested traversal) untuk menampilkan struktur hierarki hewan tersebut secara rapi ke layar terminal.

### 2. Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp. 
### Ekspektasi output : 
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-11/modul13-soal2.png)

MultiLL.h 
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor; 
    float bobot; 
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteListChild(listChild &LChild);

void printMLLStructure(listParent LParent);
void searchHewanByEkor(listParent LParent, bool tail);

#endif
```

MultiLL.cpp
```C++
#include "MultiLL.h"

bool isEmptyParent(listParent LParent) { 
    return LParent.first == NULL; 
}

bool isEmptyChild(listChild LChild) { 
    return LChild.first == NULL; 
}

void createListParent(listParent &LParent) { 
    LParent.first = NULL; 
    LParent.last = NULL; 
}

void createListChild(listChild &LChild) { 
    LChild.first = NULL; 
    LChild.last = NULL; 
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL; P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL; C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &NParent) { delete NParent; NParent = NULL; }
void deallocNodeChild(NodeChild &NChild) { delete NChild; NChild = NULL; }

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) { LParent.first = newNParent; LParent.last = newNParent; }
    else { newNParent->next = LParent.first; LParent.first->prev = newNParent; LParent.first = newNParent; }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) { LParent.first = newNParent; LParent.last = newNParent; }
    else { newNParent->prev = LParent.last; LParent.last->next = newNParent; LParent.last = newNParent; }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        deleteListChild(P->L_Child);
        if (LParent.first == LParent.last) { LParent.first = NULL; LParent.last = NULL; }
        else { LParent.first = LParent.first->next; LParent.first->prev = NULL; P->next = NULL; }
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent P = NPrev->next;
        deleteListChild(P->L_Child);
        NPrev->next = P->next;
        if (P->next != NULL) P->next->prev = NPrev;
        else LParent.last = NPrev;
        P->next = NULL; P->prev = NULL;
        deallocNodeParent(P);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) { LChild.first = newNChild; LChild.last = newNChild; }
    else { newNChild->next = LChild.first; LChild.first->prev = newNChild; LChild.first = newNChild; }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) { LChild.first = newNChild; LChild.last = newNChild; }
    else { newNChild->prev = LChild.last; LChild.last->next = newNChild; LChild.last = newNChild; }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild C = LChild.first;
        if (LChild.first == LChild.last) { LChild.first = NULL; LChild.last = NULL; }
        else { LChild.first = LChild.first->next; LChild.first->prev = NULL; C->next = NULL; }
        deallocNodeChild(C);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild C = NPrev->next;
        NPrev->next = C->next;
        if (C->next != NULL) C->next->prev = NPrev;
        else LChild.last = NPrev;
        C->next = NULL; C->prev = NULL;
        deallocNodeChild(C);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) { deleteFirstChild(LChild); }
}

void printMLLStructure(listParent LParent) {
    if (isEmptyParent(LParent)) { cout << "List Parent Kosong" << endl; return; }
    NodeParent P = LParent.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "   ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "   Nama Golongan : " << P->isidata.namaGolongan << endl;
        if (isEmptyChild(P->L_Child)) { cout << "   (tidak ada child)" << endl; }
        else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << "   - Child " << j << " :" << endl;
                cout << "       ID Hewan : " << C->isidata.idHewan << endl;
                cout << "       Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "       Habitat : " << C->isidata.habitat << endl;
                cout << "       Ekor : " << C->isidata.ekor << endl;
                cout << "       Bobot : " << C->isidata.bobot << endl;
                C = C->next; j++;
            }
        }
        cout << "----------------------" << endl;
        P = P->next; i++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    if (isEmptyParent(LParent)) {
        cout << "List Parent Kosong" << endl;
        return;
    }

    NodeParent P = LParent.first;
    int idxParent = 1;
    bool foundAny = false;

    while (P != NULL) {
        if (!isEmptyChild(P->L_Child)) {
            NodeChild C = P->L_Child.first;
            int idxChild = 1;
            while (C != NULL) {
                if (C->isidata.ekor == tail) {
                    foundAny = true;
                    cout << "Data ditemukan pada list anak dari node parent " << P->isidata.namaGolongan << " pada posisi ke-" << idxChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << C->isidata.idHewan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << idxChild << endl;
                    cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                    cout << "Habitat : " << C->isidata.habitat << endl;
                    cout << "Ekor : " << C->isidata.ekor << endl;
                    cout << "Bobot : " << C->isidata.bobot << endl;
                    cout << "-----------------------------------" << endl;
                    
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << P->isidata.idGolongan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << idxParent << endl;
                    cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                    cout << "-----------------------------------" << endl;
                }
                C = C->next;
                idxChild++;
            }
        }
        P = P->next;
        idxParent++;
    }
    
    if (!foundAny) {
        cout << "Tidak ada data hewan yang ditemukan dengan kriteria tersebut." << endl;
    }
}
```

main.cpp 
```C++
#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);
    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P3);
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);
    NodeParent P5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P5);

    NodeChild C1_1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertLastChild(P1->L_Child, C1_1);
    NodeChild C1_2 = allocNodeChild("AV002", "Bebek", "Air", true, 2.0);
    insertLastChild(P1->L_Child, C1_2);
    NodeChild C2_1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200.0);
    insertLastChild(P2->L_Child, C2_1);
    NodeChild C2_2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160.0); 
    insertLastChild(P2->L_Child, C2_2);
    NodeChild C2_3 = allocNodeChild("M002", "Kucing", "Darat", true, 4.0);
    insertLastChild(P2->L_Child, C2_3);
    NodeChild C4_1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2); 
    insertLastChild(P4->L_Child, C4_1);

    cout << "=== STRUKTUR AWAL ===" << endl;
    printMLLStructure(LP);
    cout << endl;

    cout << "=== PENCARIAN HEWAN (Ekor = FALSE) ===" << endl;
    searchHewanByEkor(LP, false);

    return 0;
}
```

### Output Unguided 2:

##### Output soal 2
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-11/output1-soal2-modul13.png)

Program ini mengimplementasikan struktur data Multi-Linked List (MLL) bertipe Doubly Linked List untuk merepresentasikan hierarki taksonomi hewan, di mana "List Induk" (Parent) menyimpan kategori golongan (seperti Mamalia atau Aves) dan setiap node induk memiliki "List Anak" (Child) yang berisi data hewan spesifik. Desain ini menggunakan pointer ganda (next dan prev) pada kedua level list, memungkinkan navigasi data dua arah yang fleksibel. Secara teknis, program mencakup manajemen memori dinamis yang lengkap, mulai dari alokasi node hingga mekanisme penghapusan aman, di mana penghapusan sebuah node induk akan secara otomatis memicu pembersihan seluruh node anak di dalamnya terlebih dahulu untuk mencegah kebocoran memori (memory leak). Pada eksekusi utamanya, program mensimulasikan pengisian data dengan menyusun lima kategori golongan dan menyisipkan berbagai hewan ke dalamnya secara spesifik. Fitur krusial yang ditambahkan adalah prosedur pencarian searchHewanByEkor yang melakukan penelusuran bersarang (nested traversal) kemudian memeriksa setiap node anak di dalam setiap node induk—untuk menemukan dan menampilkan detail hewan berdasarkan status kepemilikan ekor (dalam kasus ini mencari hewan dengan tail = false). Hasil akhir berupa visualisasi struktur hierarki lengkap beserta hasil pencarian spesifik ditampilkan ke layar untuk memverifikasi kebenaran logika penyimpanan dan penelusuran data tersebut.

### 3. Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linked listnya berubah menjadi seperi ini :
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-11/modul13-soal3-1.png)
### (Lampirkan screenshot output hasil print setelah dilakukan delete pada laporan).
### Ekspektasi output :
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-11/modul13-soal3-2.png)

MultiLL.h 
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor; 
    float bobot; 
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteListChild(listChild &LChild);

void printMLLStructure(listParent LParent);
void searchHewanByEkor(listParent LParent, bool tail);

#endif
```

MultiLL.cpp
```C++
#include "MultiLL.h"

bool isEmptyParent(listParent LParent) { 
    return LParent.first == NULL; 
}

bool isEmptyChild(listChild LChild) { 
    return LChild.first == NULL; 
}

void createListParent(listParent &LParent) { 
    LParent.first = NULL; 
    LParent.last = NULL; 
}

void createListChild(listChild &LChild) { 
    LChild.first = NULL; 
    LChild.last = NULL; 
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL; P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL; C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &NParent) { delete NParent; NParent = NULL; }
void deallocNodeChild(NodeChild &NChild) { delete NChild; NChild = NULL; }

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) { LParent.first = newNParent; LParent.last = newNParent; }
    else { newNParent->next = LParent.first; LParent.first->prev = newNParent; LParent.first = newNParent; }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) { LParent.first = newNParent; LParent.last = newNParent; }
    else { newNParent->prev = LParent.last; LParent.last->next = newNParent; LParent.last = newNParent; }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        deleteListChild(P->L_Child);
        if (LParent.first == LParent.last) { LParent.first = NULL; LParent.last = NULL; }
        else { LParent.first = LParent.first->next; LParent.first->prev = NULL; P->next = NULL; }
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent P = NPrev->next;
        deleteListChild(P->L_Child);
        NPrev->next = P->next;
        if (P->next != NULL) P->next->prev = NPrev;
        else LParent.last = NPrev;
        P->next = NULL; P->prev = NULL;
        deallocNodeParent(P);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) { LChild.first = newNChild; LChild.last = newNChild; }
    else { newNChild->next = LChild.first; LChild.first->prev = newNChild; LChild.first = newNChild; }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) { LChild.first = newNChild; LChild.last = newNChild; }
    else { newNChild->prev = LChild.last; LChild.last->next = newNChild; LChild.last = newNChild; }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild C = LChild.first;
        if (LChild.first == LChild.last) { LChild.first = NULL; LChild.last = NULL; }
        else { LChild.first = LChild.first->next; LChild.first->prev = NULL; C->next = NULL; }
        deallocNodeChild(C);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild C = NPrev->next;
        NPrev->next = C->next;
        if (C->next != NULL) C->next->prev = NPrev;
        else LChild.last = NPrev;
        C->next = NULL; C->prev = NULL;
        deallocNodeChild(C);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) { deleteFirstChild(LChild); }
}

void printMLLStructure(listParent LParent) {
    if (isEmptyParent(LParent)) { cout << "List Parent Kosong" << endl; return; }
    NodeParent P = LParent.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "   ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "   Nama Golongan : " << P->isidata.namaGolongan << endl;
        if (isEmptyChild(P->L_Child)) { cout << "   (tidak ada child)" << endl; }
        else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << "   - Child " << j << " :" << endl;
                cout << "       ID Hewan : " << C->isidata.idHewan << endl;
                cout << "       Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "       Habitat : " << C->isidata.habitat << endl;
                cout << "       Ekor : " << C->isidata.ekor << endl;
                cout << "       Bobot : " << C->isidata.bobot << endl;
                C = C->next; j++;
            }
        }
        cout << "----------------------" << endl;
        P = P->next; i++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    if (isEmptyParent(LParent)) {
        cout << "List Parent Kosong" << endl;
        return;
    }

    NodeParent P = LParent.first;
    int idxParent = 1;
    bool foundAny = false;

    while (P != NULL) {
        if (!isEmptyChild(P->L_Child)) {
            NodeChild C = P->L_Child.first;
            int idxChild = 1;
            while (C != NULL) {
                if (C->isidata.ekor == tail) {
                    foundAny = true;
                    cout << "Data ditemukan pada list anak dari node parent " << P->isidata.namaGolongan << " pada posisi ke-" << idxChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << C->isidata.idHewan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << idxChild << endl;
                    cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                    cout << "Habitat : " << C->isidata.habitat << endl;
                    cout << "Ekor : " << C->isidata.ekor << endl;
                    cout << "Bobot : " << C->isidata.bobot << endl;
                    cout << "-----------------------------------" << endl;
                    
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << P->isidata.idGolongan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << idxParent << endl;
                    cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                    cout << "-----------------------------------" << endl;
                }
                C = C->next;
                idxChild++;
            }
        }
        P = P->next;
        idxParent++;
    }
    
    if (!foundAny) {
        cout << "Tidak ada data hewan yang ditemukan dengan kriteria tersebut." << endl;
    }
}
```

main.cpp 
```C++
#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);
    NodeParent P3 = allocNodeParent("G003", "Pisces"); // Node sebelum G004
    insertLastParent(LP, P3);
    NodeParent P4 = allocNodeParent("G004", "Amfibi"); // Node yang akan dihapus
    insertLastParent(LP, P4);
    NodeParent P5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P5);

    NodeChild C1_1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertLastChild(P1->L_Child, C1_1);
    NodeChild C1_2 = allocNodeChild("AV002", "Bebek", "Air", true, 2.0);
    insertLastChild(P1->L_Child, C1_2);
    NodeChild C2_1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200.0);
    insertLastChild(P2->L_Child, C2_1);
    NodeChild C2_2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160.0); 
    insertLastChild(P2->L_Child, C2_2);
    NodeChild C2_3 = allocNodeChild("M002", "Kucing", "Darat", true, 4.0);
    insertLastChild(P2->L_Child, C2_3);
    NodeChild C4_1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2); 
    insertLastChild(P4->L_Child, C4_1);

    cout << "=== STRUKTUR AWAL ===" << endl;
    printMLLStructure(LP);
    cout << endl;

    cout << "=== PENCARIAN HEWAN (Ekor = FALSE) ===" << endl;
    searchHewanByEkor(LP, false);
    cout << endl;

    cout << "=== DELETE PARENT G004 (BESERTA CHILDNYA) ===" << endl;
    deleteAfterParent(LP, P3); 

    cout << endl << "=== STRUKTUR SETELAH DELETE ===" << endl;
    printMLLStructure(LP);

    return 0;
}
```

### Output Unguided 3:

##### Output soal 3
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-11/output1-soal3-modul13.png)
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-11/output2-soal3-modul13.png)

Program ini merupakan implementasi lanjut dari struktur data Multi-Linked List bertipe Doubly Linked List yang memodelkan hierarki taksonomi hewan, di mana setiap node induk (Golongan) memiliki list internal berisi node anak (Data Hewan). Aspek teknis yang ditonjolkan adalah manajemen memori yang aman dan manipulasi pointer yang presisi, khususnya pada operasi deleteAfterParent. Dalam kasus ini, penghapusan kategori "Amfibi" (G004) dilakukan dengan mereferensikan node sebelumnya yaitu "Pisces" (G003), sistem secara otomatis memanggil prosedur pembersihan anak untuk menghapus data "Kodok" terlebih dahulu sebelum memutus dan menyambungkan kembali rantai pointer antar-induk, sehingga mencegah terjadinya kebocoran memori (memory leak). Alur eksekusi program dalam main.cpp mensimulasikan siklus manipulasi data yang komprehensif, dimulai dari inisialisasi struktur awal yang memuat lima golongan hewan beserta anggotanya, dilanjutkan dengan fitur pencarian spesifik (searchHewanByEkor) yang menelusuri hierarki untuk menemukan hewan tanpa ekor seperti Gorila dan Kodok. Setelah pencarian, program mendemonstrasikan modifikasi struktural dengan menghapus node G004 menggunakan logika delete after, yang kemudian divalidasi melalui cetakan akhir (printMLLStructure) yang menampilkan struktur list yang telah diperbarui di mana kategori "Pisces" kini terhubung langsung dengan "Reptil" tanpa keberadaan "Amfibi".

## Kesimpulan
Multi Linked List merupakan pengembangan struktur data dinamis yang sangat efektif untuk merepresentasikan data dengan hubungan kompleks, seperti hierarki atau grid, melalui penggunaan node yang memiliki banyak pointer. Keunggulan utamanya terletak pada efisiensi manajemen memori dan kemudahan modifikasi struktur (penyisipan dan penghapusan) dibandingkan dengan array statis. Meskipun demikian, penggunaannya menuntut penanganan logika yang lebih rumit, terutama dalam memastikan integritas data saat penghapusan node induk beserta sublist-nya, serta mengatasi waktu akses data yang relatif lebih lambat akibat proses traversal.

## Referensi
[1] Patel, S. H., & Mahariba, A. J. (2019). Word Search Puzzle using Multi-Linked Lists. International Journal of Engineering and Advanced Technology (IJEAT), 8(4S2), 12-16.  
</br>[2] Stojisavljević, Đ., Brtka, E., Brtka, V., & Berković, I. (2015). Multi linked lists: an object-oriented approach. ICIST 2015 5th International Conference on Information Society and Technology, 391-396.