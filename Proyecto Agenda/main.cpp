#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <string.h>
#include <stdio.h>
using namespace std;

class Empresa {
   private:
      // Datos miembro de la clase empresa
      string apellidoEmpresa,nombreEmpresa,sitioWebEmpresa,ciudadEmpresa;
   public:
      // Funciones miembro de la clase "empresa"
      string getApellidoEmpresa(){
      	return apellidoEmpresa;
	  }
	  string getNombreEmpresa(){
      	return nombreEmpresa;
	  }
	  string getSitioWeb(){
      	return sitioWebEmpresa;
	  }
	  string getCiudad(){
      	return ciudadEmpresa;
	  }
      //void Lee(int &a2, int &b2);
      void DatosEmpresa(string ape,string nom,string sitioW,string ciu) {
         apellidoEmpresa = ape;
         nombreEmpresa = nom;
         sitioWebEmpresa = sitioW;
         ciudadEmpresa = ciu;
      }
      /*void GuardarDatos(){
      	fstream archivo("datos.txt", ios::in|ios::out);
      	cout << "Ingresando datos en el archivo..." << endl;
      	
      	archivo << apellidos<<";"<<nombres<<";"<<direccion<<";"<<telefono<<";"<<endl;
      	
      	      	
	  }*/
};

class Persona : public Empresa{
   private:
      // Datos miembro de la clase Persona
      string apellidosPersona,nombresPersona,direccionPersona,telefonoPersona;
   public:
      // Funciones miembro de la clase "persona"
      void Lee(int &a2, int &b2);
      void DatosPersona(string ape,string nom,string dir,string telef) {
         apellidosPersona = ape;
         nombresPersona = nom;
         direccionPersona = dir;
         telefonoPersona = telef;        
      }
        
	  void GuardarDatos(){
      	fstream archivo("datos.txt", ios::in|ios::out|ios::ate);
      	cout << "Ingresando datos en el archivo..." << endl;
      	
      	/*
		  //Ordenando nombres
		    for ( i = 0; i < NUM; i++ ){
		        for ( int j = i + 1; j < NUM; j++ ){
		 
		            // strcoll() devuelve -1 si el 1º parametro es mayor que el 2º, 0 si el 1º es igual al 2º, o 
		            //1 si el 1º mayor que el 2º. Lo hace caracter a caracter hasta encontrar una diferencia o un nulo que es cuando retorna uno de los valores mensionados.    
		            if ( ( strcoll(/*1º*/ /*agenda[i].nombre, /*2º*//*agenda[j].nombre) ) > 0 ) {  
		 
		                //esto va subiendo los nombres a la cabeza de la lista
		                strcpy ( temp.nombre, agenda[i].nombre );
		                strcpy ( agenda[i].nombre, agenda[j].nombre );
		                strcpy ( agenda[j].nombre, temp.nombre );
		            }
		        }
		    }
		  */
      	
      	
      	
      	archivo << apellidosPersona<<";"<<nombresPersona<<";"<<direccionPersona<<";"<<telefonoPersona<<";"<<getApellidoEmpresa()<<";"<<getNombreEmpresa()<<";"<<getSitioWeb()
		  <<";"<<getCiudad()<<endl;     	
      	
	  }
};



