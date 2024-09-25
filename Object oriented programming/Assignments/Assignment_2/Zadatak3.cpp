#include <iostream>
struct Vektor
{
	int* elementi = nullptr;
	int logicka_velicina = 1;
	int fizicka_velicina = 0;
	void vector_new()
	{
		if (elementi == nullptr)
			elementi = new int[logicka_velicina];
		int* temp_elementi = new int[logicka_velicina];
		for (int i = 0; i < fizicka_velicina; i++)
		{
			temp_elementi[i] = elementi[i];
		}
		vector_delete(elementi);
		elementi = new int[logicka_velicina];
		for (int i = 0; i < fizicka_velicina; i++)
		{
			elementi[i] = temp_elementi[i];
		}
		vector_delete(temp_elementi);
	}
	void vector_delete(int* niz)
	{
		delete[] niz;
	}
	void vector_push_back(int el)
	{
		fizicka_velicina += 1;
		if (logicka_velicina <= fizicka_velicina)
		{
			logicka_velicina = logicka_velicina * 2;
			vector_new();
		}
		elementi[fizicka_velicina - 1] = el;
	}
	void vector_pop_back()
	{
		--fizicka_velicina;
	}
	int vector_front()
	{
		return elementi[fizicka_velicina - 1];
	}
	int vector_back()
	{
		return elementi[0];
	}
	int vector_size()
	{
		return fizicka_velicina;
	}
};
int main()
{
	Vektor vektor;
	int element = 1;
	std::cout << "\nUnosite brojeve u vektor, za kraj unosa unesite 0 (nula): " << std::endl;
	while (element != 0)
	{
		std::cin >> element;
		if (element != 0)
		{
			vektor.vector_push_back(element);
		}
	}
	std::cout << "\nOvako glase clanovi niza elemenata u vektoru: " << std::endl;
	for (int i = 0; i < vektor.fizicka_velicina; i++)
	{
		printf("%d ", vektor.elementi[i]);
	}
	std::string flag = "start";
	while (flag != ".")
	{
		std::cout << "\n\nUpisite pop/push za skidanje posljednje unesenog clana odnosno postavljanje dodatnog,\nza pregled prvog/zadnjeg/velicine, odnosno unesite front/back/size. Za zavrsetak unesite '.'(tocku)" << std::endl;
		std::cin >> flag;
		if (flag == "front")
			printf("\n\tVektor na kraju glasi: %d", vektor.vector_front());
		else if (flag == "back")
			printf("\n\tVektor na pocetku glasi: %d", vektor.vector_back());
		else if (flag == "size")
			printf("\n\tVektorska velicina glasi: %d", vektor.vector_size());
		else if (flag == "pop")
		{
			vektor.vector_pop_back();
			std::cout << "\n\n\tOvako glasi promijenjen vektor:" << std::endl;
			for (int i = 0; i < vektor.fizicka_velicina; i++)
			{
				printf("%d ", vektor.elementi[i]);
			}
		}
		else if (flag == "push")
		{
			std::cout << "Unesite novi clan: " << std::endl;
			std::cin >> element;
			vektor.vector_push_back(element);
			std::cout << "\n\n\tOvako glasi promijenjen vektor:" << std::endl;
			for (int i = 0; i < vektor.fizicka_velicina; i++)
			{
				printf("%d ", vektor.elementi[i]);
			}
		}
	}
	vektor.vector_delete(vektor.elementi);
	return 0;
}