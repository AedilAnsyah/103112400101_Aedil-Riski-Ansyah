#ifndef MLL_H
#define MLL_H
#include <iostream>
#include <string>
using namespace std;

typedef struct ElmChild* address_child;
typedef struct ElmParent* address_parent;

struct ElmChild {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    address_child next;
    address_child prev;
};

struct ListChild {
    address_child first;
    address_child last;
};

struct ElmParent {
    string idGenre;
    string namaGenre;
    ListChild childs; 
    address_parent next;
    address_parent prev;
};

struct ListParent {
    address_parent first;
    address_parent last;
};

void createListParent(ListParent &L);
void createListChild(ListChild &L);
address_parent alokasiNodeParent(string id, string nama);
address_child alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);

void dealokasiNodeParent(address_parent P);
void dealokasiNodeChild(address_child C);
void insertFirstParent(ListParent &L, address_parent P);
void insertLastChild(ListChild &L, address_child C);

void hapusListChild(address_parent P);
void deleteAfterParent(ListParent &L, address_parent Prec);
void searchFilmByRatingRange(ListParent L, float minRate, float maxRate);
void printStrukturMLL(ListParent L);
address_parent findParent(ListParent L, string idGenre);

#endif