int main(int argc, char** argv) {
	
	int opcion=0;
	while(opcion!=4){
		
		string c;
	    int contador;
		string nombres="",apellidos="",direccion="",telefono="",apellidoE="null",nombreE="null",sitioWeb="null", ciudad="null";
		Persona nueva;
		string apellidoB,nombreB;
		string emp;
		string linea;
		//fstream archivo("datos.txt", ios::in|ios::out);
		ifstream salida("datos.txt",ios::in);
		ofstream entrada("temp.txt",ios::out);
		
		cout << "\n\t\tUniversidad San Francisco de Quito";
		cout << "\n\t\t\tProyecto Final";
		cout << "\n\n>>AGENDA";
		cout << "\n\nMENU" << endl;
		cout << "\n1. Imprimir Agenda";
		cout << "\n2. Ingresar Registro";
		cout << "\n3. Eliminar Registro";
		cout << "\n4. Modificar Registro";
		cout << "\n5. Salir";
		cout << "\nOpcion: ";
		cin >> opcion;
		
		switch(opcion){
			
			case 1:
				system("cls");	
				cout << "\n\t\tAGENDA\n\n";			
				contador=0;
				//nombres="",apellidos="",direccion="",telefono="",apellidoE="null",nombreE="null",sitioWeb="null", ciudad="null";
				while(getline(salida,linea))
			    {
			        for (int j = 0; j < linea.length(); j++) {
	                    c = linea.substr(j,1);
	                    if (c==";") {
	                        contador++;
	                    }else{
	                    	switch(contador){
	                    		case 0:
	                    			apellidos+=c;
	                    			//cout << apellidos;
	                    			break;
	                    		case 1:
	                    			nombres+=c;
	                    			break;
	                    		case 2:
	                    			direccion+=c;
	                    			break;
	                    		case 3:
	                    			telefono+=c;
	                    			break;
							}
						}			        	
                	}
                	contador=0;
                	cout << apellidos << " " << nombres << " " << direccion<< " " << telefono << endl;
                	cout <<"_________________________________________________________________________"<<endl;
					nombres="",apellidos="",direccion="",telefono="",apellidoE="",nombreE="",sitioWeb="", ciudad="";
			        
			    }
			    cout << endl;
			    salida.close();
				break;
			case 2:
				
				system("cls");	
				cout << "\n\t\tIngreso del Gerente\n";
				cout << "\nApellidos: ";
				cin >> apellidos;
				cout << "Nombres: ";
				cin >> nombres;
				cout << "Direccion: ";
				cin >> direccion;
				cout << "Telefono: ";
				cin >> telefono;
				cout << "Va a ingresar una empresa respecto a esta persona?(y/n)"<<endl;
				cin >> emp;
				if(emp=="y"){
					cout << "\n\t\tIngreso de una EMPRESA\n";
					cout << "\nApellidos: ";
					cin >> apellidos;
					cout << "Nombres: ";
					cin >> nombres;
					cout << "Sitio Web: ";
					cin >> sitioWeb;
					cout << "Cuidad: ";
					cin >> ciudad;
					nueva.DatosEmpresa(apellidos,nombres,sitioWeb,ciudad);
				}				
				
				nueva.DatosPersona(apellidos,nombres,direccion,telefono);
				nueva.GuardarDatos();
				break;
			case 3:
				system("cls");
				cout <<  "\n>Eliminar Registro";
				cout << "Ingrese el apellido de la Persona" <<endl;
				cin >> apellidoB;
				cout << "Ingrese el nombre de la Persona" <<endl;	
				cin >> nombreB;
				salida >> apellidos >>nombres;
				while(!salida.eof()){
					cout << "apeB/" << apellidos<<endl;
					cout << "nomB/" <<nombres<<endl;
					/*getline(salida,linea);
					for (int j = 0; j < linea.length(); j++) {
	                    c = linea.substr(j,1);
	                    if (c==";") {
	                        contador++;
	                    }else{
	                    	switch(contador){
	                    		case 0:
	                    			apellidos+=c;
	                    			//cout << apellidos;
	                    			break;
	                    		case 1:
	                    			nombres+=c;
	                    			break;
	                    		case 2:
	                    			direccion+=c;
	                    			break;
	                    		case 3:
	                    			telefono+=c;
	                    			break;
							}
						}			        	
                	}	
					*/
					
					salida>>direccion>>telefono>>apellidoE>>nombreE>>sitioWeb>>ciudad;
					if(nombreB==nombres && apellidoB==apellidos){
						cout << "Se ha eliminado el registro\n";
					}else{
						cout <<"N-"<<nombres<<"A-"<<apellidos<<"D-"<<direccion<<"T-"<<telefono<<"AE"<<apellidoE<<"NE-"<<nombreE<<"SW-"<<sitioWeb<<"C-"<<ciudad<<endl;
						entrada<<nombres<<" "<<apellidos<<" "<<direccion<<" "<<telefono<<" "<<apellidoE<<" "<<nombreE<<" "<<sitioWeb<<" "<<ciudad<<endl;
					}
					
					
					salida >> apellidos >>nombres;
				}
				
				entrada.close();
				salida.close();
				remove("datos.txt");
				getch();
				rename("temp.txt","datos.txt");
				getch();
				break;
			case 4:
				cout <<  "\n>Modificar Registro";
				
				break;
			case 5:
				
				break;
			default:
				cout << "Opcion no valida\n\n";
				break;
		}
		system("PAUSE");
		system("cls");
	}
	
	
	
	
	/*ofstream archivo("datos.txt");

    for(char letra='A'; letra <='Z'; letra++)
    archivo << letra;
    archivo.close();
	
	char letra;
    fstream letras("datos.txt", ios::in|ios::out);

    letras.seekg(7, ios::beg);   // obtiene la letra H
    letra=letras.get();
    letras.seekp(0, ios::end);
    letras << letra;  // coloca la letra al final

    letras.seekg(-13, ios::end); // obtiene la letra O
    letra = letras.get();
    letras.seekp(0, ios::end);
    letras << letra;

    letras.seekg(-17, ios::end); // obtiene la letra L
    letra = letras.get();
    letras.seekp(0, ios::end);
    letras << letra;

    letras.seekg(0, ios::beg);   // obtiene la letra A
    letra = letras.get();
    letras.seekp(0, ios::end);
    letras << letra;

    letras.seekg(-4, ios::end);
    while(!letras.eof())
    cout.put((char)letras.get());

    letras.close();
    return 0;*/
}
