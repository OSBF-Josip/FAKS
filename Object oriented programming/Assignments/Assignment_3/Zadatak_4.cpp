#include <iostream>
#include <vector>
#include "unos_ispis.hpp"
using namespace std;
void ukloni(vector<int>&, int, int&);
int main()
{
	vector<int> v0;
	int n;
	cout << "Unesite zeljenu duljinu vektora: ";
	cin >> n;
	unos_slobodni(v0, n);
	int len = v0.size();
	ispis(v0, len);
	cout << "Unesite koji broj zelite maknuti iz vektora:" << endl;
	cin >> n;
	ukloni(v0, n, len);
	--len;
	ispis(v0, len);
	return 0;
}
void ukloni(vector<int>& vektor, int check, int& len)
{
	vector<int>::iterator it = vektor.begin();
	for (int i = 0; i < len; i++)
	{
		if (vektor[i] == check)
		{
			vektor.erase((it + i));
			break;
		}
	}
}