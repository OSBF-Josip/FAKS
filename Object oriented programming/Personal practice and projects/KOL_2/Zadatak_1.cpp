#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>
#include <numbers>
using namespace std;
bool isPrime(int &n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return false;
	return true;
}
void change(int& i) { i *= i; }
int main()
{
	vector<int> vec = { 1, 4, 6, 10, 22};
	vector<int> vec2 (vec.size());
	int k = 10;
	int n = 1;
	int m = 3;
	cout << "a) ";
	transform(vec.begin(), vec.end(), vec.begin(), [n](int i) {return i + n; });
	for (int i : vec)
		cout << i << " ";
	cout << "\n";

	auto it = copy_if(vec.begin(), vec.end(), vec2.begin(), [k](int i) {return (i < k); });
	vec2.resize(distance(vec2.begin(), it));
	cout << "b) ";
	for (int i : vec2)
		cout << i << " ";
	cout << "\n";

	cout << "c) ";
	auto it1 = find_if(vec.begin(), vec.end(), [m](int i) {return !(i % m); });
	if (it1 == vec.end())
		cout << "-1";
	else
		cout << *it1;
	cout << "\n";

	cout << "d) ";
	auto it2 = remove_if(vec.begin(), vec.end(), isPrime);
	vec.resize(distance(vec.begin(), it2));
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	cout << "\n";
	cout << "e) ";
	for_each(vec2.begin(), vec2.end(), change);
	for (int i : vec2)
		cout << i << " ";
	cout << "\n";
}