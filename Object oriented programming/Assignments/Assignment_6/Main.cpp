#include "Klase.hpp"
int main()
{
	Owner prvi("Josip");
	Owner drugi("Ivan");
	prvi.tamagochi();
	drugi = prvi;
	drugi.tamagochi();

	return 0;
}