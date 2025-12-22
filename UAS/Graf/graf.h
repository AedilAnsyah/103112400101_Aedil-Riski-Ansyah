#ifndef GRAF_H
#define GRAF_H
#include <iostream>
#include <string>
using namespace std;

typedef struct ElmKota *adrKota;
typedef struct ElmEdge *adrEdge;
struct ElmKota {
    string namaKota;
    int visited;            
    adrEdge firstEdge;      
    adrKota next;          
};

struct ElmEdge {
    adrKota kotaTujuan;     
    int jarak;             
    adrEdge next;           
};

struct GraphKota {
    adrKota First;
};

typedef struct ElmQueue *adrQueue;
struct ElmQueue {
    adrKota info;
    adrQueue next;
};
struct Queue {
    adrQueue head;
    adrQueue tail;
};

typedef struct ElmStack *adrStack;
struct ElmStack {
    adrKota info;
    adrStack next;
};
struct Stack {
    adrStack top;
};

void createGraph(GraphKota &G);
adrKota alokasiNode(string nama);
adrEdge alokasiEdge(adrKota tujuan, int jarak);
void insertNode(GraphKota &G, adrKota P);
adrKota findNode(GraphKota G, string nama);
void connectNode(adrKota N1, adrKota N2, int jarak);
void deleteNode(GraphKota &G, string nama);
void printGraph(GraphKota G);
void resetVisited(GraphKota G);
void printBFS(GraphKota G, adrKota startNode);
void printDFS(GraphKota G, adrKota startNode);

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
void enqueue(Queue &Q, adrKota P);
void dequeue(Queue &Q, adrKota &P);
void createStack(Stack &S);
bool isEmptyStack(Stack S);
void push(Stack &S, adrKota P);
void pop(Stack &S, adrKota &P);

#endif