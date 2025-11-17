#include "StackMahasiswa.h"

float getNilaiAkhir(Mahasiswa M) {
    return (0.20 * M.NilaiTugas) + (0.40 * M.NilaiUTS) + (0.40 * M.NilaiUAS);
}

bool isEmpty(const StackMahasiswa& S) {
    return S.Top == -1;
}

bool isFull(const StackMahasiswa& S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa& S) {
    S.Top = -1; 
}

void Push(StackMahasiswa& S, Mahasiswa M) {
    if (isFull(S)) {
        cout << "karena stack penuh maka data (" << M.Nama << ") gagal ditambahkan" << endl;
    } else {
        S.Top++; 
        S.dataMahasiswa[S.Top] = M; 
    }
}

void Pop(StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "tidak ada data untuk di pop karena stack kosong" << endl;
    } else {
        cout << "data (" << S.dataMahasiswa[S.Top].Nama << ") berhasil di-pop" << endl;
        S.Top--; 
    }
}

void Update(StackMahasiswa& S, int posisi, Mahasiswa M) {
    int index = posisi - 1;

    if (index >= 0 && index <= S.Top) {
        S.dataMahasiswa[index] = M;
        cout << "data dalam posisi " << posisi << " berhasil di update" << endl;
    } else {
        cout << "posisi " << posisi << " tidak valid untuk update" << endl;
    }
}

void View(const StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "stack kosong" << endl;
        return;
    }

    cout << "\n--- Isi Stack (bawah ke atas) ---" << endl;
    for (int i = 0; i <= S.Top; i++) {
        Mahasiswa M = S.dataMahasiswa[i];
        float nilaiAkhir = getNilaiAkhir(M);

        cout << "Posisi " << (i + 1) << " :" << endl;
        cout << "  Nama        : " << M.Nama << endl;
        cout << "  NIM         : " << M.NIM << endl;
        cout << fixed << setprecision(2); 
        cout << "  Nilai Tugas : " << M.NilaiTugas << endl;
        cout << "  Nilai UTS   : " << M.NilaiUTS << endl;
        cout << "  Nilai UAS   : " << M.NilaiUAS << endl;
        cout << "  Nilai Akhir : " << nilaiAkhir << endl;
        cout << endl;
    }
    cout << fixed << setprecision(6);
}

void SearchNilaiAkhir(const StackMahasiswa& S, float NilaiAkhirMin, float NilaiAkhirMax) {
    if (isEmpty(S)) {
        cout << "pencarian tidak bisa dilakukan karena stack kosong" << endl;
        return;
    }

    cout << "\n--- Hasil Pencarian dengan Nilai Akhir: " << NilaiAkhirMin << " - " << NilaiAkhirMax << " ---" << endl;
    bool found = false;
    for (int i = 0; i <= S.Top; i++) {
        Mahasiswa M = S.dataMahasiswa[i];
        float nilaiAkhir = getNilaiAkhir(M);

        if (nilaiAkhir >= NilaiAkhirMin && nilaiAkhir <= NilaiAkhirMax) {
            found = true;
            cout << "Ditemukan pada Posisi : " << (i + 1) << endl;
            cout << "  Nama        : " << M.Nama << endl;
            cout << "  NIM         : " << M.NIM << endl;
            cout << "  Nilai Akhir : " << fixed << setprecision(2) << nilaiAkhir << endl;
            cout << endl;
        }
    }

    if (!found) {
        cout << "tidak ada mahasiswa dalam rentang nilai tersebut" << endl;
    }
    cout << fixed << setprecision(6);
}

void MaxNilaiAkhir(const StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "tidak bisa mencari nilai max karena stack kosong" << endl;
        return;
    }

    float maxNilai = -1.0;
    int posMax = -1;

    for (int i = 0; i <= S.Top; i++) {
        float nilaiAkhir = getNilaiAkhir(S.dataMahasiswa[i]);
        if (nilaiAkhir > maxNilai) {
            maxNilai = nilaiAkhir;
            posMax = i;
        }
    }

    Mahasiswa M = S.dataMahasiswa[posMax];
    cout << "\n--- Mahasiswa dengan Nilai Akhir Tertinggi ---" << endl;
    cout << "Ditemukan pada Posisi : " << (posMax + 1) << endl;
    cout << "  Nama        : " << M.Nama << endl;
    cout << "  NIM         : " << M.NIM << endl;
    cout << "  Nilai Akhir : " << fixed << setprecision(2) << maxNilai << endl;
    cout << endl;
    cout << fixed << setprecision(6);
}