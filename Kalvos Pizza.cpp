#include <iostream> //Libreria para entrada-salida de datos en pantalla
#include <iomanip>  //
#include <string>	//Librer�a para cadenas de texto
#include <stdlib.h>	//Librer�a para comandos de limpiar pantalla
#include <algorithm>
#include <vector>

using namespace std; 

enum mainCourse {pizza, pasta, lasagna};
enum drink {beer, soda, tea};
enum starter {garlicBread, pizzaRolls, cheeseSticks};
enum paymentType {card, cash};

//structs
struct subpizza{
	int houseNumber;
	string city, suburb, state;
};

struct pizza{
	
	string name;
	subpizza place;
	int phone, acommpanying;
	int mainC, starter, drink; 
	float amount1, amount2, amount;
	int payment, num1, num2,  num3;
	
};

struct pizza total[5];
int cantpizza = 0;
struct pizza total2[5];
int pizza = 0;

//Prototypes
void delivery();
void restaurant();
void seeDeliveries();
void seeRestaurant();
void findcustomer(int a);
void totalSales();

//Main function
int main(){
	int option = 0;
	
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
					while(option!=8){
						int a = 1;
						cout << "\n1. Agregar 1 pedido a domicilio \n";
				    	cout << "2. Agregar 1 encargo a restaurante\n";
				    	cout << "3. Ver pedidos a domicilio\n";
				    	cout << "4. Ver pedidos en restaurante\n";
				    	cout << "5. Buscar pedido por nombre\n";
						cout << "6. Ver total de venta\n";
						cout << "7. Cambiar de usuario\n";
						cout << "8. Borrar ordenes\n";
					    cout << "Opcion: ";
				    	cin >> option;
				    	cin.ignore();
				    	
				    	switch (option){
				    		case 1: system ("cls"); delivery(); break;
				    		case 2: system ("cls"); restaurant(); break;
							case 3: system ("cls"); seeDeliveries(); break;
				    		case 4: system ("cls"); seeRestaurant(); break;
				    		case 5: system ("cls"); findcustomer(a); break;
							case 6: system ("cls"); totalSales(); break;
							case 7: system ("cls"); main(); break;/*
							case 8: deleteOrders(); break;
							*/
				    	}
					}
				}
				else cout << "Contrasena erronea, por favor introduzca de nuevo la contrasena." << endl;
			system ("pause");	
			system("cls");
		}
	}
	if (user == 2) {
		while (option!=8){
			int a = 2;
			//Printing on screen and cleaning after
			cout << "Ingresando al sistema" << endl;
			system ("pause");
			system ("cls");
			
			//Printing menu			
			cout << "\n1. Agregar 1 pedido a domicilio \n";
		    cout << "2. Agregar 1 encargo a restaurante\n";
		    cout << "3. Ver pedidos a domicilio\n";
		    cout << "4. Ver pedidos en restaurante\n";
		    cout << "5. Buscar pedido por nombre\n";
			cout << "6. Ver total de venta\n";
			cout << "7. Cambiar de usuario\n";
			cout << "Opcion: ";
		    cin >> option;
		    cin.ignore();
					    	
			switch (option){
		    	case 1: system ("cls"); delivery(); break;
		    	case 2: system ("cls"); restaurant(); break;
				case 3: system ("cls"); seeDeliveries(); break;
		    	case 4: system ("cls"); seeRestaurant(); break;
		    	case 5: system ("cls"); findcustomer(a); break;
				case 6: system ("cls"); totalSales(); break;
				case 7: system ("cls"); main(); break;
				
		    }
		}
	}

	return 0;
}

