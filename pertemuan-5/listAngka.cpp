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