#include "mll.h"

void createListParent(ListParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(ListChild &L) {
    L.first = NULL;
    L.last = NULL;
}

address_parent alokasiNodeParent(string id, string nama) {
    address_parent P = new ElmParent;
    P->idGenre = id;
    P->namaGenre = nama;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->childs); 
    return P;
}

address_child alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    address_child C = new ElmChild;
    C->idFilm = id;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void dealokasiNodeParent(address_parent P) {
    delete P;
}

void dealokasiNodeChild(address_child C) {
    delete C;
}

void insertFirstParent(ListParent &L, address_parent P) {
    if (L.first == NULL) { 
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(ListChild &L, address_child C) {
    if (L.first == NULL) { 
        L.first = C;
        L.last = C;
    } else {
        C->prev = L.last;
        L.last->next = C;
        L.last = C;
    }
}

void hapusListChild(address_parent P) {
    address_child C = P->childs.first;
    address_child temp;
    while (C != NULL) {
        temp = C;
        C = C->next;
        dealokasiNodeChild(temp);
    }
    P->childs.first = NULL;
    P->childs.last = NULL;
}

void deleteAfterParent(ListParent &L, address_parent Prec) {
    if (Prec != NULL && Prec->next != NULL) {
        address_parent P = Prec->next; 
        hapusListChild(P);
        address_parent NextNode = P->next;
        Prec->next = NextNode;
        if (NextNode != NULL) {
            NextNode->prev = Prec;
        } else {
            L.last = Prec;
        }
        dealokasiNodeParent(P);
    }
}

void searchFilmByRatingRange(ListParent L, float minRate, float maxRate) {
    cout << "mencari film dengan rating " << minRate << " - " << maxRate << endl;
    address_parent P = L.first;
    int posParent = 1;
    while (P != NULL) {
        address_child C = P->childs.first;
        int posChild = 1;
        while (C != NULL) {
            if (C->ratingFilm >= minRate && C->ratingFilm <= maxRate) {
                cout << "===========================================" << endl;
                cout << "Data Film ditemukan pada list child dari node parent " << P->namaGenre 
                     << " pada posisi ke-" << posChild << "!" << endl;     
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film  : " << C->judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << posChild << endl;
                cout << "ID Film     : " << C->idFilm << endl;
                cout << "Durasi Film : " << C->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang: " << C->tahunTayang << endl;
                cout << "Rating Film : " << C->ratingFilm << endl;
                cout << "-------------------------" << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre    : " << P->idGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << posParent << endl;
                cout << "Nama Genre  : " << P->namaGenre << endl;
                cout << "===========================================" << endl;
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
        posParent++;
    }
}

void printStrukturMLL(ListParent L) {
    address_parent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre   : " << P->idGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;
        address_child C = P->childs.first;
        int j = 1;
        if (C == NULL) {
            cout << "   (Tidak ada film)" << endl;
        }
        while (C != NULL) {
            cout << "   - Child " << j << " :" << endl;
            cout << "       ID Film      : " << C->idFilm << endl;
            cout << "       Judul Film   : " << C->judulFilm << endl;
            cout << "       Durasi Film  : " << C->durasiFilm << " menit" << endl;
            cout << "       Tahun Tayang : " << C->tahunTayang << endl;
            cout << "       Rating Film  : " << C->ratingFilm << endl;
            C = C->next;
            j++;
        }
        P = P->next;
        i++;
    }
    cout << endl;
}

address_parent findParent(ListParent L, string idGenre) {
    address_parent P = L.first;
    while (P != NULL) {
        if (P->idGenre == idGenre) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}