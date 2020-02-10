#include <iostream> //Libreria para entrada-salida de datos en pantalla
#include <iomanip>  //Libreria para manipular el formateo de salida
#include <string>	//Librer�a para cadenas de texto
#include <stdlib.h>	//Librer�a para comandos de limpiar pantalla
#include <algorithm>//Libreria para manejo de algoritmos matematicos
#include <vector>	//Libreria para manejo de estructuras unidimensionales

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

//------------------------------Struct delivery---------------------------------
struct delivery{
    int houseNumber;
    int cellphone;
    string suburb, city, state;
    string name;
	mainCourse mOrder;
	drink dOrder;
	starter sOrder;
	paymentType ptOrder;
	int idOrderDel = 0, orders = 0;
	int pizza = 0, pasta = 0, lasagna = 0;
	int bread = 0, rolls = 0, sticks = 0;
	int beer = 0, soda = 0, tea = 0;
	float total;
	int timePerOrder = 0;

};
vector<delivery> delOrders;

struct deliveryT{
    int houseNumber;
    int cellphone;
    string suburb, city, state;
    string name;
	mainCourse mOrder;
	drink dOrder;
	starter sOrder;
	paymentType ptOrder;
	int idOrderDel = 0, orders = 0;
	int pizza = 0, pasta = 0, lasagna = 0;
	int bread = 0, rolls = 0, sticks = 0;
	int beer = 0, soda = 0, tea = 0;
	float total;
	int timePerOrder = 0;
	bool verificationD = false;

};
vector<deliveryT> registerDelOrders;

//------------------------------Struct restaurant-------------------------------
struct restaurant{
    string name;
	mainCourse mOrder;
	drink dOrder;
	starter sOrder;
	paymentType ptOrder;
	float total;
    int timePerOrder = 0;
	int pizza = 0, pasta = 0, lasagna = 0;
	int bread = 0, rolls = 0, sticks = 0;
	int beer = 0, soda = 0, tea = 0;
	int idOrderRest = 0, order = 0;
    int members;
};
vector<restaurant> restOrders;

struct restaurantT{
    string name;
	mainCourse mOrder;
	drink dOrder;
	starter sOrder;
	paymentType ptOrder;
	float total;
    int timePerOrder = 0;
	int pizza = 0, pasta = 0, lasagna = 0;
	int bread = 0, rolls = 0, sticks = 0;
	int beer = 0, soda = 0, tea = 0;
	int idOrderRest = 0, order = 0;
    int members;
    bool verificationR = false;
};
vector<restaurantT> registerRestOrders;

//--------------------------------Prototypes------------------------------------
void menu();
void orders(int size);
void orders(float Size);
void seeDeliverOrders();
void seeRestaurantOrders();
void sendOrder();
void calculateDeliverTime();
void calculateRestaurantTime();
void cancelOrder();
int TotalSales();

int idOrder = 0;
//----------------------------Recursive id order--------------------------------
int recursiveId(int n){ 
    if(n == 0){
        return 0;
    }
    else{
        return n + recursiveId(n -1);
    }
}

/------------------------------Main function-----------------------------------
int main(){
    
	menu();
	return 0;
}

