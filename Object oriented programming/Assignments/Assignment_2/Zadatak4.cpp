#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;
struct Matrica
{
	float element;
	int broj_redaka;
	int broj_stupaca;
	float** m;
	void unos()
	{
		m = new float* [broj_redaka];
		for (int i = 0; i < broj_redaka; i++)
		{
			m[i] = new float[broj_stupaca];
		}
		for (int i = 0; i < broj_redaka; i++)
		{
			for (int j = 0; j < broj_stupaca; j++)
			{
				cin >> element;
				m[i][j] = element;
			}
		}
	}
	void generiraj(int min_value, int max_value)
	{
		m = new float* [broj_redaka];
		for (int i = 0; i < broj_redaka; i++)
		{
			m[i] = new float[broj_stupaca];
		}
		for (int i = 0; i < broj_redaka; i++)
		{
			for (int j = 0; j < broj_stupaca; j++)
			{
				element = min_value + rand() % (max_value - min_value + 1);
				m[i][j] = element;
			}
		}
	}
	Matrica zbroji(Matrica A, Matrica B)
	{
		Matrica rez = A;
		if ((A.broj_redaka == B.broj_redaka) && (A.broj_stupaca == B.broj_stupaca))
		{
			for (int i = 0; i < rez.broj_redaka; i++)
			{
				for (int j = 0; j < rez.broj_stupaca; j++)
				{
					rez.m[i][j] = (A.m[i][j] + B.m[i][j]);
				}
			}
		}
		else
			cout << "Dimenzije moraju biti iste!" << endl;
		return rez;
	}
	Matrica oduzmi(Matrica A, Matrica B)
	{
		Matrica rez = A;
		if ((A.broj_redaka == B.broj_redaka) && (A.broj_stupaca == B.broj_stupaca))
		{
			for (int i = 0; i < rez.broj_redaka; i++)
			{
				for (int j = 0; j < rez.broj_stupaca; j++)
				{
					rez.m[i][j] = (A.m[i][j] - B.m[i][j]);
				}
			}
		}
		else
			cout << "Dimenzije moraju biti iste!" << endl;
		return rez;
	}
	Matrica mnozi(Matrica A, Matrica B)
	{
		int j = 0;
		int k = 0;
		int cntr = 0;
		float temp = 0;
		Matrica rez;
		rez.broj_redaka = A.broj_redaka;
		rez.broj_stupaca = B.broj_stupaca;
		rez.m = new float* [rez.broj_redaka];
		for (int i = 0; i < rez.broj_redaka; i++)
		{
			rez.m[i] = new float[rez.broj_stupaca];
		}
		for (int i = 0; i < A.broj_redaka; i++)
		{
			for (int j = 0; j < B.broj_stupaca; j++)
			{
				rez.m[i][j] = 0;
				for (int k = 0; k < A.broj_stupaca; k++)
				{
					rez.m[i][j] += (A.m[i][k] * B.m[k][j]);
				}
			}
		}
		return rez;
	}
	Matrica transponiraj(Matrica A)
	{
		Matrica rez;
		rez.broj_redaka = A.broj_stupaca;
		rez.broj_stupaca = A.broj_redaka;
		rez.m = new float* [rez.broj_redaka];
		for (int i = 0; i < rez.broj_redaka; i++)
		{
			rez.m[i] = new float[rez.broj_stupaca];
		}
		for(int i = 0;i<A.broj_redaka;i++)
			for (int j = 0; j < A.broj_stupaca; j++)
			{
				rez.m[j][i] = A.m[i][j];
			}
		return rez;
	}
	void ispis()
	{
		for (int i = 0; i < broj_redaka; i++)
		{
			for (int j = 0; j < broj_stupaca; j++)
				cout << fixed << setprecision(4) << right << m[i][j] << " ";
			cout << endl;
		}
	}
};
int main()
{
	int min_value;
	int max_value;
	string op;
	Matrica mater, caca, rezultat;
	cout << "Unesite broj redaka za vasu matricu: " << endl;
	cin >> mater.broj_redaka;
	cout << "Unesite broj stupaca za vasu matricu: " << endl;
	cin >> mater.broj_stupaca;
	cout << "Unosite clanove vase matrice: " << endl;
	mater.unos();
	mater.ispis();
	cout << "Unesite broj redaka za nasumicnu matricu: " << endl;
	cin >> caca.broj_redaka;
	cout << "Unesite broj stupaca za nasumicnu matricu: " << endl;
	cin >> caca.broj_stupaca;
	cout << "Unesite raspon clanova u matrici: " << endl<< "Od: ";
	cin >> min_value;
	cout << "Do: ";
	cin >> max_value;
	caca.generiraj(min_value, max_value);
	caca.ispis();
	cout << "(Zbroji/oduzmi/mnozi/trans)Unesite zeljenu operaciju: " << endl;
	cin >> op;

	if (op == "zbroji")
	{
		rezultat = rezultat.zbroji(mater, caca);
		rezultat.ispis();
	}
	else if (op == "oduzmi")
	{
		rezultat = rezultat.oduzmi(mater, caca);
		rezultat.ispis();
	}
	else if (op == "mnozi")
	{
		rezultat = rezultat.mnozi(mater, caca);
		rezultat.ispis();
	}
	else if (op == "trans")
	{
		cout << "Prvu ili drugu? ";
		cin >> op;
		if (op == "prvu")
		{
			rezultat = rezultat.transponiraj(mater);
			rezultat.ispis();
		}
		else
		{
			rezultat = rezultat.transponiraj(caca);
			rezultat.ispis();
		}
	}
	else
		cout << "\t\t\tne" << endl;
	delete[] mater.m;
	delete[] caca.m;
	delete[] rezultat.m;
	return 0;
}