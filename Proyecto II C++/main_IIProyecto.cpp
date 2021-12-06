#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <time.h>

/* Proyecto II - Estructura de Datos C++*/
/* Universidad Castro Carazo - Estructura de Datos 
 	Estudiantes: 
		Jose Ureña Aguilar
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
	string dia;
	string mes;
	string annio;
	string slash;
	slash = "/";
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
        cout<< "\n Ingresar fecha de nacimiento: \n";
        cout<<" Dia: ";cin>>dia;
        cout<<" Mes: ";cin>>mes;
        cout<<" Año: ";cin>>annio;
        fech=dia+slash+mes+slash+annio;
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
		cout<<"     Fecha Nacimiento: "<<puntero->fecha<<endl;
		puntero=puntero->sgte;
		i++;
	}
}

//OPCION #4 - Modificar Contacto

void buscar_modificar (Tlista &inicio, int telef, string nom, string empre, string fech)
{
	Tlista ptr;
	int bandera=0;
	ptr=inicio;
	while (ptr!=NULL)
	{
		if (ptr->telefono==telef)
		{ 
			cout<<"\n";
			cout<<"\n    Telefono SI se encuentra en la lista!"<<endl;
			cout<< "\n Ingresar el nuevo numero telefonico: ";
			cin >> ptr->telefono;
			
			cout<<"\n";
			cout<<"\n    Numero Telefonico Modificado!!"<<endl;
			bandera=1;
		}
		ptr=ptr->sgte;	
	}
	if (bandera==0)
	{
		cout<<"\n";
		cout<<"\n    Telefono NO se encuentra en la lista...!"<<endl;
	}
}
/*OPCION #5 - Consultar Contacto
   FUNCIONES SUB-MENU CONSULTAS*/

//OPCION #1 - Consultar Contacto - Telefono

void consulta_telefono (Tlista &inicio, int telef, string nom, string empre, string fech)
{
	Tlista ptr;
	int bandera=0;
	int i=0;
	ptr=inicio;
	while (ptr!=NULL)
	{
		if (ptr->telefono==telef)
		{ 
			cout<<"\n";
			cout<<' '<<i+1 <<")  Telefono: "<< ptr->telefono<<endl;
			cout<<"     Nombre: "<< ptr->nombre<<endl;
			cout<<"     Empresa: "<< ptr->empresa<<endl;
			cout<<"     Fecha Nacimiento: "<< ptr->fecha<<endl;
			bandera=1;
		}
		ptr=ptr->sgte;
		i++;	
	}
	if (bandera==0)
	{
		cout<<"\n";
		cout<<"\n    Telefono NO se encuentra en la lista...!"<<endl;
	}
}

//OPCION #2 - Consultar Contacto - Nombre

void consulta_nombre (Tlista &inicio, int telef, string nom, string empre, string fech)
{
	Tlista ptr;
	int bandera=0;
	int i=0;
	ptr=inicio;
	while (ptr!=NULL)
	{
		if (ptr->nombre==nom)
		{ 
			cout<<"\n";
			cout<<' '<<i+1 <<")  Telefono: "<< ptr->telefono<<endl;
			cout<<"     Nombre: "<< ptr->nombre<<endl;
			cout<<"     Empresa: "<< ptr->empresa<<endl;
			cout<<"     Fecha Nacimiento: "<< ptr->fecha<<endl;
			bandera=1;
		}
		ptr=ptr->sgte;
		i++;	
	}
	if (bandera==0)
	{
		cout<<"\n";
		cout<<"\n    Nombre NO se encuentra en la lista...!"<<endl;
	}
}

//OPCION #3 - Consultar Contacto - Empresa

