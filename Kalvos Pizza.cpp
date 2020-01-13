#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <iomanip>

using namespace std; 

//Menu function
int menu(){
		
	int option;
	int std = 6;
	
	//While bucle
	while(std !=0){
		
		//Printing
		cout<<"Bienvenido a Calvo's pizza"<<endl;
		cout<<"Seleccione el proceso a realizar: "<<endl;
		
		//Showing menu
		cout<<"1> Agregar 1 pedido a domicilio\n2> Agregar 1 encargo en restaurante"<<endl;
		cout<<"3> Ver pedidos a domicilio\n4> Ver encargos en el restaurante\n5> Ver total de venta"<<endl;	

		//Selection menu
		cin>>option;
		
		system("cls");
			
		//Menu options
		switch (option){
			case 1:
				//Deliver function
				deliver();
				break;
			case 2:
				//Restaurant function
				restaurant();
				break; 
			case 3:
				//Deliveries orders
				//seeDeliveries();
				break;
			case 4:
				//Restaurant orders
				//seeRestaurant();
				break;
			case 5:
				//Total amount
				//totalSales();
				break;
			default:
				cout<<"Seleccione una entrada valida por favor"<<endl;
				break;
		}
	}
}

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


