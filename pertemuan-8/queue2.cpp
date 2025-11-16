#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q) {
    return (Q.head == -1 || Q.head > Q.tail);
}

bool isFullQueue(const Queue &Q) {
    return Q.tail == MAKSIMAL - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh, enqueue dibatalkan." << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0; 
            Q.tail = 0; 
        } else {
            Q.tail++; 
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong, dequeue dibatalkan." << endl;
        return -1; 
    } else {
        infotype x = Q.info[Q.head]; 
        Q.head++; 
        if (isEmptyQueue(Q)) {
            CreateQueue(Q); 
        }
        
        return x; 
    }
}

void printInfo(const Queue &Q) {
    cout << " " << Q.head << " - " << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}