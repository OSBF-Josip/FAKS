#include <iostream>
#include <vector>
#include <random>
#include <string>
using namespace std;
string pig_latin(string&);
int main()
{
	string s0 = "I dislike alcoholic beverages.";
	string s1 = "Amanda wanted some John Thomas.";
	string s2 = "John wishes to be pummeled.";
	string s3 = "What time is it?";
	std::vector<string>v0;
	v0.push_back(s0);
	v0.push_back(s1);
	v0.push_back(s2);
	v0.push_back(s3);
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> raspon(0, (v0.size()-1));
	int rand_num = raspon(generator);
	cout<<pig_latin(v0[rand_num]);
	return 0;
}
string pig_latin(string& original)
{
	string samoglasnici = "aeiouAEIOU";
	string suglasnici;
	string za_samo = "hay";
	string za_su = "ay";
	string::iterator it = original.begin();
	int j, cntr;
	for (int i = 0; i < original.size(); i++)
	{
		if (original[i] == ' ' || i == 0)
		{
			j = cntr = 1;
			if (i == 0)
				j = cntr = 0;
			while (original[i + cntr] != ' ' && original[i + cntr] != '\0' && original[i + cntr] != '.' &&original[i + cntr] != '?')
				cntr++;
			if (i != 0)
				cntr--;
			if (samoglasnici.find(original[i + j], 0) == std::string::npos)
			{
				while (samoglasnici.find(original[i + j], 0) == std::string::npos)
				{
					suglasnici.push_back(original[i + j]);
					j++;
				}
				if (i != 0)
				{
					original.insert(i + 1 + cntr, suglasnici);
					original.insert(i + 1 + cntr + suglasnici.size(), za_su);
					it = original.begin();
					original.erase((it + i + 1), (it + i + j));
					suglasnici.clear();
				}
				else
				{
					original.insert(i + cntr, suglasnici);
					original.insert(i + cntr + suglasnici.size(), za_su);
					it = original.begin();
					original.erase((it + i ), (it + i + j));
					suglasnici.clear();
				}
			}
			else
			{
				original.insert(i + 1 + cntr, za_samo);
				it = original.begin();
			}
			i += cntr;
		}
	}
	return original;
}