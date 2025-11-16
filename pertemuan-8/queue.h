#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using infotype = int;

const int MAKSIMAL = 5;
struct Queue {
    infotype info[MAKSIMAL];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(const Queue &Q);
bool isFullQueue(const Queue &Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(const Queue &Q);

#endif