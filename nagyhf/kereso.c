#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



typedef struct recept {
	char name[20];
	char ossze[15];
	char elkeszit[200];
	struct recept* next;
}Recept;


//lefoglal egy receptnyi helyet �s visszaadja  a pointer�t !!!!!!!!!!!!!!!!!!!MALLOC DE M�Gnem biztos hogy j� a FREE!!!!!!!!!!!!!!!!!
Recept* create_listelement()
{
	Recept* p;
	p = (Recept*)malloc(sizeof(Recept));
	if (p == NULL)
	{
		printf("malloc error");
		exit(1);
	}
	p->next = NULL;
	return p;
}

/// <summary>
/// j� ez de men�, ez megn�zhi ha a head 0 akkor � lesz az els� elem ha nem akkor akkor a neki beadott pointer lesz a k�vetkez� elemre a head;
/// </summary>
/// <param name="head">fajl eleje</param>
/// <param name="e">fajl v�ge pointer k�vire </param>
void add_element(Recept** head, Recept* e) {
	Recept* p;
	if (*head == NULL) {

		*head = e;
		return;
	}
	for (p = *head; p->next != NULL; p = p->next) {
	}

	p->next = e;
	return;
}

Recept* create_list()
{
	//megrpob�lom e bet�lteni a receptet
	Recept* head = NULL;
	Recept* e;
	e = create_listelement();
	
	return e;
}

//stringb�l a spaceket elt�nteti �s visszaad egy �j stringet space n�lk�l
char* str_spacedel(char* str)
{
	int i = 0;
	int j = 0;
	while (str[i] != '\0')
	{
		
		if (str[i] != ' ')
		{
			str[j++] = str[i ];

		}
		else 
		{
			str[j] = str[i];
			
		}
		i++;
		
	}
	str[j] = '\0';
	return str;
}

//vesz ket chart �s ha ugyanazok 1 et ad vissza k�l�nben 0
int recept_search(const char* keres, const char* mibenkeres)
{
	int zahl_ossze =0;
	int  i=0;
	char* pos;
	
	str_spacedel(mibenkeres);


	//m�sol a tmpbe hog megtartsam az ereddeti �rt�ket
	char* tmp = keres;
	//darabokra szedem
	char* ktevo = strtok(tmp, ",");

	//array hosszat valahogy at kene adni
	
	while (ktevo != NULL)
	{
		pos = strstr(mibenkeres, ktevo);
			if(pos)
			{
				printf("%s",pos);
			}
			else
			{
				return 0;
			}

		ktevo = strtok(NULL, ",");
	}
	return 1;
	//m�g nem m�k�dik


}

int main()
{	
	char keres[15];
	int nf = 0; //not found
	///majd �t kell rakni m�sik f�ggv�nybe
	Recept* head = NULL;
	Recept* tmp=create_list();
	strcpy_s(tmp->name, 20, "rantotta");
	strcpy_s(tmp->ossze, 15, "tojas, so");
	strcpy_s(tmp->elkeszit, 200, "keverd ossze a tojast majd s�ssd ki");
	add_element(&head,tmp);

	 tmp = create_list();
	strcpy_s(tmp->name, 20, "limonade");
	strcpy_s(tmp->ossze, 15, "viz,cukor");
	strcpy_s(tmp->elkeszit, 200, "keverd ossze a vizet es ihatod is");
	add_element(&head, tmp);
	////////
	// 
	//bek�ri a receptet
	printf("ami van otthon:\n");
	gets(&keres,15,stdin);
	char* natur = str_spacedel(keres);
	
	//v�gig megy a list�n �s ki�rja a tal�latokat strcmpvel, ha ninsc tal�lat bad luck...
	for (; head!=NULL; head=head->next)
	{
		if (recept_search(natur, head->ossze))
		{
		printf("\n ehez van minden otthon:");
		printf("\n%s", head->name);
		printf("\n%s", head->ossze);
		printf("\n%s", head->elkeszit);
		nf++;
		}
		
	}
	//ha nincs tal�lat
	if(nf==0)
	printf("bad luck ehes maradsz");
	free(head);
		return 0;
}