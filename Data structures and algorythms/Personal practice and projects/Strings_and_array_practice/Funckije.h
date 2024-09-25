#ifndef Funkcije_h
#define Funkcije_h
#include <stdio.h>
#include <stdlib.h>
#define SIZE(x) ((sizeof(x))/(sizeof(x[0])))
#define INT (sizeof(int))
typedef struct
{
	float x;
	float y;
}Tocka;
typedef struct
{
	Tocka* vrhovi;
	int broj_tocaka;
}Poligon;
void printaj(const int* niz, const int duljina); //printanje niza
int velicina(const char*); //racunanje velicine stringa
int* repetitio(const int* niz_prvi, const int duljina_prvog, const int* niz_drugi, const int duljina_drugog, int* nova_duljina); //pretraga brojeva koji se ponavljaju u 2 niza
void vertite(int* niz, const int duljina); //okretanje niza
void reponere(int* niz, const int duljina); //zamjena prvog parnog i zadnjeg neparnog
int* duplici(const int* niz, const int duljina, int* nova_duljina); //uklanjanje dupliciranih clanova niza
int* effingo(const int* niz, const int duljina, int pocetak_novog, int kraj_novog); //kopiranje dijela niza/stvaranje novog od komada starog
int* addere_in_medio(const int* niz, const int duljina, const int broj); //umetanje broja po sredini niza
int* ab_initio(const int* niz, const int duljina); //brisanje prvog clana niza
int* conditionalis_remotionem(const int* niz, const int duljina, const int parni_ili_neparni_broj, int* nova_duljina); //uklanjanje clanova uz uvjet da su parni ili neparni, ovisno kojeg posaljes
char* ultimum_verbum(const char* string, const int duljina); //uklanjanje zadnje rijeci u stringu
char** separatum(const char* string, const int duljina); //dijeljenje string od dvije rijeci na dva stringa od jedne rijeci
int* ligaris(const int* prvi_niz, const int duljina_prvog, const int* drugi_niz, const int duljina_drugog, int* duljina_novog); //spajanje dva niza u jednog
int* extrahere(const int* niz, const int duljina, int* duljina_novog); //izvlacenje i spremanje neparnih brojeva u novi niz
//////////
Poligon* novi_poligon(const int*, const int*, const int);
Tocka** pozitivni(Poligon* p, int*);
#endif