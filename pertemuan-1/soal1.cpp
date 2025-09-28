#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b;
    cout << "Masukkan angka 1: ";
    cin >> a;
    cout << "Masukkan angka 2: ";
    cin >> b;

    cout << fixed << setprecision(2);
    cout << "---------------------------------------" << endl;
    cout << "Hasil Penjumlahan " << a << " dan " << b << " = " << a+b << endl;
    cout << "Hasil Pengurangan " << a << " dan " << b << " = " << a-b << endl;
    cout << "Hasil Perkalian " << a << " dan " << b << "   = " << a*b << endl;
    if (b != 0) {
        cout << "Hasil Pembagian " << a << " dan " << b << "   = " << a/b << endl;
    } else {
        cout << "Hasil Pembagian = Tidak Terdefinisi";
    }
}