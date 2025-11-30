#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
void printInorder(address root); 

void printPreorder(address root);  
void printPostorder(address root); 

#endif