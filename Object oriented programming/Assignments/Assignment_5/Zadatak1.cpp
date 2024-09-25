#include "Treseta.hpp"
using namespace std;
int main()
{
	random_device rd;
	mt19937 g(rd());
	int broj_igraca = 1;
	while(broj_igraca != 4 && broj_igraca != 2)
	{
		cout << "Koliko igraca sudjeluje?" << endl;
		cin >> broj_igraca;
	}
	Igrac a = Igrac();
	a.ime = "Josip";
	Igrac b = Igrac();
	b.ime = "Petar";
	Igrac c = Igrac();
	c.ime = "Jure";
	Igrac d = Igrac();
	d.ime = "Mate";

	Mac dek = Mac();
	dek.kreiraj();
	dek.promijesaj(g);
	for(int i = 0; i<broj_igraca;i++)
	{
		if (i == 0)
			a.ruka = dek.podijeli();
		else if (i == 1)
			b.ruka = dek.podijeli();
		else if (i == 2)
			c.ruka = dek.podijeli();
		else
			d.ruka = dek.podijeli();
	}
	if(broj_igraca==4)
	{
		a.akuza();
		b.akuza();
		c.akuza();
		d.akuza();
		printaj4(a, b, c, d);
		cout << "Josip ima " << a.broj_bodova << " boda iz akuze" << endl;
		cout << "Petar ima " << b.broj_bodova << " boda iz akuze" << endl;
		cout << "Jure ima " << c.broj_bodova << " boda iz akuze" << endl;
		cout << "Mate ima " << d.broj_bodova << " boda iz akuze" << endl;
	}
	if (broj_igraca == 2)
	{
		a.akuza();
		b.akuza();
		printaj2(a, b);
		cout << "Josip ima " << a.broj_bodova << " boda iz akuze" << endl;
		cout << "Petar ima " << b.broj_bodova << " boda iz akuze" << endl;
	}
	return 0;
}