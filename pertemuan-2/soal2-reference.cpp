#include <iostream>

using namespace std;

void tukarR(int &rA, int &rB, int &rC) {
    int temp = rA;
    rA = rB;
    rB = rC;
    rC = temp;
}

int main() {
    int a, b, c;
    a = 10;
    b = 20;
    c = 30;

    cout << "Nilai awal : \na = " << a << ", b = " << b << ", c = " << c << endl;
    tukarR(a, b, c);
    cout << "Nilai setelah ditukar : \na = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}