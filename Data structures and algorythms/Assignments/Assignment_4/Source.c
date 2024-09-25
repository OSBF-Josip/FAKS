#include "funkcije.h"
int main()
{
	int pocetak = 20000;
	int kraj = 200001;
	int korak = 20000;
	poziv_presjek(pocetak, kraj, korak);
	printf("\n\n\n\t\tS  T  O  P\n\n\n");
	poziv_presjek_jedan_sortiran(2000000, 20000000, 2000000);
	printf("\n\n\n\t\tS  T  O  P\n\n\n");
	poziv_presjek_oba_sortirana(2000000, 20000000, 2000000);
	printf("\n\n\n\t\tS  T  O  P\n\n\n");
	poziv_presjek_po_indeksima(20000000, 200000000, 20000000);
	return 0;
}