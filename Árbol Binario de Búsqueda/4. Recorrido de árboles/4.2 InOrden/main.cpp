/*4.2 Práctica: Recorrido en InOrden:
(izquierdo, raíz, derecho). Para recorrer un árbol binario no vacío en InOrden, hay que realizar las siguientes
operaciones recursivamente en cada nodo:
- Atraviese el sub-árbol izquierdo.
- Visite la raíz.
- Atraviese el sub-árbol derecho.
*/

#include <iostream>

using namespace std; 

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

void insertarNodo(Nodo *&arbol, int n){
	if (arbol == NULL){ 
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	} else { 
		int valorRaiz = arbol->dato;
		if (n < valorRaiz){
			insertarNodo(arbol->izq, n);
		} else { 
			insertarNodo(arbol->der, n);
		}
	}
}

void mostrarArbol(Nodo *arbol, int cont){
	if (arbol == NULL){
		return;
	} else {
		mostrarArbol(arbol->der,cont+1);
		for (int i=0; i<cont; i++){
			cout <<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}

bool busqueda(Nodo *arbol, int n){
	if (arbol == NULL){
		return false;
	} else if (arbol->dato == n){
		return true;
	} else if (n < arbol->dato){
		return busqueda(arbol->izq, n);
	} else {
		return busqueda(arbol->der, n);
	}
}

void preOrden(Nodo *arbol){
	if (arbol == NULL){
		return;
	} else {
		cout << arbol->dato<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

//Definimos la función InOrden (para recorrido en profundidad)
void InOrden(Nodo *arbol){
	if (arbol == NULL){
		return;
	} else {
		InOrden(arbol->izq);
		cout << arbol->dato<<" - ";
		InOrden(arbol->der);
	}
}

void menu(){
	int dato, opcion,contador=0;
	do{
		cout << "-- MENU --" << endl;
		cout << "1. Insertar n nuevo nodo" << endl;
		cout << "2. Mostrar el arbol completo" << endl;
		cout << "3. Buscar un elemento en el arbol" << endl;
		cout << "4. Recorrer el arbol en PreOrden" << endl;
		cout << "5. Recorrer el arbol en InOrden" << endl;
		cout << "6. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		switch(opcion){
			case 1: cout << "Digite un numero: ";
			cin >> dato;
			insertarNodo(arbol,dato); 
			cout << endl;
			break;
			case 2: cout << "Mostrando el árbol completo:" << endl;
			mostrarArbol(arbol, contador);
			cout << endl;
			system("pause");
			break;
			case 3: cout << "Digite el elemento a buscar: ";
			cin >> dato;
			if (busqueda(arbol,dato) == true){
				cout << endl <<"Elemento "<<dato<<" ha sido encontrado en el arbol" << endl;
			} else {
				cout << endl <<"Elemento no encontrado" << endl;
			}
			cout << endl;
			system("pause");
			break;
			case 4: cout << "Recorrido en PreOrden: ";
			preOrden(arbol);
			cout<<endl;
			system("pause");
			break;
			case 5: cout << "Recorrido en InOrden: ";
			InOrden(arbol);
			cout<<endl;
			system("pause");
			break;
		}
	} while (opcion != 6);
}

int main(){
	menu();
	
	return 0;
}