//Option 1 function
void delivery(){
	int size;
	int *A;
	
	//Printing on screen
	cout << "�Cuantos pedidos desea realizar?" << endl;
	cin >> size;
	cin.ignore();
						
	A = new int[size];
	
	//Validating size of cantpizza
	if (cantpizza < 8){
		for (int i = 0; i < size; i++){	
						
			//Printig on screen requirements to order
			cout<<"Nombre de la persona que realiza el pedido: ";
			getline (cin, total[cantpizza].name);
			cout << "\nDireccion:\n\tNumero de casa: ";
			cin >> total[cantpizza].place.houseNumber;
			cin.ignore();
			cout << "\n\tNumero de telefono: ";
			cin >> total[cantpizza].phone;
			cin.ignore();
			cout << "\n\tCiudad: ";
			getline (cin, total[cantpizza].place.city);
			cout << "\n\tColonia: ";
			getline (cin, total[cantpizza].place.suburb);
			cout << "\n********************Enter para guardar datos********************";
			cin.ignore();
			cout << "\n\tDepartamento: ";
			getline (cin, total[cantpizza].place.state);
		
			cout<<"Plato principal: 1> Pizza ($11.99)\t2> Ensalada ($6.99)\t3>Pasta ($8.99)\nSu seleccion:\t";
			cin>>total[cantpizza].mainC;
			cout << "Numero de platos que desea: "; cin >> total[cantpizza].num1;
			
			//Choosing main Course
			switch (total[cantpizza].mainC){
				case 1:
					total[cantpizza].amount1= 11.99 * total[cantpizza].num1;
					break;
				case 2:
					total[cantpizza].amount1= 6.99 * total[cantpizza].num1;
					break;
				case 3:
					total[cantpizza].amount1= 8.99 * total[cantpizza].num1;
					break;
				default:
					cout << "Seleccione una de las opciones del menu" << endl;
					break;
			}
			cin.ignore();
			
			//Printing on screen
			cout<<"Entrada: 1> Cheese Rollers ($2.99, incluye 7 unidades)\t2> Pizza Hands ($1.99, incluye 5 unidades)\nSu seleccion: ";
			cin>>total[cantpizza].starter;
			cout << "Numero de entradas que desea: "; cin >> total[cantpizza].num2;
		
			//Choosing starter
			switch (total[cantpizza].starter){
				case 1:
					total[cantpizza].amount2= total[cantpizza].amount1 + (2.99 * total[cantpizza].num2);
					break;
				case 2:
					total[cantpizza].amount2= total[cantpizza].amount1 + (1.99 * total[cantpizza].num2);
					break;
				default:
					cout << "Seleccione una de las opciones del menu" << endl;
					return;
					break;
			}
			cin.ignore();
			
			//Printing on screen
			cout<<"Bebida: 1> Gaseosa ($1.99)\t2> Te helado ($0.99)\nSu seleccion: ";
			cin>>total[cantpizza].drink;
			cout << "Numero de bebidas que desea: "; cin >> total[cantpizza].num3;
			
			//Choosing drink
			switch (total[cantpizza].drink){
				case 1:
					total[cantpizza].amount= total[cantpizza].amount2 + (1.99 * total[cantpizza].num3);
					break;
				case 2:
					total[cantpizza].amount= total[cantpizza].amount1 + (0.99 * total[cantpizza].num3);
					break;
				default:
					cout << "Seleccione una de las opciones del menu" << endl;
					return;
					break;
			}
			
			//Showing total amount of the order
			cout << "\nMonto: $" << total[cantpizza].amount;
			cin.ignore();
			
			cout<<"\nTipo de pago: \n1> Tarjeta\n2> Efectivo\nSu seleccion: ";
			cin>>total[cantpizza].payment;
			cin.ignore();
			
			
			cantpizza++;
			
			system ("cls");
		}
	}
	else cout<<"Lo sentimos, espacio lleno"<<endl;
}

