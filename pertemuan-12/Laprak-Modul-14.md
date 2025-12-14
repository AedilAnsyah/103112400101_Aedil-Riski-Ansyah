# <h1 align="center">Laporan Praktikum Modul  14 - Graph</h1>
<p align="center">Aedil Riski Ansyah - 103112400101</p>

## Dasar Teori
Graph merupakan struktur data yang terdiri dari himpunan simpul (vertices/nodes) yang terhubung oleh garis penghubung yang disebut sisi (edges) [1]. Struktur ini digunakan untuk merepresentasikan objek-objek dan hubungan antar objek tersebut, seperti peta lokasi di mana tempat adalah vertex dan jalan penghubung adalah edge [2]. Secara umum, graph dapat dikategorikan menjadi dua jenis utama: Directed Graph (Graph Berarah) di mana setiap edge memiliki arah tujuan tertentu, dan Undirected Graph (Graph Tidak Berarah) di mana hubungan antar simpul bersifat dua arah atau tidak memiliki orientasi spesifik [1]. Selain itu, terdapat Weighted Graph di mana setiap edge memiliki nilai atau bobot numerik, yang sering digunakan untuk merepresentasikan biaya, jarak, atau kapasitas dalam suatu jaringan [1].

Dalam representasi komputasi, graph dapat diimplementasikan menggunakan Adjacency Matrix (Array 2 Dimensi) atau Adjacency List (Multi Linked List) [1]. Adjacency Matrix menggunakan matriks n x n untuk menyimpan status keterhubungan antar simpul, yang mudah diimplementasikan namun memakan banyak memori (O(V^2)) terutama pada sparse graph [1]. Sebaliknya, representasi menggunakan Multi Linked List bersifat dinamis dan lebih efisien dalam penggunaan memori karena hanya menyimpan simpul yang terhubung saja, di mana simpul induk menunjuk pada simpul anak (tetangga) melalui pointer [1]. Untuk menelusuri data di dalam graph, terdapat dua metode traversal utama yaitu Breadth First Search (BFS) yang mengunjungi simpul berdasarkan kedalaman level, dan Depth First Search (DFS) yang menelusuri cabang hingga simpul terdalam sebelum kembali (backtracking) [1].


## Guided 

### 1. Graph

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrNode Next;
    adrEdge firstEdge;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrEdge AlokasiEdge(adrNode nodeTujuan);

void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
void DisconnectNode(adrNode node1, adrNode node2);
void DeleteNode(Graph &G, infoGraph X);

void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintBFS(Graph G, infoGraph StartInfo);
void PrintDFS(Graph G, infoGraph StartInfo);

#endif 
```

graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS
using namespace std;
int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL) {
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');

    return 0;
}
```

Program ini mengimplementasikan struktur data Graph Tak Berarah (Undirected Graph) menggunakan representasi Adjacency List dalam bahasa C++. Dalam struktur ini, setiap titik atau simpul (Node) disimpan dalam sebuah linked list utama, di mana setiap simpul memiliki pointer ke sub-list berisi Edge yang merepresentasikan hubungan ketetanggaannya dengan simpul lain. Karena bersifat undirected, fungsi ConnectNode secara otomatis membuat hubungan dua arah (bolak-balik) antara dua simpul yang dihubungkan. Program ini juga menangani manajemen memori yang kompleks, khususnya pada fungsi DeleteNode, yang memastikan integritas data dengan cara memutus semua koneksi yang mengarah ke simpul target dan menghapus semua koneksi yang keluar darinya sebelum simpul tersebut benar-benar dihapus dari memori.

Selain manipulasi struktur, program menyediakan fitur penelusuran (traversal) menggunakan algoritma Breadth-First Search (BFS) dan Depth-First Search (DFS). Implementasi BFS memanfaatkan pustaka queue untuk mengunjungi simpul secara melebar (per level), sedangkan DFS menggunakan pustaka stack untuk menelusuri jalur hingga kedalaman maksimum sebelum kembali (backtracking). Pada fungsi utama (main), simulasi dilakukan dengan membangun graf berisi simpul A hingga F beserta koneksinya, menampilkan struktur tetangga, melakukan penelusuran, lalu menghapus simpul 'E' untuk mendemonstrasikan bagaimana struktur graf dan hasil penelusuran berubah secara dinamis setelah penghapusan elemen.


## Unguided 

### 1. Buatlah ADT Graph tidak berarah file “graph.h”:
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-12/modul14-soal1-1.png)
### Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-12/modul14-soal1-2.png)
### 2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
### prosedur PrintDFS (Graph G, adrNode N);
### 3. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
### prosedur PrintBFS (Graph G, adrNode N);

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited; 
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node; 
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);

adrNode AlokasiNode(infoGraph X);
adrEdge AlokasiEdge(adrNode N);

void InsertNode(Graph &G, infoGraph X);
void ConnectNode(Graph &G, infoGraph X1, infoGraph X2); 
adrNode FindNode(Graph G, infoGraph X);

void PrintInfoGraph(Graph G);

void PrintDFS(Graph G, infoGraph StartInfo);
void PrintBFS(Graph G, infoGraph StartInfo);

#endif
```

graph.cpp
```C++
#include "graph.h"
#include <queue> 
#include <stack> 

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AlokasiNode(infoGraph X) {
    adrNode N = new ElmNode;
    N->info = X;
    N->visited = 0;
    N->firstEdge = NULL;
    N->Next = NULL;
    return N;
}

