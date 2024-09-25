#include <stdio.h>
#include <stdlib.h>
#define SIZE(x) (sizeof(x)/sizeof(int))
void printaj(int*, int);
int* podniz(int* niz, int start, int stop);
int* filtriraj(int* niz, int n, int th, int* nth);
int** podijeli(int* niz, int n);
typedef struct
{
	float x;
	float y;
}Tocka;
typedef struct
{
	Tocka* vrhovi;
	int broj_vrhova;
}Poligon;
Poligon* novi_poligon(float* niz_x, float* niz_y, int n);
Tocka** pozitivni(Poligon* p, int* np);
int main()
{
	int th = 4;
	int nth = 0;
	int start = 3;
	int stop = 7;
	int velicina = stop - start;
	int glavni_niz[] = { 3,1,4,1,5,9,2,6,5,3,5,9 };
	int n = SIZE(glavni_niz);
	////                ////
	Poligon* p;
	float niz_x[] = { -1, 1, 2, 3, 5, 8, -13 };
	float niz_y[] = { 2, -4, 8, -16, 32, -64, 128 };
	int n1 = SIZE(niz_x);
	int strn = 7;
	////////////////////////
	int* rez0 = podniz(glavni_niz, start, stop);
	printf("Podniz glasi: ");
	printaj(rez0, velicina);//printanje
	free(rez0);
	////////////////////////
	int* rez1 = filtriraj(glavni_niz, n, th, &nth);
	printf("\nFiltriran niz s uvjetom clanova manjih od %d glasi: ", th);
	printaj(rez1, nth);//printanje
	free(rez1);
	////////////////////////
	int** rez2 = podijeli(glavni_niz, n);
	printf("\nPodijeljeni niz, prva polovica glasi: ");
	printaj(rez2[0], (n / 2));//printanje
	printf("\nPodijeljeni niz, druga polovica glasi: ");
	printaj(rez2[1], (n - (n / 2)));//printanje
	free(rez2[0]);
	free(rez2[1]);
	free(rez2);
	////////////////////////
	p = novi_poligon(niz_x, niz_y, n1);
	printf("\nPoligonske tocke: ");
	for (int i = 0; i < strn; i++)
	{
		printf("\n[%f, ", p->vrhovi[i].x);
		printf("%f]\n", p->vrhovi[i].y);
	}
	int np = n1;

	Tocka** Pozitivni = pozitivni(p, &np);
	printf("\nPozitivne poligonske tocke: ");
	for (int i = 0; i < np; i++)
	{
		printf("\n[%f, ", Pozitivni[i]->x);
		printf("%f]\n", Pozitivni[i]->y);
	}
	free(Pozitivni);
	free(p->vrhovi);
	free(p);

	return 0;
}
void printaj(int* niz, int size)
{
	printf("{ ");
	for (int i = 0; i < size; i++)
		printf("[%d] ", niz[i]);
	printf("}\n\n");
}
int* podniz(int* niz, int start, int stop)
{
	int limit = stop - start;
	int* hyponiz = (int*)malloc(limit * sizeof(int));
	if (hyponiz == NULL)
		exit(1);
	for (int i = 0; i < limit; i++)
	{
		hyponiz[i] = niz[start];
		start++;
	}
	return hyponiz;
}
int* filtriraj(int* niz, int n, int th, int* nth)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] < th)
			*nth += 1;
	}
	int* filtrirano = (int*)malloc(*nth * sizeof(int));
	if (filtrirano == NULL)
		exit(1);
	for (int i = 0; i < n; i++)
	{
		if (niz[i] < th)
		{
			filtrirano[temp] = niz[i];
			++temp;
		}
	}
	return filtrirano;
}
int** podijeli(int* niz, int n)
{
	int prva_velicina = n/2;
	int druga_velicina = n - prva_velicina;
	int** cijeli_niz = (int**)malloc(2 * sizeof(int*));
	if (cijeli_niz == NULL)
		exit(1);
	cijeli_niz[0] = (int*)malloc(prva_velicina * sizeof(int));
	if (cijeli_niz[0] == NULL)
		exit(1);
	cijeli_niz[1] = (int*)malloc(druga_velicina * sizeof(int));
	if (cijeli_niz[1] == NULL)
		exit(1);
	for (int i = 0; i < n; i++)
	{
		if (i < prva_velicina)
			cijeli_niz[0][i] = niz[i];
		else
			cijeli_niz[1][i-prva_velicina] = niz[i];
	}
	return cijeli_niz;
}
Poligon* novi_poligon(float* niz_x, float* niz_y, int n)
{
	Poligon* p = (Poligon*)malloc(sizeof(Poligon));
	if (p == NULL)
		exit(1);
	p->vrhovi = (Tocka*)malloc(sizeof(Tocka)*n);
	if (p->vrhovi == NULL)
		exit(1);
	p->broj_vrhova = n;
	for (int i = 0; i < n; i++)
	{
		p->vrhovi[i].x = niz_x[i];
		p->vrhovi[i].y = niz_y[i];
	}
	return p;
}
Tocka** pozitivni(Poligon* p, int* np)
{
	int temp = 0;
	for (int i = 0; i < p->broj_vrhova; i++)
	{
		if ((p->vrhovi[i].x > 0) && (p->vrhovi[i].y > 0))
		{
			++temp;
		}
	}
	*np = temp;
	Tocka** pozitivne_tocke = (Tocka*)malloc(sizeof(Tocka*) * (temp));
	if (pozitivne_tocke == NULL)
		exit(1);
	temp = 0;
	for (int i = 0; i < p->broj_vrhova; i++)
	{
		if ((p->vrhovi[i].x > 0) && (p->vrhovi[i].y > 0))
		{
			pozitivne_tocke[temp] = &(p->vrhovi[i]);
			++temp;
		}
	}
	return pozitivne_tocke;
}