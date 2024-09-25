#include "Vjezbanje_vezane_liste.h"
void printaj(Element* list)
{
	while (list != NULL)
	{
		printf("%d --> ", list->broj);
		list = list->next;
	}
	printf("NULL\n");
}
Element* createList(int size) {
	if (size <= 0) return NULL;  

	Element* head = NULL;
	Element* current = NULL;

	for (int i = 0; i < size; i++) {
		Element* newNode = (Element*)malloc(sizeof(Element));  
		if (newNode == NULL) {
			printf("Memory allocation failed\n");
			exit(1);
		}
		newNode->broj = i;         
		newNode->next = NULL;      

		if (head == NULL) {
			head = newNode;        
		}
		else {
			current->next = newNode;  
		}
		current = newNode;       
	}

	return head;
}
Element* ubaci_u_glavu(Element* list, int el)
{
	Element* novi = (Element*)malloc(sizeof(Element));
	if (novi == NULL)
		exit(1);
	novi->broj = el;
	if (list == NULL)
		return novi;
	novi->next = list;
	return novi;
}
Element* ubaci_u_rep(Element* list, int el)
{
	Element* temp = list;
	Element* novi = (Element*)malloc(sizeof(Element));
	if (novi == NULL)
		exit(1);
	novi->broj = el;
	novi->next = NULL;
	if (list == NULL)
		return novi;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = novi;
	return list;
}
Element* ubaci(Element* list, int el, int pos)
{
	Element* temp = list;
	Element* novi = (Element*)malloc(sizeof(Element));
	if (novi == NULL)
		exit(1);
	novi->broj = el;
	novi->next = NULL;
	if (list == NULL)
		return novi;
	if (pos == 0)
	{
		list = ubaci_u_glavu(list, el);
		return list;
	}
	for (int i = 0; i < pos - 2; i++)
	{
		if (temp->next == NULL)
			return;
		temp = temp->next;
	}
	novi->next = temp->next;
	temp->next = novi;
	return list;
}
Element* prvi_na_zadnje(Element* list)
{
	Element* temp = list;
	Element* temp1 = list;
	list = temp->next;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = temp1;
	temp1->next = NULL;
	return list;
}
Element* zadnji_na_prvo(Element* list)
{
	Element* temp = list;
	Element* temp1 = NULL;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp1 = temp->next;
	temp->next = NULL;
	temp1->next = list;
	return temp1;
}
Element* obrisi_prvi(Element* list)
{
	if (list == NULL)
		return NULL;
	Element* mujo = list;
	list = list->next;
	return list;
}
Element* zamijeni_prvi_i_zadnji(Element* list)
{
	Element* temp = list;
	Element* zadnji = list;
	Element* prvi = list;
	while (temp->next != NULL)
	{
		if (temp->next->next == NULL)
		{
			zadnji = temp->next;
			zadnji->next = list->next;
			temp->next = list;
			temp->next->next = NULL;
			list = zadnji;
			break;
		}
		temp = temp->next;
	}
	return list;
}
Element* ukloni_zadnjih_n(Element* list, int quantity)
{
	Element* temp = list;
	Element* zadnji = list;
	int cntr = 0;
	while (temp->next != NULL)
	{
		cntr++;
		temp = temp->next;
	}
	temp = list;
	if (cntr <= quantity)
	{
		return NULL;
	}
	for (int i = 0; i < (cntr - quantity); i++)
	{
		temp = temp->next;
	}
	zadnji = temp;
	temp->next = NULL;
	return list;
}
Element* dodaj_iza_parnih(Element* list)
{
	Element* temp = list;
	Element* parni = list;
	Element* iduci = list;
	while (temp != NULL)
	{
		if (temp->broj % 2 == 0)
		{
			Element* n = (Element*)malloc(sizeof(Element));
			n->broj = 69;
			parni = temp;
			iduci = temp->next;
			n->next = iduci;
			parni->next = n;
		}
		temp = temp->next;
	}
	return list;
}
Element* dodaj_iz_niza(Element* list, int* niz)
{
	int i = 0;
	Element* temp = list;
	while (i < 8)
	{
		temp->broj = niz[i];
		temp = temp->next;
		i++;
	}
	return list;
}
Element* prvi_veci(Element* list, int n)
{
	Element* temp = list;
	Element* pokazivac = NULL;
	while (temp->next != NULL)
	{
		if (temp->broj > n)
		{
			pokazivac = temp;
			return pokazivac;
		}
		temp = temp->next;
	}
	return pokazivac;
}
void spoji(Element* prva, Element* druga)
{
	Element* temp = prva;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = druga;
}
void brisi_izmedu_indexa(Element* lista, int a, int b)
{
	Element* temp = lista;
	Element* prva = NULL;
	Element* druga = NULL;
	int cntr = 0;
	while (temp->next != NULL)
	{
		if (cntr == a)
			prva = temp;
		if (cntr == b)
			druga = temp;
		temp = temp->next;
		cntr++;
	}
	prva->next = druga;
}
int uzlazno(Element* lista)
{
	Element* temp = lista;
	while (temp->next != NULL)
	{
		if (temp->next->broj < temp->broj)
			return 0;
		temp = temp->next;
	}
	return 1;
}
svako_drugi(Element* lista)
{
	Element* temp = lista;
	while (temp->next != NULL)
	{
		temp->next = temp->next->next;
		temp = temp->next;
		if (!temp)
			break;
	}
}
Element* prvi_iz_druge_na_kraj_prve(Element* lista1, Element* lista2)
{
	if (lista1 == NULL || lista2 == NULL)
		return NULL;
	Element* temp = lista1;
	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = lista2;
	lista2 = lista2->next;
	temp->next->next = NULL;
	return lista1;

	//alternativno:
	//Element* novi = (Element*)malloc(sizeof(Element));
	//if (novi == NULL)
	//	exit(1);
	//if (lista2 == NULL) {
	//	if (lista1 == NULL)
	//		return NULL;
	//	else
	//		return lista1;
	//}
	//novi->broj = lista2->broj;
	//novi->next = NULL;
	//if (lista1 == NULL)
	//	return novi;
	//Element* temp = lista1;
	//while (temp->next != NULL) {
	//	temp = temp->next;
	//}
	//temp->next = novi;
	//return lista2;
}
Element* brisi_sve_djeljivo_sa_el(Element* lista, int n)
{
	if (lista == NULL)
		return lista;
	Element* store = lista;
	Element* temp = lista;
	Element* previous = lista;
	Element* prvi = lista;
	if ((temp->broj % n) == 0)
		while ((temp->broj % n) == 0) {
			temp = temp->next;
		}
	prvi = temp;
	temp = lista;
	while (temp->next != NULL) {
		if ((temp->broj % n) == 0) {
			store = temp;
			temp = temp->next;
			previous ->next = temp;
			free(store);
		}
		else {
			previous = temp;
			temp = temp->next;
			store = temp;
		}
	}
	if ((temp->broj % n) == 0)
		temp = NULL;
	return prvi;
}