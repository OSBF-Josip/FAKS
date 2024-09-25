#include <iostream>
#include <vector>
#include <algorithm>
#include "unos_ispis.hpp"
using namespace std;
void max_min(vector<int>&, int&, int&);
int main()
{
	int vek_niz[] = { 2,4,6,8,10,1,3,5,7,9 };
	int suma = 0;
	int min_i, max_i;
	min_i = max_i = 0;
	vector<int>v0 = { vek_niz + 0, vek_niz + 10 };
	//unos_slobodni(v0, 10);
	ispis(v0, (int)v0.size());
	max_min(v0, min_i, max_i);
	printf("\n\n");
	for (int i = (max_i + 1); i < v0.size(); i++)
	{
		suma += v0.at(i);
	}
	cout <<"Ovo je suma svih brojeva iza najveceg u vektoru: "<< endl;
	cout << suma;
	printf("\n\n");
	v0.insert((v0.begin()+min_i), 0);
	cout << "Ovo je unesena 0 ispred najmanjeg elementa: " << endl;
	ispis(v0, (int)v0.size());
	sort(v0.begin(), v0.end());
	printf("\n\n");
	cout << "Ovo je sortiran vektor: " << endl;
	ispis(v0, (int)v0.size());
	printf("\n\n");
}
void max_min(vector<int>& v0, int& min_i, int& max_i)
{
	int min_num = v0[0];
	int max_num = v0[0];
	min_i = 0;
	max_i = 0;
	for (int i = 0;i<v0.size();i++)
	{
		if (v0[i] >= max_num)
		{
			max_num = v0[i];
			max_i = i;
		}
		if (v0[i] <= min_num)
		{
			min_num = v0[i];
			min_i = i;
		}
	}
}