/------------------------------Menu function-----------------------------------
void menu(){

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
		bool validation = true;
		//While bucle
		do{
			//Printing
			cout<<"Bienvenido, por favor introduzca la contrasena para continuar: ";
			cin>>password;     
			
			//Password verification
			if (password == passw){
				system("cls");
				//Do-While bucle
				do{
					int size = 0, option = 0;
					float Size = 0;
					//Show on screen
					cout << "\n1. Agregar orden a domicilio \n";
					cout << "2. Agregar orden a restaurante\n";
					cout << "3. Ver ordenes a domicilio\n";
					cout << "4. Ver ordenes en restaurante\n";
					cout << "5. Despachar ordenes a domicilio o restaurante\n";
					cout << "6. Ver tiempo promedio de espera domicilio\n";
					cout << "7. Ver tiempo promedio de espera restaurante\n";
					cout << "8. Cancelar orden\n";
					cout << "9. Calcular total de ventas\n";
					cout << "10. Cambiar de usuario\n";
					cout << "11. Salir\n";
				    cout << "\nDetermine numero de ordenes a realizar:\t"; cin >> size; cin.ignore();
				    Size = size;
				    cout << "\nSeleccione una de las opciones del menu anterior:\t";
			    	cin >> option;
			    	cin.ignore();
				    
					//Determinating function selected	
			    	switch (option){
			    		case 1: system ("cls"); orders(size); break;
			    		case 2: system ("cls"); orders(Size); break;
						case 3: system ("cls"); seeDeliverOrders(); break;
			    		case 4: system ("cls"); seeRestaurantOrders(); break;
			    		case 5: system ("cls"); sendOrder(); break;
						case 6: system ("cls"); calculateDeliverTime(); break;
						case 7: system ("cls"); calculateRestaurantTime(); break;
						case 8: system ("cls"); cancelOrder(); break;
						case 9: system ("cls"); TotalSales(); break;
				       	case 10: system ("cls"); main(); break;
						case 11: system ("cls"); validation = false; break;
						default: cout << "Opcion ingresada no valida" << endl; break;
							
			    	}
					
					cout << "PROCESO FINALIZADO" << endl;

				}while(validation);
			return;
			}
				
			else cout << "Contrasena erronea, por favor introduzca de nuevo la contrasena." << endl;
    			system ("pause");	
    			system ("cls");
		}while(password != passw);
	}
	else if (user == 2){
		//Clean screen
		system ("cls");
		bool validation = true;
		//Do-While bucle
		do{
			int size = 0, option = 0;
			float Size = 0;
			//Show on screen			
			cout << "\n1. Agregar orden a domicilio \n";
			cout << "2. Agregar orden a restaurante\n";
			cout << "3. Ver ordenes a domicilio\n";
			cout << "4. Ver ordenes en restaurante\n";
			cout << "5. Despachar ordenes a domicilio o restaurante\n";
			cout << "6. Ver tiempo promedio de espera domicilio\n";
			cout << "7. Ver tiempo promedio de espera restaurante\n";
			cout << "8. Calcular total de ventas\n";
			cout << "9. Cambiar de usuario\n";
			cout << "10. Salir\n";
			cout << "\nDetermine numero de ordenes a realizar:\t"; cin >> size; cin.ignore();
		    Size = size;
		    cout << "\nSeleccione una de las opciones del menu anterior:\t";
	    	cin >> option;
	    	cin.ignore();
			//Determinating function selected	    	
	    	switch (option){
	    		case 1: system ("cls"); orders(size); break;
	    		case 2: system ("cls"); orders(Size); break;
				case 3: system ("cls"); seeDeliverOrders(); break;
	    		case 4: system ("cls"); seeRestaurantOrders(); break;
	    		case 5: system ("cls"); sendOrder(); break;
				case 6: system ("cls"); calculateDeliverTime(); break;
				case 7: system ("cls"); calculateRestaurantTime(); break;
				case 8: system ("cls"); TotalSales(); break;
				case 9: system ("cls"); main(); break;
				case 10: system ("cls"); validation = false; break;
				default: cout << "Opcion ingresada no valida" << endl; break;
							
	    	}
					
			cout << "PROCESO FINALIZADO" << endl;

		}while(validation);
		return;
	}
	else
	    cout << "Usuario no existe\n\n";
	system ("cls");
	return menu();
}

