#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <iomanip>

using namespace std; 

//Structs
struct pizza{
	//Personal information variables
	string name, address[50];
	int phone, acommpanying;
	//Menu information variables
	int mainC, starter, drink;
	//Money information variables
	float amount1, amount2, amount;
	int payment, num1, num2, num3;
};

//Prototipes
void menu();
int deliver();
int restaurant();
void seeDeliveries();
void seeRestaurant();

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

//Menu function
void menu(){
	pizza option;
	int std = 6;
	
	//While bucle
	while(std !=0){
		
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
				deliver(option.election);
				break;
			case 2:
				//Restaurant function
				restaurant(option.election);
				break; 
			case 3:
				//Deliveries orders
				seeDeliveries(selection.option3);
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
}

//Option 1 function
int deliver(int option1){
	pizza option;
	//Cleaning Buffer
	fflush(stdin);
	
	//Printing personal information requirements 
	cout << "Nombre de la persona que realiza el pedido: ";	getline (cin, option.name);
	cout << endl <<"Direccion: ";	getline (cin, option.address);
	cout << "\nTelefono: ";	cin >> option.phone;
	
	//Printing main Course menu
	cout << "\nPlato principal: 1> Pizza ($11.99)\t2> Ensalada ($6.99)\t3>Pasta ($8.99)\nSu seleccion:\t";	cin >> option.mainC;
	
	//Choosing main Course
	switch (option.mainC){
		case 1:
			option.amount1=11.99 * option.num1;
			break;
		case 2:
			option.amount1=6.99 * option.num1;
			break;
		case 3:
			option.amount1=8.99 * option.num1;
			break;
		default:
			cout << "Seleccione una de las opciones del menu" << endl;
			break;
	}
	
	cout << "Numero de platos que desea: "; cin >> option.num1;
	
	//Printing starter menu
	cout << "\nEntrada: 1> Cheese Rollers ($2.99, incluye 7 unidades)\t2> Pizza Hands ($1.99, incluye 5 unidades)\nSu seleccion:"; cin >> option.starter;
	
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
	
	cout << "Numero de entradas que desea: "; cin >> option.num2;
	
	//Printing drink menu
	cout << "\nBebida: 1> Gaseosa ($1.99)\t2> Te helado ($0.99)\nSu seleccion:"; cin >> option.drink;
	
	//Choosing drink
	switch (option.drink){
		case 1:
			option.amount= option.amount2 + (1.99 * option.num3);
			break;
		case 2:
			option.amount= option.amount1 + (0.99 * option.num3);
			break;
		default:
			cout << "Seleccione una de las opciones del menu" << endl;
			return 0;
			break;
	}
	
	cout << "Numero de bebidas que desea: "; cin >> option.num3;
	
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
int restaurant(){
	
	//Cleaning buffer
	fflush(stdin);
	
	//Printing personal information requirements 
	cout<<"Nombre de la persona que realiza la reserva: ";	cin>>name;
	cout<<endl<<"Apellido: "; cin>>lastN;
	cout<<"\nAcompanantes por mesa: ";	cin>>acommpanying;
	cout<<"\nPlato principal: 1> Pizza ($11.99)\t2> Ensalada ($6.99)\t3>Pasta ($8.99)\nSu seleccion: ";	cin>>mainC;
	
	//Choosing main Course
	switch (mainC){
		case 1:
			amount1=11.99*acommpanying;
			break;
		case 2:
			amount1=6.99*acommpanying;
			break;
		default:
			amount1=8.99*acommpanying;
			break;
	}
	
	//Printing starter menu
	cout<<"\nEntrada: 1> Cheese Rollers ($2.99, incluye 7 unidades)\t2> Pizza Hands ($1.99, incluye 5 unidades)\nSu seleccion:";	cin>>starter;
	
	//Choosing starter
	switch (starter){
		case 1:
			amount2= amount1+(2.99*acommpanying);
			break;
		default:
			amount2= amount1+(1.99*acommpanying);
			break;
	}
	
	//Printing drink menu
	cout<<"\nBebida: 1> Gaseosa ($1.99)\t2> Te helado ($0.99)\nSu seleccion:";	cin>>drink;
	
	//Choosing drink
	switch (drink){
		case 1:
			amount= amount2+(1.99*acommpanying);
			break;
		default:
			amount= amount1+(0.99*acommpanying);
			break;
	}
	
	//Showing total amount of the order 
	cout<<"\nMonto: $"<<amount;
	
	//Asking for payment method
	cout<<endl<<"\nTipo de pago: \n1> Tarjeta\n2> Efectivo\nSu seleccion:";	cin>>payment;
	
	//Verifying payment method selection
	if (payment==1){
		cout<<"Ha seleccionado tipo de pago con tarjeta."<<endl;
	}
	else cout<<"Ha seleccionado tipo de pago en efectivo."<<endl;
	
	//Creating text folder
	ofstream restaurant("restaurantRecord.txt",ios_base::app); //Guardo el espacio en un archivo
	if (restaurant.is_open()){ //Si el archivo se abre
		restaurant<<name<<" "<<lastN<<" "<<acommpanying<<" "<<mainC<<" "<<starter<<" "<<drink<<" "<<amount<<" "<<payment<<" "<<endl;
		cout<<endl;
		restaurant.close();
	}		
	else cout<<"No se puede abrir el archivo o no existe"<<endl;
	
	system("cls");
	return 0;
	
}

