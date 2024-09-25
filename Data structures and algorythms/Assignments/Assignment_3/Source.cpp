#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	float x, y, z;
} Vrh;

typedef struct
{
	float normala_x, normala_y, normala_z; //vektor normale
	Vrh niz_vrhova[3];
	unsigned short boja_trokuta;
} Trokut;

typedef struct
{
	Trokut* niz_trokuta;
	int n;
} Objekt3D;

Objekt3D* read_binary(FILE* fp)
{
	Objekt3D* objekt = (Objekt3D*)malloc(sizeof(Objekt3D));
	if (objekt == NULL)
		exit(1);
	fp = fopen("primjerbin.stl", "rb");
	if (!fp)
		return NULL;

	fseek(fp, 80, SEEK_SET);
	fread(&(objekt->n), sizeof(unsigned int), 1, fp);

	objekt->niz_trokuta = (Trokut*)malloc(sizeof(Trokut) * objekt->n);
	if (objekt->niz_trokuta == NULL)
		exit(1);

	int i = 0;
	while (!feof(fp))
	{
		fread(&(objekt->niz_trokuta[i]), 50, 1, fp);
		i++;
	}
	fclose(fp);
	return objekt;
}

void write_binary(FILE* fp, Objekt3D* objekt)
{
	fp = fopen("write_bin.stl", "wb");
	if (fp == NULL)
	{
		printf("Neuspjelo otvaranje datoteke! \n");
		exit(1);
	}

	int zaglavlje[20] = { 0 };

	fwrite(zaglavlje, sizeof(zaglavlje[0]), 20, fp);
	fwrite(&(objekt->n), sizeof(objekt->n), 1, fp);

	for (int i = 0; i < objekt->n; ++i)
		fwrite(&(objekt->niz_trokuta[i]), 50, 1, fp);

	fclose(fp);
}

void write_text(FILE* fp, Objekt3D* objekt)
{
	fp = fopen("write_txt.stl", "wt");
	if (fp == NULL)
	{
		printf("Neuspjelo otvaranje datoteke! \n");
		exit(1);
	}
	fprintf(fp, "solid OpenSCAD_Model\n");
	for (int i = 0; i < objekt->n; ++i)
	{
		fprintf(fp, "\tfacet normal %f %f %f \n", objekt->niz_trokuta[i].normala_x, objekt->niz_trokuta[i].normala_y, objekt->niz_trokuta[i].normala_z);
		fprintf(fp, "\t\touter loop \n");
		fprintf(fp, "\t\t\tvertex %f %f %f \n", objekt->niz_trokuta[i].niz_vrhova[0].x, objekt->niz_trokuta[i].niz_vrhova[0].y, objekt->niz_trokuta[i].niz_vrhova[0].z);
		fprintf(fp, "\t\t\tvertex %f %f %f \n", objekt->niz_trokuta[i].niz_vrhova[1].x, objekt->niz_trokuta[i].niz_vrhova[1].y, objekt->niz_trokuta[i].niz_vrhova[1].z);
		fprintf(fp, "\t\t\tvertex %f %f %f \n", objekt->niz_trokuta[i].niz_vrhova[2].x, objekt->niz_trokuta[i].niz_vrhova[2].y, objekt->niz_trokuta[i].niz_vrhova[2].z);
		fprintf(fp, "\t\tendloop \n");
		fprintf(fp, "\tendfacet \n");
	}
	fprintf(fp, "endsolid OpenSCAD_Model");
	fclose(fp);
}

void delete_objekt(Objekt3D* objekt)
{
	free(objekt->niz_trokuta);
	free(objekt);
}


int main()
{
	FILE* first = NULL;
	Objekt3D* objekt = read_binary(first);

	write_binary(first, objekt);

	write_text(first, objekt);

	delete_objekt(objekt);
	return 0;
}