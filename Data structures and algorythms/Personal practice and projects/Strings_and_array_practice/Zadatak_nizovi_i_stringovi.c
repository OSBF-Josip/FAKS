#include "Funckije.h"
int main()
{
	int niz0[] = { 1,2,3,4,5,6,7,8,9,10 };
	int niz1[] = { 1,2,22,12,50,6,7,22,1,5,13,69,17 };
	int niz2[] = { -1,2,-3,5,2,8,2,4,5,-1 };
	int niz3[] = { 0,1,2,3,-4,5,6,-7,8,9 };
	char* string0 = "Za domovinu mrijeti kolika slast!";
	char* string1 = "Anathema sit";
	int len0 = SIZE(niz0);
	int len1 = SIZE(niz1);
	int len2 = SIZE(niz2);
	int len3 = SIZE(niz3);
	int str_len0 = velicina(string0);
	int str_len1 = velicina(string1);
	int rez_len;
	int pos1 = 3;
	int pos2 = 8;
	int nuovo = 69;
	int* rez0 = repetitio(niz0, len0, niz1, len1, &rez_len);
	printaj(rez0, rez_len);//////////
	free(rez0);
	vertite(niz0, len0);
	printaj(niz0, len0);//////////
	reponere(niz0, len0);
	printaj(niz0, len0);//////////
	int* rez1 = duplici(niz2, len2, &rez_len);
	printaj(rez1, rez_len);//////////
	free(rez1);
	int* rez2 = effingo(niz0, len0, pos1, pos2);
	printaj(rez2, (pos2 - pos1)+1);//////////
	free(rez2);
	int* rez3 = addere_in_medio(niz0, len0, nuovo);
	printaj(rez3, (len0 + 1));//////////
	free(rez3);
	int* rez4 = ab_initio(niz3, len3);
	printaj(rez4, (len3 - 1));//////////
	free(rez4);
	int* rez5 = conditionalis_remotionem(niz3, len3, 3, &rez_len);
	printaj(rez5, rez_len);//////////
	free(rez5);
	char* rez_string0 = ultimum_verbum(string0, str_len0);
	printf("\nOvako glasi string:\n\n\t%s\n", rez_string0);
	free(rez_string0);
	char** rez_string1 = separatum(string1, str_len1);
	printf("\nOvako glasi string:\n\n\t%s\n", rez_string1[0]);
	printf("\nOvako glasi string:\n\n\t%s\n", rez_string1[1]);
	free(rez_string1[0]);
	free(rez_string1[1]);
	free(rez_string1);
	int* rez6 = ligaris(niz3, len3, niz0, len0, &rez_len);
	printaj(niz3, len0);//////////
	printaj(niz0, len0);//////////
	printaj(rez6, rez_len);//////////
	free(rez6);
	int* rez7 = extrahere(niz3, len3, &rez_len);
	printaj(rez7, rez_len);
	free(rez7);
	Poligon* p = novi_poligon(niz2, niz3, len3);
	printf("Poligon glasi:\n");
	printf("\nX: | ");
	for (int i = 0; i < len3; i++)
	{
		printf("%f ", p->vrhovi[i].x);
	}
	printf("\n\nY: | ");
	for (int i = 0; i < len3; i++)
	{
		printf("%f ", p->vrhovi[i].y);
	}
	printf("\n\n");
	Tocka** poz = pozitivni(p, &rez_len);
	printf("\nPozitivne poligonske tocke: ");
	for (int i = 0; i < rez_len; i++)
	{
		printf("\n[%f, ", poz[i]->x);
		printf("%f]\n", poz[i]->y);
	}
	free(poz);
	free(p->vrhovi);
	free(p);
	return 0;
}