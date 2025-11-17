#include <iostream>
#include "SLLInventory.h"

using namespace std;

int main() {
    List L;
    createList(L);
    
    Product P, P_deleted;

    P = {"Pulpen", "A001", 20, 2500, 0};
    insertLast(L, P);
    P = {"Buku Tulis", "A002", 15, 5000, 10};
    insertLast(L, P);
    P = {"Penghapus", "A003", 30, 1500, 0};
    insertLast(L, P);

    viewList(L);
    cout << endl;

    deleteFirst(L, P_deleted);;
    viewList(L);
    cout << endl;

    Product P_update = {"Stabilo", "A010", 40, 9000, 5}; 
    updateAtPosition(L, 2, P_update);
    cout << endl;

    viewList(L);
    cout << endl;

    searchByFinalPriceRange(L, 2000, 7000);
    cout << endl;

    MaxHargaAkhir(L);
    cout << endl;

    return 0;
}