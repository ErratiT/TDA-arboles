# TDA-arboles
Todo sobre el Tipo de Dato Abstracto **Árbol**.

## Conceptos
**Árbol:** _Consta de un conjunto finito de elementos denominados nodos  un cojunto finito de lineas dirigidas, denominadas ramas, que conectan los nodos._    
**Longitud de Camino:** _Número de ramas a pasar para llegar de un nodo a otro._  
**Altura de un nodo:** _Desde las hojas hacia arriba. (Inicia 0)._  
**Profundida de un nodo (Nivel):** _Desde la raíz hacia abajo. (Inicia 0)._  
**Nodos hermanos:** _Deben estar en el mismo nivel y deben tener en común el mismo padre._  
**Orden:** _Máxima cantidad de hijos que puede tener cada nodo._  

**Árbol binario:** _Árbol de orden 2. Se conoce el nodo de la izquierda como <ins>hijo izquierdo</ins> y el nodo de la derecha como <ins>hijo derecho</ins>._  
_Es una estructura recursiva, se divide en tres subconjuntos disjuntos:_  
**- Nodo Raíz**  
**- Subárbol izquierdo**  
**- Subárbol derecho**  

### Tipos de Árboles Binarios
**Árbol lleno:** _Todos sus nodos, excepto los del último nivel, tienen 2 hijos._  
**Árbol completo:** _Todos sus nodos están llenos, excepto posiblemente el último nivel, el cual se llena estrictamente de izquierda a derecha._  
**Árbol degenerado:** _Tiene 1 solo hijo (extendido), podría ser una lista enlazada._

### Estructura de un Árbol Binario
```
struct Nodo{  
  int dato;
  nodo *der;
  nodo *izq
};
```

### ¿Qué es un Árbol Binario de Búsqueda?
_Es aquel que dado un nodo, todos los datos del subárbol izquierdo son menores, mientras que los datos del subárbol derecho son mayores._

### Operaciones en Árboles binarios de Búsqueda
**Insertar un nodo en el árbol.**  
**Mostrar el árbol completo.**  
**Buscar un nodo específico.**  
**Recorrer el árbol.**  
_Preorden._  
_Inorden._  
_Postorden._  
**Borrar un nodo del árbol.**  
