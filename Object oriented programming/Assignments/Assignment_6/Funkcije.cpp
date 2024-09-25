#include "Klase.hpp"
void Owner::tamagochi()
{
	std::vector<VirtualPet>::iterator it;
	int vrijeme = 0;
	std::string radnja;
	std::string odluka = "da";
	int ljubimac = 0;
	while (odluka == "da")
	{
		this->novi_ljubimac();
		std::cout << "Zelite li jos jednog ljubimca?\t\t";
		std::cin >> odluka;
	}
	while (1)
	{
		it = this->ljubimci.begin();
		if (this->ljubimci.size() == 0)
			break;
		std::cout << "Promijeni korisnika?\t";
		std::cin >> odluka;
		if (odluka == "da")
			break;
		std::cout << "Za kojeg ljubimca zelite akcije?\t\t\n\n";
		this->svi_ljubimci();
		std::cin >> ljubimac;
		ljubimac -= 1;
		if (ljubimac < 0)
			exit(0);
		while (1)
		{
			std::cout << "Unesi radnju: " << std::endl;
			std::cin >> radnja;
			if (radnja == "nahrani")
				this->ljubimci[ljubimac].nahrani();
			else if (radnja == "spavaj")
			{
				std::cout << "Unesi vrijeme spavanja: ";
				std::cin >> vrijeme;
				this->ljubimci[ljubimac].spavaj(vrijeme);
			}
			else if (radnja == "probudi")
				this->ljubimci[ljubimac].probudi();
			else if (radnja == "igraj")
				this->ljubimci[ljubimac].igraj();
			else if (radnja == "stanje")
				this->ljubimci[ljubimac].stanje_pet();
			else if (radnja == "prebij")
				this->ljubimci[ljubimac].prebij();
			else if (radnja == "stop")
				break;
			if (this->ljubimci[ljubimac].provjera_stanja())
			{
				std::cout << "\n\tKrepao...\n\n";
				this->ljubimci[ljubimac].~VirtualPet();
				this->ljubimci.erase(it + ljubimac);
				break;
			}
		}
	}
}
VirtualPet::VirtualPet(std::string ime_ljubimca, std::string vrsta_ljubimca)
{
	this->ime = ime_ljubimca;
	this->vrsta = vrsta_ljubimca;
}
void VirtualPet::nahrani()
{
	if(this->budnost)
	{
		if (glad >= 20)
		{
			this->glad -= 20;
			this->sreca += 5;
		}
		else
			std::cout << "Vec je sit!" << std::endl;
	}
	else
		std::cout << "Jos pajki..." << std::endl;
}
void VirtualPet::spavaj(int vrijeme)
{
	if (this->glad <= 20 && this->budnost)
	{
		this->glad += (5 * vrijeme);
		this->sreca += (2 * vrijeme);
		this->budnost = false;
	}
	else
		std::cout << "Provjeri spava li i je li dovoljno sit!" << std::endl;
}
void VirtualPet::probudi()
{
	this->budnost = true;
}
void VirtualPet::igraj()
{
	if (this->budnost)
	{
		this->sreca += 10;
		this->glad += 10;
	}
	else
		std::cout << "Jos pajki..." << std::endl;
}
void VirtualPet::stanje_pet()
{
	using namespace std;
	cout << "\t" << "Sreca: " << this->sreca << "\tGlad: " << this->glad << "\tBudan? " << this->budnost << endl << endl;;
}
void VirtualPet::prebij()
{
	this->sreca -= 30;
	this->glad += 30;
}
void VirtualPet::ime_i_vrsta()
{
	std::cout << this->ime << "\t" << this->vrsta << std::endl;
	this->stanje_pet();
	std::cout << std::endl;
}
int VirtualPet::provjera_stanja()
{
	if (((this->glad) > 120) || ((this->sreca) < (-20)))
		return 1;
	else
		return 0;
}
void Owner::stanje(int redni_broj)
{
	ljubimci[redni_broj].stanje_pet();
}
void Owner::novi_ljubimac()
{
	std::string ime;
	std::string vrsta;
	std::cout << "Unesite vrstu vaseg novog ljubimca: ";
	std::cin >> vrsta;
	std::cout << "Unesite ime vaseg novog ljubimca: ";
	std::cin >> ime;
	VirtualPet ljubimac(ime, vrsta);
	this->ljubimci.push_back(ljubimac);
}
void Owner::svi_ljubimci()
{
	for (int i = 0; i < (this->ljubimci.size()); i++)
	{
		std::cout << (i + 1) << "\t";
		this->ljubimci[i].ime_i_vrsta();
	}
}
std::vector<int> Owner::usporedi()
{
	std::vector<int> vek_sreca;
	for (int i = 0; i < this->ljubimci.size(); i++)
	{
		vek_sreca.push_back(this->ljubimci[i].get_sreca());
	}
	return vek_sreca;
}
void usporedi_owner(Owner a, Owner b)
{

	if (a.usporedi() < b.usporedi())
	{

	}
}