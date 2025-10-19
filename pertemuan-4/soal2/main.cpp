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