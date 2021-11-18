#include <stdio.h>
#include <stdlib.h>
typedef struct receptd {
	char name[20];
	char ossze[10];
	char elkeszit[200];
	struct receptd* next;
} Receptd;

//lefoglal egy receptnyi helyet �s visszaadja  a pointer�t
Receptd* create_listelement()
{
	Receptd* p;
	p = (Receptd*)malloc(sizeof(Receptd));
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
void add_element(Receptd** head, Receptd* e) {
	Receptd* p;
	if (*head == NULL) {
		
		*head = e;
		return;
	}
	for (p = *head; p->next != NULL; p = p->next) {
	}
	
	p->next = e; 
	return;
}

void create_list()
{
	//megrpob�lom e bet�lteni a receptet
	Receptd* head = NULL;
	Receptd* e;
	e = create_listelement();
	strcpy_s(e->name, 20, "rantotta");
	strcpy_s(e->ossze, 10, "tojas");
	strcpy_s(e->elkeszit, 200, "keverd ossze a tojast majd s�ssd ki");
	printf("\nneve:\t%s\n osszetevok:%s \n Recept:\n%s",e->name,e->ossze,e->elkeszit);
	
}