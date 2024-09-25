#include "Funckije.h"
void printaj(const int* niz, const int len)
{
	printf("\nNiz glasi: [ ");
	for (int i = 0; i < len; i++)
	{
		if (i != (len - 1))
			printf("%d, ", niz[i]);
		else
			printf("%d ]", niz[i]);
	}
	printf(" \n");
}
int velicina(const char* string)
{
	int i = 0;
	for (i; string[i] != '\0'; i++);
	return i;
}
int* repetitio(const int* niz0, const int len0, const int* niz1, const int len1, int* rez_len)
{
	int cntr = 0;
	for (int i = 0; i < len0; i++)
	{
		for (int j = 0; j < len1; j++)
		{
			if (niz0[i] == niz1[j])
				cntr++;
		}
	}
	*rez_len = cntr;
	int* rez_niz = (int*)malloc(cntr * INT);
	if (rez_niz == NULL)
		exit(1);
	cntr = 0;
	for (int i = 0; i < len0; i++)
	{
		for (int j = 0; j < len1; j++)
		{
			if (niz0[i] == niz1[j])
			{
				rez_niz[cntr] = niz0[i];
				cntr++;
			}
		}
	}
	return rez_niz;
}
void vertite(int* niz, const int len)
{
	int* temp_niz = (int*)malloc(len * INT);
	if (temp_niz == NULL)
		exit(1);
	int j = 0;
	for (int i = (len - 1); i >= 0; i--)
	{
		temp_niz[j] = niz[i];
		j++;
	}
	for (int i = 0; i < len; i++)
	{
		niz[i] = temp_niz[i];
	}
	free(temp_niz);
}
void reponere(int* niz, const int len)
{
	int prvi_parni = len + 1;
	int zadnji_neparni = len + 1;
	int temp = 0;
	for (int i = 0; i < len; i++)
	{
		if (niz[i] % 2 == 0)
		{
			prvi_parni = i;
			break;
		}
	}
	for (int i = (len - 1); i >= 0; i--)
	{
		if (niz[i] % 2 != 0)
		{
			zadnji_neparni = i;
			break;
		}
	}
	if (prvi_parni < len && zadnji_neparni < len)
	{
		temp = niz[prvi_parni];
		niz[prvi_parni] = niz[zadnji_neparni];
		niz[zadnji_neparni] = temp;
	}
	else
		printf("\nNije pronaden neparan/paran broj!\n");
}
int* duplici(const int* niz, const int len, int* new_len)
{
	int pos = 0;
	int flag = 0;
	int* novi_niz = (int*)malloc(len * INT);
	if (novi_niz == NULL)
		exit(1);
	for (int i = 0; i < len; i++)
	{
		flag = 1;
		for (int j = i; j >= 0; j--)
		{
			if (i != j)
			{
				if (niz[i] == niz[j])
				{
					flag = 0;
				}
			}
		}
		if (flag)
		{
			novi_niz[pos] = niz[i];
			pos++;
		}
	}
	*new_len = pos;
	int* rez_niz = realloc(novi_niz, pos * INT);
	return rez_niz;
}
int* effingo(const int* niz, const int len, int start, int end)
{
	int* novi_niz = (int*)malloc((end - start + 1) * INT);
	if (novi_niz == NULL)
		exit(1);
	int pos = 0;
	for (int i = start; i <= end; i++)
	{
		novi_niz[pos] = niz[i];
		pos++;
	}
	return novi_niz;
}
int* addere_in_medio(const int* niz, const int len, const int num)
{
	int* novi_niz = (int*)malloc((len + 1) * INT);
	if (novi_niz == NULL)
		exit(1);
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		if (i == (len / 2))
		{
			novi_niz[i] = num;
			j++;
		}
		novi_niz[j] = niz[i];
		j++;
	}
	return novi_niz;
}
int* ab_initio(const int* niz, const int len)
{
	int j = 0;
	int* novi_niz = (int*)malloc((len - 1) * INT);
	if (novi_niz == NULL)
		exit(1);
	for (int i = 1; i < len; i++)
	{
		novi_niz[j] = niz[i];
		j++;
	}
	return novi_niz;
}
int* conditionalis_remotionem(const int* niz, const int len, const int uvjet, int* rez_len)
{
	int cntr = 0;
	for (int i = 0; i < len; i++)
	{
		if (niz[i] % 2 == uvjet % 2)
			cntr++;
	}
	int* novi_niz = (int*)malloc(cntr * INT);
	*rez_len = cntr;
	if (novi_niz == NULL)
		exit(1);
	cntr = 0;
	for (int i = 0; i < len; i++)
	{
		if (niz[i] % 2 == uvjet % 2)
		{
			novi_niz[cntr] = niz[i];
			cntr++;
		}
	}
	return novi_niz;
}
char* ultimum_verbum(const char* string, const int len)
{
	int cntr = 0;
	int j = 0;
	for (int i = len; string[i] != ' '; i--)
		cntr++;
	char* novi_string = (char*)malloc(cntr);
	for (int i = (len - cntr + 1); i <= len; i++)
	{
		novi_string[j] = string[i];
		j++;
	}
	return novi_string;
}
char** separatum(const char* string, const int len)
{
	int prva_len = 0;
	int druga_len = 0;
	int i = 0;
	for (i; string[i] != ' '; i++); //pod uvjetom da su rijeci odvojene razmakom
	prva_len = i + 1; //dodajemo 1 za \0
	druga_len = len - i; //1 viska za \0 oduzimanjem
	char** novi_zbirni_string = (char**)malloc(2 * sizeof(char*));
	if (novi_zbirni_string == NULL)
		exit(1);
	novi_zbirni_string[0] = (char*)malloc(prva_len);
	if (novi_zbirni_string[0] == NULL)
		exit(1);
	novi_zbirni_string[1] = (char*)malloc(druga_len);
	if (novi_zbirni_string[1] == NULL)
		exit(1);
	i = 0;
	for (int j = 0; j < prva_len; j++)
		novi_zbirni_string[0][j] = string[j];
	novi_zbirni_string[0][prva_len - 1] = '\0';
	for (int k = (prva_len); k < len; k++)
	{
		novi_zbirni_string[1][i] = string[k];
		i++;
	}
	novi_zbirni_string[1][druga_len - 1] = '\0';
	return novi_zbirni_string;
}
int* ligaris(const int* niz1, const int len1, const int* niz2, const int len2, int* rez_len)
{
	*rez_len = (len1 + len2);
	int* novi_niz = (int*)malloc(*rez_len * INT);
	if (novi_niz == NULL)
		exit(1);
	int j = 0;
	for (int i = 0; i < *rez_len; i++)
	{
		if (i >= len1)
		{
			novi_niz[i] = niz2[j];
			j++;
		}
		else
			novi_niz[i] = niz1[i];
	}
	return novi_niz;
}
int* extrahere(const int* niz, const int len, int* rez_len)
{
	int cntr = 0;
	for (int i = 0; i < len; i++)
	{
		if (niz[i] % 2 != 0)
			cntr++;
	}
	*rez_len = cntr;
	int* novi_niz = (int*)malloc(cntr * INT);
	if (novi_niz == NULL)
		exit(1);
	cntr = 0;
	for (int i = 0; i < len; i++)
	{
		if (niz[i] % 2 != 0)
		{
			novi_niz[cntr] = niz[i];
			cntr++;
		}
	}
	return novi_niz;
}
Poligon* novi_poligon(const int* niz_x, const int* niz_y, const int len)
{
	Poligon* p = (Poligon*)malloc(sizeof(Poligon));
	if (p == NULL)
		exit(1);
	p->vrhovi = (Tocka*)malloc(len * sizeof(Tocka));
	if (p->vrhovi == NULL)
		exit(1);
	p->broj_tocaka = len;
	for (int i = 0; i < len; i++)
	{
		p->vrhovi[i].x = niz_x[i];
		p->vrhovi[i].y = niz_y[i];
	}
	return p;
}
Tocka** pozitivni(Poligon* p, int* rez_len)
{
	int temp = 0;;
	for (int i = 0; i < p->broj_tocaka; ++i)
		if ((p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0))
			temp++;
	Tocka** poz = (Tocka*)malloc(temp * sizeof(Tocka*));
	if (poz == NULL)
		exit(1);
	*rez_len = temp;
	temp = 0;
	for (int i = 0; i < p->broj_tocaka; i++)
	{
		if (p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0)
		{
			poz[temp] = &(p->vrhovi[i]);
			temp++;
		}
	}
	return poz;
}