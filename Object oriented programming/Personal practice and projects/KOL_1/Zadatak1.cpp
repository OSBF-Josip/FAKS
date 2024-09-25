#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Airport
{
private:
	string airport;
public:
	Airport() {};
	Airport (string air) { airport = air; }
	int getTotalFuelConsumption()
	{

	}

};
class Flight
{
private:
	Airport my_airport;
	Airport dest_airport;
	int distance;
	int fuel_consumption;
public:
	Flight() {};
	Flight(Airport my_airport, Airport dest_airport, int dist) { this->my_airport = my_airport; this->dest_airport = dest_airport; this->distance = dist; }
	void calculateFuelConsumption()
	{
		if ((this->distance) < 500)
		{
			cout << (this->distance * 41) << endl;
			this->fuel_consumption = this->distance * 41;
		}
		else if((this->distance) > 500 && (this->distance) < 10000)
		{
			cout << (this->distance * 101) << endl;
			this->fuel_consumption = this->distance * 101;
		}
		else if ((this->distance) > 10000)
		{
			cout << (this->distance * 121) << endl;
			this->fuel_consumption = this->distance * 121;
		}
	}


};
int main()
{
	string my_airport("Rome");
	Airport airport(my_airport);

	Flight flight1(my_airport, "Rio de Janeiro", 9200);
	flight1.calculateFuelConsumption();
	airport.addFlight(flight1);

	Flight flight2(my_airport, "Buenos Aires", 12000);
	flight1.calculateFuelConsumption();
	airport.addFlight(flight2);

	airport.getTotalFuelConsumption();
	return 0;
}