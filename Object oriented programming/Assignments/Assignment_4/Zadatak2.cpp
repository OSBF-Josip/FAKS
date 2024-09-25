#include <iostream>
#include <string>
using namespace std;
void ispravak(string&);
int main()
{
	string recenica = "Ja bih ,ako ikako mogu,ovu recenicu , napisao, ispravno. Kljucna je i , interpunkcija .";
	cout << recenica << endl;
	ispravak(recenica);
	cout << recenica << endl;
	return 0;
}
void ispravak(string& original)
{
	string novi;
	string::iterator it = original.begin();
	int cntr = 0;
	for (int i = 0; i<original.size(); i++)
	{
		if (original[i] == ',' || original[i] == '.')
		{
			if (original[i - 1] == ' ')
			{
				original.erase(it + (i - 1));
				
			}
		}
	}
	novi = original;
	it = novi.begin();
	for (int i = 0; i < novi.size(); i++)
	{
		if (novi[i] == ',' || novi[i] == '.')
		{
			if (novi[i + 1] != ' ')
			{
				novi.insert(it + i + 1, ' ');
			}
		}
	}
	original = novi;
}