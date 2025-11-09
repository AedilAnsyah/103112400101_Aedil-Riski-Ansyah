#ifndef STACK_H
#define STACK_H
#define MAX_ELEMENT 20
typedef int infotype;

// Latihan 1
struct Stack {
    infotype info[MAX_ELEMENT];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void Push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// Latihan 2
void pushAscending(Stack &S, infotype x);

// Latihan 3
void getInputStream(Stack &S);

#endif 