adrEdge AlokasiEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode N = AlokasiNode(X);
    if (G.first == NULL) {
        G.first = N;
    } else {
        adrNode temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = N;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode curr = G.first;
    while (curr != NULL) {
        if (curr->info == X) {
            return curr;
        }
        curr = curr->Next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph X1, infoGraph X2) {
    adrNode N1 = FindNode(G, X1);
    adrNode N2 = FindNode(G, X2);

    if (N1 != NULL && N2 != NULL) {
        adrEdge E1 = AlokasiEdge(N2);
        E1->Next = N1->firstEdge; 
        N1->firstEdge = E1;

        adrEdge E2 = AlokasiEdge(N1);
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    } else {
        cout << "Salah satu node tidak ditemukan!" << endl;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode curr = G.first;
    while (curr != NULL) {
        cout << "Node " << curr->info << ": ";
        adrEdge e = curr->firstEdge;
        while (e != NULL) {
            cout << e->Node->info;
            if (e->Next != NULL) cout << ", ";
            e = e->Next;
        }
        cout << endl;
        curr = curr->Next;
    }
}

void ResetVisited(Graph &G) {
    adrNode curr = G.first;
    while (curr != NULL) {
        curr->visited = 0;
        curr = curr->Next;
    }
}

void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode startNode = FindNode(G, StartInfo);
    if (startNode == NULL) return;

    stack<adrNode> S;
    S.push(startNode);
    
    cout << "DFS Traversal: ";
    while (!S.empty()) {
        adrNode curr = S.top();
        S.pop();

        if (curr->visited == 0) {
            curr->visited = 1;
            cout << curr->info << " ";

            adrEdge e = curr->firstEdge;
            while (e != NULL) {
                if (e->Node->visited == 0) {
                    S.push(e->Node);
                }
                e = e->Next;
            }
        }
    }
    cout << endl;
}

void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode startNode = FindNode(G, StartInfo);
    if (startNode == NULL) return;

    queue<adrNode> Q;
    Q.push(startNode);
    startNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Q.empty()) {
        adrNode curr = Q.front();
        Q.pop();
        cout << curr->info << " ";

        adrEdge e = curr->firstEdge;
        while (e != NULL) {
            if (e->Node->visited == 0) {
                e->Node->visited = 1; 
                Q.push(e->Node);
            }
            e = e->Next;
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);
    
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'G');
    ConnectNode(G, 'D', 'H');
    ConnectNode(G, 'E', 'H');
    ConnectNode(G, 'F', 'H');
    ConnectNode(G, 'G', 'H');

    cout << "=== INFORMASI GRAPH (TETANGGA) ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    PrintDFS(G, 'A');
    PrintBFS(G, 'A');

    return 0;
}
```

### Output Unguided :

##### Output soal 1, 2, 3
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-12/output1-soal123-modul14.png)

Program ini mengimplementasikan struktur data Graph Tidak Berarah (Undirected Graph) menggunakan representasi Adjacency List untuk memodelkan hubungan antar elemen. Struktur graph terdiri dari sekumpulan simpul (Node) yang saling terhubung melalui sisi (Edge). Setiap node (simpul) menyimpan informasi (karakter), status kunjungan (visited), pointer ke node berikutnya dalam daftar utama, serta pointer ke edge pertama yang menghubungkannya dengan node lain. Fungsi ConnectNode bertugas menghubungkan dua node dengan membuat edge di kedua arah (misalnya A ke B dan B ke A), sehingga hubungan bersifat simetris. Program ini juga dilengkapi dengan manajemen memori dinamis melalui alokasi node dan edge. Fitur utama program ini adalah dua algoritma penelusuran graph: Breadth-First Search (BFS) dan Depth-First Search (DFS). BFS menggunakan struktur data antrean (queue) untuk menelusuri graph secara melebar, mengunjungi semua tetangga terdekat dari sebuah simpul sebelum bergerak ke level berikutnya. Sebaliknya, DFS menggunakan tumpukan (stack) untuk menelusuri graph secara mendalam, mengikuti satu jalur sejauh mungkin sebelum kembali (backtracking) ke simpul sebelumnya. Pada fungsi main, sebuah graph kompleks dengan 8 simpul (A hingga H) dibangun sesuai pola tertentu, kemudian struktur koneksinya ditampilkan, diikuti dengan hasil urutan penelusuran menggunakan kedua metode tersebut untuk mendemonstrasikan perbedaan cara kerja BFS dan DFS .


## Kesimpulan
Graph merupakan struktur data non-linear yang sangat efektif untuk merepresentasikan dan menganalisis hubungan antar data yang kompleks, serta memvisualisasikan tren atau perbandingan dalam berbagai aplikasi bisnis dan media. Pemilihan metode representasi graph, apakah menggunakan Array (Matriks) atau Pointer (Linked List), sangat bergantung pada karakteristik masalah dan kebutuhan efisiensi; Linked List lebih disukai untuk menghemat memori pada data dinamis, sedangkan Matriks menawarkan kemudahan implementasi untuk graph berukuran kecil atau padat. Selain struktur penyimpanannya, pemahaman mengenai algoritma traversal (BFS dan DFS) serta algoritma optimasi seperti Dijkstra dan Bellman-Ford menjadi kunci dalam menyelesaikan masalah penentuan jalur dan analisis jaringan.

## Referensi
[1] Kudase, J., & Bane, P. (2016). A Brief Study of Graph Data Structure. International Journal of Advanced Research in Computer and Communication Engineering, 5(6), 268-272. </br>[2] Medina, G., & Moreira, M. (n.d.). Data Structures and Graph Algorithms. [White paper].