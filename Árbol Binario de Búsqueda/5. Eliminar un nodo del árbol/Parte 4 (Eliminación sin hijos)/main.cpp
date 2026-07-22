//5. Eliminar un nodo del árbol (P4)

#include <iostream>

using namespace std; 

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

Nodo *arbol = NULL;

Nodo *crearNodo(int n, Nodo *padre){
	Nodo *nuevo_nodo  = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;
	
	return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n, Nodo *padre){
	if (arbol == NULL){ 
		Nodo *nuevo_nodo = crearNodo(n,padre);
		arbol = nuevo_nodo;
	} else { 
		int valorRaiz = arbol->dato;
		if (n < valorRaiz){
			insertarNodo(arbol->izq, n,arbol);
		} else { 
			insertarNodo(arbol->der, n,arbol);
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

void InOrden(Nodo *arbol){
	if (arbol == NULL){
		return;
	} else {
		InOrden(arbol->izq);
		cout << arbol->dato<<" - ";
		InOrden(arbol->der);
	}
}

void PostOrden(Nodo *arbol){
	if (arbol == NULL){
		return;
	} else {
		PostOrden(arbol->izq);
		PostOrden(arbol->der);
		cout << arbol->dato<<" - ";
	}
}

//Función para determinar el nodo más izq posible
Nodo *minimo(Nodo *arbol){
	if (arbol == NULL){ //Si el árbol está vacío
		return NULL; //Retornas nulo
	}
	if (arbol->izq){ //Si tiene hijo izq
		return minimo(arbol->izq); //Buscamos la parte más izq posible
	} else {
		return arbol;
	}
}

//Función para reemplazar dos nodos
void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
	if (arbol->padre){
		//arbol->padre hay que asignarle su nuevo hijo
		if (arbol->dato == arbol->padre->izq->dato){
			arbol->padre->izq = nuevoNodo;
		}
		else if(arbol->dato == arbol->padre->der->dato){
			arbol->padre->der = nuevoNodo;
		}
	}
	if (nuevoNodo){
		//Procedemos a asignarle su nuevo padre
		nuevoNodo->padre = arbol->padre;
	}
}

//Función para destruir un nodo
void destruirNodo(Nodo *nodo){
	nodo->izq = NULL;
	nodo->der = NULL;
	
	delete nodo;
}
//Función para eliminar el nodo encontrado
void eliminarNodo(Nodo *nodoEliminar){
	if (nodoEliminar->izq && nodoEliminar->der){ //Si tiene hijo izq y der
		Nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoEliminar->izq){ //Si tiene hijo izq
		reemplazar(nodoEliminar,nodoEliminar->izq);
		destruirNodo(nodoEliminar);
	}
	else if(nodoEliminar->der){
		reemplazar(nodoEliminar,nodoEliminar->der);
		destruirNodo(nodoEliminar);
	} 
	else {
		reemplazar(nodoEliminar,NULL);
		destruirNodo(nodoEliminar);
	}
}

//Eliminar un nodo del árbol
void eliminar(Nodo *arbol,int n){
	if (arbol == NULL){ //Si el arbol está vacío
		return;
	} else if (n < arbol->dato){ //Si el valor es menor
		eliminar(arbol->izq,  n); //Busca por la izq
	} else if (n > arbol->dato){ //Si el arbol es mayor
		eliminar(arbol->der, n); //Busca por la der
	} else { //Si ya encontraste el valor
		eliminarNodo(arbol);
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
		cout << "6. Recorrer el arbol en PostOrden" << endl;
		cout << "7. Eliminar un numero" << endl;
		cout << "8. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		switch(opcion){
			case 1: cout << "Digite un numero: ";
			cin >> dato;
			insertarNodo(arbol,dato,NULL); 
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
			case 6: cout << "Recorrido en PostOrden: ";
			PostOrden(arbol);
			cout<<endl;
			system("pause");
			break;
			case 7:  cout << "Digite el numero a eliminar: ";
			cin >> dato;
			eliminar(arbol,dato);
			cout << endl;
			system("pause");
			break;
		}
	} while (opcion != 8);
}

int main(){
	menu();
	
	return 0;
}