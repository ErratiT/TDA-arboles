//1. Práctica: Insertar nodos en un árbol binario de búsqueda (ABB)

#include <iostream>

using namespace std; 

//Primero creamos el nodo.
struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

Nodo *arbol = NULL;

Nodo *crearNodo(int n){
	Nodo *nuevo_nodo  = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo-> izq = NULL;
	
	return nuevo_nodo;
}

//Comenzamos la función insertar
void insertarNodo(Nodo *&arbol, int n){
	//Ahora, para insertar un nodo en el árbol necesitas tener en cuenta:
	if (arbol == NULL){ //El árbol puede estar vacío.
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	} else { //El árbol ya tiene un nodo o más.
		int valorRaiz = arbol->dato;
		if (n < valorRaiz){ //Si el elemento es menor a la raíz insertamos en la izquierda.
			insertarNodo(arbol->izq, n);
		} else { //Si el elemento es mayor a la raíz, insertamos en el lado derecho.
			insertarNodo(arbol->der, n);
		}
	}
}

void menu(){
	int dato, opcion;
	do{
		cout << "-- MENU --" << endl;
		cout << "1. Insertar n nuevo nodo" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		switch(opcion){
			case 1: cout << "Digite un numero: ";
			cin >> dato;
			insertarNodo(arbol,dato); //Insertamos un nuevo nodo
			cout << endl;
			break;
		}
	} while (opcion != 2);
}

int main(){
	menu();
}