#include <iostream>

template <class T>
struct nodo {
    int clave;
    T info;
    nodo* izq = NULL;
    nodo* der = NULL;
    nodo* padre = NULL;
    char color;
};
