#include <stdio.h>
#include <string.h>

typedef struct recept {
	char name[20];
	char ossze[10];
	char elkeszit[200];
	struct recept* next;
}Recept;
//lefoglal egy receptnyi helyet �s visszaadja  a pointer�t
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
	char keres[10];
	int nf = 0; //not found
	///majd �t kell rakni m�sik f�ggv�nybe
	Recept* head = NULL;
	Recept* tmp=create_list();
	strcpy_s(tmp->name, 20, "rantotta");
	strcpy_s(tmp->ossze, 10, "tojas");
	strcpy_s(tmp->elkeszit, 200, "keverd ossze a tojast majd s�ssd ki");
	add_element(&head,tmp);

	 tmp = create_list();
	strcpy_s(tmp->name, 20, "limonade");
	strcpy_s(tmp->ossze, 10, "viz");
	strcpy_s(tmp->elkeszit, 200, "keverd ossze a vizet es ihatod is");
	add_element(&head, tmp);
	////////
	// 
	//bek�ri a receptet
	printf("ami van otthon:\n");
	scanf_s("%s", &keres,10);
	
	//v�gig megy a list�n �s ki�rja a tal�latokat strcmpvel, ha ninsc tal�lat bad luck...
	for (; head!=NULL; head=head->next)
	{
		if (recept_search(keres, head->ossze))
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

		return 0;
}