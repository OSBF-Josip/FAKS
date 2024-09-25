#include <iostream>
#include <vector>

template <typename T>
T get_min(const T& a, const T& b)
{
	return (a < b) ? a : b;
}
int main1()
{
	using namespace std;
	int a, b;
	string c, d;
	cout << "Unesite prvi broj: " << endl;
	cin >> a;
	cout << "Unesite drugi broj: " << endl;
	cin >> b;
	cout << get_min(a, b) << " je manji broj!" << endl;
	cout << "Unesite prvi string: " << endl;
	cin >> c;
	cout << "Unesite drugi string: " << endl;
	cin >> d;
	cout << get_min(c, d) << " je manji string!" << endl;

	return 0;
}