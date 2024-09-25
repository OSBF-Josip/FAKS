#include "unos_ispis.hpp"
#include <iostream>;
void unos_slobodni(vector<int>& vektor, int len)
{
	int i = 0;
	int element;
	cout << "Unosite brojeve u vektor: " << endl;
	for(i;i<len;i++)
	{
		cin >> element;
		vektor.push_back(element);
	}
}
void unos_ograniceni(vector<int>& vektor, int pocetak, int kraj)
{
	int element = pocetak;
	cout << "Unosite brojeve u vektor: " << endl;
	while ((element >= pocetak) && (element <= kraj))
	{
		cin >> element;
		if((element >= pocetak) && (element <= kraj))
			vektor.push_back(element);
	}
}
void ispis(vector<int>& vektor, int len)
{
	cout << "Vektor izgleda ovako: ";
	for (int i = 0; i < len; i++)
	{
		cout << vektor[i] << " ";
	}
	cout << endl;
}