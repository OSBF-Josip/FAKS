#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	return NULL;
}

void AddNode(BSTree* bst, char* word)
{
	// Rekurzivno se trazi mjesto za novi cvor u stablu. Ako rijec postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokazivac.
	if (*bst == NULL)
	{
		*bst = (BSTree)malloc(sizeof(Node));
		//(*bst)->word = (char*)malloc(sizeof(char) * (strlen(word) + 1));
		//strcpy((*bst)->word, str);
		(*bst)->word = word;
		(*bst)->left = NULL;
		(*bst)->right = NULL;
		return;
	}
	else if (strcmp((*bst)->word, word) > 0) // usporedivanje
	{
		AddNode(&(*bst)->left, word);
	}
	else if (strcmp((*bst)->word, word) < 0)
	{
		AddNode(&(*bst)->right, word);
	}
	else
		free(word);
}

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se pronasla najduza grana (visina stabla).
	if (bst == NULL)
	{
		return 0;
	}

	int left_branch = BSTHeight(bst->left);
	int right_branch = BSTHeight(bst->right);


	if (left_branch >= right_branch)
	{
		return (left_branch + 1);
	}

	else if (left_branch < right_branch)
	{
		return (right_branch + 1);
	}


}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rijeci u stablu na ekran po abecednom redu.
	// In-order setnja po stablu (lijevo dijete, cvor, desno dijete)
	// inorder
	if (bst == NULL)
	{
		return;
	}

	PrintBSTree(bst->left); //  lijevo dijete
	printf("%s ", bst->word);
	PrintBSTree(bst->right); // desno dijete


}

void SaveBSTree(BSTree bst, FILE* fd)
{
	// Snima rijec po rijec iz stabla u tekstualnu datoteku. Rijeci su odvojene razmakom.
	// Pre-order setnja po stablu (trenutni cvor pa djeca)
	if (bst == NULL)
	{
		return;
	}
	fprintf(fd, "%s ", bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);

}

/*void printPreorder(BSTree bst)
{
	if (bst == NULL)
	{
		return;
	}
	printf("%s ", bst->word); // cvor

	printPreorder(bst->left);
	printPreorder(bst->right);
}*/


void DeleteBSTree(BSTree bst)
{
	// Brise stablo (string word i sam cvor) iz memorije.
	// Post-order setnja po stablu (prvo djeca pa trenutni cvor)

	if (bst == NULL)
	{
		return;
	}
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);

	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE* fd)
{
	// Ucitava rijec po rijec iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rijec duplicirati sa strdup().

	BSTree bst = NULL;

	char buffer[1024];
	while (readWord(fd, buffer))
	{
		printf("%s\n", buffer);
		AddNode(&bst, _strdup(buffer));
	}
	return bst;

}