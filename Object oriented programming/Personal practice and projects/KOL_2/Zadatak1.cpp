#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;
void print(string i) { cout << i << endl; }
bool is_punct(char znak) { return ispunct(znak); }
void remove_punct(string &str) { str.erase(remove_if(str.begin(), str.end(), is_punct), str.end()); }
void rev_word(string& str) { reverse(str.begin(), str.end()); }
void okreni(vector<string> &vs)
{
	for_each(vs.begin(), vs.end(), remove_punct);
	for_each(vs.begin(), vs.end(), rev_word);
}
void unos(string& str, vector<string>& vs)
{
	cout << "Unosi recenice: " << endl;
	while (1)
	{
		getline(cin, str);
		if (str == "0")
			break;
		vs.push_back(str);
	}
}
int main() 
{
	string str;
	vector<string> vs;
	unos(str, vs);
	okreni(vs);
	for_each(vs.begin(), vs.end(), print);
	return 0;
}
