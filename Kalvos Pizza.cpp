#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <iomanip>

using namespace std; 

//struct
struct pizza{	
	int election;
	
	//Personal information variables
	string name, lastN, address;
	int phone, acommpanying;
	
	//Menu information variables
	int mainC, starter, drink;
	
	//Money information variables
	float amount1, amount2, amount;
	int payment, num1, num2,  num3;
};

void menu();
int deliver(int option1, int array);
int restaurant(int option2, int array);
void seeDeliveries(int option3);

//Main function
int main(){
	
	//Variables
	int user;
	char password[5];
	string passw;
	passw = "class"; 
	
	//Asking for user
	cout << "Seleccione su usuario\n";
	cout << "1) ADMINISTRADOR\t\t2) EMPLEADO" << endl;
	cin >> user;
	
	if (user == 1){
		//Clean screen
		system ("cls");
		
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
	else {
		//Printing on screen and cleaning after
		cout << "Ingresando al sistema" << endl;
		system ("pause");
		
	}
}

//Menu function
void menu(){
	pizza option;										  
	int array = 0;										  
	int *p;	
	
	//Printing on screen 								
	cout << "Determine la dimension del arreglo: ";	
	cin >> array;	
	
	//Create dinamic arrangements									
	p = new int [array];
	
	for (int i = 0; i < array; i++){
		
		//Printing
		cout << "Bienvenido a Calvo's pizza" << endl;
		cout << "Seleccione el proceso a realizar: " << endl;
		
		//Showing menu
		cout << "1> Agregar 1 pedido a domicilio\n2> Agregar 1 encargo en restaurante" << endl;
		cout << "3> Ver pedidos a domicilio\n4> Ver encargos en el restaurante\n5> Ver total de venta" << endl;	

		//Selection menu
		cin >> option.election;
		
		system("cls");
			
		//Menu options
		switch (option.election){
			case 1:
				//Deliver function
				deliver(option.election, array);
				break;
			case 2:
				//Restaurant function
				restaurant(option.election, array);
				break; 
			case 3:
				//Deliveries orders
				seeDeliveries(option.election);
				break;
			case 4:
				//Restaurant orders
				//seeRestaurant(selection.option4);
				break;
			case 5:
				//Total amount
				//totalSales(selection.option5);
				break;
			default:
				cout << "Seleccione una entrada valida por favor" << endl;
				break;
		}
	}
	cout << "ERROR\nEl tamano del arreglo no es valido" << endl;
	return;
}

//Option 1 function
int deliver(int option1, int array){
	pizza option;
	//Cleaning Buffer
	fflush(stdin);
	
	//Printing personal information requirements 
	cout << "Nombre de la persona que realiza el pedido: ";	getline (cin, option.name);
	cout << endl <<"Direccion: ";	getline (cin, option.address);
	cout << "\nTelefono: ";	cin >> option.phone;
	
	//Printing main Course menu
	cout << "\nPlato principal: 1> Pizza ($11.99)\t2> Ensalada ($6.99)\t3>Pasta ($8.99)\nSu seleccion:\t";	cin >> option.mainC;
	cout << "Numero de platos que desea: "; cin >> option.num1;
	
	//Choosing main Course
	switch (option.mainC){
		case 1:
			option.amount1= 11.99 * option.num1;
			break;
		case 2:
			option.amount1= 6.99 * option.num1;
			break;
		case 3:
			option.amount1= 8.99 * option.num1;
			break;
		default:
			cout << "Seleccione una de las opciones del menu" << endl;
			break;
	}
	
	//Printing starter menu
	cout << "\nEntrada: 1> Cheese Rollers ($2.99, incluye 7 unidades)\t2> Pizza Hands ($1.99, incluye 5 unidades)\nSu seleccion:"; cin >> option.starter;
	cout << "Numero de entradas que desea: "; cin >> option.num2;
	
	//Choosing starter
	switch (option.starter){
		case 1:
			option.amount2= option.amount1 + (2.99 * option.num2);
			break;
		case 2:
			option.amount2= option.amount1 + (1.99 * option.num2);
			break;
		default:
			cout << "Seleccione una de las opciones del menu" << endl;
			return 0;
			break;
	}
	
	//Printing drink menu
	cout << "\nBebida: 1> Gaseosa ($1.99)\t2> Te helado ($0.99)\nSu seleccion:"; cin >> option.drink;
	cout << "Numero de bebidas que desea: "; cin >> option.num3;
		
	//Choosing drink
	switch (option.drink){
		case 1:
			option.amount= option.amount2 + (1.99 * option.num2);
			break;
		case 2:
			option.amount= option.amount1 + (0.99 * option.num2);
			break;
		default:
			cout << "Seleccione una de las opciones del menu" << endl;
			return 0;
			break;
	}
	
	//Showing total amount of the order
	cout << "\nMonto: $" << option.amount;
	
	//Asking for payment method
	cout << endl << "\nTipo de pago: \n1> Tarjeta\n2> Efectivo\nSu seleccion:";	cin >> option.payment;
	
	//Verifyin payment method selection
	if (option.payment==1){
		cout << "Ha seleccionado tipo de pago con tarjeta." << endl;
	}
	else cout << "Ha seleccionado tipo de pago en efectivo." << endl;
	
	//Cleaning screen
	system("cls");
	
	return 0;
}

//Option 2 function
int restaurant(int option2, int array){
	pizza option;
	
	//Cleaning buffer
	fflush(stdin);
	
	//Printing personal information requirements 
	cout << "Nombre de la persona que realiza la reserva: ";	getline (cin, option.name);
	cout << "\nAcompanantes por mesa: ";	cin >> option.acommpanying;
	cout << "\nPlato principal: 1> Pizza ($11.99)\t2> Ensalada ($6.99)\t3>Pasta ($8.99)\nSu seleccion: ";	cin >> option.mainC;
	
	//Choosing main Course
	switch (option.mainC){
		case 1:
			option.amount1 = 11.99 * option.acommpanying;
			break;
		case 2: 
			option.amount1 = 6.99 * option.acommpanying;
			break;
		default:
			option.amount1 = 8.99 * option.acommpanying;
			break;
	}
	
	//Printing starter menu
	cout << "\nEntrada: 1> Cheese Rollers ($2.99, incluye 7 unidades)\t2> Pizza Hands ($1.99, incluye 5 unidades)\nSu seleccion:"; cin >> option.starter;
	
	//Choosing starter
	switch (option.starter){
		case 1:
			option.amount2 = option.amount1 + (2.99 * option.acommpanying);
			break;
		default:
			option.amount2 = option.amount1 + (1.99 * option.acommpanying);
			break;
	}
	
	//Printing drink menu
	cout << "\nBebida: 1> Gaseosa ($1.99)\t2> Te helado ($0.99)\nSu seleccion:";	cin >> option.drink;
	
	//Choosing drink
	switch (option.drink){
		case 1:
			option.amount = option.amount2 + (1.99 * option.acommpanying);
			break;
		default:
			option.amount = option.amount2 + (0.99 * option.acommpanying);
			break;
	}
	
	//Showing total amount of the order 
	cout << "\nMonto: $" << option.amount;
	
	//Asking for payment method
	cout << endl << "\nTipo de pago: \n1> Tarjeta\n2> Efectivo\nSu seleccion:";	cin >> option.payment;
	
	//Verifying payment method selection
	if (option.payment == 1){
		cout << "Ha seleccionado tipo de pago con tarjeta." << endl;
	}
	else cout << "Ha seleccionado tipo de pago en efectivo." << endl;
	
	system ("pause");
	system("cls");
	
	return 0;
	
}

//Option 3 function
void seeDeliveries(int option3){
	pizza option;
}

