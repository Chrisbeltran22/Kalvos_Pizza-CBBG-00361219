#include <iostream> //Libreria para entrada-salida de datos en pantalla
#include <iomanip>  //Libreria para manipular el formateo de salida
#include <string>	//Librería para cadenas de texto
#include <stdlib.h>	//Librería para comandos de limpiar pantalla
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
		
		cout << "\n¿Desea agregar un plato? (s/n)\t"; cin >> decision; 
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
				cout << "\n¿Desea agregar otro plato? (s/n)\t"; cin >> decision;
			}while(decision == 's' || decision == 'S' );
		}
		
		cout << "\n¿Desea agregar una entrada? (s/n)\t"; cin >> decision;
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
				cout << "\n¿Desea agregar otra entrada? (s/n)\t"; cin >> decision; 
			}while(decision == 's' || decision == 'S' );
		}
		
		cout << "\n¿Desea agregar una bebida? (s/n)\t"; cin >> decision;
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
				cout << "\n¿Desea agregar otra bebida? (s/n)\t"; cin >> decision; 
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
		cout << "\nAcompañantes por mesa: "; cin >> unRestaurant.members; cin.ignore(); copyOrderR.members = unRestaurant.members;
		
		cout << "\n¿Desea agregar un plato? (s/n)\t"; cin >> decision; 
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
                    cout << "\n¿Desea agregar otro plato? (s/n)\t"; cin >> decision;
            }while(decision == 's' || decision == 'S' );
        }
		
		
		cout << "\n¿Desea agregar una entrada? (s/n)\t"; cin >> decision;
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
				cout << "\n¿Desea agregar otra entrada? (s/n)\t"; cin >> decision; 
			}while(decision == 's' || decision == 'S' );
		}
		
		cout << "\n¿Desea agregar una bebida? (s/n)\t"; cin >> decision;
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
				cout << "\n¿Desea agregar otra bebida? (s/n)\t"; cin >> decision; 
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

///--------------------------Check orders at home--------------------------------
void seeDeliverOrders(){
    for (int i = 0; i < delOrders.size(); i++) {
    	cout << "\nOrden numero:\t" << idOrder;
        cout << "\nNombre del cliente:\t" << delOrders[i].name;
		cout << "\nDireccion\n\tNumero de casa:\t" << delOrders[i].houseNumber;
		cout << "\n\tColonia:\t" << delOrders[i].suburb;
		cout << "\n\tMunicipio:\t" << delOrders[i].city;
		cout << "\n\tDepartamento:\t" << delOrders[i].state;
		cout << "\nTelefono:\t" << delOrders[i].cellphone;
        cout << "\nPlato principal:\n";
        cout << " Pizza ha sido ordenada " << delOrders[i].pizza << " veces";
        cout << " \nPasta ha sido ordenada " << delOrders[i].pasta << " veces";
        cout << " \nLasagna ha sido ordenada " << delOrders[i].lasagna << " veces";
		cout << "\nEntrada:\n";
		cout << " Pan con ajo ha sido ordenada " << delOrders[i].bread << " veces";
        cout << " \nPizza rolls ha sido ordenada " << delOrders[i].rolls << " veces";
        cout << " \nPalitos de queso ha sido ordenada " << delOrders[i].sticks << " veces";
		cout << "\nBebida:\n";
		cout << " Cerveza ha sido ordenada " << delOrders[i].beer << " veces";
        cout << " \nSoda ha sido ordenada " << delOrders[i].soda << " veces";
        cout << " \nTe ha sido ordenada " << delOrders[i].tea << " veces";
		cout << "\nTipo de pago:\ntarjeta(0)\tefectivo(1)\n" << delOrders[i].ptOrder;
		cout << "\nTotal a pagar:\t$" << delOrders[i].total;
		cout << "\nTiempo de espera de la orden:\t" << delOrders[i].timePerOrder;
		cout << endl << endl;
    }
    cout << "\n\n----------------NO HAY DATOS A MOSTRAR----------------\n\n";
    system("pause");
    system("cls");
}

