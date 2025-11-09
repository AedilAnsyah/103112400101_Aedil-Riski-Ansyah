#include "stack.h"
#include <iostream>
using namespace std;

// Latihan 1
void CreateStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX_ELEMENT - 1;
}

void Push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        return -1; 
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    if (!isEmpty(S)) {
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S)) {
        Push(temp, pop(S));
    }

    S = temp;
}

// Latihan 2
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.top] < x) {
        Push(temp, pop(S));
    }
    Push(S, x);
    while (!isEmpty(temp)) {
        Push(S, pop(temp));
    }
}

// Latihan 3
void getInputStream(Stack &S) {
    char c;
  
    while ((c = cin.get()) != '\n') {
        if (c >= '0' && c <= '9') {
            infotype x = c - '0'; 
            Push(S, x);
        }
    }
}