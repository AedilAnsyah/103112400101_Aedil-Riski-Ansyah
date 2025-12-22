#include <iostream>
#include "graf.h"

using namespace std;

int main() {
    GraphKota G;
    createGraph(G);

    adrKota bogor = alokasiNode("Bogor");
    adrKota bekasi = alokasiNode("Bekasi");
    adrKota jakarta = alokasiNode("Jakarta");
    adrKota depok = alokasiNode("Depok");
    adrKota tangerang = alokasiNode("Tangerang");

    insertNode(G, jakarta);
    insertNode(G, bogor);
    insertNode(G, depok);
    insertNode(G, tangerang);
    insertNode(G, bekasi);

    connectNode(bogor, bekasi, 60);
    connectNode(bogor, depok, 22);
    connectNode(bogor, jakarta, 42);
    connectNode(jakarta, bekasi, 16);
    connectNode(jakarta, depok, 21);
    connectNode(jakarta, tangerang, 24);
    connectNode(bekasi, tangerang, 45);
    connectNode(depok, tangerang, 30);

    cout << "=== KONDISI AWAL GRAPH ===" << endl;
    printGraph(G);
    cout << "=== DELETE NODE DEPOK ===" << endl;
    deleteNode(G, "Depok");
    printGraph(G);

    cout << "=== HASIL TRAVERSAL BFS & DFS (Start: Tangerang) ===" << endl;    
    adrKota startNode = findNode(G, "Tangerang");

    if (startNode != NULL) {
        printBFS(G, startNode);
        printDFS(G, startNode);
    } else {
        cout << "Node Tangerang tidak ditemukan!" << endl;
    }

    return 0;
}