#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string recenica_og = "Ovo je primjer recenice";
	string rijec;
	cout << "Unesite recenicu: ";
	cin >> recenica_og;
	cout << "Unesite rijec: ";
	cin >> rijec;
	for (int i = 0; i < recenica_og.size(); i++)
	{
		if (recenica_og[i] == ' ')
			for (int j = 0; j < rijec.size(); j++)
				recenica_og.insert((recenica_og.begin() + i+j), rijec[j]);
	}
	return 0;
}