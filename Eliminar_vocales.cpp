#include <iostream>
#include <stdlib.h>

using namespace std;

//Autor: Naiver Anillo
struct letra
{
	string carac;
	letra *sig;
};

void imprimir_lista(letra *cab);
void eliminar_vocales(letra *cab);
int main()
{
int opc=1,rep=1;
string dato;
struct letra *cab, *q, *nuevo;
/* Segmento de creación de la lista */
    while(rep == 1){	
        cab=NULL;
        opc=1;
        while(opc==1)
        {
            nuevo= new letra;
            printf("\nSuministre una letra: ");
            cin>>dato;
            nuevo->carac=dato;
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
eliminar_vocales(cab);
} 


void imprimir_lista(letra *cab)
{	letra *q;

q=cab;
while( q != NULL)
{	
    
    cout<<q->carac<<" ---> ";

q=q->sig;
};

printf("NULL \n");
}

void eliminar_vocales(letra *cab)
{
    letra *p,*q,*z;
    
    p=cab;
    
    while(p != NULL)
    {
        if(p->carac == "a" || p->carac == "e" || p->carac == "i" || p->carac == "o" || p->carac == "u" )
        {
            if(p == cab)
            {
                cab=p->sig;
                p->sig=NULL;
                
                free(p);
                
                p=cab;
               
            }else{
                z=cab;
                while(z->sig != p)
                {
                    z=z->sig;
                }
                
                
                z->sig=p->sig;
                p->sig=NULL;
                free(p);
        
                p=z;
               
                z=NULL;
            }
        }else{
            p=p->sig;
           
        }
    }
    printf("\n La lista modificada fue :\n");
    imprimir_lista(cab);
}
