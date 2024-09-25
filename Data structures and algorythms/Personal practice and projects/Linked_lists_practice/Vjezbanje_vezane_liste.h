#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct _Element
{
	int broj;
	struct _Element* next;
} Element;
void printaj(Element*);
Element* createList(int);
Element* ubaci_u_glavu(Element*, int);
Element* ubaci_u_rep(Element*, int);
Element* ubaci(Element*, int, int);
Element* prvi_na_zadnje(Element*);
Element* zadnji_na_prvo(Element*);
Element* obrisi_prvi(Element*);
Element* zamijeni_prvi_i_zadnji(Element*);
Element* ukloni_zadnjih_n(Element*, int);
Element* dodaj_iza_parnih(Element*);
Element* dodaj_iz_niza(Element*, int*);
Element* prvi_veci(Element*, int);
Element* prvi_iz_druge_na_kraj_prve(Element*, Element*);
Element* brisi_sve_djeljivo_sa_el(Element*, int);