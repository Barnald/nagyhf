#include <stdio.h>
#include <string.h>
#include "database.c"
typedef struct recept {
	char name[20];
	char ossze[10];
	char elkeszit[200];
}Recept;

//vesz ket chart �s ha ugyanazok 1 et ad vissza k�l�nben 0
int recept_search(const char* keres, const char* mibenkeres)
{

	if(strcmp(keres,mibenkeres)==0)
	{
		return 1;
	}
	return 0;

}

int main()
{	
	//nem m�k�dik a create list
	 create_list();
	char keres[10];

	//l�trehoz egy receptet
	Recept rantotta;

	strcpy_s(rantotta.name,sizeof(rantotta.name), "rantotta");
	strcpy_s(rantotta.ossze, sizeof(rantotta.ossze), "tojas");
	strcpy_s(rantotta.elkeszit, sizeof(rantotta.elkeszit), "keverd ossze a tojast majd s�ssd ki");
	
	//bek�ri a receptet
	printf("ami van otthon:\n");
	scanf_s("%s", &keres,10);
	if (recept_search(keres, rantotta.ossze))
	{
		printf("\n ehez van minden otthon:");
		printf("\n%s", rantotta.name);
		printf("\n%s", rantotta.ossze);
		printf("\n%s", rantotta.elkeszit);
	}
	else
	{
		printf("bad luck ehes maradsz");
	}

		return 0;
}