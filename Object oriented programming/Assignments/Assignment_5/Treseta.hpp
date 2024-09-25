#ifndef TRESETA
#define TRESETA
#include <string>
#include <algorithm>
#include <random>
#include <iostream>
#include <iomanip>
using namespace std;
class Karta
{
public:
	string zog;
	int broj;

};
class Igrac
{
public:
	Karta* ruka;
	string ime;
	int broj_bodova = 0;
	void akuza()
	{
		int cntr_1 = 0;
		int cntr_2 = 0;
		int cntr_3 = 0;
		int napolitana_kupe = 0;
		int napolitana_spadi = 0;
		int napolitana_bastoni = 0;
		int napolitana_dinari = 0;
		for (int i = 0; i < 10; i++)
		{
			if (ruka[i].broj == 1)
				cntr_1++;
			if (ruka[i].broj == 2)
				cntr_2++;
			if (ruka[i].broj == 3)
				cntr_3++;
			if (ruka[i].zog == "Kupe" && (ruka[i].broj == 1 || ruka[i].broj == 2 || ruka[i].broj == 3))
				napolitana_kupe++;
			if (ruka[i].zog == "Spadi" && (ruka[i].broj == 1 || ruka[i].broj == 2 || ruka[i].broj == 3))
				napolitana_spadi++;
			if (ruka[i].zog == "Bastoni" && (ruka[i].broj == 1 || ruka[i].broj == 2 || ruka[i].broj == 3))
				napolitana_bastoni++;
			if (ruka[i].zog == "Dinari" && (ruka[i].broj == 1 || ruka[i].broj == 2 || ruka[i].broj == 3))
				napolitana_dinari++;
		}
		if (cntr_1 >= 3)
			broj_bodova += cntr_1;
		if (cntr_2 >= 3)
			broj_bodova += cntr_2;
		if (cntr_3 >= 3)
			broj_bodova += cntr_3;
		if (napolitana_kupe >= 3)
			broj_bodova += napolitana_kupe;
		if (napolitana_spadi >= 3)
			broj_bodova += napolitana_spadi;
		if (napolitana_dinari >= 3)
			broj_bodova += napolitana_dinari;
		if (napolitana_bastoni >= 3)
			broj_bodova += napolitana_bastoni;
	}

};
class Mac
{
public:
	Karta shpil[40];
	int len = 40;
	void promijesaj(mt19937 kljuc)
	{
		shuffle(this->shpil, this->shpil + 40, kljuc);
	}
	Karta* podijeli()
	{
		int j = 0;
		Karta* novi_shpil = new Karta[len];
		for (int i = 40 - len; i < 40; i++)
		{
			novi_shpil[j] = shpil[i];
			j++;
		}
		len -= 10;
		Karta* nova_ruka = new Karta[10];
		for (int i = 0; i < 10; i++)
		{
			nova_ruka[i] = novi_shpil[i];
		}
		delete[]novi_shpil;
		return nova_ruka;
	}
	void kreiraj()
	{
		int k = 0;
		for (int p = 0; p < 4; p++)
		{
			string zog;
			if (p == 0)
				zog = "Kupe";
			else if (p == 1)
				zog = "Bastoni";
			else if (p == 2)
				zog = "Spadi";
			else
				zog = "Dinari";
			for (int i = 0; i < 10; i++)
			{
				this->shpil[p * 10 + i].zog = zog;
				if (i < 7)
					this->shpil[p * 10 + i].broj = i + 1;
				else if (i == 7)
					this->shpil[p * 10 + i].broj = 11;
				else if (i == 8)
					this->shpil[p * 10 + i].broj = 12;
				else if (i == 9)
					this->shpil[p * 10 + i].broj = 13;
			}
		}
	}
};
void printaj4(Igrac, Igrac, Igrac, Igrac);
void printaj2(Igrac, Igrac);
#endif 