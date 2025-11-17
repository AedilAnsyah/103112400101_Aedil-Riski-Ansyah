#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;


struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating; 
};

struct Node; 
typedef Node* address;

struct Node {
    Song info;
    address prev;
    address next;
};

struct List {
    address head;
    address tail;
};

bool isEmpty(List L);
void createList(List &L);
address allocate(Song S);
void deallocate(address &P);

void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, address Q, Song S);
void insertBefore(List &L, address Q, Song S);

void deleteFirst(List &L, Song &S); 
void deleteLast(List &L, Song &S);  
void deleteAfter(List &L, address Q, Song &S); 
void deleteBefore(List &L, address Q, Song &S);

void updateAtPosition(List &L, int posisi, Song S);
void updateBefore(List &L, address Q, Song S);

void viewList(List L);
void searchByPopularityRange(List L, float minScore, float maxScore);
float calculatePopularity(Song S);

address findAtPosition(List L, int posisi);


#endif 