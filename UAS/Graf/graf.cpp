#include "graf.h"

void createGraph(GraphKota &G) {
    G.First = NULL;
}

adrKota alokasiNode(string nama) {
    adrKota P = new ElmKota;
    P->namaKota = nama;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrEdge alokasiEdge(adrKota tujuan, int jarak) {
    adrEdge E = new ElmEdge;
    E->kotaTujuan = tujuan;
    E->jarak = jarak;
    E->next = NULL;
    return E;
}

void insertNode(GraphKota &G, adrKota P) {
    if (G.First == NULL) {
        G.First = P;
    } else {
        adrKota last = G.First;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = P;
    }
}

adrKota findNode(GraphKota G, string nama) {
    adrKota P = G.First;
    while (P != NULL) {
        if (P->namaKota == nama) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void connectNode(adrKota N1, adrKota N2, int jarak) {
    if (N1 == NULL || N2 == NULL) return;
    adrEdge E1 = alokasiEdge(N2, jarak);
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;
    adrEdge E2 = alokasiEdge(N1, jarak);
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void deleteNode(GraphKota &G, string nama) {
    adrKota target = findNode(G, nama);
    if (target == NULL) {
        cout << "Node " << nama << " tidak ditemukan." << endl;
        return;
    }
    adrKota P = G.First;
    while (P != NULL) {
        if (P != target) {
            adrEdge prevE = NULL;
            adrEdge currE = P->firstEdge;
            while (currE != NULL) {
                if (currE->kotaTujuan == target) {
                    if (prevE == NULL) {
                        P->firstEdge = currE->next;
                    } else {
                        prevE->next = currE->next;
                    }
                    delete currE;
                    break; 
                }
                prevE = currE;
                currE = currE->next;
            }
        }
        P = P->next;
    }
    adrEdge e = target->firstEdge;
    while (e != NULL) {
        adrEdge temp = e;
        e = e->next;
        delete temp;
    }
    if (G.First == target) {
        G.First = target->next;
    } else {
        adrKota prev = G.First;
        while (prev->next != target) {
            prev = prev->next;
        }
        prev->next = target->next;
    }
    delete target;
}

void printGraph(GraphKota G) {
    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    adrKota P = G.First;
    while (P != NULL) {
        cout << "Node " << P->namaKota << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        if (E == NULL) cout << "-";
        while (E != NULL) {
            cout << E->kotaTujuan->namaKota << "(" << E->jarak << " KM)";
            if (E->next != NULL) cout << ", ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
    cout << endl;
}

void createQueue(Queue &Q) {
    Q.head = NULL;
    Q.tail = NULL;
}
bool isEmptyQueue(Queue Q) {
    return Q.head == NULL;
}
void enqueue(Queue &Q, adrKota P) {
    adrQueue qNode = new ElmQueue;
    qNode->info = P;
    qNode->next = NULL;
    if (Q.head == NULL) {
        Q.head = qNode;
        Q.tail = qNode;
    } else {
        Q.tail->next = qNode;
        Q.tail = qNode;
    }
}
void dequeue(Queue &Q, adrKota &P) {
    if (isEmptyQueue(Q)) {
        P = NULL;
    } else {
        adrQueue temp = Q.head;
        P = temp->info;
        Q.head = Q.head->next;
        if (Q.head == NULL) {
            Q.tail = NULL;
        }
        delete temp;
    }
}

void createStack(Stack &S) {
    S.top = NULL;
}
bool isEmptyStack(Stack S) {
    return S.top == NULL;
}
void push(Stack &S, adrKota P) {
    adrStack sNode = new ElmStack;
    sNode->info = P;
    sNode->next = S.top;
    S.top = sNode;
}
void pop(Stack &S, adrKota &P) {
    if (isEmptyStack(S)) {
        P = NULL;
    } else {
        adrStack temp = S.top;
        P = temp->info;
        S.top = S.top->next;
        delete temp;
    }
}

void resetVisited(GraphKota G) {
    adrKota P = G.First;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

void printBFS(GraphKota G, adrKota startNode) {
    if (startNode == NULL) return;
    resetVisited(G);
    Queue Q;
    createQueue(Q);
    enqueue(Q, startNode);
    startNode->visited = 1;
    cout << "BFS Traversal: ";
    adrKota curr;
    while (!isEmptyQueue(Q)) {
        dequeue(Q, curr);
        cout << curr->namaKota << " - ";

        adrEdge E = curr->firstEdge;
        while (E != NULL) {
            if (E->kotaTujuan->visited == 0) {
                E->kotaTujuan->visited = 1;
                enqueue(Q, E->kotaTujuan);
            }
            E = E->next;
        }
    }
    cout << endl;
}

void printDFS(GraphKota G, adrKota startNode) {
    if (startNode == NULL) return;
    resetVisited(G);
    Stack S;
    createStack(S);
    push(S, startNode);
    
    cout << "DFS Traversal: ";
    adrKota curr;
    while (!isEmptyStack(S)) {
        pop(S, curr);

        if (curr->visited == 0) {
            curr->visited = 1;
            cout << curr->namaKota << " - ";
            adrEdge E = curr->firstEdge;
            while (E != NULL) {
                if (E->kotaTujuan->visited == 0) {
                    push(S, E->kotaTujuan);
                }
                E = E->next;
            }
        }
    }
    cout << endl;
}