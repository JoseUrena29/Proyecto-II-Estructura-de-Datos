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
    Tlista aux,nuevo;
    nuevo = new(struct nodo);
    nuevo->telefono=telef;
	nuevo->nombre=nom;
	nuevo->empresa=empre;
	nuevo->fecha=fech;
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
    	if (telef < inicio->telefono)
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
		  while (aux->sgte!=inicio && aux->telefono < telef)	
		  {
		  aux=aux->sgte;
    	  }
    	  if (aux->telefono>telef)
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

void buscarElemento(Tlista &inicio, int telef, string nom, string empre, string fech)
{
    Tlista encontrado = inicio;
    int i = 1, bandera = 0;
    string dia;
	string mes;
	string annio;
	string slash;
	slash = "/";
 
 	if(inicio!=NULL)
	 {
	 	do
	 	{
	 		if(encontrado->telefono==telef)	
	 		{
				cout<<"\n";
		 		cout<<"\n    Telefono ya se encuentra en la lista...!"<<endl;
	            bandera = 1;	
			}
	 		encontrado = encontrado->sgte;	
		}while(encontrado!=inicio && bandera!=1);
		
		if(bandera==0){
			cout<<"\n    Telefono agregado a la lista!"<<endl;
			
		}		
	 }
	 
	 
	 
    /*while(encontrado->sgte!=inicio && bandera!=1)
    {
        if(encontrado->telefono==telef)
        {
        	cout<<"\n";
	 		cout<<"\n    Telefono ya se encuentra en la lista...!"<<endl;
            bandera = 1;
        }
        encontrado = encontrado->sgte;
        i++;
    }
 
    if(bandera==0){
    	cout<< "\n Ingresar nombre: "; cin>> nom;
    	cout<< "\n Ingresar empresa: "; cin>> empre;
        cout<< "\n Ingresar fecha de nacimiento: \n";
        cout<<" Dia: ";cin>>dia;
        cout<<" Mes: ";cin>>mes;
        cout<<" Año: ";cin>>annio;
        fech=dia+slash+mes+slash+annio;
        //insertar(inicio,telef,nom,empre,fech);
        cout<<"\n";
	 	cout<<"\n    Telefono agregado a la lista!"<<endl;
	}*/

}

//OPCION #2 - Borrar Contacto
void eliminarcontacto(Tlista &inicio, int telef)
{
    Tlista p;
    p = inicio;
    int i=1;
    int bandera=0;
    string respuesta;
    
    if (inicio->telefono == telef)
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
		    	cout<<"\n\n\t Contacto eliminado!"<<endl;
			}
			if(respuesta=="2"){
				cout<<"\n\n\t Contacto NO eliminado!"<<endl;
			}
    	bandera=1;
     	}
    else
    {
	p=inicio;
    while(p->sgte!=inicio && bandera!=1)
    { 
		if(p->telefono==telef)
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
					p->ant->sgte= p->sgte;
					p->sgte->ant=p->ant; 
					delete(p);
			    	cout<<"\n\n\t Contacto eliminado!"<<endl;
				}
				if(respuesta=="2"){
					cout<<"\n\n\t Contacto NO eliminado!"<<endl;
				}
          bandera = 1;
        }
        p = p->sgte;
        i++;
    }
    }
    if (p->telefono==telef && bandera!=1)
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
			    p->sgte->ant=p->ant;
		    	p->ant->sgte=p->sgte;
		    	delete(p);	   
		    	cout<<"\n\n\t Contacto eliminado!"<<endl;
			}
			if(respuesta=="2"){
				cout<<"\n\n\t Contacto NO eliminado!"<<endl;
			}
    	bandera=1;
	}
    if(bandera==0)
        cout<<"\n\n\t Numero no se encuentra en la lista...!"<<endl;
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
		cout<<' '<<i <<")  Telefono: "<< aux->telefono<<endl;
		cout<<"     Nombre: "<< aux->nombre<<endl;
		cout<<"     Empresa: "<< aux->empresa<<endl;
		cout<<"     Fecha Nacimiento: "<<aux->fecha<<endl;
		aux=aux->sgte;
		i++;  	
        }
    if (aux->sgte==inicio) 
        cout<<"\n";
		cout<<' '<<i <<")  Telefono: "<< aux->telefono<<endl;
		cout<<"     Nombre: "<< aux->nombre<<endl;
		cout<<"     Empresa: "<< aux->empresa<<endl;
		cout<<"     Fecha Nacimiento: "<<aux->fecha<<endl;
}



