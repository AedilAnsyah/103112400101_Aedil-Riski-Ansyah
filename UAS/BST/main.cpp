#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    Address root = Nil; 

    cout << "=== 1) INPUT DATA ===" << endl;
    insertNode(root, 50, "Monitor LED", 10);
    insertNode(root, 30, "Keyboard RGB", 20);
    insertNode(root, 70, "Mouse Gaming", 15);
    insertNode(root, 20, "Kabel HDMI", 50);
    insertNode(root, 40, "Headset 7.1", 12);
    insertNode(root, 60, "Webcam HD", 8);
    insertNode(root, 80, "Speaker BT", 5);
    cout << "Data berhasil diinput\n" << endl;

    cout << "=== 2) TRAVERSAL AWAL ===" << endl;
    cout << "InOrder  : " << endl; 
    inOrder(root); cout << endl;
    cout << "PreOrder : " << endl; 
    preOrder(root); cout << endl;
    cout << "PostOrder: "<< endl; 
    postOrder(root); cout << endl;
    cout << endl;

    cout << "=== 3) SEARCH BY ID ===" << endl;
    int cariId = 40;
    cout << "Mencari ID " << cariId << "... ";
    Address hasil = searchById(root, cariId);
    if (hasil != Nil) cout << "[DITEMUKAN] " << hasil->namaProduk << endl;
    else cout << "[TIDAK DITEMUKAN]" << endl;

    cout << "=== 4) SEARCH BY ID ===" << endl;
    cariId = 99;
    cout << "Mencari ID " << cariId << "... ";
    hasil = searchById(root, cariId);
    if (hasil != Nil) cout << "[DITEMUKAN] " << hasil->namaProduk << endl;
    else cout << "[TIDAK DITEMUKAN]" << endl;
    cout << endl;

    cout << "=== 5) SEARCH BY PRODUCT ===" << endl;
    searchByProduct(root, "Webcam HD");
    cout << endl;

    cout << "=== 6) SEARCH BY PRODUCT ===" << endl;
    searchByProduct(root, "Printer");
    cout << endl;

    cout << "=== 7) FIND MIN & MAX ===" << endl;
    Address minNode = findMin(root);
    Address maxNode = findMax(root);
    if(minNode != Nil) cout << "Min ID: " << minNode->idProduk << " (" << minNode->namaProduk << ")" << endl;
    if(maxNode != Nil) cout << "Max ID: " << maxNode->idProduk << " (" << maxNode->namaProduk << ")" << endl;
    cout << endl;

    cout << "=== 8) DELETE NODE (20) - Leaf ===" << endl;
    cout << "Menghapus ID 20..." << endl;
    deleteNode(root, 20); 
    
    cout << "=== 9) INORDER SETELAH DELETE 20 ===" << endl;
    cout << "InOrder  : " << endl; 
    inOrder(root); cout << endl;

    cout << "=== 10) DELETE NODE (30) - 1 Child ===" << endl;
    cout << "Menghapus ID 30..." << endl;
    deleteNode(root, 30);

    cout << "=== 11) INORDER SETELAH DELETE 30 ===" << endl;
    cout << "InOrder  : " << endl; 
    inOrder(root); cout << endl;

    cout << "=== 12) DELETE NODE (50) - Root/2 Children ===" << endl;
    cout << "Menghapus ID 50..." << endl;
    deleteNode(root, 50);

    cout << "=== 13) INORDER SETELAH DELETE 50 ===" << endl;
    cout << "InOrder  : " << endl; 
    inOrder(root); cout << endl;

    cout << "=== 14) DELETE TREE ===" << endl;
    cout << "Menghapus seluruh tree..." << endl;
    deleteTree(root);
    
    cout << "=== 15) INORDER SETELAH DELETE TREE ===" << endl;
    cout << "InOrder  : " << endl; 
    if (root == Nil) cout << "(Tree Kosong)";
    else inOrder(root);
    cout << endl;

    return 0;
}