/----------------------------Delivery function---------------------------------
void orders(int size){
    delivery unDeliver;
    deliveryT copyOrderD;
    char decision;
    int num1 = 0, num2 = 0, num3 = 0;
	float amount, amount1, amount2, amount3;

	for (int i = 0; i < size; i++){
		int aux = 0; int idOrder;
		cout << "Nombre del cliente: "; getline (cin, unDeliver.name); copyOrderD.name = unDeliver.name;
		cout << "Direccion\n\tNumero de casa: "; cin >> unDeliver.houseNumber; copyOrderD.houseNumber = unDeliver.houseNumber; cin.ignore();
		cout << "\tColonia: "; getline (cin, unDeliver.suburb); copyOrderD.suburb = unDeliver.suburb;
		cout << "\tMunicipio: "; getline (cin, unDeliver.city); copyOrderD.city = unDeliver.city;
		cout << "\tDepartamento: "; getline (cin, unDeliver.state); copyOrderD.state = unDeliver.state;
		cout << "Telefono: "; cin >> unDeliver.cellphone; copyOrderD.cellphone = unDeliver.cellphone; cin.ignore();
		
		cout << "\n�Desea agregar un plato? (s/n)\t"; cin >> decision; 
		if (decision == 's' || decision == 'S'){
			do{
			    num1++;
				cout << "\nPlato principal:\n1> Pizza $13.99\t2> Pasta $5.55\t3> Lasagna $6.25\nSu seleccion:\t";
				cin >> aux;
				
				//Choosing main Course
				if(aux == 1){
		            unDeliver.mOrder = pizza; 
		            unDeliver.pizza++;
		            copyOrderD.mOrder = pizza; 
		            copyOrderD.pizza++;
				}
		        else if(aux == 2){
		            unDeliver.mOrder = pasta;
		            unDeliver.pasta++;
		            copyOrderD.mOrder = pasta;
		            copyOrderD.pasta++;
		        }
		        else{
		            unDeliver.mOrder = lasagna;
		            unDeliver.lasagna++;
		            copyOrderD.mOrder = lasagna;
		            copyOrderD.lasagna++;
			    }
				
				//Calculating main course amount
				switch (aux){
					case 1:
						amount1+= 13.99;
						break;
					case 2:
						amount1+= 5.55;
						break;
					case 3:
						amount1+= 6.25;
						break;
					default:
						cout << "\nSeleccione una de las opciones del menu" << endl;
						break;
				}
				cin.ignore();
				cout << "\n�Desea agregar otro plato? (s/n)\t"; cin >> decision;
			}while(decision == 's' || decision == 'S' );
		}
		
		cout << "\n�Desea agregar una entrada? (s/n)\t"; cin >> decision;
		if (decision == 's' || decision == 'S' ){
			do{	
			    num2++;
				//Printing on screen
				cout << "\nEntrada:\n1> Orden de pan con ajo $3.99\n2> Orden de pizza rolls $4.99\n3> Orden de palitos de queso $3.75\nSu seleccion: ";
				cin >> aux;
				
				//Choosing starter
				if(aux == 1){
		            unDeliver.sOrder = garlicBread;
		            unDeliver.bread++;
		            copyOrderD.sOrder = garlicBread;
		            copyOrderD.bread++;
				}
		        else if(aux == 2){
		            unDeliver.sOrder = pizzaRolls;
		            unDeliver.rolls++;
		            copyOrderD.sOrder = pizzaRolls;
		            copyOrderD.rolls++;
		        }
		        else{
		            unDeliver.sOrder = cheeseSticks;
					unDeliver.sticks++;
					copyOrderD.sOrder = cheeseSticks;
					copyOrderD.sticks++;
		        }
				//Calculating starter amount
				switch (aux){
					case 1:
						amount2+= 3.99;
						break;
					case 2:
						amount2+= 4.99;
						break;
					case 3: 
						amount2+= 3.75;
						break;
					default:
						cout << "\nSeleccione una de las opciones del menu" << endl;
						return;
						break;
				}
				cin.ignore();
				cout << "\n�Desea agregar otra entrada? (s/n)\t"; cin >> decision; 
			}while(decision == 's' || decision == 'S' );
		}
		
		cout << "\n�Desea agregar una bebida? (s/n)\t"; cin >> decision;
		if (decision == 's' || decision == 'S'){
			do{
			    num3++;
				//Printing on screen
				cout << "\nBebida:\n1> Cerverza $1.99\t2> Soda $0.95\t3> Te helado $1.15\nSu seleccion: ";
				cin >> aux;
								
				if(aux == 1){
		            unDeliver.dOrder = beer;
		            copyOrderD.dOrder = beer;
		            unDeliver.beer++;
		            copyOrderD.beer++;
				}
		        else if(aux == 2){
		            unDeliver.dOrder = soda;
		            unDeliver.soda++;
		            copyOrderD.dOrder = soda;
		            copyOrderD.soda++;
		        }
		        else{
		            unDeliver.dOrder = tea;
		            unDeliver.tea++;
		            copyOrderD.dOrder = tea;
		            copyOrderD.tea++;
		        }
		            
				//Choosing drink
				switch (aux){
					case 1:
						amount3+= 1.99;
						break;
					case 2:
						amount3+= 0.95;
						break;
					case 3:
						amount3+= 1.15;
						break;
					default:
						cout << "\nSeleccione una de las opciones del menu" << endl;
						return;
						break;
				}
				cout << "\n�Desea agregar otra bebida? (s/n)\t"; cin >> decision; 
			}while(decision == 's' || decision == 'S' );
		}
		//Calculating total of the order
		amount = amount1 + amount2 + amount3;
		//Determinating time of the order
		unDeliver.timePerOrder = (((1.10 * num1) + (1.5 * num2) + (1.35 * num3)) + 15 );
		copyOrderD.timePerOrder = (((1.10 * num1) + (1.5 * num2) + (1.35 * num3)) + 15 );
		cout << "Tiempo de espera de la orden:\t" << unDeliver.timePerOrder;
		//Showing amount of the order
		cout << "\nMonto: $" << amount;
		unDeliver.total = amount;
		copyOrderD.total = amount;
		cin.ignore();
		
		
		cout << "\nTipo de pago:\n\t 1> Tarjeta\t2> Efectivo\nSu seleccion: ";
		cin >> aux;
		if(aux == 1){
            unDeliver.ptOrder = card;
            copyOrderD.ptOrder = card;
		}
        else{
            unDeliver.ptOrder = cash;
            copyOrderD.ptOrder = cash;
        }
		unDeliver.idOrderDel = idOrder++;
		copyOrderD.idOrderDel = unDeliver.idOrderDel;
        copyOrderD.verificationD = false;
		
		delOrders.insert(delOrders.end(), unDeliver);
		registerDelOrders.insert(registerDelOrders.end(), copyOrderD);
	}
}

