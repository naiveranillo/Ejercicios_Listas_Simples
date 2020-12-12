#include <stdlib.h>
#include <iostream>
using namespace std ;

//Autor: Naiver Anillo

struct pila
{
	int num;
	pila *sig;
};

struct pila *p=NULL;

void crearpila(pila **tope);
void imprimir_pila(pila *tope);
void pop (pila **tope);
bool empty_p (pila *tope);
void push(pila **tope,pila **y);
void Eliminar_Mayor(pila *tope);

int main()
{	
	struct pila *tope;
	cout<<"\n[PILA 1]";
	crearpila(&tope);
	Eliminar_Mayor(tope);
/* segmento de impresion de la lista */
   //printf("\n [PILA 1 FUE CREADA ASI] \n");
   //imprimir_pila(tope);
   
	system("pause");
} // fin de main 

void crearpila(pila **tope)
{
	int opc=1,dato;
	struct pila *nuevo;
	/* Segmento de creación de la lista */	
	*tope=NULL;
	while(opc==1)
	{
		printf("\nSuministre un numero:");
		cin>>dato;
		nuevo= new pila;
		nuevo->num=dato;
		nuevo->sig=NULL;
		if( *tope == NULL)
		{
			*tope=nuevo;
		}
		else
		{
			push(&*tope,&nuevo);
		}
		printf("\n Desea continuar ? (1:SI, 2: NO) ? :");
		cin >> opc;
	}

}
bool empty_p (pila *tope)
{
	bool x=false;
	if (tope == NULL)
	{
		x=true;
	}

	return(x);
}

void pop (pila **tope)
{
	
	p=*tope;
	*tope=(*tope)->sig;
	p->sig=NULL;

}

void push(pila **tope,pila **y)
{
	(*y)->sig=*tope;
	*tope=*y;
}

void imprimir_pila(pila *tope)
{	
	cout<<"----------[PILA]------------"<<endl<<endl;
	while(!empty_p(tope))
	{	
		cout<<"            "<<tope->num<<"            "<<endl;
		pop (&tope);
		free(p);
	};

	cout<<"            NULL            "<<endl<<endl;
	cout<<"-----------[FIN]------------"<<endl<<endl;
}

void Eliminar_Mayor(pila *tope)
{
	pila *topeaux1, *topeaux2, *y;
	int contd=0, contnr=0, num=0;
	
	if (empty_p(tope))
	{
		cout<<"Error!!, no hay datos"<<endl;
	}else{
		pop(&tope);
		if(empty_p(tope))
		{
			cout<<"Error!!, Faltan datos"<<endl;
			push(&tope,&p);
		}else{
			push(&tope,&p);
			topeaux1=NULL;
			topeaux2=NULL;
			
			while(!empty_p(tope)) //CONTAR NODOS 
			{
				pop(&tope);
				contd++;
				push(&topeaux1,&p);
			}
			
			pop(&topeaux1);
			num=p->num;
			push(&topeaux1,&p);
			
			while (!empty_p(topeaux1)) //CONTAR NUMEROS REPETIDOS
			{
				pop(&topeaux1);
				
				if(p->num == num)
				{
					contnr++;
				}
				
				push(&topeaux2,&p);
			}
			
			if (contd == contnr)
			{
				cout<<"-------------------------------------------------"<<endl;
				cout<<"[TODOS LOS NUMEROS SON REPETIDOS]"<<endl;
				cout<<"-------------------------------------------------"<<endl;
			}else{
				pop(&topeaux2);
				num=p->num;
				push(&topeaux2,&p);
				
				while (!empty_p(topeaux2)) //HALLAR MAYOR
				{
					pop(&topeaux2);
					
					if(p->num > num)
					{
						num=p->num;
					}
					
					push(&topeaux1,&p);
				}
				
				while (!empty_p(topeaux1)) //ELIMINAR EL MAYOR
				{
					pop(&topeaux1);
					
					if(p->num == num)
					{
						free(p);
					}else{
						push(&topeaux2,&p);
					}
				}
				
				while(!empty_p(topeaux2)) //INVERTIR DATOS EN LA PILA ORIGINAL
				{
					pop(&topeaux2);
					push(&tope,&p);
				}
				
				cout<<"\n[NUMERO MAYOR ELIMINADO][PILA INVERTIDA]"<<endl;
				
				imprimir_pila(tope);
			}
			
			
		}
		
	}
	
	
}


