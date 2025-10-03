#include <iostream>

using namespace std;

int cariMax(const int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int cariMin(const int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void hitungAvg(const int arr[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    double avg = total / size;
    cout << "Rata-rata array: " << avg << endl;
}

void tampilan(const int arr[], int size) {
    cout << "Isi Array: { ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << (i == size - 1 ? " " : ", ");
    }
    cout << "}" << endl;
}

int main() {
    int arr[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tampilan(arr, 10);
            break;
        case 2:
            cout << "Nilai maksimal dari array: " << cariMax(arr, 10) << endl;
            break;
        case 3:
            cout << "Nilai minimum dari array: " << cariMin(arr, 10) << endl;
            break;
        case 4:
            hitungAvg(arr, 10);
            break;           
        case 5:
            cout << "Program selesai" << endl;
        default:
            cout << "Pilihan tidak valid";
        }
    } while (pilihan != 5);

    return 0;
}