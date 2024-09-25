#include "Klase.hpp"
int main()
{
	Owner prvi("Josip");
	Owner drugi("Ivan");
	prvi.tamagochi();
	drugi = prvi;
	drugi.tamagochi();
	std::cout << prvi.get_ljubimci().at(0) << std::endl;
	return 0;
}