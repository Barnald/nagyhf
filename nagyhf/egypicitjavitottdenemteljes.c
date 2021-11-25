#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct recept {
	char name[20];
	char ossze[15];
	char elkeszit[200];
    int osszcucc;
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
int recept_search(const char* keres, Recept *head)
{
    char *mibenkeres = head->ossze;
	int zahl_ossze =0;
	int  i=0;
	char* pos;
    int backer = 0;

	//m�sol a tmpbe hogy megtartsam az eredeti �rt�ket
	char tmp[20];
    strcpy(tmp, mibenkeres);
	//darabokra szedem
	char* ktevo = strtok(tmp, ",");

	//array hosszat valahogy at kene adni
	while (ktevo != NULL)
	{
        if(ktevo[strlen(ktevo)-1] == '\n'){
            ktevo[strlen(ktevo)-1] = '\0';
        }
		pos = strstr(keres, ktevo);
        if(pos)
        {
            backer++;
        }
        else
        {
            return 0;
        }

		ktevo = strtok(NULL, ",");
	}
    if(backer < head->osszcucc){
        return 0;
    }
	return 1;
	//m�g nem m�k�dik


}

int main()
{	
	char keres[20], caller[20];
	int nf = 0; //not found
	///majd �t kell rakni m�sik f�ggv�nybe
	Recept* head = NULL;
	Recept* tmp=create_list();
	strcpy(tmp->name, "rantotta");
	strcpy(tmp->ossze, "tojas,so");
	strcpy(tmp->elkeszit, "keverd ossze a tojast majd sussd ki");
    tmp->osszcucc  = 2;
	add_element(&head,tmp);

	 tmp = create_list();
	strcpy(tmp->name, "limonade");
	strcpy(tmp->ossze, "viz,cukor");
	strcpy(tmp->elkeszit, "keverd ossze a vizet es ihatod is");
    tmp->osszcucc = 2;
	add_element(&head, tmp);
	////////
	// 
	//bek�ri a receptet
	printf("ami van otthon:\n");
    fgets(keres, 15, stdin);
	char* natur = str_spacedel(keres);

	//v�gig megy a list�n �s ki�rja a tal�latokat strcmpvel, ha ninsc tal�lat bad luck...
	for (; head!=NULL; head=head->next)
	{
        strcpy(caller, natur);
		if (recept_search(caller, head))
		{
            printf("\n ehez van minden otthon:");
            printf("\n%s", head->name);
            printf("\n%s", head->ossze);
            printf("\n%s", head->elkeszit);
            printf("\n");
            nf++;
		}
	}
	//ha nincs tal�lat
	if(nf==0)
	printf("bad luck ehes maradsz\n");
	free(head);
		return 0;
}
