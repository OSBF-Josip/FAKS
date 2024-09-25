#include "likovi.hpp"
int main()
{
	std::vector<Enemy*> vek_boss;
	Boss Alpharius(1, 1);
	Monster Fulgrim;
	Boss Perturabo(1, 1);
	Monster Horus;
	Boss Angron(1, 1);
	Player ME;
	vek_boss.push_back(&Alpharius);
	vek_boss.push_back(&Fulgrim);
	vek_boss.push_back(&Perturabo);
	vek_boss.push_back(&Horus);
	vek_boss.push_back(&Angron);


	for (auto boss : vek_boss) {
		boss->displayInfo();
	}


	try {
		Boss bossman;
	}
	catch(std::invalid_argument const& ex) {
		std::cout << "exeption, smrdis" << ex.what() << std::endl;
	}
	return 0;
}