//OPCION #4 - Modificar Contacto
void modificarcontacto (Tlista &inicio, int telef, string nom, string empre, string fech)
{
    Tlista encontrado = inicio;
    int i = 1, bandera = 0;
 
 	if(inicio!=NULL)
	 {
	 	do
	 	{
	 		if(encontrado->telefono==telef)	
	 		{
	 			
	 			cout<<"\n";
				cout<<"\n    Telefono SI se encuentra en la lista!"<<endl;
				cout<< "\n Ingresar el nuevo numero telefonico: ";
				cin >> encontrado->telefono;
				
				cout<<"\n";
				cout<<"\n\n\t    Numero Telefonico Modificado!!"<<endl;
	            bandera = 1;	
			}
	 		encontrado = encontrado->sgte;	
		}while(encontrado!=inicio && bandera!=1);
		
		if(bandera==0){
			cout<<"\n    Telefono NO se encuentra en la lista...!"<<endl;
			
		}		
	 }	
}


/*OPCION #5 - Consultar Contacto
   FUNCIONES SUB-MENU CONSULTAS*/

//OPCION #1 - Consultar Contacto - Telefono
void consultatelefono (Tlista &inicio, int telef, string nom, string empre, string fech)
{
	Tlista encontrado = inicio;
    int i = 0, bandera = 0;
 
 	if(inicio!=NULL)
	 {
	 	do
	 	{
	 		if(encontrado->telefono==telef)	
	 		{
				cout<<"\n";
				cout<<' '<<i+1 <<")  Telefono: "<< encontrado->telefono<<endl;
				cout<<"     Nombre: "<< encontrado->nombre<<endl;
				cout<<"     Empresa: "<< encontrado->empresa<<endl;
				cout<<"     Fecha Nacimiento: "<< encontrado->fecha<<endl;
				bandera=1;	
			}
	 		encontrado = encontrado->sgte;
			i++;	
		}while(encontrado!=inicio && bandera!=1);
		
		if(bandera==0){
			cout<<"\n    Telefono NO se encuentra en la lista...!"<<endl;
			
		}		
	 }
}



//OPCION #2 - Consultar Contacto - Nombre
void consultanombre (Tlista &inicio, int telef, string nom, string empre, string fech)
{
	Tlista encontrado = inicio;
    int i = 0, bandera = 0;
 
 	if(inicio!=NULL)
	 {
	 	do
	 	{
	 		if(encontrado->nombre==nom)	
	 		{
				cout<<"\n";
				cout<<' '<<i+1 <<")  Telefono: "<< encontrado->telefono<<endl;
				cout<<"     Nombre: "<< encontrado->nombre<<endl;
				cout<<"     Empresa: "<< encontrado->empresa<<endl;
				cout<<"     Fecha Nacimiento: "<< encontrado->fecha<<endl;
				bandera=1;	
			}
	 		encontrado = encontrado->sgte;
			i++;	
		}while(encontrado!=inicio && bandera!=1);
		
		if(bandera==0){
			cout<<"\n    Nombre NO se encuentra en la lista...!"<<endl;	
		}		
	 }
}

