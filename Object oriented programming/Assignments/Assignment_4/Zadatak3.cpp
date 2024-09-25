#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void obrni(vector<string>&);
int main()
{
	vector<string> vs;
	string unos_string;
	cout << "Unesite 3 stringa:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> unos_string;
		vs.push_back(unos_string);
	}
	obrni(vs);
	cout << vs[0] << endl << vs[1] << endl << vs[2] << endl;
	return 0;
}
void obrni(vector<string>& vs)
{
	for (int i = 0; i < vs.size(); i++)
	{
		reverse(vs[i].begin(), vs[i].end());
	}
	sort(vs.begin(), vs.end());
}