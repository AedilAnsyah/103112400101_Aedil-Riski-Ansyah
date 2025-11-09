# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Aedil Riski Ansyah - 103112400101</p>

## Dasar Teori
Dalam struktur data, Stack (tumpukan) didefinisikan sebagai list linier atau bentuk struktur data yang operasinya didasarkan pada prinsip LIFO (Last In First Out) [1, 2]. Prinsip LIFO berarti data yang terakhir kali dimasukkan adalah data yang pertama kali akan diambil atau dihapus [1]. Secara konseptual, ini adalah cara paling sederhana untuk menyimpan informasi sementara, sering dianalogikan seperti tumpukan nampan di kafetaria [2]. Semua operasi pada stack hanya dapat dilakukan pada satu posisi, yang dikenal sebagai elemen puncak atau "Top" [1].

Dua operasi paling fundamental pada stack adalah Push dan Pop [2]. Operasi Push berfungsi untuk menambahkan atau menyisipkan satu elemen baru ke dalam tumpukan, di mana elemen ini akan menempati posisi Top [1, 2]. Sebaliknya, operasi Pop berfungsi untuk mengambil atau mengeluarkan satu elemen dari dalam stack, dan elemen yang diambil selalu yang berada pada posisi Top [1, 2]. Dalam bentuknya yang paling murni, stack hanya mengizinkan akses ke elemen teratas ini [2]. Stack dapat diimplementasikan menggunakan array (tabel) dengan sebuah variabel indeks untuk melacak posisi Top [1, 2], atau menggunakan representasi pointer [1].

## Guided 

### 1. Stack Menggunakan Linked List

stack.h
```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

Program ini adalah implementasi struktur data Stack (Tumpukan) C++ yang menggunakan linked list, terbagi dalam file stack.h, stack.cpp, dan main.cpp. File header (stack.h) mendefinisikan struktur node (terdiri dari dataAngka dan pointer next) dan stack (terdiri dari pointer top). File ini juga mendaftarkan semua prototype fungsi. File implementasi (stack.cpp) berisi logika dari semua fungsi. createStack menginisialisasi top ke Nil (NULL). Logika inti LIFO (Last In First Out) ditangani oleh push, yang menambahkan node baru ke top, dan pop, yang melepaskan node top dan memanggil dealokasi untuk menghapusnya. Program ini juga menyertakan fungsi utilitas seperti view (menampilkan semua data), update (mengubah data di posisi tertentu), dan searchData (mencari nilai). File main.cpp bertindak sebagai driver untuk menguji stack. Program ini membuat stack, melakukan push lima node (berisi nilai 1 sampai 5), kemudian secara berurutan mendemonstrasikan fungsi view, pop (dua kali), update, dan searchData untuk memverifikasi bahwa semua operasi berjalan dengan benar.

### 2. Stack Menggunakan Array

stack.h
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

//ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```

stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if (isFull(s)){
        cout << "Stak Penuh!" << endl;
    }else{
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if (isEmpty(s)){
        cout << "Stak Kosong!" << endl;
    }else{
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if (isEmpty(s))
    {
        cout << "Stack Kosong!" << endl;
        return;
    }
    if (posisi <= 0)
    {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    // index = top - (posisi - 1)
    int idx = s.top - (posisi -1);
    if (idx < 0 || idx > s.top)
    {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }
    
    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka: ";
    cin >> s.data[idx];
    cout << "data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
    }else{
        for (int i = s.top; i >= 0; --i)
        {
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; i--){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan dalam stack!" << endl;
    }
    cout << endl;
}
```

main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;
    
    pop(s);
    pop(s);
    cout << endl;
    
    cout << "--- Stack setelah pop ---" << endl;
    view(s);
    cout << endl;
    
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;
    
    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```

Program ini adalah implementasi struktur data Stack (Tumpukan) dalam C++ yang menggunakan representasi array (tabel) dengan ukuran tetap (MAX = 10). Kode ini dibagi menjadi tiga file yaitu stack.h, stack.cpp, dan main.cpp.File header stack.h mendefinisikan struktur utamanya, stackTable, yang terdiri dari array data untuk menyimpan elemen dan sebuah integer top yang berfungsi sebagai indeks penanda puncak tumpukan (diinisialisasi ke -1 untuk menandakan stack kosong). File ini juga mendaftarkan semua prototype fungsi. File implementasi stack.cpp berisi logika dari semua fungsi tersebut. Fungsi inti LIFO (Last In First Out) diimplementasikan oleh push (menaikkan top lalu menambahkan data di indeks baru) dan pop (mengambil data dari top lalu menurunkannya). Selain itu, program ini dilengkapi fungsi utilitas seperti view (menampilkan isi stack dari top ke bawah), update (mengubah data pada posisi tertentu), dan searchData (mencari nilai dan melaporkan posisinya). File main.cpp bertindak sebagai driver yang menguji ADT stack. Program ini membuat stack, melakukan push lima angka (1 hingga 5), melihat hasilnya, melakukan pop dua kali, lalu menguji fungsi update dan searchData untuk menunjukkan fungsionalitas lengkap dari implementasi stack ini.


## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”:
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-7/modul7-soal1-1.png)
### Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-7/modul7-soal1-2.png)

### 2. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-7/modul7-soal2-1.png)
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-7/modul7-soal2-2.png)

