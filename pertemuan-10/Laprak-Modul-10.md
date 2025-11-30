# <h1 align="center">Laporan Praktikum Modul 10 - Tree (Bagian Pertama)</h1>
<p align="center">Aedil Riski Ansyah - 103112400101</p>

## Dasar Teori
Rekursif adalah sebuah teknik penyelesaian masalah dengan cara memecah masalah menjadi sub-masalah yang lebih kecil dan sama jenisnya dengan masalah awal, lalu menyelesaikan sub-masalah tersebut secara berulang hingga mencapai kasus dasar. Teknik ini sering digunakan dalam ilmu komputer, matematika, dan linguistik. Rekursi dapat membantu mengurangi jumlah kode yang dibutuhkan, namun dalam beberapa kasus, penggunaan rekursi bisa lebih mahal secara memori dan performa dibandingkan dengan pengulangan (loop). Namun, ada beberapa kasus di mana rekursi bisa digunakan untuk menyelesaikan masalah yang lebih kompleks, yang tidak bisa atau sulit diselesaikan dengan loop biasa. Dalam pemrograman, rekursif sering digunakan untuk menyelesaikan permasalahan yang membutuhkan pemecahan matematika dan ilmu komputer . Namun, perlu diingat bahwa penggunaan rekursi harus dilakukan dengan bijak dan memperhatikan efisiensi dan memori, serta memahami algoritma yang menggunakan rekursi secara tidak langsung.

Decision Tree merupakan salah satu cara data processing dalam memprediksi masa depan dengan cara membangun klasifikasi atau regresi model dalam bentuk struktur pohon. Hal tersebut dilakukan dengan cara memecah terus ke dalam himpunan bagian yang lebih kecil lalu pada saat itu juga sebuah pohon keputusan secara bertahap dikembangkan. Hasil akhir dari proses tersebut adalah pohon dengan node keputusan dan node daun. Sebuah node keputusan (misalnya, Cuaca/ Outlook) memiliki dua atau lebih cabang (misalnya, Panas, Berawan dan Hujan).Decision Tree juga berguna untuk dieksplorasi data, menemukan hubungan antara sejumlah calon variabel input dengan sebuah variabel target. Pohon keputusan eksplorasi data dan pemodelan yang salah langkah pertama yang sangat baik dalam proses pemodelan yang digunakan sebagai model akhir untuk beberapa teknik lainnya.Kelebihan lain dari metode ini adalah mampu mengeliminasi perhitungan atau data-data yang tidak diperlukan. Karena sampel yang ada biasanya hanya diuji berdasarkan kriteria atau kelas tertentu.Meski memiliki banyak kelebihan, namun bukan berarti ini tidak memiliki kekurangan. Pohon keputusan ini mungkin tumpang tindih, terutama jika kelas dan kriteria yang digunakan sangat sering dapat meningkatkan waktu pengambilan keputusan sesuai dengan kapasitas memori yang diperlukan.


## Guided 

### 1. Implementasi BST

bst.h
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node;

struct BST {
    int angka;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```

bst.cpp
```C+
#include "bst.h"
#include <iostream>

using namespace std;
//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```

main.cpp
```C++

#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```

Program ini adalah implementasi dari struktur data queue (antrian) dalam C++ yang menggunakan pendekatan singly linked list. Strukturnya dibagi menjadi tiga file: queue.h sebagai file header, queue.cpp sebagai file implementasi, dan main.cpp sebagai program utama (driver) untuk menguji queue. File header queue.h mendefinisikan struktur Node, yang berisi string nama dan pointer next, serta struktur queue yang mengelola antrian dengan dua pointer: head (depan) dan tail (belakang). File queue.cpp menyediakan logika untuk fungsi-fungsi queue. CreateQueue menginisialisasi head dan tail ke nullptr. enQueue menambahkan elemen baru di akhir antrian (pada tail), sementara deQueue menghapus elemen dari awal antrian (pada head), dengan penanganan khusus untuk memastikan tail juga menjadi nullptr jika antrian menjadi kosong. File main.cpp adalah program yang menjalankan dan menguji fungsionalitas queue. Pertama, sebuah queue Q dibuat dan diinisialisasi. Program kemudian memanggil enQueue sebanyak enam kali, menambahkan nama "dhimas", "Arvin", "Rizal", "Hafizh", "Fathur", dan "Atha" secara berurutan. Setelah itu, viewQueue dipanggil untuk mencetak isi queue, yang menampilkan keenam nama tersebut. Selanjutnya, program memanggil deQueue sebanyak empat kali. Sesuai prinsip FIFO (First In First Out), ini akan menghapus empat nama pertama yang dimasukkan ("dhimas", "Arvin", "Rizal", dan "Hafizh"). Program kemudian memanggil viewQueue lagi untuk menampilkan isi queue yang tersisa, yaitu "Fathur" dan "Atha". Terakhir, clearQueue dipanggil untuk menghapus semua elemen yang tersisa sebelum program berakhir.

## Unguided 

### 1. Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”:
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-10/modul10-soal1-1.png)
### Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-10/modul10-soal1-2.png)
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-10/modul10-soal1-3.png)

