#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std ;

//AUTOR: NAIVER ANILLO

/* Segmento de declaracion de estructuras y variables */
struct nodo
{	int num;
	nodo *sig;
} ;

int c=0;
void imprimir_lista(nodo *cab);
int hallar_mayor (nodo *cab);

/* Segmento de Programa Principal*/
int main()
{	
	int opc=1, dato, y=0, r=0;
	struct nodo *cab, *q, *nuevo;
	
	/* Segmento de creación de la lista */	
	cab=NULL;
	while(opc==1)
	{
		printf("\nSuministre un numero:");
		cin>>dato;
		nuevo= new nodo;
		nuevo->num=dato;
		nuevo->sig=NULL;
		if( cab == NULL)
		{
			cab=nuevo;
			q=cab;
		}
		else
		{
			q->sig=nuevo;
		// se refresca el apuntador al ultimo nodo 
		// hasta el momento
			q=nuevo;
		}
		printf("\n Desea continuar ? (1:SI, 2: NO) ? :");
		cin >> opc;
	}
	
	
	/* segmento de impresion de la lista */
	printf("\nLa lista creada fue :\n");
	imprimir_lista(cab);
	r=hallar_mayor (cab);
	cout<<"\nEl mayor fue "<<r<<endl;
	cout<<"El numero mayor esta a "<<c<<" nodos"<<endl;
	system("pause");

} // fin de main 

void imprimir_lista(nodo *cab)
{	
	nodo *q;
	
	q=cab;
	while( q != NULL)
	{	
		printf(" %d ---> ", q->num);
		
		q=q->sig;
	};
	
	printf("NULL \n");
}

int hallar_mayor (nodo *cab)
{
	nodo *p;
	int may=0;
	
	if (cab == NULL)
	{
	 cout<<"Error faltan nodos"<<endl;
	}else{
		p=cab->sig;
		may=cab->num;
	
		while (p != NULL)
		{
			if(p->num>may)
			{
				may=p->num;
			}
			p=p->sig;
		}
	
		p=cab;
	
		while (p->num != may)
		{
		   c=c+1;
		   p=p->sig;
		}
	}
	
	return(may);
}
