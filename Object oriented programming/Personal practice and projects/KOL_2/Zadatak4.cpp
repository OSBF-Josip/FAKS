#include <iostream>
#include <vector>

class Quad
{
protected:
	int a;
	int b;
	int c;
	int d;
public:
	Quad() :a(0), b(0), c(0), d(0) {}
	Quad(int a, int b, int c, int d) { this->a = a; this->b = b; this->c = c; this->d = d; }
	virtual int opseg() = 0;
	virtual int povrsina() = 0;
	virtual std::pair<int, int> get_stranica() = 0;
	virtual ~Quad() {}
};
class Kvadrat : public Quad
{
public:
	Kvadrat(int a) { this->a = a; }
	int opseg() override { return (this->a * 4); };
	int povrsina() override { return (this->a * this->a); }
	std::pair<int, int> get_stranica() override { return std::pair<int, int>(a, a); };
};
class Pravokutnik : public Quad
{
public:
	Pravokutnik(int a, int b) { this->a = a; this->b = b; }
	int opseg() override { return (this->a * 2 + this->b * 2); };
	int povrsina() override { return (this->a * this->b); }
	std::pair<int, int> get_stranica() override { return std::pair<int,int>(a,b); }
};
Quad* najveci(std::vector<Quad*> vek)
{
	Quad* temp = vek.at(0);
	for (auto i : vek)
	{
		if (i->povrsina() > temp->povrsina())
			temp = i;
	}
	return temp;
}
int main()
{
	std::vector<Quad*> vect = {new Kvadrat(3), new Kvadrat(4), new Pravokutnik(1, 5), new Pravokutnik(2, 5), new Kvadrat(7)};
	Quad* kvad = najveci(vect);
	std::cout << "Stranica prva: " << kvad->get_stranica().first<< "Stranica druga: "<< kvad->get_stranica().second << std::endl;
}