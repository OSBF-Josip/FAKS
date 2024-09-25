#include "funkcije.h"
void poziv_presjek(int pocetak, int kraj, int korak)
{
	printf("\n\nOvo je PRESJEK:\n");
	srand((unsigned int)time(NULL));
	for (int n = pocetak; n < kraj; n += korak) {
		int* niz0 = generate(n);
		int* niz1 = generate(n);
		shuffle(niz0, n);
		shuffle(niz1, n);

		int stime = clock();
		//
		int len_presjek = presjek(niz0, niz1, n);
		//
		int etime = clock();

		printf("\nn = %d\tt = %f s\t A/B = %d\n", n, ((float)(etime - stime)) / CLOCKS_PER_SEC, len_presjek);
		free(niz0);
		free(niz1);
	}
}
void poziv_presjek_jedan_sortiran(int pocetak, int kraj, int korak)
{
	printf("\n\nOvo je PRESJEK JEDAN SORTIRAN:\n");
	srand((unsigned int)time(NULL));
	for (int n = pocetak; n < kraj; n += korak) {
		int* niz0 = generate(n);
		int* niz1 = generate(n);
		shuffle(niz0, n);
		shuffle(niz1, n);

		int stime = clock();
		//
		int len_presjek = presjek_jedan_sortiran(niz0, niz1, n);
		//
		int etime = clock();

		printf("\nn = %d\tt = %f s\t A/B = %d\n", n, ((float)(etime - stime)) / CLOCKS_PER_SEC, len_presjek);
		free(niz0);
		free(niz1);
	}
}
void poziv_presjek_oba_sortirana(int pocetak, int kraj, int korak)
{
	printf("\n\nOvo je PRESJEK OBA SORTIRANA:\n");
	srand((unsigned int)time(NULL));
	for (int n = pocetak; n < kraj; n += korak) {
		int* niz0 = generate(n);
		int* niz1 = generate(n);
		shuffle(niz0, n);
		shuffle(niz1, n);

		int stime = clock();
		//
		int len_presjek = presjek_oba_sortirana(niz0, niz1, n);
		//
		int etime = clock();

		printf("\nn = %d\tt = %f s\t A/B = %d\n", n, ((float)(etime - stime)) / CLOCKS_PER_SEC, len_presjek);
		free(niz0);
		free(niz1);
	}
}
void poziv_presjek_po_indeksima(int pocetak, int kraj, int korak)
{
	printf("\n\nOvo je PRESJEK PO INDEKSIMA:\n");
	srand((unsigned int)time(NULL));
	for (int n = pocetak; n < kraj; n += korak) {
		int* niz0 = generate(n);
		int* niz1 = generate(n);
		shuffle(niz0, n);
		shuffle(niz1, n);

		int stime = clock();
		//
		int len_presjek = presjek_po_indeksima(niz0, niz1, n);
		//
		int etime = clock();

		printf("\nn = %d\tt = %f s\t A/B = %d\n", n, ((float)(etime - stime)) / CLOCKS_PER_SEC, len_presjek);
		free(niz0);
		free(niz1);
	}
}
int cmp(const void* a, const void* b) {
	return *((int*)a) - *((int*)b);
}
int* generate(int n) {
	int* niz = (int*)malloc(n * sizeof(int));
	if (niz == NULL)
		exit(1);
	niz[0] = 1 + rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 5;
	}
	return niz;
}
void shuffle(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		int j = RANDOM % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}
int presjek(int* skup_a, int* skup_b, int len)
{
	int cntr = 0;
	for(int i = 0;i<len;i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (skup_a[i] == skup_b[j])
			{
				cntr++;
				break;
			}
		}
	}
	return cntr;
}
int presjek_jedan_sortiran(int* skup_a, int* skup_b, int len)
{
	int cntr = 0;
	qsort(skup_b, len, sizeof(int), cmp);
	for (int i = 0; i < len; i++)
	{
		if (bsearch(&skup_a[i], skup_b, len, sizeof(int), cmp))
			cntr++;
	}
	return cntr;
}
int presjek_oba_sortirana(int* skup_a, int* skup_b, int len)
{
	int cntr = 0;
	int i = 0;
	int j = 0;
	qsort(skup_a, len, sizeof(int), cmp);
	qsort(skup_b, len, sizeof(int), cmp);
	while (i < len && j < len)
	{
		if (skup_a[i] < skup_b[j])
			i++;
		else if(skup_a[i] > skup_b[j])
			j++;
		else
		{
			i++;
			j++;
			cntr++;
		}
	}
	return cntr;
}
int presjek_po_indeksima(int* skup_a, int* skup_b, int len)
{
	int cntr = 0;
	int max_a = 0;
	int max_b = 0;
	for (int i = 0; i < len; i++)
	{
		if (skup_a[i] > max_a)
			max_a = skup_a[i];
		if (skup_b[i] > max_b)
			max_b = skup_b[i];
	}
	int* index_a = (int*)calloc((max_a + 1), sizeof(int));
	if (index_a == NULL)
		exit(1);
	int* index_b = (int*)calloc((max_b + 1), sizeof(int));
	if (index_b == NULL)
		exit(1);
	for (int i = 0; i < len; i++)
	{
		index_a[skup_a[i]] = 1;
		index_b[skup_b[i]] = 1;
 	}
	int bot = min(max_a, max_b);
	for (int i = 0; i < bot; i++)
	{
		if ((index_a[i] == 1) && (index_b[i] == 1))
			cntr++;
	}
	free(index_a);
	free(index_b);
	return cntr;
}