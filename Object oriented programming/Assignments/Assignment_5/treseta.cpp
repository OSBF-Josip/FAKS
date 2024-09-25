#include "Treseta.hpp"
void printaj4(Igrac a, Igrac b, Igrac c, Igrac d)
{
	cout << left << setw(20) << "\t" << a.ime << left << setw(20) << "\t" << b.ime << left << setw(20) << "\t" << c.ime << left << setw(20) << "\t\t" << " " << d.ime << left << setw(20) << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << left<<setw(20)<< "\t" << a.ruka[i].broj << " " << a.ruka[i].zog << left << setw(20) << "\t" << b.ruka[i].broj << " " << b.ruka[i].zog << left << setw(20) << "\t" << c.ruka[i].broj << " " << c.ruka[i].zog << left << setw(20)<<"\t" << d.ruka[i].broj << " " << d.ruka[i].zog << endl;
	}
}
void printaj2(Igrac a, Igrac b)
{
	cout << left << setw(20) << "\t" << a.ime << left << setw(20) << "\t" << b.ime << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << left << setw(20) << "\t" << a.ruka[i].broj << " " << a.ruka[i].zog << left << setw(20) << "\t" << b.ruka[i].broj << " " << b.ruka[i].zog << endl;
	}
}