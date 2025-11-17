#include "SLLInventory.h"
#include <iomanip> 

float calculateHargaAkhir(Product P) {
    return P.HargaSatuan * (1 - P.DiskonPersen / 100);
}

bool isEmpty(List L) {
    return L.head == NULL;
}

void createList(List &L) {
    L.head = NULL;
}

address allocate(Product P) {
    address newNode = new Node;
    newNode->info = P;
    newNode->next = NULL;
    return newNode;
}

void deallocate(address P) {
    delete P;
}

void insertFirst(List &L, Product P) {
    address newNode = allocate(P);
    newNode->next = L.head;
    L.head = newNode;
}

void insertLast(List &L, Product P) {
    address newNode = allocate(P);
    if (isEmpty(L)) {
        L.head = newNode;
    } else {
        address current = L.head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertAfter(List &L, address Q, Product P) {
    if (Q != NULL) {
        address newNode = allocate(P);
        newNode->next = Q->next;
        Q->next = newNode;
    }
}

void deleteFirst(List &L, Product &P) {
    if (!isEmpty(L)) {
        address temp = L.head;
        P = temp->info;
        L.head = temp->next;
        deallocate(temp);
    }
}

void deleteLast(List &L, Product &P) {
    if (!isEmpty(L)) {
        if (L.head->next == NULL) { 
            deleteFirst(L, P);
        } else {
            address current = L.head;
            while (current->next->next != NULL) {
                current = current->next;
            }
            address temp = current->next;
            P = temp->info; 
            current->next = NULL;
            deallocate(temp);
        }
    }
}

void deleteAfter(List &L, address Q, Product &P) {
    if (Q != NULL && Q->next != NULL) {
        address temp = Q->next;
        P = temp->info; 
        Q->next = temp->next;
        deallocate(temp);
    }
}

void updateAtPosition(List &L, int posisi, Product dataBaru) {
    address current = L.head;
    int count = 1;
    while (current != NULL && count < posisi) {
        current = current->next;
        count++;
    }
    if (current != NULL) { 
        current->info = dataBaru;
    } else {
        cout << "posisi " << posisi << " di luar range" << endl;
    }
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "list inventory kosong" << endl;
        return;
    }
    
    address current = L.head;
    int i = 1;
    cout << "--- Daftar Inventory ---" << endl;
    while (current != NULL) {
        Product P = current->info;
        float hargaAkhir = calculateHargaAkhir(P);
        
        cout << "Posisi : " << i << endl;
        cout << "  Nama         : " << P.Nama << endl;
        cout << "  SKU          : " << P.SKU << endl;
        cout << "  Jumlah       : " << P.Jumlah << endl;
        cout << "  Harga Satuan : " << P.HargaSatuan << endl;
        cout << "  Diskon       : " << P.DiskonPersen << "%" << endl;
        cout << "  Harga Akhir  : " << fixed << setprecision(2) << hargaAkhir << endl; // Tampilkan 2 angka desimal
        
        current = current->next;
        i++;
    }
}

void searchByFinalPriceRange(List L, float minPrice, float maxPrice) {
    cout << "--- Hasil Pencarian dalam Rentang Harga : " << minPrice << " - " << maxPrice << " ---" << endl;
    address current = L.head;
    int i = 1;
    bool found = false;
    
    while (current != NULL) {
        Product P = current->info;
        float hargaAkhir = calculateHargaAkhir(P);
        
        if (hargaAkhir >= minPrice && hargaAkhir <= maxPrice) {
            found = true;
            cout << "Ditemukan di Posisi : " << i << endl;
            cout << "  Nama         : " << P.Nama << endl;
            cout << "  SKU          : " << P.SKU << endl;
            cout << "  Harga Akhir  : " << fixed << setprecision(2) << hargaAkhir << endl;        }
        current = current->next;
        i++;
    }
    
    if (!found) {
        cout << "tidak ada produk dalam rentang harga tersebut" << endl;
    }
}

void MaxHargaAkhir(List L) {
    cout << "--- Produk Harga Akhir Tertinggi ---" << endl;
    if (isEmpty(L)) {
        cout << "list inventory kosong" << endl;
        return;
    }
    
    float maxHarga = -1.0;
    address current = L.head;
    while (current != NULL) {
        float hargaAkhir = calculateHargaAkhir(current->info);
        if (hargaAkhir > maxHarga) {
            maxHarga = hargaAkhir;
        }
        current = current->next;
    }

    current = L.head;
    int i = 1;
    while (current != NULL) {
        Product P = current->info;
        float hargaAkhir = calculateHargaAkhir(P);
        if (hargaAkhir == maxHarga) {
            cout << "Posisi : " << i << endl;
            cout << "  Nama         : " << P.Nama << endl;
            cout << "  SKU          : " << P.SKU << endl;
            cout << "  Harga Akhir  : " << fixed << setprecision(2) << hargaAkhir << endl;
        }
        current = current->next;
        i++;
    }
}