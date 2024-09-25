#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int prebroj(std::string const&, std::string const&);
int main()
{
	string glavni_string, podstring;
	cout << "Unesite neki string: " << std::endl;
	getline(std::cin, glavni_string);
	cout << "Unesite neki podstring: " << std::endl;
	getline(std::cin, podstring);
	cout<<"Ovo je broj podstringova -> "<<podstring<< " <- u glavnom stringu -> "<<glavni_string<< " <-\n"<<prebroj(glavni_string, podstring) << endl;
	
	return 0;
}
int prebroj(std::string const& s0, std::string const& s1)
{
	int brojac = 0;
	auto iter = s0.begin();
	auto iter1 = search(s0.begin(), s0.end(), s1.begin(), s1.end());
	if (iter1 == s0.end()-1)
	{
		brojac++;
		return brojac;
	}
	if (iter1 == iter || iter1 != iter)
		brojac++;
	for (int i = 0; i < s0.size(); i++)
	{
		iter = search(s0.begin() + i, s0.end(), s1.begin(), s1.end());
		if (iter1 != iter && (iter!=s0.end()))
		{
			iter1 = iter;
			brojac++;
		}
	}
	return brojac;
}