void consulta_empresa (Tlista &inicio, int telef, string nom, string empre, string fech)
{
	Tlista ptr;
	int bandera=0;
	int i=0;
	ptr=inicio;
	while (ptr!=NULL)
	{
		if (ptr->empresa==empre)
		{ 
			cout<<"\n";
			cout<<' '<<i+1 <<")  Telefono: "<< ptr->telefono<<endl;
			cout<<"     Nombre: "<< ptr->nombre<<endl;
			cout<<"     Empresa: "<< ptr->empresa<<endl;
			cout<<"     Fecha Nacimiento: "<< ptr->fecha<<endl;
			bandera=1;
		}
		ptr=ptr->sgte;
		i++;	
	}
	if (bandera==0)
	{
		cout<<"\n";
		cout<<"\n    Empresa NO se encuentra en la lista...!"<<endl;
	}
}

//OPCION #4 - Consultar Contacto - Cumpleaños
void consulta_cumple (Tlista &inicio, int telef, string nom, string empre, string fech)
{
	struct fecha {
	int dia, mes, anio;
	};	
	
	time_t tiempoahora;
	time(&tiempoahora);
	cout<<"\n Fecha Actual: 0", ctime(&tiempoahora);
    
	struct tm *mytime = localtime(&tiempoahora);
	printf("%d/%d/%d", mytime->tm_mday, mytime->tm_mon+1,mytime->tm_year+1900);
	
	fecha cumple;
	cout<<"\n\n";
	cout<<" Ingrese su fecha de cumpleaños: "<<endl;
	cout<<" Dia: "; cin >>cumple.dia;
	cout<<" Mes: "; cin >>cumple.mes;
	
	Tlista ptr;
	int bandera=0;
	int i=0;
	ptr=inicio;
	//while (ptr!=NULL)
	//{
		if (cumple.dia == mytime->tm_mday && cumple.mes == mytime->tm_mon+1)
		{ 
			cout<<"\n";
			cout<<"\n\t* * * * * FELIZ CUMPLEAÑOS!!! * * * * * \n"<<endl;
			
			//cout<<"     Nombre: "<< ptr->nombre<<endl;
			//cout<<"     Empresa: "<< ptr->empresa<<endl;
			//cout<<"     Fecha Nacimiento: "<< ptr->fecha<<endl;
			bandera=1;
		}
		//ptr=ptr->sgte;
		//i++;	
	//}
	if (bandera==0)
	{
		cout<<"\n";
		cout<<"\n    No hay cumpleañeros en la lista para el dia de hoy...!"<<endl;
	}
}

