#include <iostream>

using namespace std;

void tukarP(int *pA, int *pB, int *pC) {
    int temp = *pA;
    *pA = *pB;
    *pB = *pC;
    *pC = temp;
}

int main() {
    int a, b, c;
    a = 10;
    b = 20;
    c = 30;

    cout << "Nilai awal : \na = " << a << ", b = " << b << ", c = " << c << endl;
    tukarP(&a, &b, &c);
    cout << "Nilai setelah ditukar : \na = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}