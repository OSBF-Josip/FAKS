#include <stdio.h>
int mystrlen(const char*);
char* mystrcpy(char*, const char*);
int mystrcmp(const char*, const char*);
char* mystrcat(char*, char*);
char* mystrstr(const char*, const char*);
char* reverse(char*, char*);
int main()
{
	char niz_prvi[200] = "Your mother was a hamster, you father smelt of elderberries, i fart in your general direction!";
	char* niz_drugi = "righ";
	char* niz_treci = "father";
	char* niz_cetvrti = "Always look on the bright side of life!";
	char* niz_peti = "doG";
	char* niz_abc_prvi = "a b c";
	char* niz_abc_drugi = "a b";
	char* niz_abc_treci = "z a c";
	char dest[100];
	char dest1[10];
	printf("MYSTRLEN:\nDuljina niza je: %d\n\n", mystrlen(niz_drugi));
	printf("MYSTRCPY:\nKopirani string je: %s\n\n", mystrcpy(dest, niz_cetvrti));
	printf("MYSTRCMP:\nRezultat usoredbe stringova je: %d\n\n", mystrcmp(niz_abc_prvi, niz_abc_drugi));
	printf("MYSTRCAT:\nKonkatenanirani string glasi: %s\n\n", mystrcat(niz_prvi, niz_cetvrti));
	printf("MYSTRSTR:\nString u stringu pocinje na poziciji: %s\n\n", mystrstr(niz_cetvrti, niz_drugi));
	printf("REVERSE:\nZabrnuti string glasi: %s\n\n", reverse(dest1, niz_peti));
}
int mystrlen(const char* niz)
{
	int size = 0;
	for (size; niz[size] != '\0'; size++);
	return size;
}
char* mystrcpy(char* dest, const char* source)
{
	int i = 0;
	for(i;source[i] != '\0';i++)
	{
		dest[i] = source[i];
	}
	dest[i] = '\0';
	return dest;
}
int mystrcmp(const char* first, const char* second)
{
	int i = 0;
	for (i; first[i] != '\0'; i++)
	{
		if (first[i] < second[i])
			return -1;
		else if (first[i] > second[i])
			return 1;
	}
	if (second[i] != '\0')
		return -1;
	return 0;
}
char* mystrcat(char* dest, char* source)
{
	int i = mystrlen(dest);
	int j = 0;
	for (j; source[j] != '\0'; j++)
	{
		dest[i] = source[j];
		i++;
	}
	dest[i] = '\0';
	return dest;
}
char* mystrstr(const char* big, const char* smol)
{
	int i = 0;
	int j = 0;
	for (i; big[i] != '\0'; i++)
	{
		int k = i;
			j = 0;
			for (k; smol[j] != '\0';j++)
			{
				if (big[k] != smol[j])
					break;
				k++;
			}
		if (smol[j] == '\0')
			return &big[i];
	}
	return NULL;
}
char* reverse(char* dest, char* source)
{
	int len = mystrlen(source)-1;
	int i = 0;
	for (i; len >= 0; len--)
	{
		dest[i] = source[len];
		i++;
	}
	dest[i] = '\0';
	return dest;
}