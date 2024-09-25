#include <iostream>
#include <string>
#include <vector>
class Vehicle
{
public:
	virtual void displayInfo() = 0;
};
class Car : public Vehicle
{
protected:
	std::string brand;
	std::string model;
	int year;
public:
	Car() {};
	Car(std::string brand, std::string model, int year) { this->brand = brand; this->model = model; this->year = year; }
	void displayInfo() override { std::cout << "Marka: " << this->brand << "\nModel: " << this->model << "\nYear: " << this->year; }
	~Car() {};
};
class Bike : public Vehicle
{
protected:
	std::string type;
	int gearCount;
public:
	Bike() {};
	Bike(std::string type, int gearCount) { this->type = type; this->gearCount = gearCount; }
	void displayInfo() override { std::cout << "\nTip: " << this->type << "\nBroj brzina: " << this->gearCount; }
	~Bike() {};
};
int main()
{
	Car bibi("Mercedes", "stodvajstrica", 1989);
	Bike tjutju("Monocikl", 1);
	std::vector<Vehicle*> vrumvrum { &bibi, &tjutju };
	for (auto i : vrumvrum)
	{
		i->displayInfo();
	}
	return 0;
}