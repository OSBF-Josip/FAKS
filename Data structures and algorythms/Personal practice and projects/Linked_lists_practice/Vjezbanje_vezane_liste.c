#include "Vjezbanje_vezane_liste.h"
#
int main()
{
	int* niz1 = (int*)malloc(sizeof(int) * 10);
	if (!niz1)
		exit(1);
	for (int i = 0; i < 9; i++)
	{
		niz1[i] = i;
	}
	int niz[] = { 1,2,3,4,5,6,7,8,9 };
	Element* lista = NULL;
	Element* lista1 = NULL;
	Element* lista2 = NULL;
	Element* lista3 = NULL;
	Element* lista4 = NULL;
	Element* lista5 = NULL;
	Element* lista6 = NULL;
	Element* lista7 = NULL;
	Element* lista8 = NULL;
	Element* lista9 = NULL;
	Element* lista10 = (Element*)malloc(sizeof(Element)*10);
	Element* lista11 = NULL;
	Element a, b, c, d, e, f, g, h;
	Element i, j, k, l, m, n, o, p;
	{
		a.broj = 1;
		b.broj = 2;
		c.broj = 3;
		d.broj = 4;
		e.broj = 5;
		f.broj = 6;
		g.broj = 7;
		//h.broj = 8;
		//h.next = NULL;
		//g.next = &h;
		g.next = NULL;
		f.next = &g;
		e.next = &f;
		d.next = &e;
		c.next = &d;
		b.next = &c;
		a.next = &b;
		lista = &a;
	}
	{

		i.broj = 10;
		j.broj = 12;
		k.broj = 13;
		l.broj = 14;
		m.broj = 15;
		n.broj = 16;
		o.broj = 17;
		p.broj = 18;
		p.next = NULL;
		o.next = &p;
		n.next = &o;
		m.next = &n;
		l.next = &m;
		k.next = &l;
		j.next = &k;
		i.next = &j;
		lista1 = &i;
	}
	printf("LISTA0: \t");
	printaj(lista);
	//lista1 = ubaci_u_glavu(lista, 5);
	printf("LISTA1: \t"); 
	printaj(lista1);
	//spoji(lista, lista1);
	//brisi_izmedu_indexa(lista, 2, 5);
	//svako_drugi(lista);
	lista = prvi_iz_druge_na_kraj_prve(lista, lista1);
	//printf("\n UZLAZNA 0 ILI 1: %d\n", uzlazno(lista));

	/*lista2 = ubaci_u_rep(lista, 9);
	printf("LISTA2: \t");
	printaj(lista2);*/
	//lista3 = ubaci(lista, 69, 4);
	//printf("LISTA3: \t");
	//printaj(lista3);
	//lista4 = prvi_na_zadnje(lista);
	//printf("LISTA4: \t");
	//printaj(lista4);
	//printf("LISTA5: \t");
	//lista5 = zadnji_na_prvo(lista);
	//printaj(lista5);
	//printf("LISTA6: ");
	//lista6 = obrisi_prvi(lista);
	//printaj(lista6);
	//printf("LISTA7: \t");
	//lista7 = zamijeni_prvi_i_zadnji(lista);
	//printaj(lista7);
	//printf("LISTA8: \t");
	//lista8 = ukloni_zadnjih_n(lista, 3);
	//printaj(lista8);
	//printf("LISTA9: \t");
	//lista9 = dodaj_iza_parnih(lista);
	//printaj(lista9);
	//int size = 10;
	//lista10 = createList(size);
	//printf("LISTA10: \t");
	//lista10 = dodaj_iz_niza(lista, niz);
	//printaj(lista10);
	//printf("LISTA11: \t");
	//lista11 = prvi_veci(lista, 6);
	//printaj(lista11);
	//Element* listus = (Element*)malloc(sizeof(Element));
	//listus = brisi_sve_djeljivo_sa_el(lista10, 2);
	printf("NOVA LISTA: \t");
	printaj(lista);
	return 0;
}