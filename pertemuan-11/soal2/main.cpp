#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);
    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P3);
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);
    NodeParent P5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P5);

    NodeChild C1_1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertLastChild(P1->L_Child, C1_1);
    NodeChild C1_2 = allocNodeChild("AV002", "Bebek", "Air", true, 2.0);
    insertLastChild(P1->L_Child, C1_2);
    NodeChild C2_1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200.0);
    insertLastChild(P2->L_Child, C2_1);
    NodeChild C2_2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160.0); 
    insertLastChild(P2->L_Child, C2_2);
    NodeChild C2_3 = allocNodeChild("M002", "Kucing", "Darat", true, 4.0);
    insertLastChild(P2->L_Child, C2_3);
    NodeChild C4_1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2); 
    insertLastChild(P4->L_Child, C4_1);

    cout << "=== STRUKTUR AWAL ===" << endl;
    printMLLStructure(LP);
    cout << endl;

    cout << "=== PENCARIAN HEWAN (Ekor = FALSE) ===" << endl;
    searchHewanByEkor(LP, false);

    return 0;
}