bstree1.h
```C++
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
address findNode(infotype x, address root);
void printInorder(address root);

#endif
```

bstree1.cpp
```C++
#include "bstree1.h"
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
        } else {
            
        }
    }
}


address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) {
        return root;
    }
    if (x < root->info) {
        return findNode(x, root->left);
    }
    return findNode(x, root->right);
}

// Mencetak tree secara InOrder (Left - Root - Right)
void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}
```

main1.cpp
```C++
#include <iostream>
#include "bstree1.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;
    
    address root = Nil;
    
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6); 
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);
    

    printInorder(root);
    
    cout << endl;
    return 0;
}
```

Program C++ tersebut merupakan implementasi dari struktur data Binary Search Tree (BST) yang dipecah menjadi tiga file terpisah untuk modularitas: header (bstree1.h), implementasi fungsi (bstree1.cpp), dan program utama (main1.cpp). Pada file header, didefinisikan sebuah struktur Node yang memiliki tiga komponen utama, yaitu info untuk menyimpan data bertipe integer, serta dua pointer bertipe address (left dan right) yang menunjuk ke anak kiri dan kanan. File ini juga mendeklarasikan prototipe fungsi penting seperti alokasi untuk pembuatan node baru, insertNode untuk penambahan data, findNode untuk pencarian, dan printInorder untuk menampilkan isi pohon.

Logika utama program dijalankan pada file bstree1.cpp. Fungsi insertNode menggunakan pendekatan rekursif untuk menempatkan angka baru pada posisi yang tepat: jika angka lebih kecil dari nilai node saat ini, ia akan bergerak ke sub-pohon kiri, dan jika lebih besar, ke sub-pohon kanan. Logika ini juga menangani duplikasi data secara implisit, di mana jika nilai yang dimasukkan sama dengan nilai yang sudah ada (blok else kosong), maka data tersebut tidak akan ditambahkan lagi. Selain itu, terdapat fungsi printInorder yang melakukan penelusuran (traversal) dengan urutan Left-Root-Right, yang memiliki karakteristik khusus pada BST yaitu akan menghasilkan keluaran data yang terurut secara menaik (dari kecil ke besar).

Pada file main1.cpp, program menginisialisasi sebuah tree kosong dengan root bernilai NULL. Kemudian, serangkaian angka (1, 2, 6, 4, 5, 3, 6, 7) dimasukkan satu per satu menggunakan fungsi insertNode. Penting untuk dicatat bahwa angka '6' dicoba untuk dimasukkan dua kali, namun berkat logika pada fungsi insert, angka 6 yang kedua akan diabaikan sehingga tidak ada duplikasi dalam tree. Akhirnya, fungsi printInorder dipanggil untuk mencetak seluruh simpul yang telah disusun, yang akan menghasilkan urutan angka terurut: 1 - 2 - 3 - 4 - 5 - 6 - 7.

### 2.  Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
### ➢ fungsi hitungJumlahNode( root:address ) : integer
### /* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
### ➢ fungsi hitungTotalInfo( root:address, start:integer ) : integer
### /* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
### ➢ fungsi hitungKedalaman( root:address, start:integer ) : integer
### /* fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree */
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-10/modul10-soal2.png)

bstree2.h
```C++
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


int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

#endif
```

bstree2.cpp
```C++
#include "bstree2.h"
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

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start;
    }
    
    int kedalamanKiri = hitungKedalaman(root->left, start + 1);
    int kedalamanKanan = hitungKedalaman(root->right, start + 1);
    
    if (kedalamanKiri > kedalamanKanan) {
        return kedalamanKiri;
    } else {
        return kedalamanKanan;
    }
}
```

main2.cpp
```C++
#include <iostream>
#include "bstree2.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);
    
    printInorder(root);
    cout << "\n";
    
 
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;
    
    return 0;
}
```

Program C++ ini merupakan pengembangan lanjutan dari implementasi Binary Search Tree (BST) yang dirancang secara modular dalam tiga file: bstree2.h, bstree2.cpp, dan main2.cpp. Selain fitur standar seperti alokasi memori, penyisipan data (insertNode), dan pencetakan data secara terurut (printInorder), program ini diperkaya dengan tiga fungsi rekursif baru untuk analisis properti pohon. File header mendeklarasikan struktur pohon dan prototipe fungsi, sementara file implementasi mendefinisikan logika rekursi untuk menghitung jumlah total node, menjumlahkan seluruh nilai data (info), dan mengukur kedalaman maksimum atau tinggi pohon dari root hingga daun terjauh.

Logika utama dalam bstree2.cpp memanfaatkan kekuatan rekursi untuk menelusuri setiap cabang pohon. Fungsi hitungJumlahNode bekerja dengan mengembalikan nilai 0 jika node kosong, atau 1 ditambah hasil penjumlahan node di sub-pohon kiri dan kanan jika node ada. Serupa dengan itu, hitungTotalInfo mengakumulasikan nilai angka yang tersimpan di setiap node. Fungsi yang paling kompleks, hitungKedalaman, menelusuri pohon sambil membawa variabel counter (start); fungsi ini akan membandingkan kedalaman yang dicapai oleh sub-pohon kiri dan kanan, lalu mengembalikan nilai terbesar untuk menentukan tinggi maksimum pohon tersebut.

