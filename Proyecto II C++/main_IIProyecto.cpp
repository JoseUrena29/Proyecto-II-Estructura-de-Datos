#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

/* Proyecto II - Estructura de Datos C++*/
/* Universidad Castro Carazo - Estructura de Datos 
 	Estudiantes: 
		Jose Ure�a Aguilar
		Abel Abarca Jimenez 
*/
using namespace std;
struct nodo{
       int telefono,opcion;
	   string nombre;              
	   string empresa;
	   string fecha;        
	   struct nodo *sgte; 
	   struct nodo *ant;
};

typedef struct nodo *Tlista;

//FUNCIONES MENU PRINCIPAL

//OPCION #1 - Ingresar Contacto

void insertar(Tlista &inicio, int telef, string nom, string empre, string fech)
{
	Tlista temp,ptr,ant;
	temp= new(struct nodo);
	temp->telefono=telef;
	temp->nombre=nom;
	temp->empresa=empre;
	temp->fecha=fech;
	temp->sgte=NULL;
	if (inicio==NULL)
	    inicio=temp;
	else
	{
	  if (telef<inicio->telefono)
	  {
	  	temp->sgte=inicio;
	  	inicio=temp;
	  }
	  else 
	    {
	      ant=NULL;
	  	  ptr=inicio;
	  	  while(ptr->sgte!= NULL && telef>ptr->telefono)
		   {
		    ant=ptr;
			ptr=ptr->sgte;
		   }
		  if (telef>ptr->telefono)
		 	ptr->sgte=temp;
		  else
		 	{
		 	ant->sgte=temp;	
		 	temp->sgte=ptr;
			 }
	    }
    }
}

void buscar_insertar (Tlista &inicio, int telef, string nom, string empre, string fech)
{
	Tlista ptr;
	int bandera=0;
	ptr=inicio;
	while (ptr!=NULL)
	{
		if (ptr->telefono==telef)
		{
			cout<<"\n";
	 		cout<<"\n    Telefono ya se encuentra en la lista...!"<<endl;	
			bandera=1;
		}
		ptr=ptr->sgte;	
	}
	if (bandera==0)
	{
		cout<< "\n Ingresar nombre: "; cin>> nom;
        cout<< "\n Ingresar empresa: "; cin>> empre;
        cout<< "\n Ingresar fecha de nacimiento: "; cin>> fech;
	 	insertar(inicio,telef,nom,empre,fech);
	 	cout<<"\n";
	 	cout<<"\n    Telefono agregado a la lista!"<<endl;
	}
}


//OPCION #2 - Borrar Contacto

void eliminarcontacto (Tlista &inicio, int telef)
{
	Tlista ptr,ant;
	int i=1, bandera=0;
	if(inicio->telefono==telef)
	{
	 	ptr=inicio;
		inicio=ptr->sgte;
		delete(ptr);
		cout<<"\n\n Contacto eliminado!"<<endl;
	 	bandera=1;
	}
	else
	{
		ant=NULL;
		ptr=inicio;
		while (ptr->sgte!=NULL && ptr->telefono!=telef)
		{
     		ant=ptr;
	 		ptr=ptr->sgte;
		}
		if(ptr->sgte==NULL)
		{
			delete(ptr);
			ant->sgte=NULL;
			cout<<"\n\n Contacto eliminado!"<<endl;
			bandera=1;
		}
		else
		{
			ant->sgte=ptr->sgte;
			delete(ptr);
			cout<<"\n\n Contacto eliminado!"<<endl;
			bandera=1;
		}
		
	    if(bandera==0)
	      cout<<"\n\n Numero no se encuentra en la lista...!"<<endl;
    } 
}

void buscar_eliminar (Tlista &inicio, int telef)
{
	Tlista ptr;
	int i=1, bandera=0;
	string respuesta;
	ptr=inicio;
	while (ptr!=NULL)
	{
		if (ptr->telefono==telef)
		{
			cout<<"\n";
			cout<<"Contacto Encontrado en la posicion: "<< i<<endl;
			cout<<"\n Desea eliminar el contacto? 1.Si / 2.No -> Respuesta:  "; cin>>respuesta;	
            		
			while(respuesta!="1" && respuesta!="2")
			{
				cout<<"\n ERROR!! OPCION INCORRECTA!!"<<endl;
				cout<<"\n Desea eliminar el contacto? 1.Si / 2.No -> Respuesta:  "; cin>>respuesta;
			}
			
				if(respuesta=="1"){
					eliminarcontacto(inicio,telef);
				}
				if(respuesta=="2"){
					cout<<"\n Contacto NO eliminado!"<<endl;
				}
			bandera=1;
		}
		ptr=ptr->sgte;
		i++;
	}
	if(bandera==0)
	 cout<<"\n\n Contacto no se encuentra en la lista...!"<<endl;
}


