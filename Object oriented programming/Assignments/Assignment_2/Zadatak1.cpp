#include <iostream>
using namespace std;
int*& min_max(int*, int);
int main()
{
	int len = 10;
	int* niz = new int[len] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int* pozicija = min_max(niz, len);
	cout << "Ovo je najmanji broj u nizu: " << pozicija[0] << ", a ovo je najveci broj u nizu: " << pozicija[1] << endl;
	delete[] niz;
	delete[] pozicija;
	return 0;
}
int*& min_max(int* niz, int len)
{
	int min = niz[0];
	int max = niz[0];
	int* pozicija_temp = new int[2] {0, 0};
	for (int i = 0; i<len;i++)
	{
		if (niz[i] <= min)
			min = niz[i];
		if (niz[i] >= max)
			max = niz[i];
	}
	pozicija_temp[0] = min;
	pozicija_temp[1] = max;
	return pozicija_temp;
}