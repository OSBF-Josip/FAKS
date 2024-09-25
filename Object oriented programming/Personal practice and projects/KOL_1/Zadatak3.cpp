#include <iostream>
#include <vector>
using namespace std;
void transform(vector<int>&);
int main()
{
	int unos = 1;
	vector<int> vek;
	cout << "Unosite brojeve: "<<endl;
	while (unos != 0)
	{
		cin >> unos;
		vek.push_back(unos);
	}
	transform(vek);
	for (int i = 0; i < vek.size(); i++)
	{
		cout << vek[i]<<" ";
	}
	return 0;
}
void transform(vector<int>& vek)
{
	for (int i = 0; i < vek.size(); i++)
	{
		cout << "Ovo je " << i + 1 << " korak:" << endl;
		while(vek[i]!=2 && vek[i] != 4 && vek[i] != 8 && vek[i] != 16 && vek[i]!= 0)
		{
			if (vek[i] % 2 == 0)
			{
				vek[i] = vek[i] / 2;
				cout << vek[i]<<" ";
			}
			else
			{
				vek[i] = vek[i] * 3 + 1;
				cout << vek[i] << " ";
			}
		}
	}
}