//OPCION #3 - Imprimir lista Contacto Agenda

void imprimir(Tlista inicio)
{
	cout<<"\n\t\t- - - - - - LISTA DE CONTACTOS - - - - -"<<endl;
	
	int i=0;
	Tlista puntero;
	puntero=inicio;
	while (puntero!=NULL)
	{
		cout<<"\n";
		cout<<' '<<i+1 <<")  Telefono: "<< puntero->telefono<<endl;
		cout<<"     Nombre: "<< puntero->nombre<<endl;
		cout<<"     Empresa: "<< puntero->empresa<<endl;
		cout<<"     Fecha Nacimiento: "<< puntero->fecha<<endl;
		puntero=puntero->sgte;
		i++;
	}
}

//OPCION #4 - Modificar Contacto

//OPCION #5 - Consultar Contacto
//FUNCIONES SUB-MENU CONSULTAS


void menu1()
{	
    cout<<"\n\t\t + - - - - - - AGENDA TELEFONICA - - - - - - +  \n\n";
    cout<<" 1. Ingresar Contacto                "<<endl;
    cout<<" 2. Borrar Contacto                  "<<endl;
    cout<<" 3. Imprimir Agenda                  "<<endl;
    cout<<" 4. Modificar Contacto               "<<endl;
    cout<<" 5. Consultar                        "<<endl;
    cout<<" 6. Salir							"<<endl;
 
    cout<<"\n INGRESE UNA OPCION: ";
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
                 buscar_insertar(inicio, telefdato, nombredato, empresadato, fechadato);
            break;
            case 2:
               if (inicio==NULL)
            	    cout<< "\n La agenda se encuentra vacia .....!"<<endl;
            	else
            	{
            		cout<< "\n Telefono a eliminar: ";cin>> telefdato;
            		buscar_eliminar(inicio, telefdato);
                	//eliminarcontacto(inicio,telefdato);
				}    
            break;
            case 3:
            	if (inicio==NULL)
            	    cout<< "\n La agenda se encuentra vacia .....!"<<endl;
            	else
            	{
                	imprimir(inicio);
				}                
            break;
            case 4:
            	if (inicio==NULL)
            	    cout<< "\n La agenda se encuentra vacia .....!"<<endl;
            	else
            	{
                 	
				}
			break;
			
			case 5:
			// SUB-MENU Consultar contacto
                 do{
				system("cls");
				cout<< "\n\t CONSULTAR CONTACTO\n"<<endl;
				cout<< " 1.  Por numero de telefono                        "<<endl;
				cout<< " 2.  Por nombre de contacto                        "<<endl;
				cout<< " 3.  Por nombre de empresa                         "<<endl;
				cout<< " 4.  Por cumplea�os                                "<<endl;
				cout<< " 5.  Volver                                        "<<endl;
				cout<<"\n";
				cout<< " \n Ingrese una opcion: ";
				cin >> opcion;
				
					
				switch(opcion){
						
					case 1:	
						if (inicio==NULL)
	            	    	cout<< "\n La agenda se encuentra vacia .....!"<<endl;
		            	else
		            	{
		                 	
		                 	
						}
					break;

					case 2:
						if (inicio==NULL)
	            	    	cout<< "\n La agenda se encuentra vacia .....!"<<endl;
		            	else
		            	{
		                 	
		                 	
						}	
					break;
						
					case 3:
						if (inicio==NULL)
	            	    	cout<< "\n La agenda se encuentra vacia .....!"<<endl;
		            	else
		            	{
		                 	
		                 	
						}
						
					break;
					
					case 4:	
						if (inicio==NULL)
	            	    	cout<< "\n La agenda se encuentra vacia .....!"<<endl;
		            	else
		            	{
		                 	
		                 	
						}
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
