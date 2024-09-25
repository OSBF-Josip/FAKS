#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <numeric>
using namespace std;
class Razlomak
{
public:
	int brojnik;
	int nazivnik;
	Razlomak(int brojnik, int nazivnik) { this->brojnik = brojnik;  this->nazivnik = nazivnik; }
};
int najveciZajednickiDjelitelj(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
Razlomak parseRazlomak(const std::string& str) {
    istringstream stream(str);
    int brojnik, nazivnik;
    char separator;
    stream >> brojnik >> separator >> nazivnik;

    if (separator != '/' || stream.fail()) {
        throw std::invalid_argument("Invalid format for Razlomak: " + str);
    }

    return Razlomak(brojnik, nazivnik);
}
vector<Razlomak> puni_skrati(string filename)
{
	ifstream fin(filename);

    vector<Razlomak> razlomci;
    string line;

    while (getline(fin, line)) {
        istringstream lineStream(line);
        string token;

        while (getline(lineStream, token, ',')) {
            Razlomak razlomak = parseRazlomak(token);
            int mjau = najveciZajednickiDjelitelj(razlomak.brojnik, razlomak.nazivnik);
            razlomak.brojnik /= mjau;
            razlomak.nazivnik /= mjau;

            razlomci.push_back(razlomak);
        }
    }
    return razlomci;

}
int main()
{
    vector<Razlomak> moj_vek = puni_skrati("razlomci.txt");
    for (Razlomak i : moj_vek)
    {
        cout << i.brojnik << "/" << i.nazivnik << endl;
    }
}