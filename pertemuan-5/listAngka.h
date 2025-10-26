#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
#include <cstddef> 

using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka Angka;
    address Next;
};

struct linkedList {
    address First;
};

void CreateList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &node);

void insertFirst(linkedList &L, address nodeBaru);
void insertLast(linkedList &L, address nodeBaru);
void insertAfter(linkedList &L, address nodeBaru, address nodePrev);

void delAfter(linkedList &L, address &nodeHapus, address nodePrev);
void printList(linkedList L);
int nbList(linkedList L);

void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address nodePrev);

void SearchByData(linkedList L, dataAngka data);
void SearchByAddress(linkedList L, address node);
void SearchByRange(linkedList L, dataAngka nilaiMin);

#endif