//Option 2 function
void restaurant(){	
	int size;
	int *E;
	
	cout << "�Cuantos pedidos desea realizar?" << endl;
	cin >> size;
	cin.ignore();
				
	E = new int[size];
	
	if (pizza < 8){
		for (int i = 0; i < size; i++){
			//Printing requeriments on screen
			cout << "Nombre de la persona que realiza la reserva: ";
			getline (cin, total2[pizza].name);
			
			cout << "Acompanantes por mesa: ";
			cin >> total2[pizza].acommpanying;
			
			cout << "Plato principal: 1> Pizza ($11.99)\t2> Ensalada ($6.99)\t3>Pasta ($8.99)\nSu seleccion:\t";
			cin >> total2[pizza].mainC;
		
			//Choosing main Course
			switch (total2[pizza].mainC){
				case 1:
					total2[pizza].amount1= 11.99 * total2[pizza].acommpanying;
					break;
				case 2:
					total2[pizza].amount1= 6.99 * total2[pizza].acommpanying;
					break;
				case 3:
					total2[pizza].amount1= 8.99 * total2[pizza].acommpanying;
					break;
				default:
					cout << "Seleccione una de las opciones del menu" << endl;
					break;
			}
			cin.ignore();
			
			//Printing on screen
			cout<<"Entrada: 1> Cheese Rollers ($2.99, incluye 7 unidades)\t2> Pizza Hands ($1.99, incluye 5 unidades)\nSu seleccion: ";
			cin>>total2[pizza].starter;
	
			//Choosing starter
			switch (total2[pizza].starter){
				case 1:
					total2[pizza].amount2= total2[pizza].amount1 + (2.99 * total2[pizza].acommpanying);
					break;
				case 2:
					total2[pizza].amount2= total2[pizza].amount1 + (1.99 * total2[pizza].acommpanying);
					break;
				default:
					cout << "Seleccione una de las opciones del menu" << endl;
					break;
			}
			cin.ignore();
		
			//Printing on screen
			cout<<"Bebida: 1> Gaseosa ($1.99)\t2> Te helado ($0.99)\nSu seleccion: ";
			cin>>total2[pizza].drink;
		
			//Choosing drink
			switch (total2[pizza].drink){
				case 1:
					total2[pizza].amount= total2[pizza].amount2 + (1.99 * total[pizza].acommpanying);
					break;
				case 2:
					total2[pizza].amount= total2[pizza].amount2 + (0.99 * total[pizza].acommpanying);
					break;
				default:
					cout << "Seleccione una de las opciones del menu" << endl;
					break;
			}
		
			//Showing total amount of the order 
			cout << "\nMonto: $" << total2[pizza].amount;
			cin.ignore();
		
			//Asking for payment method
			cout<<"\nTipo de pago: \n1> Tarjeta\n2> Efectivo\nSu seleccion: ";
			cin>>total2[pizza].payment;
			cin.ignore();
		
			
			pizza++;
			
			system ("cls");
		}
	}
	else cout<<"Lo sentimos, espacio lleno"<<endl;
	
}

