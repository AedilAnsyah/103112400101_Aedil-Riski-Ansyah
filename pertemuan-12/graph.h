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