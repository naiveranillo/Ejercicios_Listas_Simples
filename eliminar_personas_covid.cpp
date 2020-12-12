#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct persona
{
	int ced;
	string nom;
	bool indicador_covid;
	
	persona *sig;
};

void imprimir_lista(persona *cab);
void eliminar_personas_covid(persona *cab);

int main()
{
	persona *cab,*p,*nuv;
	int ced=0,opc=1,opc2=0;
	bool covid;
	string nom;
	cab=NULL;
	
	while (opc==1)
	{
		if(cab == NULL)
		{
			cab = new persona;
			cout<<"\nDigite la cedula: ";
			cin>>ced;
			cab->ced = ced;
			cout<<"Digite nombre: ";
			cin>>nom;
			cab->nom = nom;
			cout<<endl<<"Positivo para covid? Si=1 | No=2: ";
			cin>>opc2;
			if(opc2 == 1){
				cab->indicador_covid = true;
			}else{
				cab->indicador_covid = false;
			}
			cab->sig=NULL;
			p=cab;
		}else{
			nuv= new persona;
			cout<<"\nDigite la cedula: ";
			cin>>ced;
			nuv->ced = ced;
			cout<<"Digite nombre: ";
			cin>>nom;
			nuv->nom = nom;
			cout<<endl<<"Positivo para covid? Si=1 | No=2: ";
			cin>>opc2;
			if(opc2 == 1){
				nuv->indicador_covid = true;
			}else{
				nuv->indicador_covid = false;
			}	
			nuv->sig=NULL;
			p->sig=nuv;
			p=p->sig;
		}		
		cout<<endl<<"Quieres continuar? Si:1 NO:2: ";
		cin>>opc;
	
	}
	eliminar_personas_covid(cab);
	//imprimir_lista(cab);
	system("pause");
}

void imprimir_lista(persona *cab)
{
	persona *p;
	p=cab;
	
	while (p != NULL)
	{
		cout<<p->ced<<" "<<p->nom<<" "<<p->indicador_covid<<" --> ";
		p=p->sig;
	}
	cout<<"NULL"<<endl;

}

void eliminar_personas_covid(persona *cab)
{
	persona *p, *q;
	bool sw = false, sw2 = false;
	int cantidad = 0;
	if(cab == NULL)
	{
		cout<<"Esta vacia la lista"<<endl;
	}else{
		if(cab->sig == NULL)
		{
			if(cab->indicador_covid == true)
			{
				free(cab);
				cab = NULL;	
				cantidad = cantidad + 1;
			}
		}else{
				p = cab;
				
				while(sw2 != true && cab != NULL)
				{
					if(p == cab && sw == false)
					{
						if(p->indicador_covid == true)
						{
							cab = cab->sig;
							p->sig = NULL;
							free(p);
							p = cab;
							cantidad = cantidad + 1;
						}else{
							q = p->sig;
							sw = true;
							
							if(q == NULL)
							{
								sw2 = true;
							}
						}
					}else{
						if(q->indicador_covid == true)
						{
							p->sig = q->sig;
							q->sig = NULL;
							free(q);
							q = p->sig;
							cantidad = cantidad + 1;
						}else{
							p = p->sig;
							q = q->sig;
						}
						
						if(q == NULL)
						{
							sw2 = true;
						}
					}	
				}
				
			}
	}
	
	if(cantidad != 0)
	{
		cout<<"\nCantidad de personas contagiadas: "<<cantidad<<endl;
	}else{
		cout<<"\nNo hubo personas contagiadas"<<endl;
	}
	
	imprimir_lista(cab);
}

