#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <time.h>

/* Proyecto II Listas Enlazadas Circular - Estructura de Datos C++*/
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
    Tlista aux,nuevo,encontrado;
    int bandera=0;
    nuevo = new(struct nodo);
    nuevo->telefono = telef;
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
    	while (encontrado->sgte!=inicio && bandera!=1)
	{
		if (encontrado->telefono==telef)
		{
			cout<<"\n";
	 		cout<<"\n    Telefono ya se encuentra en la lista...!"<<endl;	
			bandera=1;
		}
		encontrado=encontrado->sgte;	
	
    	if (telef < inicio->telefono && nom < inicio->nombre && empre < inicio->empresa && fech < inicio->fecha  )
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
		  while (aux->sgte!=inicio && aux->telefono < telef && aux->nombre < nom && aux->empresa < empre && aux->fecha < fech)	
		  {
		  aux=aux->sgte;
    	  }
    	  if (aux->telefono>telef && aux->nombre>nom  && aux->empresa>empre && aux->fecha >fech)
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
}

void buscar_insertar (Tlista &inicio, int telef, string nom, string empre, string fech)
{
	Tlista encontrado = inicio;
	int bandera=0;
	string dia;
	string mes;
	string annio;
	string slash;
	slash = "/";
	
	while (encontrado->sgte!=inicio && bandera!=1)
	{
		if (encontrado->telefono==telef)
		{
			cout<<"\n";
	 		cout<<"\n    Telefono ya se encuentra en la lista...!"<<endl;	
			bandera=1;
		}
		encontrado=encontrado->sgte;	
	}
	if (bandera==0)
	{
		cout<<"\n    Telefono no encontrado!"<<endl;
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

void buscarElemento(Tlista &inicio, int telef, string nom, string empre, string fech)
{
    Tlista encontrado = inicio;
    int i = 1, bandera = 0;
 
    while(encontrado->sgte!=inicio && bandera!=1)
    {
        if(encontrado->telefono==telef)
        {
            cout<<endl<<" Encontrada en la posición "<< i <<endl;
            bandera = 1;
        }
        encontrado = encontrado->sgte;
        i++;
    }
 
    if(bandera==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
        insertar(inicio,telef,nom,empre,fech);
}

//OPCION #2 - Borrar Contacto
void buscar_eliminar(Tlista &inicio, int telef)
{
    Tlista p;
    p = inicio;
    int i=0;
    int bandera=0;
    
    if (inicio->telefono == telef)
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
		if(p->telefono==telef)
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
    if (p->telefono==telef && bandera!=1)
    {
    	p->sgte->ant=p->ant;
    	p->ant->sgte=p->sgte;
    	delete(p);
    	bandera=1;
	}
    if(bandera==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
}



//OPCION #3 - Imprimir lista Contacto Agenda
void imprimir(Tlista inicio)
{
	cout<<"\n\t\t- - - - - - LISTA DE CONTACTOS - - - - -"<<endl;
	
   Tlista aux;
   int i=1;
   aux= inicio;
   while (aux->sgte != inicio)
       {
       	cout<<"\n";
		cout<<' '<<i+1 <<")  Telefono: "<< aux->telefono<<endl;
		cout<<"     Nombre: "<< aux->nombre<<endl;
		cout<<"     Empresa: "<< aux->empresa<<endl;
		cout<<"     Fecha Nacimiento: "<<aux->fecha<<endl;
		aux=aux->sgte;
		i++;  	
        }
    if (aux->sgte==inicio) 
        cout<<"\n";
		cout<<' '<<i+1 <<")  Telefono: "<< aux->telefono<<endl;
		cout<<"     Nombre: "<< aux->nombre<<endl;
		cout<<"     Empresa: "<< aux->empresa<<endl;
		cout<<"     Fecha Nacimiento: "<<aux->fecha<<endl;
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




//OPCION #2 - Consultar Contacto - Nombre




//OPCION #3 - Consultar Contacto - Empresa




//OPCION #4 - Consultar Contacto - Cumpleaños




void menu1()
{	
	time_t tiempoahora;
	time(&tiempoahora);
	cout<<"\n Fecha Actual: ", ctime(&tiempoahora);
    
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

int main() {
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
                 cout<< "\n Ingresar nombre: "; cin>> nombredato;
                 cout<< "\n Ingresar empresa: "; cin>> empresadato;
                 cout<< "\n Ingresar fecha de nacimiento: "; cin>> fechadato;
                 //buscar_insertar(inicio, telefdato, nombredato, empresadato, fechadato);
                 insertar(inicio, telefdato, nombredato, empresadato, fechadato);
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
				cout<<"\n Fecha Actual: ", ctime(&tiempoahora);
			    
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
		                 	//cout<< "\n Ingrese el Telefono a consultar: ";cin>> telefdato;
            				//consulta_telefono(inicio, telefdato, nombredato, empresadato, fechadato);		
						}
					break;
					
					//OPCION #2 - Consultar Contacto - Nombre
					case 2:
						if (inicio==NULL)
	            	    	cout<< "\n La agenda se encuentra vacia .....!"<<endl;
		            	else
		            	{
		                 	cout<< "\n Ingrese el Nombre a consultar: ";cin>> nombredato;
            				//consulta_nombre(inicio, telefdato, nombredato, empresadato, fechadato);	 	
						}	
					break;
					
					//OPCION #3 - Consultar Contacto - Empresa	
					case 3:
						if (inicio==NULL)
	            	    	cout<< "\n La agenda se encuentra vacia .....!"<<endl;
		            	else
		            	{
		                 	//cout<< "\n Ingrese el Nombre de la Empresa a consultar: ";cin>> empresadato;
            				//consulta_empresa(inicio, telefdato, nombredato, empresadato, fechadato);		
						}	
					break;
					
					//OPCION #4 - Consultar Contacto - Cumpleaños
					case 4:	
						if (inicio==NULL)
	            	    	cout<< "\n La agenda se encuentra vacia .....!"<<endl;
		            	else
		            	{
		                 //consulta_cumple(inicio, telefdato, nombredato, empresadato, fechadato);		
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
