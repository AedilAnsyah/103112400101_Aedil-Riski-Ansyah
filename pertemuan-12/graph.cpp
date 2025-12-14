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