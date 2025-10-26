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