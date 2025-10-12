#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED
using namespace std;
#include <string>

struct pelajaran {
    string namamapel;
    string kodemapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif