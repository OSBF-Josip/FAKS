#ifndef FUNKCIJE
#define FUNKCIJE
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define RANDOM (rand() * rand())
void poziv_presjek(int, int, int);
void poziv_presjek_jedan_sortiran(int, int, int);
void poziv_presjek_oba_sortirana(int, int, int);
void poziv_presjek_po_indeksima(int, int, int);
//
int* generate(int);
void shuffle(int*, int);
//
int presjek(int*, int*, int);
int presjek_jedan_sortiran(int*, int*, int);
int presjek_oba_sortirana(int*, int*, int);
int presjek_po_indeksima(int*, int*, int);
#endif