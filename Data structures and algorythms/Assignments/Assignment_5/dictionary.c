#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  _AFX_SECURE_NO_WARNINGS
#include "dictionary.h"
Dictionary create()
{
    Dictionary novi_word = (Word*)malloc(sizeof(Word));
    if (novi_word == NULL)
        exit(1);
    novi_word->count = 0;
    novi_word->word = NULL;
    novi_word->next = NULL;
	return novi_word;
}
void add(Dictionary dict, char* str)
{
    //provjeri jel dict == NULL, ako je, onda ce dict bit string
    //ako nije == NULL, prolazi kroz dict, gledaš ponavljanje, ako se ponavlja, broj rijeci se povecava +=1
    //ako ne postoji, dodaje se na kraj
	Dictionary p = dict;
	Dictionary n = dict->next;
	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	if (novi == NULL)
		exit(1);
	novi->word = (char*)malloc(sizeof(char) * (strlen(str) + 1));
	if (novi->word == NULL)
		exit(1);
	strcpy(novi->word, str);
	novi->count = 1;

	while (n != NULL)
	{
		if (strcmp(n->word, str) == 0)
		{
			n->count++;
			free(novi->word);
			free(novi);
			return;
		}
		else if (strcmp(n->word, str) > 0)
		{
			novi->next = n;
			p->next = novi;
			return;
		}
		n = n->next;
		p = p->next;
	}
	p->next = novi;
	novi->next = NULL;
}
void print(Dictionary dict)
{
	Dictionary temp = dict->next;
	while (temp->next != NULL)
	{
		printf("\n%s\t\t%d\n", temp->word, temp->count);
		temp = temp->next;
	}
}
void destroy(Dictionary dict)
{
	Dictionary temp;
	while (dict != NULL)
	{
		temp = dict;
		dict = dict->next;
		free(temp->word);
		free(temp);
	}
}
int filter(Word* w)
{
	if ((w->count > 5 && w->count < 10) && strlen(w->word) > 3)
	{
		return 1;
	}
	else
		return 0;
}

Dictionary filterDictionary(Dictionary indict, int(*filter)(Word* w))
{
	Dictionary p = indict;
	Dictionary n = indict->next;
	while (n != NULL)
	{
		if (filter(n) == 1)
		{
			p = p->next;
			n = n->next;
		}
		else
		{
			p->next = n->next;
			free(n->word);
			free(n);
			n = p->next;
		}
	}
	return indict;
}