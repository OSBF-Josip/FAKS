#include <iostream>
#include <algorithm>
template <typename T>
void sort(T& niz) {
	std::qsort(niz, 10, sizeof(T), compare);
}
template <typename T = char*>
void sort(T& niz) {
	std::qsort(niz, 10, sizeof(T), compare);
}
template <typename T>
int compare(const void* a, const void* b) {
	return (*(T*)a - *(T*)b);
}
int main()
{
	int niz[10] = { 5,2,3,1,2,4,6,9,12,8 };
	char str[] = {"The lazy fox abhores the dew!"};
	sort(niz);
	sort(str);
	for (int i = 0; i < 10; i++) {
		std::cout << niz[i] << " ";

		return 0;
	}
}