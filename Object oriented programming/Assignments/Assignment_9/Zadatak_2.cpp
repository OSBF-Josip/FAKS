#include <iostream>
#include <vector>

template <typename T>
class Set
{
private:
	std::vector<T> my_set;
public:
	void add_element(T& element){
		my_set.push_back(element);
	}
	void remove_element(T& element){
		my_set.erase(std::find(my_set.begin(), my_set.end(), element));
	}
	void check_for_element(T& element){
		auto it = std::find(my_set.begin(), my_set.end(), element);
		if (it == my_set.end())
			std::cout << "\n404\nelement not found!" << std::endl;
		else
			std::cout << "Element " << element << " pronaden na poziciji " << std::distance(my_set.begin(), it) << std::endl;
	}
	const std::vector<T>& get_set() const { return my_set; }
};
int main() {
	int i = 0;
	Set <int> my_set;
	std::cout << "Unosite nesto: " << std::endl;
	int element;
	while (i < 10) {
		std::cin >> element;
		my_set.add_element(element);
		i++;
	}
	for (auto x : my_set.get_set()) {
		std::cout << x << " ";
	}
	std::cout<<"\n";
	std::cout << "\nKoji element zelite ukloniti? " << std::endl;
	std::cin >> element;
	my_set.remove_element(element);
	for (auto x : my_set.get_set()) {
		std::cout << x << " ";
	}
	std::cout << "\n";
	return 0;
}