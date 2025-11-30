#include "bstree3.h"
#include <iostream>

using namespace std;

address alokasi(infotype x) {
    address newNode = new Node;
    newNode->info = x;
    newNode->left = Nil;
    newNode->right = Nil;
    return newNode;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}


void printPreorder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";    
        printPreorder(root->left);      
        printPreorder(root->right);     
    }
}

void printPostorder(address root) {
    if (root != Nil) {
        printPostorder(root->left);     
        printPostorder(root->right);    
        cout << root->info << " - ";    
    }
}