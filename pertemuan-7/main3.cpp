#include <iostream>
#include "stack.h" // Menggunakan ADT yang sama

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack (S);
    getInputStream(S); 
    
    printInfo (S);
    
    cout<<"balik stack"<<endl;
    
    balikStack (S);
    printInfo (S);
    
    return 0;
}