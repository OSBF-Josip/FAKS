#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <ctype.h>
using namespace std;
bool is_vowel(char i) { return (tolower(i) == 'a' || tolower(i) == 'e' || tolower(i) == 'i' || tolower(i) == 'o' || tolower(i) == 'u'); }
pair<int, int> count_letter()
{
	int vowel = 0;
	int consonant = 0;
	vector<char> vc;
	pair<int, int> vi;
	istream_iterator<char> it(cin);
	istream_iterator<char> eos;
	copy(it, eos, back_inserter(vc));
	vowel = count_if(vc.begin(), vc.end(), is_vowel);
	vi.first = vowel;
	vi.second = vc.size() - vowel;
	return vi;
}
int main()
{
	pair<int, int> vi = count_letter();
	cout << "Samoglasnici" << vi.first << "\nSuglasnici" << vi.second << endl;
	return 0;
}