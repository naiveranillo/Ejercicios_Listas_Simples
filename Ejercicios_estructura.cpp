#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

//Autor: Naiver Anillo

bool filtro;

struct nodo
{
	int num;
	nodo *sig;
};
bool entre_impares_unpar(nodo *cab);
void imprimir_lista(nodo *cab);
void imprimir_binario(nodo *cab);
bool verificar_serie(nodo *cab);

int main()
{
	nodo *cab,*p,*nuv;
	int num=0,opc=1,dato=0;
	bool sw,sw2, exit = false;
	cab=NULL;
	
	do{	
		system("cls");
		cout<<endl<<endl<<endl;
		cout<<"\t\t\t\t[Menu]"<<endl<<endl;
		cout<<"\t\t1. Verificar en la lista si hay entre dos pares un impar."<<endl<<
			"\t\t2. Imprime el numero menor en forma binaria."<<endl<<
			"\t\t3. Verifica si sigue la serie de que si la multiplicacion de los 2 primeros numeros\n\t\t   en la lista es igual al siguiente numero."<<endl<<
			"\t\t4. Crear lista nueva."<<endl<<
			"\t\t5. Salir."<<endl;
		
		cout<<"\t\tElige una Opcion: ";
		cin>>opc;					
		cout<<endl;		
		switch(opc)
		{
			case 1:
				imprimir_lista(cab);
				cout<<endl;
				sw=entre_impares_unpar(cab);
				
				if(filtro != true)
				{
					if(sw==true)
					{
						cout<<"\t\tNo hay entre dos impares un par"<<endl;
					}else{
						cout<<"\t\tSi hay entre dos impares un par"<<endl;
					}		
				}
				system("pause");
			break;
			
			case 2:
				imprimir_binario(cab);
				cout<<endl;
				system("pause");
			break;
			
			case 3:
				sw2=verificar_serie(cab);
				if(filtro != true)
				{
					if(sw2==true)
					{
						cout<<"\t\tSi cumple"<<endl;
					}else{
						cout<<"\t\tNo cumple"<<endl;
					}	
				}
				system("pause");
			break;
			
			case 4:
				cab=NULL;
				opc=1;
				while (opc==1)
				{
					if(cab == NULL)
					{
						cab= new nodo;
						cout<<"\t\tSuministre un numero: ";
						cin>>dato;
						cab->num=dato;
						cab->sig=NULL;
						p=cab;
					}else{
						nuv= new nodo;
						cout<<"\t\tSuministre un numero: ";
						cin>>dato;
						nuv->num=dato;
						nuv->sig=NULL;
						p->sig=nuv;
						p=p->sig;
					}
		
					cout<<"\t\tQuieres continuar? Si:1 NO:2: ";
					cin>>opc;
	
				}
				
				system("cls");
				imprimir_lista(cab);
				system("pause");
				
				
			break;
			
			case 5:
				exit=true;
			break;
			
			default:
				cout<<"\n\t\t[OPCION INCORRECTA]"<<endl;
				system("pause");
			
		}
	}while(exit == false);
	
}

void imprimir_lista(nodo *cab)
{
	nodo *p;
	p=cab;
	cout<<"\n\t\tLa lista quedo asi: "<<endl;
	cout<<"\t\t";
	while (p != NULL)
	{
		cout<<p->num<<" --> ";
		p=p->sig;
	}
	cout<<"NULL"<<endl;
	

}

bool entre_impares_unpar(nodo *cab)
{
	nodo *p,*q,*r;
	bool sw=true;
	filtro=false;
	
	if (cab == NULL)
	{
		cout<<"\t\tFaltan datos"<<endl;
		filtro=true;
	}else{
		if(cab->sig == NULL)
		{
			cout<<"\t\tFaltan datos"<<endl;
			filtro=true;
		}else{
			p=cab->sig;
			if(p->sig == NULL)
			{
				cout<<"\t\tFaltan datos"<<endl;
				filtro=true;
			}else{
				p=cab;
				q=p->sig;
				r=q->sig;
				
				while (r  != NULL && sw==true)
				{
					if(p->num%2 != 0 && q->num%2 == 0 && r->num%2 != 0)
					{
					sw=false;
					}
					p=p->sig;
					q=q->sig;
					r=r->sig;
				}
				
			}
		}
	}
	return(sw);
}

void imprimir_binario(nodo *cab)
{
	nodo *p,*nuv,*cab2;
	int num=0,res=0,men=0;
	filtro = false;
	if(cab == NULL)
	{
		cout<<"\t\tFaltan datos"<<endl;
		filtro=true;
	}else{
		men=cab->num;
	    p=cab;
	    
	    if(p->sig != NULL)
	    {
	    	while (p != NULL)
	    	{
	    	
		  		if(p->num<men)
		    	{
		    		men=p->num;
		    	}
		    	p=p->sig;
	    	}	
		}
	    
	    num=men;
	    cab2=NULL;
	    do{
	    	res=num%2;
			if(cab2 == NULL)
			{
				cab2= new nodo;
				cab2->num=res;
				cab2->sig=NULL;
				p=cab2;
			}else{
				nuv= new nodo;
				nuv->num=res;
				nuv->sig=p;
				p=nuv;
			}
	    	num=num/2;
	    }while(num != 0);
	    cout<<endl;
	    cab2=nuv;
	    imprimir_lista(cab2);
	    cout<<"\t\tNumero menor: "<<men<<endl;	
	}
    
}

bool verificar_serie(nodo *cab)
{
	nodo *p,*q;
	int mult=0;
	bool sw=true;
	filtro = false;
	
	if(cab == NULL)
	{
		cout<<"\t\tFaltan datos"<<endl;
		filtro=true;
	}else{
		if(cab->sig == NULL)
		{
			cout<<"\t\tFaltan datos"<<endl;
			filtro=true;
		}else{
			if((cab->sig)->sig == NULL)
			{
				cout<<"\t\tFaltan datos"<<endl;
				filtro=true;
			}else{
				mult=cab->num;
				p=cab->sig;
				mult=mult*p->num;
				q=p->sig;
				
				while(q!=NULL && sw==true)
				{
					if(mult != q->num)
					{
						sw=false;
					}else{
						p=p->sig;
						q=q->sig;
						mult=mult*p->num;
					}
					
				}
				p=cab->sig;
				q=p->sig;
			    cab->sig=p->sig;
			    p->sig=NULL;
			    free(p);
				imprimir_lista(cab);
			}
		}
	}
	
	return(sw);
}
