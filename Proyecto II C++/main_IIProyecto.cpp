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
       int tef,opcion;
	   string nombre;              
	   string empresa;
	   string fecha;        
	   struct nodo *sgte; 
	   struct nodo *ant;
};
typedef struct nodo *Tlista;


void insertar(Tlista &inicio, int telef, string nom, string empre, string fech)
{
    Tlista aux,nuevo;
    nuevo = new(struct nodo);
    nuevo->tef = telef;
    nuevo->nombre = nom;
    nuevo->empresa = empre;
    nuevo->fecha = fech;
    nuevo->sgte = NULL;
    nuevo->ant = NULL;
    
    if ( inicio==NULL)
    {
    	inicio=nuevo;
    	nuevo->ant=inicio;
    	nuevo->sgte=inicio;
    }
    else
    {
    	if (telef < inicio->tef && nom < inicio->nombre && empre < inicio->empresa && fech < inicio->fecha  )
    	{
    		nuevo->sgte=inicio;
    		nuevo->ant=nuevo->sgte->ant;
    		nuevo->sgte->ant=nuevo;
    		nuevo->ant->sgte=nuevo;
    		inicio=nuevo;
		}
    	else
    	{
    	  aux=inicio;
		  while (aux->sgte!=inicio && aux->tef < telef && aux->nombre < nom && aux->empresa < empre && aux->fecha < fech)	
		  {
		  aux=aux->sgte;
    	  }
    	  if (aux->tef>telef && aux->nombre>nom  && aux->empresa>empre && aux->fecha >fech)
    	  {
    	  	nuevo->sgte=aux;
    	  	nuevo->ant=nuevo->sgte->ant;
    	  	nuevo->sgte->ant=nuevo;
    	  	nuevo->ant->sgte=nuevo;
		  }
		  else
		  {
		  	nuevo->ant=aux;
		  	nuevo->sgte=nuevo->ant->sgte;
		  	nuevo->sgte->ant=nuevo;
		  	nuevo->ant->sgte=nuevo;
		  }
		}
    }    
}

void imprimir(Tlista inicio)
{
   Tlista aux;
   int i=1;
   aux= inicio;
   while (aux->sgte != inicio)
       {
   	    cout <<' '<< i+1 <<")Telefono: " << aux->tef << endl;
   	    cout <<' '<< i+1 <<")Nombre: " << aux->nombre << endl;
   	    cout <<' '<< i+1 <<")Empresa: " << aux->empresa << endl;
   	    cout <<' '<< i+1 <<")Fecha Nacimiento: " << aux->fecha << endl;
        aux=aux->sgte;
        i++;  	
        }
    if (aux->sgte==inicio)
        cout <<' '<< i+1 <<")Telefono: " << aux->tef << endl;
        cout <<' '<< i+1 <<")Nombre: " << aux->nombre << endl;
        cout <<' '<< i+1 <<")Empresa: " << aux->empresa << endl;
        cout <<' '<< i+1 <<")Fecha Nacimiento: " << aux->fecha << endl;
}

void eliminarcontacto(Tlista &inicio, int telef)
{
    Tlista p;
    p = inicio;
    int i=0;
    int bandera=0;
    
    if (inicio->tef == telef)
    {
    	p->ant->sgte=p->sgte;
    	p->sgte->ant=p->ant;
    	if (p->sgte==inicio)
    	{
    		inicio=NULL;
		}
		else
		{
			inicio=p->sgte;
		}
    	delete(p);
    	bandera=1;
     	}
    else
    {
	p=inicio;
    while(p->sgte!=inicio && bandera!=1)
    { 
		if(p->tef==telef)
        {
          p->ant->sgte= p->sgte;
		  p->sgte->ant=p->ant; 
		  delete(p);
		  cout<<endl<<" Encontrada en la posición "<< i <<endl;
          bandera = 1;
        }
        p = p->sgte;
        i++;
    }
    }
    if (p->tef==telef && bandera!=1)
    {
    	p->sgte->ant=p->ant;
    	p->ant->sgte=p->sgte;
    	delete(p);
    	bandera=1;
	}
    if(bandera==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
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
    int op,opcion;     
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
			
			case 5:
			//// Consultar contacto-----
                 do{
				system("cls");
				cout<< "\n\t CONSULTAR CONTACTO\n"<<endl;
				cout<< " 1.  Por numero de telefono                        "<<endl;
				cout<< " 2.  Por nombre de contacto                        "<<endl;
				cout<< " 3.  Por nombre de empresa                         "<<endl;
				cout<< " 4.  Por cumpleaños                                "<<endl;
				cout<< " 5.  Volver                                        "<<endl;
				cout<<"\n";
				cout<< " \n Ingrese una opcion: ";
				cin >> opcion;
				
					
				switch(opcion){
						
					case 1:	
					break;

					case 2:
						
					break;
						
					case 3:
					break;
					
					case 4:	
					break;                                 
				}
			}while (opcion != 5);
			break;		   
    	 }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=6);
  
   system("pause");
   return 0;
}
