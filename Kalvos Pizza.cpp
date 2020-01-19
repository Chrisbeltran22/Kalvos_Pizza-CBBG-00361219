#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <iomanip>

using namespace std; 

//struct
struct continente{
	
	string name, address;
	int phone, acommpanying;
	int mainC, starter, drink; 
	float amount1, amount2, amount;
	int payment, num1, num2,  num3;
	
};

struct continente total[5];
int cantcontinentes = 0;
struct continente total2[5];
int cantidad = 0;

//Prototypes
void delivery();
void restaurant();
void seeDeliveries();
void seeRestaurant();
void totalSales();

//Main function
int main(){
	int opcion = 0;
	
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
					while(opcion!=8){
						cout << "\n1. Agregar 1 pedido a domicilio \n";
				    	cout << "2. Agregar 1 encargo a restaurante\n";
				    	cout << "3. Ver pedidos a domicilio\n";
				    	cout << "4. Ver pedidos en restaurante\n";
						cout << "5. Ver total de venta\n";
						cout << "6. Cambiar de usuario\n";
						cout << "7. Borrar ordenes\n";
					    cout << "Opcion: ";
				    	cin >> opcion;
				    	cin.ignore();
				    	
				    	switch (opcion){
				    		case 1: system ("cls"); delivery(); break;
				    		case 2: system ("cls"); restaurant(); break;
							case 3: system ("cls"); seeDeliveries(); break;
				    		case 4: system ("cls"); seeRestaurant(); break;
				    		case 5: system ("cls"); totalSales(); break;
							case 6: system ("cls"); main(); break;/*
							case 7: deleteOrders(); break;
							*/
				    	}
					}
				}
				else if (user == 2)
				{
					cout<<"Ingresando al sistema"<<endl;
					system ("pause");
					system ("cls");
				}
				else cout << "Contrasena erronea, por favor introduzca de nuevo la contrasena." << endl;
			system ("pause");	
			system("cls");
		}
	}
	else {
		//Printing on screen and cleaning after
		cout << "Ingresando al sistema" << endl;
		system ("pause");
		//menuEmployee();
		
	}

	return 0;
}

//Option 1 function
void delivery(){
	
	if (cantcontinentes < 8){
		cout<<"Nombre de la persona que realiza el pedido: ";
		getline (cin, total[cantcontinentes].name);
		
		cout<<"Direccion: ";
		getline (cin, total[cantcontinentes].address);
		
		cout<<"Numero de telefono: ";
		cin >> total[cantcontinentes].phone;
		
		cout<<"Plato principal: 1> Pizza ($11.99)\t2> Ensalada ($6.99)\t3>Pasta ($8.99)\nSu seleccion:\t";
		cin>>total[cantcontinentes].mainC;
		cout << "Numero de platos que desea: "; cin >> total[cantcontinentes].num1;
		
		//Choosing main Course
		switch (total[cantcontinentes].mainC){
			case 1:
				total[cantcontinentes].amount1= 11.99 * total[cantcontinentes].num1;
				break;
			case 2:
				total[cantcontinentes].amount1= 6.99 * total[cantcontinentes].num1;
				break;
			case 3:
				total[cantcontinentes].amount1= 8.99 * total[cantcontinentes].num1;
				break;
			default:
				cout << "Seleccione una de las opciones del menu" << endl;
				break;
		}
		cin.ignore();
		
		//Printing on screen
		cout<<"Entrada: 1> Cheese Rollers ($2.99, incluye 7 unidades)\t2> Pizza Hands ($1.99, incluye 5 unidades)\nSu seleccion: ";
		cin>>total[cantcontinentes].starter;
		cout << "Numero de entradas que desea: "; cin >> total[cantcontinentes].num2;
	
		//Choosing starter
		switch (total[cantcontinentes].starter){
			case 1:
				total[cantcontinentes].amount2= total[cantcontinentes].amount1 + (2.99 * total[cantcontinentes].num2);
				break;
			case 2:
				total[cantcontinentes].amount2= total[cantcontinentes].amount1 + (1.99 * total[cantcontinentes].num2);
				break;
			default:
				cout << "Seleccione una de las opciones del menu" << endl;
				return;
				break;
		}
		cin.ignore();
		
		//Printing on screen
		cout<<"Bebida: 1> Gaseosa ($1.99)\t2> Te helado ($0.99)\nSu seleccion: ";
		cin>>total[cantcontinentes].drink;
		cout << "Numero de bebidas que desea: "; cin >> total[cantcontinentes].num3;
		
		//Choosing drink
		switch (total[cantcontinentes].drink){
			case 1:
				total[cantcontinentes].amount= total[cantcontinentes].amount2 + (1.99 * total[cantcontinentes].num3);
				break;
			case 2:
				total[cantcontinentes].amount= total[cantcontinentes].amount1 + (0.99 * total[cantcontinentes].num3);
				break;
			default:
				cout << "Seleccione una de las opciones del menu" << endl;
				return;
				break;
		}
		
		//Showing total amount of the order
		cout << "\nMonto: $" << total[cantcontinentes].amount;
		cin.ignore();
		
		cout<<"\nTipo de pago: \n1> Tarjeta\n2> Efectivo\nSu seleccion: ";
		cin>>total[cantcontinentes].payment;
		cin.ignore();
		
		
		cantcontinentes++;
		
		system ("cls");
	}
	else cout<<"Lo sentimos, espacio lleno"<<endl;
}

