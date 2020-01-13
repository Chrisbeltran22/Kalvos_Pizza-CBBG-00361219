#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <iomanip>

using namespace std; 

//Main function
int main(){
	
	//Variables
	char password[5];
	string passw;
	passw = "class"; 
	
	//While bucle
	while(password != passw){
		
		//Printing
		cout<<"Bienvenido, por favor introduzca la contrasena para continuar: ";
		cin>>password;
		
		//Password verification
			if (password == passw){
				system("cls");
				menu();
			}
			else cout<<"Contrasena erronea, por favor introduzca de nuevo la contrasena."<<endl;
		
		system ("pause");	
		system("cls");
	}
}


