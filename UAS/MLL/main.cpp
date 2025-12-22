#include <iostream>
#include "mll.h"

using namespace std;

int main() {
    ListParent LP;
    createListParent(LP);
    address_parent P1, P2, P3, P4;
    address_child C;

    P4 = alokasiNodeParent("G004", "Romance");
    insertFirstParent(LP, P4);
    C = alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6);
    insertLastChild(P4->childs, C);
    C = alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6);
    insertLastChild(P4->childs, C);
    P3 = alokasiNodeParent("G003", "Horror");
    insertFirstParent(LP, P3);
    C = alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4);
    insertLastChild(P3->childs, C);
    P2 = alokasiNodeParent("G002", "Comedy");
    insertFirstParent(LP, P2);
    C = alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0);
    insertLastChild(P2->childs, C);
    C = alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8);
    insertLastChild(P2->childs, C);
    P1 = alokasiNodeParent("G001", "Action");
    insertFirstParent(LP, P1);
    C = alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6);
    insertLastChild(P1->childs, C);

    cout << ">> 3) PRINT STRUKTUR MLL (AWAL):" << endl;
    printStrukturMLL(LP);
    cout << ">> 4) SEARCH FILM RATING 8.0 - 8.5:" << endl;
    searchFilmByRatingRange(LP, 8.0, 8.5);
    cout << endl;
    cout << ">> 5) DELETE AFTER PARENT (PREV = G001, DELETE G002):" << endl;
    deleteAfterParent(LP, P1); 
    cout << "Penghapusan selesai." << endl << endl;
    cout << ">> 6) PRINT STRUKTUR MLL (SETELAH DELETE):" << endl;
    printStrukturMLL(LP);

    return 0;
}