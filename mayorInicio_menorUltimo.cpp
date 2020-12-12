#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std ;

//AUTOR: NAIVER ANILLO

//Poner el numero mayor en el primer nodo y el menor en el ultimo nodo
struct nodo{
	int num;
	nodo *sig;	
};

void edit_lista(nodo *cab);
void imprimir_lista(nodo *cab);

int main(){
	
	nodo *cab = NULL, *p = NULL, *nuevo = NULL;
	int num = 0, opc = 1;
	
	while(opc == 1)
	{
		nuevo = new nodo;
		cout<<"\nDigite un numero: ";
		cin >> num;
		nuevo->num = num;
		nuevo->sig = NULL;
		
		if(cab == NULL)
		{
			cab = nuevo;
			p = cab;
		}else{
			p->sig = nuevo;
			p = p->sig;
		}
		
		cout<<"\nQuieres ingresar mas? SI=1 || NO=2: ";
		cin >> opc;
	}
	
	edit_lista(cab); 
		
	system("pause");
}

void imprimir_lista(nodo *cab)
{
	nodo *p;
	
	p = cab;
	while (p != NULL)
	{
		cout<<p->num<<" --> ";
		p = p->sig;
	}
	cout<<"NULL\n";
}	

void edit_lista(nodo *cab)
{
	nodo *p,*q;
	int men=0, may=0;
	
	if (cab == NULL)
	{
		cout<<"\nNo hay datos";
	}else{
		if(cab->sig == NULL)
		{
			cout<<"\nFaltan datos";
		}else{		
			p = cab;
			may = p->num;
			men = p->num;		
			while(p != NULL)
			{
				if(p->num > may)
				{
					may = p->num;
				}
				
				if(p->num < men)
				{
					men = p->num;
				}				
				p = p->sig;
			}	
			p = cab;	
			while (p != NULL)
			{
				if(p->num == may)
				{
					p->num = cab->num;
					cab->num = may;
				}		
				if(p->sig == NULL)
				{
					q=cab;					
					while(q != NULL)
					{
						if(q->num == men)
						{
							q->num = p->num;
							p->num = men;
						}						 
						q = q->sig;
					}
				}				
				p = p->sig;
			}
		}
	}
	
	imprimir_lista(cab);
}