//Option 2 function
int restaurant(int option2, int array){	
	//Cleaning buffer
	fflush(stdin);
	
	if (cantidad < 8){
		//Printing requeriments on screen
		cout << "Nombre de la persona que realiza la reserva: ";
		getline (cin, total2[cantidad].name);
		
		cout << "Acompanantes por mesa: ";
		cin >> total2[cantidad].acommpanying;
		
		cout << "Plato principal: 1> Pizza ($11.99)\t2> Ensalada ($6.99)\t3>Pasta ($8.99)\nSu seleccion:\t";
		cin >> total2[cantidad].mainC;
	
		//Choosing main Course
		switch (total2[cantidad].mainC){
			case 1:
				total2[cantidad].amount1= 11.99 * total2[cantidad].acommpanying;
				break;
			case 2:
				total2[cantidad].amount1= 6.99 * total2[cantidad].acommpanying;
				break;
			case 3:
				total2[cantidad].amount1= 8.99 * total2[cantidad].acommpanying;
				break;
			default:
				cout << "Seleccione una de las opciones del menu" << endl;
				break;
		}
		cin.ignore();
		
		//Printing on screen
		cout<<"Entrada: 1> Cheese Rollers ($2.99, incluye 7 unidades)\t2> Pizza Hands ($1.99, incluye 5 unidades)\nSu seleccion: ";
		cin>>total2[cantidad].starter;

		//Choosing starter
		switch (total2[cantidad].starter){
			case 1:
				total2[cantidad].amount2= total2[cantidad].amount1 + (2.99 * total2[cantidad].acommpanying);
				break;
			case 2:
				total2[cantidad].amount2= total2[cantidad].amount1 + (1.99 * total2[cantidad].acommpanying);
				break;
			default:
				cout << "Seleccione una de las opciones del menu" << endl;
				return;
				break;
		}
		cin.ignore();
	
		//Printing on screen
		cout<<"Bebida: 1> Gaseosa ($1.99)\t2> Te helado ($0.99)\nSu seleccion: ";
		cin>>total2[cantidad].drink;
	
		//Choosing drink
		switch (total2[cantidad].drink){
			case 1:
				total2[cantidad].amount= total2[cantidad].amount2 + (1.99 * total[cantidad].acommpanying);
				break;
			case 2:
				total2[cantidad].amount= total2[cantidad].amount2 + (0.99 * total[cantidad].acommpanying);
				break;
			default:
				cout << "Seleccione una de las opciones del menu" << endl;
				return;
				break;
		}
	
		//Showing total amount of the order 
		cout << "\nMonto: $" << total2[cantidad].amount;
		cin.ignore();
	
		//Asking for payment method
		cout<<"\nTipo de pago: \n1> Tarjeta\n2> Efectivo\nSu seleccion: ";
		cin>>total2[cantidad].payment;
		cin.ignore();
	
		
		cantidad++;
		
		system ("cls");
	}
	else cout<<"Lo sentimos, espacio lleno"<<endl;
	
}

