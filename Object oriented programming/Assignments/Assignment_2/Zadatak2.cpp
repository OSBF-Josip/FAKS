#include <iostream>
using namespace std;
int& uvecaj(int*, int);
int main()
{
    int len = 4;
    int* niz = new int[len]{ 2,4,6,8 };
    int j = 1; 
    uvecaj(niz, j)++;
    for (int i = 0; i < len ; i++) {
        cout << niz[i] << " ";
    }
    return 0;
}
int& uvecaj(int* niz, int i)
{
    return niz[i];
}