//-----------------------Check orders at restaurant-----------------------------
void seeRestaurantOrders(){
    for (int i = 0; i < restOrders.size(); i++) {
    	cout << "Orden numero:\t" << idOrder;
        cout << "\nNombre del cliente:\t" << restOrders[i].name;
		cout << "\nPlato principal:\n";
		cout << " Pizza ha sido ordenada " << restOrders[i].pizza << " veces";
        cout << " \nPasta ha sido ordenada " << restOrders[i].pasta << " veces";
        cout << " \nLasagna ha sido ordenada " << restOrders[i].lasagna << " veces";
		cout << "\nEntrada:\n";
		cout << " Pan con ajo ha sido ordenada " << restOrders[i].bread << " veces";
        cout << " \nPizza rolls ha sido ordenada " << restOrders[i].rolls << " veces";
        cout << " \nPalitos de queso ha sido ordenada " << restOrders[i].sticks << " veces";
		cout << "\nBebida:\n";
		cout << " Cerveza ha sido ordenada " << restOrders[i].beer << " veces";
        cout << " \nSoda ha sido ordenada " << restOrders[i].soda << " veces";
        cout << " \nTe ha sido ordenada " << restOrders[i].tea << " veces";
		cout << "\nTipo de pago:\ntarjeta(0)\tefectivo(1)\n" << restOrders[i].ptOrder;
		cout << "\nTotal a pagar:\t$" << restOrders[i].total;
		cout << "\nTiempo de espera de la orden:\t" << restOrders[i].timePerOrder;
    } 
    cout << "\n\n----------------NO HAY DATOS A MOSTRAR----------------\n\n";
    system("pause");
}

//-------------------------Select and send orders-------------------------------
void sendOrder(){
    delivery unDeliver;
    deliveryT copyOrderD;
    restaurantT copyOrderR;
    restaurant unRestaurant;
    int option;
    
    cout << "Seleccione donde desea realizarlo:\n1- Delivery\t2- Restaurante\nSu eleccion: ";
    cin >> option; cin.ignore();
    
    if(option == 1){
        string unNombre;
        cout << "Nombre del cliente: ";
        getline(cin, unNombre);
        
        for(auto iter = delOrders.begin(); iter != delOrders.end(); ++iter){
            if(iter->name == unNombre){
                for (int i = 0; i < delOrders.size(); i++) {
                    copyOrderD.verificationD = true;
                    delOrders[i].orders = 1;
                    copyOrderD.orders = delOrders[i].orders;
                    cout << "\nOrden numero:\t" << idOrder;
                    copyOrderD.idOrderDel = idOrder;
                    cout << "\nNombre del cliente:\t" << delOrders[i].name;
                    copyOrderD.name = delOrders[i].name;
            		cout << "\nDireccion\n\tNumero de casa:\t" << delOrders[i].houseNumber;
            		copyOrderD.houseNumber = delOrders[i].houseNumber;
            		cout << "\n\tColonia:\t" << delOrders[i].suburb;
            		copyOrderD.suburb = delOrders[i].suburb;
            		cout << "\n\tMunicipio:\t" << delOrders[i].city;
            		copyOrderD.city = delOrders[i].city;
            		cout << "\n\tDepartamento:\t" << delOrders[i].state;
            		copyOrderD.state = delOrders[i].state;
            		cout << "\nTelefono:\t" << delOrders[i].cellphone; cin.ignore();
            		copyOrderD.cellphone = delOrders[i].cellphone;
                    cout << "\nPlato principal:\n";
                    cout << " Pizza ha sido ordenada " << delOrders[i].pizza << " veces";
                    copyOrderD.pizza = delOrders[i].pizza;
                    cout << " \nPasta ha sido ordenada " << delOrders[i].pasta << " veces";
                    copyOrderD.pasta = delOrders[i].pasta;
                    cout << " \nLasagna ha sido ordenada " << delOrders[i].lasagna << " veces";
                    copyOrderD.lasagna = delOrders[i].lasagna;
            		cout << "\nEntrada:\n";
            		cout << " Pan con ajo ha sido ordenada " << delOrders[i].bread << " veces";
            		copyOrderD.bread = delOrders[i].bread;
                    cout << " \nPizza rolls ha sido ordenada " << delOrders[i].rolls << " veces";
                    copyOrderD.rolls = delOrders[i].rolls;
                    cout << " \nPalitos de queso ha sido ordenada " << delOrders[i].sticks << " veces";
                    copyOrderD.sticks = delOrders[i].sticks;
            		cout << "\nBebida:\n";
            		cout << " Cerveza ha sido ordenada " << delOrders[i].beer << " veces";
            		copyOrderD.beer = delOrders[i].beer;
                    cout << " \nSoda ha sido ordenada " << delOrders[i].soda << " veces";
                    copyOrderD.soda = delOrders[i].soda;
                    cout << " \nTe ha sido ordenada " << delOrders[i].tea << " veces";
                    copyOrderD.tea = delOrders[i].tea;
            		cout << "\nTipo de pago:\ntarjeta(0)\tefectivo(1)\n" << delOrders[i].ptOrder;
            		copyOrderD.ptOrder = delOrders[i].ptOrder;
            		cout << "\nTotal a pagar:\t$" << delOrders[i].total;
            		copyOrderD.total = delOrders[i].total;
            		cout << "\nTiempo que espero la orden:\t" << delOrders[i].timePerOrder;
            		copyOrderD.timePerOrder = delOrders[i].timePerOrder;
                }
                registerDelOrders.insert(registerDelOrders.end(), copyOrderD);
                iter = delOrders.erase(iter);
                cout << "\nOrden entregada a domicilio.\n";
                break;
            }
        }
        cout << "\n\n----------------NO HAY DATOS A MOSTRAR----------------\n\n";
        system("pause");
    }
    else if(option == 2){	
        string unNombre;
        cout << "Nombre del cliente: ";
        getline(cin, unNombre);
        
        for(auto iter = restOrders.begin(); iter != restOrders.end(); ++iter){
            if(iter->name == unNombre){
            	for (int i = 0; i < restOrders.size(); i++) {
            	    restOrders[i].order = 1;
            	    copyOrderR.order = 1;
            	    copyOrderR.verificationR = true;
                    cout << "Orden numero:\t" << idOrder;
                    cout << "\nNombre del cliente:\t" << restOrders[i].name;
            		cout << "\nPlato principal:\n";
                    cout << " Pizza ha sido ordenada " << restOrders[i].pizza << " veces";
                    copyOrderR.pizza = restOrders[i].pizza;
                    cout << " \nPasta ha sido ordenada " << restOrders[i].pasta << " veces";
                    copyOrderR.pasta = restOrders[i].pasta;
                    cout << " \nLasagna ha sido ordenada " << restOrders[i].lasagna << " veces";
                    copyOrderR.lasagna = restOrders[i].lasagna;
            		cout << "\nEntrada:\n";
            		cout << " Pan con ajo ha sido ordenada " << restOrders[i].bread << " veces";
            		copyOrderR.bread = restOrders[i].bread;
                    cout << " \nPizza rolls ha sido ordenada " << restOrders[i].rolls << " veces";
                    copyOrderR.rolls = restOrders[i].rolls;
                    cout << " \nPalitos de queso ha sido ordenada " << restOrders[i].sticks << " veces";
                    copyOrderR.sticks = restOrders[i].sticks;
            		cout << "\nBebida:\n";
            		cout << " Cerveza ha sido ordenada " << restOrders[i].beer << " veces";
            		copyOrderR.beer = restOrders[i].beer;
                    cout << " \nSoda ha sido ordenada " << restOrders[i].soda << " veces";
                    copyOrderR.soda = restOrders[i].soda;
                    cout << " \nTe ha sido ordenada " << restOrders[i].tea << " veces";
                    copyOrderR.tea = restOrders[i].tea;
            		cout << "\nTipo de pago:\ntarjeta(0)\tefectivo(1)\n" << restOrders[i].ptOrder;
            		copyOrderR.ptOrder = restOrders[i].ptOrder;
            		cout << "\nTotal a pagar:\t$" << restOrders[i].total;
            		copyOrderR.total = restOrders[i].total;
            		cout << "\nTiempo que espero la orden:\t" << restOrders[i].timePerOrder;
            		copyOrderR.timePerOrder = restOrders[i].timePerOrder;
                }
                registerRestOrders.insert(registerRestOrders.end(), copyOrderR);
                iter = restOrders.erase(iter);
                cout << "\nOrden servida en restaurante.\n";
                break;
            }
        }
        cout << "\n\n----------------NO HAY DATOS A MOSTRAR----------------\n\n";
        system("pause");
    }
}

