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