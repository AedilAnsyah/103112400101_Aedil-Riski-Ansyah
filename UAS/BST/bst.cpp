#include "BST.h"

Address alokasi(int id, string nama, int stok) {
    Address P = new Node;
    if (P != Nil) {
        P->idProduk = id;
        P->namaProduk = nama;
        P->stok = stok;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

void dealokasi(Address p) {
    delete p;
}

void insertNode(Address &root, int id, string nama, int stok) {
    if (root == Nil) {
        root = alokasi(id, nama, stok);
    } else {
        if (id < root->idProduk) {
            insertNode(root->left, id, nama, stok);
        }
        else if (id > root->idProduk) {
            insertNode(root->right, id, nama, stok);
        }
    }
}

Address searchById(Address root, int id) {
    if (root == Nil || root->idProduk == id) {
        return root;
    }
    if (id < root->idProduk) {
        return searchById(root->left, id);
    }
    return searchById(root->right, id);
}

void findByNameRec(Address root, string nama, bool &found) {
    if (root == Nil) return;
    if (root->namaProduk == nama) {
        cout << "[DITEMUKAN] ID: " << root->idProduk 
             << " | Nama: " << root->namaProduk 
             << " | Stok: " << root->stok << endl;
        found = true;
    }

    findByNameRec(root->left, nama, found);
    findByNameRec(root->right, nama, found);
}

void searchByProduct(Address root, string nama) {
    bool found = false;
    cout << "Mencari Nama '" << nama << "'... ";
    findByNameRec(root, nama, found);
    if (!found) {
        cout << "[TIDAK DITEMUKAN]" << endl;
    }
}

Address findMin(Address root) {
    if (root == Nil) return Nil;
    Address curr = root;
    while (curr->left != Nil) {
        curr = curr->left;
    }
    return curr;
}

Address findMax(Address root) {
    if (root == Nil) return Nil;
    Address curr = root;
    while (curr->right != Nil) {
        curr = curr->right;
    }
    return curr;
}

void deleteNode(Address &root, int id) {
    if (root == Nil) return;
    if (id < root->idProduk) {
        deleteNode(root->left, id);
    } else if (id > root->idProduk) {
        deleteNode(root->right, id);
    } else {
        Address temp;
        if (root->left == Nil) {
            temp = root->right;
            dealokasi(root);
            root = temp; 
        } else if (root->right == Nil) {
            temp = root->left;
            dealokasi(root);
            root = temp; 
        } else {
            temp = findMin(root->right);
            root->idProduk = temp->idProduk;
            root->namaProduk = temp->namaProduk;
            root->stok = temp->stok;
            deleteNode(root->right, temp->idProduk);
        }
    }
}

void deleteTree(Address &root) {
    if (root == Nil) return;
    deleteTree(root->left);
    deleteTree(root->right);
    dealokasi(root);
    root = Nil;
}

void inOrder(Address root) {
    if (root != Nil) {
        inOrder(root->left);
        cout << "ID: " << root->idProduk << endl;
        cout << "Nama: " << root->namaProduk << endl;
        cout << "Stok: " << root->stok << endl;
        cout << "-----------------" << endl;
        inOrder(root->right);
    }
}

void preOrder(Address root) {
    if (root != Nil) {
        cout << "(" << root->idProduk << ") " << root->namaProduk << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Address root) {
    if (root != Nil) {
        postOrder(root->left);
        postOrder(root->right);
        cout << "(" << root->idProduk << ") " << root->namaProduk << " ";
    }
}