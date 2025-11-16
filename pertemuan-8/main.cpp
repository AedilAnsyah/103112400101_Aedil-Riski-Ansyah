#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Queue Q;
    CreateQueue(Q);
    cout << "---------------------------------" << endl;
    cout << "<< H - T | Queue info >>" << endl;
    cout << "---------------------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); 
    printInfo(Q); 
    enqueue(Q, 2); 
    printInfo(Q); 
    enqueue(Q, 7); 
    printInfo(Q);

    dequeue(Q); 
    printInfo(Q); 
    dequeue(Q); 
    printInfo(Q); 
    dequeue(Q); 
    printInfo(Q); 

    return 0;
}