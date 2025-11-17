#include <iostream>
#include "DLLPlaylist.h" 

using namespace std;

int main() {
    List L;
    Song S, S_out; 
    address Q;     

    createList(L);
    S = {"Senja di Kota", "Nona Band", 210, 150, 4.2};
    insertLast(L, S);
    S = {"Langkahmu", "Delta", 185, 320, 4.8};
    insertLast(L, S);
    S = {"Hujan Minggu", "Arka", 240, 90, 3.9};
    insertLast(L, S);
    viewList(L);

    deleteLast(L, S_out);
    S = {"Pelita", "Luna", 200, 260, 4.5};
    updateAtPosition(L, 2, S);
    viewList(L);

    Q = findAtPosition(L, 2); 
    S = {"Senandung", "Mira", 175, 120, 4.0};
    if (Q != NULL) {
        insertBefore(L, Q, S);
    }
    viewList(L);

    Q = findAtPosition(L, 2);
    S = {"Lagu Bebas", "Artis Bebas", 100, 50, 3.0}; 
    if (Q != NULL) {
        updateBefore(L, Q, S); 
    }
    viewList(L);

    Q = findAtPosition(L, 3);
    if (Q != NULL) {
        deleteBefore(L, Q, S_out); 
        cout << "Lagu yang dihapus: \"" << S_out.Title << "\"" << endl;
    }
    viewList(L);

    searchByPopularityRange(L, 150.0, 300.0);

    return 0;
}