void menu1()
{	
	time_t tiempoahora;
	time(&tiempoahora);
	cout<<"\n Fecha Actual: 0", ctime(&tiempoahora);
    
	struct tm *mytime = localtime(&tiempoahora);
	printf("%d/%d/%d", mytime->tm_mday, mytime->tm_mon+1,mytime->tm_year+1900);
	cout<<"\n"<<endl;
	
	cout << "\n\t\t|--------------------------------------|";
	cout << "\n\t\t|        ° AGENDA TELEFONICA °         |";
	cout << "\n\t\t|--------------------------------------|\n\n";
    cout<<" 1. Ingresar Contacto                "<<endl;
    cout<<" 2. Borrar Contacto                  "<<endl;
    cout<<" 3. Imprimir Agenda                  "<<endl;
    cout<<" 4. Modificar Contacto               "<<endl;
    cout<<" 5. Consultar                        "<<endl;
    cout<<" 6. Salir							"<<endl;
 
    cout<<"\n Ingrese una opcion: ";
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
        	//OPCION #1 - Ingresar Contacto
            case 1:
				 cout<< "\n Ingresar telefono: "; cin>> telefdato;
                 buscar_insertar(inicio, telefdato, nombredato, empresadato, fechadato);
            break;
            
            //OPCION #2 - Borrar Contacto
            case 2:
               if (inicio==NULL)
            	    cout<< "\n La agenda se encuentra vacia .....!"<<endl;
            	else
            	{
            		cout<< "\n Telefono a eliminar: ";cin>> telefdato;
            		buscar_eliminar(inicio, telefdato);
				}    
            break;
            
            //OPCION #3 - Imprimir lista Contacto Agenda
            case 3:
            	if (inicio==NULL)
            	    cout<< "\n La agenda se encuentra vacia .....!"<<endl;
            	else
            	{
                	imprimir(inicio);
				}                
            break;
            
            //OPCION #4 - Modificar Contacto
            case 4:
            	if (inicio==NULL)
            	    cout<< "\n La agenda se encuentra vacia .....!"<<endl;
            	else
            	{
                    cout<< "\n Telefono a modificar: ";cin>> telefdato;
            		buscar_modificar(inicio, telefdato, nombredato, empresadato, fechadato);	
				}
			break;
			
			//OPCION #5 - Consultar Contacto
			case 5:
			// SUB-MENU Consultar contacto
			
				 do{
				system("cls");
				time_t tiempoahora;
				time(&tiempoahora);
				cout<<"\n Fecha Actual: 0", ctime(&tiempoahora);
			    
				struct tm *mytime = localtime(&tiempoahora);
				printf("%d/%d/%d", mytime->tm_mday, mytime->tm_mon+1,mytime->tm_year+1900);
				cout<<"\n"<<endl;

				cout << "\n\t\t|--------------------------------------|";
				cout << "\n\t\t|        ° AGENDA TELEFONICA °         |";
				cout << "\n\t\t|--------------------------------------|\n\n";
				cout<< "\n\t+- - - - - CONSULTAR CONTACTO - - - - -+\n"<<endl;
				cout<< " 1.  Por numero de telefono                        "<<endl;
				cout<< " 2.  Por nombre de contacto                        "<<endl;
				cout<< " 3.  Por nombre de empresa                         "<<endl;
				cout<< " 4.  Por cumpleaños                                "<<endl;
				cout<< " 5.  Volver                                        "<<endl;
				cout<<"\n";
				cout<< " \n Ingrese una opcion: ";
				cin >> opcion;
				
					
				switch(opcion){
					
					//OPCION #1 - Consultar Contacto - Telefono	
					case 1:	
						if (inicio==NULL)
	            	    	cout<< "\n La agenda se encuentra vacia .....!"<<endl;
		            	else
		            	{
		                 	cout<< "\n Ingrese el Telefono a consultar: ";cin>> telefdato;
            				consulta_telefono(inicio, telefdato, nombredato, empresadato, fechadato);		
						}
					break;
					
					//OPCION #2 - Consultar Contacto - Nombre
					case 2:
						if (inicio==NULL)
	            	    	cout<< "\n La agenda se encuentra vacia .....!"<<endl;
		            	else
		            	{
		                 	cout<< "\n Ingrese el Nombre a consultar: ";cin>> nombredato;
            				consulta_nombre(inicio, telefdato, nombredato, empresadato, fechadato);	 	
						}	
					break;
					
					//OPCION #3 - Consultar Contacto - Empresa	
					case 3:
						if (inicio==NULL)
	            	    	cout<< "\n La agenda se encuentra vacia .....!"<<endl;
		            	else
		            	{
		                 	cout<< "\n Ingrese el Nombre de la Empresa a consultar: ";cin>> empresadato;
            				consulta_empresa(inicio, telefdato, nombredato, empresadato, fechadato);		
						}	
					break;
					
					//OPCION #4 - Consultar Contacto - Cumpleaños
					case 4:	
						if (inicio==NULL)
	            	    	cout<< "\n La agenda se encuentra vacia .....!"<<endl;
		            	else
		            	{
		                 consulta_cumple(inicio, telefdato, nombredato, empresadato, fechadato);		
						}
					break;                                 
				}
				
				cout<<endl<<endl;
				system("pause");  system("cls");
				
			}while (opcion != 5);
			break;		   
    	 }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=6);
  
   system("pause");
   return 0;
}
