#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <iomanip>

using namespace std; 

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

void menu();
int deliver();
int restaurant();

//Option 5 function


//Option 4 function


//Option 3 function

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
				seeDeliveries();
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

//Option 1 function
int deliver(){
	
	//Cleaning Buffer
	fflush(stdin);
	
	//Printing personal information requirements 
	cout<<"Nombre de la persona que realiza el pedido: ";	cin>>name;
	cout<<endl<<"Apellido: "; cin>>lastN;
	cout<<endl<<"Direccion: ";	cin>>address;
	cout<<"\nTelefono: ";	cin>>phone;
	
	//Printing main Course menu
	cout<<"\nPlato principal: 1> Pizza ($11.99)\t2> Ensalada ($6.99)\t3>Pasta ($8.99)\nSu seleccion: ";	cin>>mainC;
	cout<<"Numero de platos que desea: "; cin>>num1;
	
	//Choosing main Course
	switch (mainC){
		case 1:
			amount1=11.99*num1;
			break;
		case 2:
			amount1=6.99*num1;
			break;
		default:
			amount1=8.99*num1;
			break;
	}
	
	//Printing starter menu
	cout<<"\nEntrada: 1> Cheese Rollers ($2.99, incluye 7 unidades)\t2> Pizza Hands ($1.99, incluye 5 unidades)\nSu seleccion:";	cin>>starter;
	cout<<"Numero de entradas que desea: "; cin>>num2;
	
	//Choosing starter
	switch (starter){
		case 1:
			amount2= amount1+ (2.99*num2);
			break;
		default:
			amount2= amount1+ (1.99*num2);
			break;
	}
	
	//Printing drink menu
	cout<<"\nBebida: 1> Gaseosa ($1.99)\t2> Te helado ($0.99)\nSu seleccion:";	cin>>drink;
	cout<<"Numero de bebidas que desea: "; cin>>num3;
	
	//Choosing drink
	switch (drink){
		case 1:
			amount= amount2+ (1.99*num3);
			break;
		default:
			amount= amount1+ (0.99*num3);
			break;
	}
	
	//Showing total amount of the order
	cout<<"\nMonto: $"<<amount;
	
	//Asking for payment method
	cout<<endl<<"\nTipo de pago: \n1> Tarjeta\n2> Efectivo\nSu seleccion:";	cin>>payment;
	
	//Verifyin payment method selection
	if (payment==1){
		cout<<"Ha seleccionado tipo de pago con tarjeta."<<endl;
	}
	else cout<<"Ha seleccionado tipo de pago en efectivo."<<endl;
	
	//Creating text folder
	ofstream delivery("deliveryRecord.txt",ios_base::app); 
	if (delivery.is_open()){
		//Saving order information 
		delivery<<name<<" "<<lastN<<" "<<" "<<mainC<<" "<<starter<<" "<<drink<<" "<<amount<<" "<<payment<<" "<<endl;
		cout<<endl;
		delivery.close();
	}		
	else cout<<"No se puede abrir el archivo o no existe"<<endl;
	
	return 0;
	
	//Cleaning screen
	system("cls");
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