//Option 3 function
void seeDeliveries(){
	string name;
	cout<<"Pedidos a domicilio: ";
	
	for (int i = 0; i < cantcontinentes; i++){
		if (name.compare(total[i].name) != 0){
			cout << endl;
			cout << endl << "Nombre: " << total[i].name;
			cout << endl << "Direccion: " << total[i].address;
			cout << endl << "Telefono: " << total[i].phone;
			cout << endl << "Plato principal:\n1> Pizza\t2> Ensalada\t3>Pasta\nSu seleccion: " << total[i].mainC;	
			cout << endl << "Numero de platos: " << total[i].num1;
			cout << endl << "Entrada: 1> Cheese Rollers\t2> Pizza Hands\nSu seleccion: " << total[i].starter;
			cout << endl << "Numero de entradas: " << total[i].num2;
			cout << endl << "Bebida: 1> Gaseosa\t2> Te helado\nSu seleccion: " << total[i].drink;
			cout << endl << "Numero de bebidas: " << total[i].num3;
			cout << endl << "Tipo de pago: 1> Tarjeta\t2> Efectivo\nSu seleccion: " << total[i].payment;
			cout << endl << "Total a pagar: $" << total[i].amount;
			cout << endl;
			
			system ("pause");
			system ("cls");	
		}
		else cout<<"No se ha encontrado informacion en este continente"<<endl;
	}
}

//Option 4 function
void seeRestaurant(){
	string name;
	cout<<"Encargos en restaurante: ";
	
	for (int j = 0; j < cantidad; j++){
		if (name.compare(total2[j].name) != 0){
			cout << endl;
			cout << endl << "Nombre: " << total2[j].name;
			cout << endl << "Acompanantes: " << total2[j].acommpanying;
			cout << endl << "Plato principal:\n1> Pizza\t2> Ensalada\t3>Pasta\nSu seleccion: " << total2[j].mainC;	
			cout << endl << "Entrada: 1> Cheese Rollers\t2> Pizza Hands\nSu seleccion: " << total2[j].starter;
			cout << endl << "Bebida: 1> Gaseosa\t2> Te helado\nSu seleccion: " << total2[j].drink;
			cout << endl << "Tipo de pago: 1> Tarjeta\t2> Efectivo\nSu seleccion: " << total2[j].payment;
			cout << endl << "Total a pagar: $" << total2[j].amount;
			cout << endl;
			
			system ("pause");
			system ("cls");
				
		}
		else cout<<"No se ha encontrado informacion en este continente"<<endl;
	}
	
	system ("cls");
}

int deleteOrders(){
	pizza option;
}

//Menu employee function
void menuEmployee(){
	pizza option;										  
	int arrayE = 0;										  
	int *pE;	
	
	//Printing on screen 								
	cout << "Determine la dimension del arreglo: ";	
	cin >> arrayE;	
	
	//Create dinamic arrangements									
	pE = new int [arrayE];
	
	while(arrayE != 0){
		
		//Printing
		cout << "Bienvenido a Calvo's pizza" << endl;
		cout << "Seleccione el proceso a realizar: " << endl;
		
		//Showing menu
		cout << "1> Agregar 1 pedido a domicilio\n2> Agregar 1 encargo en restaurante3> Ver pedidos a domicilio" << endl;
		cout << "4> Ver encargos en el restaurante\n5> Ver total de venta\n6> Regresar a seleccion de usuario" << endl;	

		//Selection menu
		cin >> option.electionE;
		
		system("cls");
			
		//Menu options
		switch (option.electionE){
			case 1:
				//Deliver function
				deliverE(option.electionE, arrayE);
				break;
			case 2:
				//Restaurant function
				restaurantE(option.electionE, arrayE);
				break; 
			case 3:
				//Deliveries orders
				//seeDeliveriesE(option.electionE);
				break;
			case 4:
				//Restaurant orders
				//seeRestaurant(selection.option4);
				break;
			case 5:
				//Total amount
				//totalSales(selection.option5);
				break;
			case 6:
				//Return main menu
				main();
			case 7:
				deleteOrders();
			default:
				cout << "Seleccione una entrada valida por favor" << endl;
				break;
		}
	}
	cout << "Fin del programa" << endl;
	return;
}

//Deliver employee function
int deliverE(int option1E, int arrayE){
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
	
	//Pause to clean screen
	system ("pause");
	system("cls");
	
	return 0;
}

//Restaurant employee function
int restaurantE(int option2E, int arrayE){
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
	
	//Pause to clean screen
	system ("pause");
	system("cls");
	
	return 0;
	
}
