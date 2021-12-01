#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

/* Proyecto II - Estructura de Datos C++*/
/* Universidad Castro Carazo - Estructura de Datos 
 	Estudiantes: 
		Jose Ureña Aguilar
		Abel Abarca Jimenez 
*/
using namespace std;
struct nodo{
       int tef;
	   string nombre;              
	   string empresa;
	   string fecha;        
	   struct nodo *sgte; 
	   struct nodo *ant;
};
typedef struct nodo *Tlista;

void insertar(Tlista &inicio, int telef, string nom, string empre, string fech)
{
	Tlista temp;
	temp= new(struct nodo);
	temp->tef=telef;
	temp->nombre=nom;
	temp->empresa=empre;
	temp->fecha=fech;
	temp->sgte=inicio;
	inicio=temp;
}
void imprimir(Tlista inicio)
{
	int i=0;
	Tlista puntero;
	puntero=inicio;
	while (puntero!=NULL)
	{
		cout<<' '<<i+1 <<")Telefono: "<< puntero->tef<<endl;
		cout<<' '<<i+1 <<")Nombre: "<< puntero->nombre<<endl;
		cout<<' '<<i+1 <<")Empresa: "<< puntero->empresa<<endl;
		cout<<' '<<i+1 <<")Fecha Nacimiento: "<< puntero->fecha<<endl;
		puntero=puntero->sgte;
		i++;
	}
}
void eliminarcontacto (Tlista &inicio, int telef)
{
	Tlista ptr,ant;
	int i=1, bandera=0;
	if(ptr->tef==telef)
	{
	 	ptr=inicio;
		inicio=ptr->sgte;
		delete(ptr);
	 	bandera=1;
	}
	else
	{
		ant=NULL;
		ptr=inicio;
		while (ptr->sgte!=NULL && ptr->tef!=telef)
		{
     		ant=ptr;
	 		ptr=ptr->sgte;
		}
		if(ptr->sgte==NULL)
		{
			delete(ptr);
			ant->sgte=NULL;
			bandera=1;
		}
		else
		{
			ant->sgte=ptr->sgte;
			delete(ptr);
			bandera=1;
		}
		
	    if(bandera==0)
	      cout<<"\n\n Contacto no encontrado...!"<<endl;
    }
}

void menu1()
{
    cout<<"\n\t\t Nuestra agenda Telefonica  \n\n";
    cout<<" 1. Ingresar Contacto                "<<endl;
    cout<<" 2. Borrar Contacto                  "<<endl;
    cout<<" 3. Imprimir Agenda                  "<<endl;
    cout<<" 4. Modificar Contacto               "<<endl;
    cout<<" 5. Consultar                        "<<endl;
    cout<<" 6. Salir							"<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}
int main()
{
    Tlista inicio = NULL;
    int op;     
    int telefdato;  
    string nombredato;
    string empresadato;
    string fechadato;

    system("color 0b");
 
    do
    {
        menu1();  cin>> op;
 
        switch(op)
        {
            case 1:
				 cout<< "\n Ingresar telefono: "; cin>> telefdato;
                 cout<< "\n Ingresar nombre: "; cin>> nombredato;
                 cout<< "\n Ingresar empresa: "; cin>> empresadato;
                 cout<< "\n Ingresar fecha de nacimiento: "; cin>> fechadato;
                 insertar(inicio, telefdato, nombredato, empresadato, fechadato);
            break;
            case 2:
               if (inicio==NULL)
            	    cout<< "\n No hay numeros en la agenda ....."<<endl;
            	else
            	{
            		cout<< "\n Telefono a eliminar: ";cin>> telefdato;
                	eliminarcontacto(inicio,telefdato);
				}      
            break;
            case 3:
            	if (inicio==NULL)
            	    cout<< "\n No hay numeros en la agenda ......"<<endl;
            	else
            	{
                	imprimir(inicio);
				}                
            break;
            case 4:
                 
            break;		   
    	 }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=6);
  
   system("pause");
   return 0;
}
