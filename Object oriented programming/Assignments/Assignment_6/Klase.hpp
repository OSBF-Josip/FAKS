#ifndef KLASE
#define KLASE
#include <iostream>
#include <vector>
#include <string>
class VirtualPet
{
private:
	std::string ime;
	std::string vrsta;
	int glad = 50;
	int sreca = 20;
	bool budnost = true;
public:
	VirtualPet(std::string ime_ljubimca, std::string vrsta_ljubimca);
	~VirtualPet() {};
	void nahrani();
	void spavaj(int);
	void probudi();
	void igraj();
	void prebij();
	void stanje_pet();
	void ime_i_vrsta();
	int provjera_stanja();
	int get_sreca() const{ return sreca; };
	int get_glad() const { return glad; };
};
class Owner
{
private:
	std::string ime;
	std::vector<VirtualPet> ljubimci;
public:
	void tamagochi();
	Owner(std::string ime) {};
	Owner(const Owner& other) : ljubimci(other.ljubimci) {};
	void novi_ljubimac();
	void stanje(int);
	void svi_ljubimci();
	std::vector<int> usporedi();
};
void usporedi_owner(Owner, Owner);
#endif