//---------------------------Restaurant function--------------------------------
void orders(float Size){
	restaurant unRestaurant;
	restaurantT copyOrderR;
	char decision;
	int num1 = 0, num2 = 0, num3 = 0;
	float amount, amount1 = 0, amount2 = 0, amount3 = 0;
	
	for (int i = 0; i < Size; i++){
		int aux = 0;
		cout << "\nNombre del cliente: "; getline (cin, unRestaurant.name); copyOrderR.name = unRestaurant.name;
		cout << "\nAcompa�antes por mesa: "; cin >> unRestaurant.members; cin.ignore(); copyOrderR.members = unRestaurant.members;
		
		cout << "\n�Desea agregar un plato? (s/n)\t"; cin >> decision; 
		if (decision == 's' || decision == 'S'){
            do{
                num1++;
                cout << "\nPlato principal:\n1> Pizza $13.99\t2> Pasta $5.55\t3> Lasagna $6.25\nSu seleccion:\t";
                cin >> aux;
                    	
                //Choosing main Course
               if(aux == 1){
		            unRestaurant.mOrder = pizza; 
		            unRestaurant.pizza++;
		            copyOrderR.mOrder = pizza;
		            copyOrderR.pizza++;
				}
		        else if(aux == 2){
		            unRestaurant.mOrder = pasta;
		            unRestaurant.pasta++;
		            copyOrderR.mOrder = pasta;
		            copyOrderR.pasta++;
		        }
		        else{
		            unRestaurant.mOrder = lasagna;
		            unRestaurant.lasagna++;
		            copyOrderR.mOrder = lasagna;
		            copyOrderR.lasagna++;
			    }
                    
                //Calculating main course amount
                    switch (aux){
                        case 1:
                            amount1+= 13.99;
                            break;
                        case 2:
                            amount1+= 5.55;
    						break;
                        case 3:
                            amount1+= 6.25;
    						break;
                        default:
    						cout << "\nSeleccione una de las opciones del menu" << endl;
                            break;
                    }
                    cin.ignore();
                    cout << "\n�Desea agregar otro plato? (s/n)\t"; cin >> decision;
            }while(decision == 's' || decision == 'S' );
        }
		
		
		cout << "\n�Desea agregar una entrada? (s/n)\t"; cin >> decision;
		if (decision == 's' || decision == 'S' ){
			do{	
                num2++;
				//Printing on screen
				cout << "\nEntrada:\n1> Orden de pan con ajo $3.99\n2> Orden de pizza rolls $4.99\n3> Orden de palitos de queso $3.75\nSu seleccion: ";
				cin >> aux;
				
				//Choosing starter
				if(aux == 1){
		            unRestaurant.sOrder = garlicBread;
		            unRestaurant.bread++;
		            copyOrderR.sOrder = garlicBread;
		            copyOrderR.bread++;
				}
		        else if(aux == 2){
		            unRestaurant.sOrder = pizzaRolls;
		            unRestaurant.rolls++;
		            copyOrderR.sOrder = pizzaRolls;
		            copyOrderR.rolls++;
		        }
		        else{
		            unRestaurant.sOrder = cheeseSticks;
					unRestaurant.sticks++;
					copyOrderR.sOrder = cheeseSticks;
		            copyOrderR.sticks++;
		        }
					
				//Calculating starter amount
				switch (aux){
					case 1:
						amount2+= 3.99;
						break;
					case 2:
						amount2+= 4.99;
						break;
					case 3:
						amount2+= 3.75;
						break;
					default:
						cout << "\nSeleccione una de las opciones del menu" << endl;
						return;
						break;
				}
				cin.ignore();
				cout << "\n�Desea agregar otra entrada? (s/n)\t"; cin >> decision; 
			}while(decision == 's' || decision == 'S' );
		}
		
		cout << "\n�Desea agregar una bebida? (s/n)\t"; cin >> decision;
		if (decision == 's' || decision == 'S'){
			do{
				num3++;
				//Printing on screen
				cout << "\nBebida:\n1> Cerverza $1.99\t2> Soda $0.95\t3> Te helado $1.15\nSu seleccion: ";
				cin >> aux;
								
				if(aux == 1){
		            unRestaurant.dOrder = beer;
		            unRestaurant.beer++;
		            copyOrderR.dOrder = beer;
		            copyOrderR.beer++;
				}
		        else if(aux == 2){
		            unRestaurant.dOrder = soda;
		            unRestaurant.soda++;
		            copyOrderR.dOrder = soda;
		            copyOrderR.soda++;
		        }
		        else{
		            unRestaurant.dOrder = tea;
		            unRestaurant.tea++;
		            copyOrderR.dOrder = tea;
		            copyOrderR.tea++;
		        }
                  
				//Choosing drink
				switch (aux){
					case 1:
						amount3+= 1.99;
						break;
					case 2:
						amount3+= 0.95;
						break;
					case 3:
						amount3+= 1.15;
						break;
					default:
						cout << "\nSeleccione una de las opciones del menu" << endl;
						return;
						break;
				}
				cout << "\n�Desea agregar otra bebida? (s/n)\t"; cin >> decision; 
			}while(decision == 's' || decision == 'S' );
		}
		//Calculating total of the order
		amount = amount1 + amount2 + amount3;
		//Calculating time of the order
		unRestaurant.timePerOrder += ((1.10 * num1) + (1.5 * num2) + (1.35 * num3));
		copyOrderR.timePerOrder += ((1.10 * num1) + (1.5 * num2) + (1.35 * num3));
		cout << "Tiempo de espera de su orden:\t" << unRestaurant.timePerOrder;
		//Showing amount of the order
		cout << "\nMonto: $" << amount;
		cin.ignore();
		unRestaurant.total = amount;
		copyOrderR.total = amount;
		
		cout << "\nTipo de pago:\n\t 1> Tarjeta\t2> Efectivo\nSu seleccion: ";
		cin >> aux;
		if(aux == 1){
            unRestaurant.ptOrder = card;
            copyOrderR.ptOrder = card;
		}
        else{
            unRestaurant.ptOrder = cash;
            copyOrderR.ptOrder = cash;
	    }
		
        unRestaurant.idOrderRest = idOrder++;
        copyOrderR.idOrderRest = unRestaurant.idOrderRest;
        copyOrderR.verificationR = false;
        
        restOrders.insert(restOrders.end(), unRestaurant);
        registerRestOrders.insert(registerRestOrders.end(), copyOrderR);
	}
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


