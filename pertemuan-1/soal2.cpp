#include <iostream>
#include <string>
using namespace std;

string satuan(int n) {
    switch (n) {
        case 1: return "satu";
        case 2: return "dua";
        case 3: return "tiga";
        case 4: return "empat";
        case 5: return "lima";
        case 6: return "enam";
        case 7: return "tujuh";
        case 8: return "delapan";
        case 9: return "sembilan";
        default: return "";
    }
}

int main() {
    int n;
    string hasil;

    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if (n < 0 || n > 100) {
        hasil = "Input harus berupa bilangan 0-100";
    } else {
        if (n == 0) {
            hasil = "nol";
        } else if (n == 10) {
            hasil = "sepuluh";    
        } else if (n == 11) {
            hasil = "sebelas";
        } else if (n == 100) {
            hasil = "seratus";
        } else if (n < 10) {
            hasil = satuan(n);
        } else if (n < 20) {
            hasil = satuan(n%10) + " belas";
        } else {
            int puluhan = n / 10;
            int sisa = n % 10;
            hasil = satuan(puluhan) + " puluh";
            if (sisa != 0) {
                hasil += " " + satuan(sisa);
            }
        }
    }

    cout << "\nAngka " << n << " dalam bentuk tulisan: " << hasil << endl;
}