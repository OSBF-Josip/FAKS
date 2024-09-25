#include "unos_ispis.hpp"
#include <iostream>
#include <vector>

int main()
{
	vector<int> v0;
	vector<int> v1;
	vector<int> v2;
	int len0;
	int pocetak;
	int kraj;
	cout << "Unesite zeljenu duljinu vektora: " << endl;
	cin >> len0;
	unos_slobodni(v0, len0);
	cout << "Sada unesite drugi vektor u intervalu: " <<endl;
	cout << "Pocetak intervala: ";
	cin >> pocetak;
	cout << "Kraj intervala: ";
	cin >> kraj;
	unos_ograniceni(v1, pocetak, kraj);
	int len1 = v1.size();
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len0; j++)
		{
			if (v1[i] == v0[j])
				break;
			else if (j == (len0-1))
			{
				v2.push_back(v1[i]);
			}
		}
	}
	int len2 = v2.size();
	cout << "Drugi vektor bez clanova prvog vektora glasi: "<<endl;
	ispis(v2, len2);
	return 0;
}