### 3. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-7/modul7-soal3.png)

Ketiga soal menggunakan file header dan file implementasi yang sama yaitu stack.h dan stack.cpp
stack.h
```C++
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
```

stack.cpp
```C++
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
```

main1.cpp untuk Latihan 1
```C++
#include <iostream>
#include "stack.h" 

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    Push (S, 3);
    Push (S, 4);
    Push (S, 8);
    pop (S);
    Push (S, 2);
    Push (S, 3);
    pop (S);
    Push (S, 9);

    printInfo (S);
    cout<<"balik stack"<<endl;
    balikStack (S);
    printInfo (S);
    
    return 0;
}
```

main2.cpp untuk Latihan 2
```C++
#include <iostream>
#include "stack.h" 

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    pushAscending (S,3);
    pushAscending (S,4);
    pushAscending (S,8);
    pushAscending (S,2);
    pushAscending (S,3);
    pushAscending (S,9);
    
    printInfo (S);
    cout<<"balik stack"<<endl;
    balikStack (S);
    printInfo (S);
    
    return 0;
}
```

main3.cpp untuk Latihan 3
```C++
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
```

### Output Unguided :

##### Output soal 1, 2, 3
![Screenshot Output Unguided 1_1](https://github.com/AedilAnsyah/103112400101_Aedil-Riski-Ansyah/blob/main/pertemuan-7/output1-soal123-modul7.png)

Program ini adalah implementasi lengkap dari Abstract Data Type (ADT) Stack dalam C++, yang menggunakan representasi array (tabel) dengan ukuran tetap (MAX_ELEMENT 20). Arsitektur kode ini memisahkan interface (deklarasi) dari implementasi (logika), yang kemudian digunakan oleh tiga program pengujian (driver) terpisah.

File header stack.h bertindak sebagai interface utama. Ia mendefinisikan struct Stack yang berisi array info untuk data dan sebuah integer top untuk melacak indeks puncak (menggunakan top = -1 untuk menandakan stack kosong). File ini mendaftarkan semua prototipe fungsi yang dibutuhkan untuk ketiga latihan, termasuk CreateStack, Push, pop, printInfo, balikStack (Latihan 1), pushAscending (Latihan 2), dan getInputStream (Latihan 3).

File implementasi stack.cpp menyediakan definisi (logika) untuk setiap fungsi yang dideklarasikan di header. Fungsi Latihan 1 mencakup operasi LIFO dasar seperti Push (menaikkan top dan menyisipkan) dan pop (mengambil data dan menurunkan top), serta balikStack yang menggunakan stack sementara untuk membalik urutan elemen. Fungsi Latihan 2, pushAscending, adalah Push khusus yang menjaga stack tetap terurut; ia memindahkan elemen yang lebih kecil ke stack sementara sebelum menyisipkan elemen baru. Fungsi Latihan 3, getInputStream, membaca input karakter (cin.get()) dari pengguna hingga 'Enter', mengubah karakter digit menjadi integer, dan mem-Push nya ke stack.

Terakhir, ada tiga file driver terpisah (main1.cpp, main2.cpp, main3.cpp) yang masing-masing mengimpor stack.h dan stack.cpp untuk menguji fungsionalitas tertentu. main1.cpp menguji operasi dasar Push, pop, dan balikStack. main2.cpp secara khusus menguji pushAscending untuk memverifikasi fungsionalitas pengurutan. main3.cpp menguji getInputStream untuk menunjukkan kemampuan stack menerima input langsung dari pengguna.

## Kesimpulan
Stack (Tumpukan) adalah sebuah struktur data linier fundamental yang beroperasi berdasarkan prinsip LIFO (Last In First Out), di mana elemen yang terakhir dimasukkan adalah elemen yang pertama kali dikeluarkan. Seluruh operasi, baik penyisipan (Push) maupun pengambilan (Pop), hanya dapat dilakukan pada satu ujung yang disebut "Top". Sebagai sebuah Abstract Data Type (ADT) , stack dapat diimplementasikan dengan dua cara utama: secara statis menggunakan array (tabel) dengan satu variabel integer untuk melacak indeks top, atau secara dinamis menggunakan pointer (linked list) di mana top adalah pointer yang menunjuk ke elemen teratas. Dalam komputasi, stack memiliki peran krusial dan digunakan secara luas untuk empat fungsi utama: evaluasi ekspresi aritmatika (termasuk konversi ke notasi postfix ), pengelolaan pemanggilan subroutine atau fungsi dengan menyimpan return address , mendukung rekursi , alokasi dinamis untuk variabel lokal , dan penerusan parameter antar fungsi.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
</br>[2] Koopman, Jr., P. (1989). STACK COMPUTERS the new wave. Pittsburgh, USA: Ellis Horwood.