/------------------Check average time of deliveries orders---------------------
void calculateDeliverTime(){
    int total = 0;
    for (int i = 0; i < delOrders.size(); i++) {
	    cout << "Tiempo de espera de orden #" << i + 1 << " a domicilio es: " << delOrders[i].timePerOrder << " minutos\n";
	    total += delOrders[i].timePerOrder;
    }
    cout << "Tiempo de espera total es: " << total << " minutos\n";
	system("pause");
}

//-----------------Check average time of orders at restaurant-------------------
void calculateRestaurantTime(){
    int total = 0;
    for (int i = 0; i < restOrders.size(); i++) {
	    cout << "Tiempo de espera de orden #" << i + 1 << " a domicilio es: " << restOrders[i].timePerOrder << " minutos\n";
	    total += restOrders[i].timePerOrder;
    }
    cout << "Tiempo de espera total es: " << total << " minutos\n";
	system("pause");
    
}

//----------------------------Cancel orders-------------------------------------
void cancelOrder(){
    delivery unDeliver;
    restaurant unRestaurant;
    string unNombre; int option;
    cout << "Seleccione donde desea realizarlo:\n1- Delivery\t2- Restaurante\nSu eleccion: ";
    cin >> option; cin.ignore();
    if(option == 1){
        cout << "Nombre del cliente a despachar: ";
        getline(cin, unNombre);
        for(auto iter = delOrders.begin(); iter != delOrders.end(); ++iter){
            if(iter->name == unNombre){
            	for (int i = 0; i < delOrders.size(); i++) {
                    cout << "\nOrden numero:\t" << idOrder;
                    cout << "\nNombre del cliente:\t" << delOrders[i].name;
            		cout << "\nDireccion\n\tNumero de casa:\t" << delOrders[i].houseNumber;
            		cout << "\n\tColonia:\t" << delOrders[i].suburb;
            		cout << "\n\tMunicipio:\t" << delOrders[i].city;
            		cout << "\n\tDepartamento:\t" << delOrders[i].state;
            		cout << "\nTelefono:\t" << delOrders[i].cellphone; cin.ignore();
                    cout << "\nPlato principal:\n";
                    cout << " Pizza ha sido ordenada " << delOrders[i].pizza << " veces";
                    cout << " \nPasta ha sido ordenada " << delOrders[i].pasta << " veces";
                    cout << " \nLasagna ha sido ordenada " << delOrders[i].lasagna << " veces";
            		cout << "\nEntrada:\n";
            		cout << " Pan con ajo ha sido ordenada " << delOrders[i].bread << " veces";
                    cout << " \nPizza rolls ha sido ordenada " << delOrders[i].rolls << " veces";
                    cout << " \nPalitos de queso ha sido ordenada " << delOrders[i].sticks << " veces";
            		cout << "\nBebida:\n";
            		cout << " Cerveza ha sido ordenada " << delOrders[i].beer << " veces";
                    cout << " \nSoda ha sido ordenada " << delOrders[i].soda << " veces";
                    cout << " \nTe ha sido ordenada " << delOrders[i].tea << " veces";
            		cout << "\nTipo de pago:\t" << delOrders[i].ptOrder;
            		cout << "\nTotal a pagar:\t" << delOrders[i].total;
            		cout << "\nTiempo que espero la orden:\t" << delOrders[i].timePerOrder;
                }
                iter = delOrders.erase(iter);
                cout << "\nOrden cancelada.\n";
                break;
            }
        }
    }
    else if(option == 2){
        cout << "Nombre del cliente a despachar: ";
        getline(cin, unNombre);
        
        for(auto iter = restOrders.begin(); iter != restOrders.end(); ++iter){
            if(iter->name == unNombre){
            	for (int i = 0; i < restOrders.size(); i++) {
                    cout << "Orden numero:\t" << idOrder;
                    cout << "\nNombre del cliente:\t" << restOrders[i].name;
            		cout << "\nPlato principal:\n";
            		cout << " Pizza ha sido ordenada " << restOrders[i].pizza << " veces";
                    cout << " \nPasta ha sido ordenada " << restOrders[i].pasta << " veces";
                    cout << " \nLasagna ha sido ordenada " << restOrders[i].lasagna << " veces";
            		cout << "\nEntrada:\n";
            		cout << " Pan con ajo ha sido ordenada " << restOrders[i].bread << " veces";
                    cout << " \nPizza rolls ha sido ordenada " << restOrders[i].rolls << " veces";
                    cout << " \nPalitos de queso ha sido ordenada " << restOrders[i].sticks << " veces";
            		cout << "\nBebida:\n";
            		cout << " Cerveza ha sido ordenada " << restOrders[i].beer << " veces";
                    cout << " \nSoda ha sido ordenada " << restOrders[i].soda << " veces";
                    cout << " \nTe ha sido ordenada " << restOrders[i].tea << " veces";
            		cout << "\nTipo de pago:\t" << restOrders[i].ptOrder;
            		cout << "\nTotal a pagar:\t" << restOrders[i].total;
            		cout << "\nTiempo que espero la orden:\t" << restOrders[i].timePerOrder;
                }
                iter = restOrders.erase(iter);
                cout << "\nOrden cancelada.\n";
                break;
            }
        }
    }
}

//----------------------------Total Sales---------------------------------------
int TotalSales(){
    deliveryT copyOrderD;
    restaurantT copyOrderR;
    float total = 0, totalD = 0, totalR = 0;
    
    if(copyOrderD.verificationD = true || copyOrderR.verificationR == true){
        for (int i = 0; i < registerDelOrders.size(); i++) {
            totalD += registerDelOrders[i].total;
        }
        for (int i = 0; i < registerRestOrders.size(); i++) {
            totalR += registerRestOrders[i].total;
        }
        total = totalD + totalR;
    }

    cout << "Total de ingreso de ordenes:\t$" << total << endl;
}


