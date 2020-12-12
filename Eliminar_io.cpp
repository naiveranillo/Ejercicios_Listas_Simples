#include <iostream>
#include <stdlib.h>

using namespace std;

//Autor: Naiver Anillo
struct nombre
{
	string letra;
	nombre *sig;
};

void imprimir_lista(nombre *cab);
void eliminar_io(nombre *cab);
int main()
{
int opc=1,rep=1;
string dato;
struct nombre *cab, *q, *nuevo;
/* Segmento de creación de la lista */
    while(rep == 1){	
        cab=NULL;
        opc=1;
        printf("[Si el 'io' esta entre dos nodos, eliminar los nodos y sin desordenar la lista]\n");
        while(opc==1)
        {
            nuevo= new nombre;
            printf("\nSuministre una letra: ");
            cin>>dato;
            nuevo->letra=dato;
            nuevo->sig=NULL;
                if( cab == NULL)
                {
                    cab=nuevo;
                    q=cab;
                }
                else
                {
                    q->sig=nuevo;

                    q=nuevo;
                }
            printf("\n Desea continuar ? (1:SI, 2: NO) ? :");
            cin >> opc;
        }
        
         printf("\n Desea digitar nuevamente la lista ? (1:SI, 2: NO) ? :");
         cin>>rep;
        
}

/* segmento de impresion de la lista */
printf("\n La lista creada fue :\n");
imprimir_lista(cab);
eliminar_io(cab);
} 


void imprimir_lista(nombre *cab)
{	nombre *q;

q=cab;
while( q != NULL)
{	
    
    cout<<q->letra<<" ---> ";

q=q->sig;
};

printf("NULL \n");
}

void eliminar_io(nombre *cab)
{
    nombre *p,*q,*z;
    
    p=cab;
    q=p->sig;
    while(q != NULL)
    {
        if(p->letra == "i" && q->letra == "o")
        {
            if(p == cab)
            {
                cab=q->sig;
                p->sig=NULL;
                q->sig=NULL;
                free(p);
                free(q);
                p=cab;
                q=p->sig;
            }else{
                z=cab;
                while(z->sig != p)
                {
                    z=z->sig;
                }
                
                p->sig=NULL;
                z->sig=q->sig;
                q->sig=NULL;
                free(p);
                free(q);
                p=z;
                q=p->sig;
                z=NULL;
            }
        }else{
            p=p->sig;
            q=q->sig;
        }
    }
    
    printf("\n La lista modificada quedo asi:\n");
    imprimir_lista(cab);
}

