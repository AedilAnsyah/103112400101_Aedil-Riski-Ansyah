#include "DLLPlaylist.h"

float calculatePopularity(Song S) {
    return (0.8*S.PlayCount) + (20.0*S.Rating);
}

address findAtPosition(List L, int posisi) {
    if (isEmpty(L) || posisi < 1) {
        return NULL;
    }
    address P = L.head;
    int currentPos = 1;
    while (P != NULL && currentPos < posisi) {
        P = P->next;
        currentPos++;
    }
    return P; 
}

bool isEmpty(List L) {
    return L.head == NULL && L.tail == NULL;
}

void createList(List &L) {
    L.head = NULL;
    L.tail = NULL;
}

address allocate(Song S) {
    address P = new Node;
    P->info = S;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void deallocate(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, Song S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = P;
        L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast(List &L, Song S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = P;
        L.tail = P;
    } else {
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}

void insertAfter(List &L, address Q, Song S) {
    if (Q == NULL) {
        cout << "tidak bisa insert after node null" << endl;
        return;
    }
    if (Q == L.tail) {
        insertLast(L, S);
    } else {
        address P = allocate(S);
        P->next = Q->next;
        P->prev = Q;
        Q->next->prev = P;
        Q->next = P;
    }
}

void insertBefore(List &L, address Q, Song S) {
    if (Q == NULL) {
        cout << "tidak bisa insert before node null" << endl;
        return;
    }
    if (Q == L.head) {
        insertFirst(L, S);
    } else {
        address P = allocate(S);
        P->prev = Q->prev;
        P->next = Q;
        Q->prev->next = P;
        Q->prev = P;
    }
}

void deleteFirst(List &L, Song &S) {
    if (isEmpty(L)) {
        cout << "list kosong" << endl;
        return;
    }
    address P = L.head;
    S = P->info;
    if (L.head == L.tail) { 
        L.head = NULL;
        L.tail = NULL;
    } else {
        L.head = P->next;
        L.head->prev = NULL;
        P->next = NULL;
    }
    deallocate(P);
}

void deleteLast(List &L, Song &S) {
    if (isEmpty(L)) {
        cout << "list kosong" << endl;
        return;
    }
    address P = L.tail;
    S = P->info; 
    if (L.head == L.tail) { 
        L.head = NULL;
        L.tail = NULL;
    } else {
        L.tail = P->prev;
        L.tail->next = NULL;
        P->prev = NULL;
    }
    deallocate(P);
}

void deleteAfter(List &L, address Q, Song &S) {
    if (Q == NULL || Q == L.tail || Q->next == NULL) {
        cout << "tidak bisa delete after node ini" << endl;
        return;
    }
    if (Q->next == L.tail) {
        deleteLast(L, S);
    } else {
        address P = Q->next;
        S = P->info;
        Q->next = P->next;
        P->next->prev = Q;
        P->next = NULL;
        P->prev = NULL;
        deallocate(P);
    }
}

void deleteBefore(List &L, address Q, Song &S) {
    if (Q == NULL || Q == L.head || Q->prev == NULL) {
        cout << "tidak bisa delete before node ini" << endl;
        return;
    }
    if (Q->prev == L.head) {
        deleteFirst(L, S);
    } else {
        address P = Q->prev;
        S = P->info;
        Q->prev = P->prev;
        P->prev->next = Q;
        P->next = NULL;
        P->prev = NULL;
        deallocate(P);
    }
}

void updateAtPosition(List &L, int posisi, Song S) {
    address P = findAtPosition(L, posisi);
    if (P != NULL) {
        P->info = S; 
    } else {
        cout << "posisi " << posisi << " tidak ditemukan" << endl;
    }
}

void updateBefore(List &L, address Q, Song S) {
    if (Q == NULL || Q == L.head || Q->prev == NULL) {
        cout << "tidak ada node sebelum node Q untuk di update" << endl;
    } else {
        Q->prev->info = S; 
    }
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "playlist kosong" << endl;
        return;
    }

    cout << "--- Isi Playlist ---" << endl;
    address P = L.head;
    int pos = 1;
    while (P != NULL) {
        Song S = P->info;
        float popScore = calculatePopularity(S);

        cout << "Posisi : " << pos << endl;
        cout << "  Title           : " << S.Title << endl;
        cout << "  Artist          : " << S.Artist << endl;
        cout << "  Duration        : " << S.DurationSec << "s" << endl;
        cout << "  PlayCount       : " << S.PlayCount << endl;
        cout << "  Rating          : " << fixed << setprecision(1) << S.Rating << endl;
        cout << "  PopularityScore : " << fixed << setprecision(2) << popScore << endl;
        cout << endl;

        P = P->next;
        pos++;
    }
    cout << fixed << setprecision(6); 
}

void searchByPopularityRange(List L, float minScore, float maxScore) {
    if (isEmpty(L)) {
        cout << "pencarian tidak bisa dilakukan karena playlist kosong" << endl;
        return;
    }

    cout << "\n--- Hasil Pencarian dengan Popularity: " << minScore << " - " << maxScore << " ---" << endl;
    address P = L.head;
    int pos = 1;
    bool found = false;
    while (P != NULL) {
        Song S = P->info;
        float popScore = calculatePopularity(S);

        if (popScore >= minScore && popScore <= maxScore) {
            found = true;
            cout << "Ditemukan pada Pos : " << pos << endl;
            cout << "  Title            : " << S.Title << endl;
            cout << "  Artist           : " << S.Artist << endl;
            cout << "  Popularity Score : " << fixed << setprecision(2) << popScore << endl;
        }

        P = P->next;
        pos++;
    }

    if (!found) {
        cout << "tidak ada lagu dalam rentang score tersebut" << endl;
    }
    cout << fixed << setprecision(6); 
}