//Option 3 function
void seeDeliveries(){
	string name;
	cout<<"\t\tPEDIDOS A DOMICILIO\n";
	
	for (int i = 0; i < cantpizza; i++){
		if (name.compare(total[i].name) != 0){
			cout << cout << "Orden numero " << i + 1 << endl;
			cout << endl << "Nombre: " << total[i].name;
			cout << "Direccion:\n\tNumero de casa: " << total[i].place.houseNumber;
			cout << "\n\tCiudad: " << total[i].place.city;
			cout << "Direccion:\n\tColonia: " << total[i].place.suburb;
			cout << "\n\tDepartamento: " << total[i].place.state;
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
	
	for (int j = 0; j < pizza; j++){
		if (name.compare(total2[j].name) != 0){
			cout << cout << "Orden numero " << j + 1 << endl;
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
		else cout<<"No se ha encontrado informacion"<<endl;
	}
	
	system ("cls");
}

//Option 5 function
void findcustomer(int a){
	string name;
	string nameComp;
		
	if (a == 1){
		for (int i = 0; i < cantpizza; i++){   
			cout << "Ingrese el nombre del cliente: "; cin >> nameComp;
			if (name.compare(total[i].name) != 0){
				cout << "Orden numero " << i + 1 << endl;
				cout << endl << "Nombre: " << total[i].name;
				cout << "Direccion:\n\tNumero de casa: " << total[i].place.houseNumber;
				cout << "\n\tCiudad: " << total[i].place.city;
				cout << "Direccion:\n\tColonia: " << total[i].place.suburb;
				cout << "\n\tDepartamento: " << total[i].place.state;
				cout << endl << "Telefono: " << total[i].phone;
				cout << endl << "Plato principal:\n1> Pizza\t2> Ensalada\t3>Pasta\nSu seleccion: " << total[i].mainC;	
				cout << endl << "Numero de platos: " << total[i].num1;
				cout << endl << "Entrada: 1> Cheese Rollers\t2> Pizza Hands\nSu seleccion: " << total[i].starter;
				cout << endl << "Numero de entradas: " << total[i].num2;
				cout << endl << "Bebida: 1> Gaseosa\t2> Te helado\nSu seleccion: " << total[i].drink;
				cout << endl << "Numero de bebidas: " << total[i].num3;
				cout << endl << "Tipo de pago: 1> Tarjeta\t2> Efectivo\nSu seleccion: " << total[i].payment;
				cout << endl << "Total a pagar: $" << total[i].amount;
				cout << endl << endl;
					
				system ("pause");
				system ("cls");	
			}
			else cout<<"No se ha encontrado informacion"<<endl;
			
			return;
		}
		
	}
	else{
		for (int i = 0; i < cantpizza; i++){   
			cout << "Ingrese el nombre del cliente: "; cin >> nameComp;
			if (name.compare(total[i].name) != 0){
				cout << "Orden numero " << i + 1 << endl;
				cout << endl << "Nombre: " << total[i].name;
				cout << "Direccion:\n\tNumero de casa: " << total[i].place.houseNumber;
				cout << "\n\tCiudad: " << total[i].place.city;
				cout << "Direccion:\n\tColonia: " << total[i].place.suburb;
				cout << "\n\tDepartamento: " << total[i].place.state;
				cout << endl << "Telefono: " << total[i].phone;
				cout << endl << "Plato principal:\n1> Pizza\t2> Ensalada\t3>Pasta\nSu seleccion: " << total[i].mainC;	
				cout << endl << "Numero de platos: " << total[i].num1;
				cout << endl << "Entrada: 1> Cheese Rollers\t2> Pizza Hands\nSu seleccion: " << total[i].starter;
				cout << endl << "Numero de entradas: " << total[i].num2;
				cout << endl << "Bebida: 1> Gaseosa\t2> Te helado\nSu seleccion: " << total[i].drink;
				cout << endl << "Numero de bebidas: " << total[i].num3;
				cout << endl << "Tipo de pago: 1> Tarjeta\t2> Efectivo\nSu seleccion: " << total[i].payment;
				cout << endl << "Total a pagar: $" << total[i].amount;
				cout << endl << endl;
					
				system ("pause");
				system ("cls");	
				return;
			}
			else cout<<"No se ha encontrado informacion"<<endl;
		}
		return;
	}
}

//Option 6 function
void totalSales(){
	string name;
	float acum = 0;
	float acum2 = 0;
	float cant = 0;
	
	for (int i = 0; i < cantpizza; i++){
		if (name.compare(total[i].name) != 0){
			cout << endl;		
					
			acum = total[i].amount + acum;
								
		}
		else cout<<"No se ha encontrado informacion"<<endl;
	}
	
	for (int j = 0; j < pizza; j++){
		if (name.compare(total2[j].name) != 0){
			cout << endl;		
					
			acum2 = total2[j].amount + acum2;
					
			system ("pause");
			system ("cls");
								
		}
		else cout<<"No se ha encontrado informacion"<<endl;
			
	}
	
	cout << "Monto total de ordenes a domicilio es: $" << acum << endl;
	cout << endl;		
	cout << "Monto total de ordenes en restaurante es: $" << acum2 << endl;
			
	system ("pause"); cout << endl << endl;
			
	cant = acum + acum2;
	cout << "Monto total de ordenes es: $" << cant << endl;
	
	system ("pause");
	system ("cls");
}