Pada bagian eksekusi di main2.cpp, sebuah pohon dibentuk dengan memasukkan angka-angka: 1, 2, 6, 4, 5, 3, 6, dan 7. Sistem penyisipan otomatis mencegah duplikasi, sehingga angka 6 yang dimasukkan kedua kali akan diabaikan. Setelah mencetak urutan angka yang telah terurut (1 sampai 7), program memanggil ketiga fungsi analisis tadi. Hasil akhirnya akan menampilkan statistik lengkap berupa kedalaman pohon (menunjukkan berapa level hierarki yang terbentuk), jumlah total node (sebanyak 7 node), serta total penjumlahan dari seluruh angka yang ada di dalam pohon.

### 3. Print tree secara pre-order dan post-order
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-10/modul10-soal3.png)

bstree3.h
```C++
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
```

bstree3.cpp
```C++
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
```

main3.cpp
```C++
#include <iostream>
#include "bstree3.h"

using namespace std;

int main() {
    address root = Nil;
    
    insertNode(root, 6); 
    insertNode(root, 4); 
    insertNode(root, 7); 
    insertNode(root, 2); 
    insertNode(root, 5); 
    insertNode(root, 1); 
    insertNode(root, 3); 
    
    cout << "Tampilan Pre-Order  : ";
    printPreorder(root);
    cout << endl;

    cout << "Tampilan Post-Order : ";
    printPostorder(root);
    cout << endl;
    
    return 0;
}
```

Program C++ ini merupakan implementasi modular dari struktur data Binary Search Tree (BST) yang terdiri dari file header (bstree3.h), file implementasi (bstree3.cpp), dan program utama (main3.cpp). Fokus utama pada variasi kode ini adalah penerapan metode penelusuran (traversal) pohon yang lebih lengkap. Selain fungsi dasar alokasi dan penyisipan node (insertNode) yang menyusun data secara rekursif (nilai kecil di kiri, besar di kanan), program ini mendefinisikan tiga jenis logika penelusuran: printInorder (Left-Root-Right), printPreorder (Root-Left-Right), dan printPostorder (Left-Right-Root).

Pada bagian eksekusi di main3.cpp, program membangun sebuah pohon dengan memasukkan angka-angka dalam urutan: 6, 4, 7, 2, 5, 1, dan 3, di mana angka 6 menjadi root utama. Berbeda dengan kode sebelumnya, program ini secara spesifik mendemonstrasikan perbedaan output antara metode Pre-Order dan Post-Order. Pre-Order akan mencetak root di awal sebelum menelusuri cabang, sementara Post-Order akan memproses seluruh anak cabang terlebih dahulu sebelum mencetak root. Hal ini memperlihatkan bagaimana struktur pohon yang sama dapat menghasilkan urutan data yang berbeda tergantung pada algoritma kunjungan yang digunakan.

### Output Unguided :

##### Output soal 1, 2, 3
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-10/output1-soal123-modul10.png)


## Kesimpulan
Implementasi Binary Search Tree (BST) merupakan contoh nyata penggunaan struktur data hierarkis yang efisien untuk pengelolaan data dinamis. Prinsip utamanya terletak pada aturan penempatan node secara otomatis, di mana nilai yang lebih kecil dari root ditempatkan di sub-pohon kiri dan nilai yang lebih besar ditempatkan di sub-pohon kanan. Secara teknis, struktur ini sangat bergantung pada algoritma rekursif, yaitu teknik memecah masalah utama menjadi sub-masalah yang lebih kecil untuk melakukan operasi esensial seperti penyisipan data, pencarian, hingga perhitungan statistik pohon seperti jumlah node dan kedalaman maksimum. Dalam pengembangan perangkat lunak, BST sering diimplementasikan dengan pendekatan modular yang memisahkan definisi struktur, logika fungsi, dan program eksekusi untuk menjaga keterbacaan kode. Selain itu, fleksibilitas BST terlihat pada berbagai metode penelusuran (traversal) seperti InOrder yang menghasilkan data terurut, serta PreOrder dan PostOrder yang digunakan untuk keperluan analisis struktur lainnya. Hal ini menjadikan BST sebagai solusi yang terstruktur dan mangkus untuk menangani operasi pencarian dan pengurutan data yang kompleks.

## Referensi
[1] Rahmawati, E., Medina, P., & Azhari, D. S. (2024). Rekursif Dalam Pemrograman: Teori Dan Praktek. Padang: Fakultas Ilmu Komputer UPI YPTK Padang.
</br>[2] Rizki, S. (2012). PENERAPAN TEORI GRAF UNTUK MENYELESAIKAN MASALAH MINIMUM SPANNING TREE (MST) MENGGUNAKAN ALGORITMA KRUSKAL. Lampung: Universitas Muhammadiyah Metro.