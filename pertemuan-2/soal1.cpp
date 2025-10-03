#include <iostream>

using namespace std;

void tampilan(int mtx[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mtx1[3][3] = {
        {1,2,4},
        {3,1,2},
        {7,5,4}
    };
    int mtx2[3][3] = {
        {3,1,7},
        {3,5,4},
        {8,1,5}
    };
    int hasil[3][3];
    cout << "\n=== HASIL PENJUMLAHAN ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = mtx1[i][j] + mtx2[i][j];
        }
    }
    tampilan(hasil);

    cout << "\n=== HASIL PENGURANGAN ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = mtx1[i][j] - mtx2[i][j];
        }
    }
    tampilan(hasil);

    cout << "\n=== HASIL PERKALIAN ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                hasil[i][j] += mtx1[i][k] * mtx2[k][j];
            }
        }
    }
    tampilan(hasil);

    return 0;
}