//OPCION #3 - Consultar Contacto - Empresa
void consultaempresa (Tlista &inicio, int telef, string nom, string empre, string fech)
{
	Tlista encontrado = inicio;
    int i = 0, bandera = 0;
 
 	if(inicio!=NULL)
	 {
	 	do
	 	{
	 		if(encontrado->empresa==empre)	
	 		{
				cout<<"\n";
				cout<<' '<<i+1 <<")  Telefono: "<< encontrado->telefono<<endl;
				cout<<"     Nombre: "<< encontrado->nombre<<endl;
				cout<<"     Empresa: "<< encontrado->empresa<<endl;
				cout<<"     Fecha Nacimiento: "<< encontrado->fecha<<endl;
				bandera=1;	
			}
	 		encontrado = encontrado->sgte;
			i++;	
		}while(encontrado!=inicio && bandera!=1);
		
		if(bandera==0){
			cout<<"\n    Nombre NO se encuentra en la lista...!"<<endl;	
		}		
	 }
}

//OPCION #4 - Consultar Contacto - Cumpleaños
void consultacumple (Tlista &inicio, int telef, string nom, string empre, string fech)
{
	struct fecha {
	int dia, mes, anio;
	};	
	
	time_t tiempoahora;
	time(&tiempoahora);
	cout<<"\n Fecha Actual: ", ctime(&tiempoahora);
    
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
		if (cumple.dia == mytime->tm_mday && cumple.mes == mytime->tm_mon+1)
		{ 
			cout<<"\n";
			cout<<"\n\n\t* * * * * FELIZ CUMPLEAÑOS!!! * * * * * \n"<<endl;
			bandera=1;
		}

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
    string dia;
	string mes;
	string annio;
	string slash;
	slash = "/";
    	
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
		        cout<< "\n Ingresar fecha de nacimiento: \n";
		        cout<<" Dia: ";cin>>dia;
		        cout<<" Mes: ";cin>>mes;
		        cout<<" Año: ";cin>>annio;
		        fechadato=dia+slash+mes+slash+annio;
				insertar(inicio, telefdato, nombredato, empresadato, fechadato);
                //buscarElemento(inicio, telefdato, nombredato, empresadato, fechadato);
                 
                 
            break;
            
            //OPCION #2 - Borrar Contacto
            case 2:
               if (inicio==NULL)
            	    cout<< "\n La agenda se encuentra vacia .....!"<<endl;
            	else
            	{
            		cout<< "\n Telefono a eliminar: ";cin>> telefdato;
            		eliminarcontacto(inicio, telefdato);
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
            		modificarcontacto(inicio, telefdato, nombredato, empresadato, fechadato);	
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
		                 	cout<< "\n Ingrese el Telefono a consultar: ";cin>> telefdato;
            				consultatelefono(inicio, telefdato, nombredato, empresadato, fechadato);		
						}
					break;
					
					//OPCION #2 - Consultar Contacto - Nombre
					case 2:
						if (inicio==NULL)
	            	    	cout<< "\n La agenda se encuentra vacia .....!"<<endl;
		            	else
		            	{
		                 	cout<< "\n Ingrese el Nombre a consultar: ";cin>> nombredato;
            				consultanombre(inicio, telefdato, nombredato, empresadato, fechadato);	 	
						}	
					break;
					
					//OPCION #3 - Consultar Contacto - Empresa	
					case 3:
						if (inicio==NULL)
	            	    	cout<< "\n La agenda se encuentra vacia .....!"<<endl;
		            	else
		            	{
		                 	cout<< "\n Ingrese el Nombre de la Empresa a consultar: ";cin>> empresadato;
            				consultaempresa(inicio, telefdato, nombredato, empresadato, fechadato);		
						}	
					break;
					
					//OPCION #4 - Consultar Contacto - Cumpleaños
					case 4:	
						if (inicio==NULL)
	            	    	cout<< "\n La agenda se encuentra vacia .....!"<<endl;
		            	else
		            	{
		                 consultacumple(inicio, telefdato, nombredato, empresadato, fechadato);		
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
