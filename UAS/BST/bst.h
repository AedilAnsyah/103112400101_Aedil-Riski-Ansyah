#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#define Nil NULL 

using namespace std;

struct Node {
    int idProduk;       // Key
    string namaProduk;
    int stok;
    Node *left;
    Node *right;
};

typedef Node* Address;
Address alokasi(int id, string nama, int stok); 
void dealokasi(Address p);
void insertNode(Address &root, int id, string nama, int stok); 
void deleteNode(Address &root, int id); 
void deleteTree(Address &root);

Address searchById(Address root, int id);
void searchByProduct(Address root, string nama); 
void findByNameRec(Address root, string nama, bool &found); 
Address findMin(Address root);
Address findMax(Address root);
void inOrder(Address root);
void preOrder(Address root);
void postOrder(Address root);

#endif