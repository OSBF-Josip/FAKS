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
	bool operator==(const VirtualPet &drugi);
	bool operator!=(const VirtualPet& drugi);
	VirtualPet operator=(const VirtualPet& drugi);
	void operator++();
	bool operator<(const VirtualPet& drugi);
	bool operator>(const VirtualPet& drugi);
	bool operator>=(const VirtualPet& drugi);
	bool operator<= (const VirtualPet & drugi);
	friend std::ostream& operator<<(std::ostream& os, const VirtualPet& vp);
};
class Food
{
private:
	static int counter;
public:
	void print_hrana() { std::cout << this->counter << std::endl; };
	void increment() { this->counter++; };
	void decrement() { this->counter--; };
	friend int get_counter(Food &hrana);
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
	Owner operator=(const Owner& drugi);
	std::vector<VirtualPet> get_ljubimci();
};
void usporedi_owner(Owner, Owner);
#endif