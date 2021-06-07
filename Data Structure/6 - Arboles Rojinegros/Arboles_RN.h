// adaptado de: https://gist.github.com/SubCoder1/70c2cedc44353ffc539c7567b1051028

#include <iostream>
#include "nodo.h"
using namespace std;

template <class T>
 class Arbol_RN {

    nodo <T> * raiz;

    public:
        Arbol_RN() : raiz(NULL) {}

        nodo <T>* GetRaiz(){ return raiz; }

         void InsertarNodo(int dato, T info) {
           if(raiz == NULL){
               raiz = new nodo <T>;
               raiz->clave = dato;
               raiz->info = info;
               raiz->padre = NULL;
               raiz->color = 'n';
           }
           else {
               nodo <T>* conector = GetRaiz();
               nodo <T>* nuevo = new nodo <T>;
               nuevo->clave = dato;
               nuevo->info = info;

               while(conector != NULL){
                   if(conector->clave > dato){
                       if(conector->izq == NULL){
                           conector->izq = nuevo;
                           nuevo->color = 'r';
                           nuevo->padre = conector;
                           break; }
                       else { conector = conector->izq; }
                   } else {
                       if(conector->der == NULL){
                           conector->der = nuevo;
                           nuevo->color = 'r';
                           nuevo->padre = conector;
                           break; }
                       else {  conector = conector->der; }
                   }
               }
            RebalanceInsertar(nuevo);
           }cout<<"El elemento ha sido insertado! \n";
        }

        void RebalanceInsertar(nodo <T>* z) {
            while(z->padre->color == 'r') {
                nodo <T>* abuelo = z->padre->padre;
                nodo <T>* tio = GetRaiz();
                if(z->padre == abuelo->izq) {
                    if(abuelo->der) { tio = abuelo->der; }
                    if(tio->color == 'r'){
                        z->padre->color = 'n';
                        tio->color = 'n';
                        abuelo->color = 'r';
                        if(abuelo->clave != raiz->clave){ z = abuelo; }
                        else { break; }
                    }
                    else if(z == abuelo->izq->der) {
                       RotacionIzq(z->padre);
                    }
                    else {
                        z->padre->color = 'n';
                        abuelo->color = 'r';
                        RotacionDer(abuelo);
                        if(abuelo->clave != raiz->clave){ z = abuelo; }
                        else { break; }
                    }
                }
                else {
                    if(abuelo->izq) { tio = abuelo->izq; }
                    if(tio->color == 'r'){
                        z->padre->color = 'n';
                        tio->color = 'n';
                        abuelo->color = 'r';
                        if(abuelo->clave != raiz->clave){ z = abuelo; }
                        else { break; }
                    }
                    else if(z == abuelo->der->izq){
                        RotacionDer(z->padre);
                    }
                    else {
                        z->padre->color = 'n';
                        abuelo->color = 'r';
                        RotacionIzq(abuelo);
                        if(abuelo->clave != raiz->clave){ z = abuelo; }
                        else { break; }
                    }
                }
            }
            raiz->color = 'n';
        }

        void EliminarNodo(nodo <T>* padre, nodo <T>* curr, int dato) {
            if(curr == NULL) { return; }
            if(curr->clave == dato) {
                //CASO 1
                if(curr->izq == NULL && curr->der == NULL) {
                    if(padre->clave == curr->clave){ raiz = NULL; }
                    else if(padre->der == curr) {
                        RebalanceEliminar(curr);
                        padre->der = NULL;
                    } 
                    else { 
                        RebalanceEliminar(curr);
                        padre->izq = NULL;
                    }
                }
                //CASO 2
                else if(curr->izq != NULL && curr->der == NULL) {
                    int cambio = curr->clave;
                    curr->clave = curr->izq->clave;
                    curr->izq->clave = cambio;
                    EliminarNodo(curr, curr->der, dato);
                }
                else if(curr->izq == NULL && curr->der != NULL) {
                    int cambio = curr->clave;
                    curr->clave = curr->der->clave;
                    curr->der->clave = cambio;
                    EliminarNodo(curr, curr->der, dato);
                }
                //CASO 3
                else {
                    bool band = false;
                    nodo <T>* temp = curr->der;
                    while(temp->izq) { band = true; padre = temp; temp = temp->izq; }
                    if(!band) { padre = curr; }
                    int cambio = curr->clave;
                    curr->clave = temp->clave;
                    temp->clave = cambio;
                    EliminarNodo(padre, temp, cambio);
                }
            }
        }

        void Eliminar(int dato) {
            nodo <T>* temp = raiz;
            nodo <T>* padre = temp;
            bool band = false;
            if(!temp) { EliminarNodo(NULL, NULL, dato); }

            while(temp) {
                if(dato == temp->clave) { band = true; EliminarNodo(padre, temp, dato); break; }
                else if(dato < temp->clave) { padre = temp ; temp = temp->izq; }
                else { padre = temp ; temp = temp->der; }
            }

            if(!band) { cout << "\nEl elemento no ha sido encontrado"; }
        }

        void RebalanceEliminar(nodo <T>* z) { 
            while(z->clave != raiz->clave && z->color == 'n') {
                nodo <T>* hermano = GetRaiz();
                if(z->padre->izq == z) {
                    if(z->padre->der){ hermano = z->padre->der; }
                    if(hermano) {
                        //CASO 1
                        if(hermano->color == 'r') {
                            hermano->color = 'n';
                            z->padre->color = 'r';
                            RotacionIzq(z->padre);
                            hermano = z->padre->der;
                        }
                         //CASO 2
                        if(hermano->izq == NULL && hermano->der == NULL) {
                            hermano->color = 'r';
                            z = z->padre;
                        }
                        else if(hermano->izq->color == 'n' && hermano->der->color == 'n') {
                            hermano->color = 'r';
                            z = z->padre;
                        }
                        //CASO 3
                        else if(hermano->der->color == 'n') {
                            hermano->izq->color = 'n';
                            hermano->color = 'r';
                            RotacionDer(hermano);
                            hermano = z->padre->der;
                        } else {
                            hermano->color = z->padre->color;
                            z->padre->color = 'n';
                            if(hermano->der){ hermano->der->color = 'n'; }
                            RotacionIzq(z->padre);
                            z = raiz;
                        }
                    } 
                } else {
                    if(z->padre->der == z){
                        if(z->padre->izq){ hermano = z->padre->izq; }
                        if(hermano) {
                            //CASO 1
                            if(hermano->color == 'r'){
                                hermano->color = 'n';
                                z->padre->color = 'r';
                                RotacionDer(z->padre);
                                hermano = z->padre->izq;
                            }
                            //CASO 2
                             if(hermano->izq == NULL && hermano->der == NULL) {
                                hermano->color = 'r';
                                z = z->padre;
                            }
                            else if(hermano->izq->color == 'n' && hermano->der->color == 'n') {
                                hermano->color = 'r';
                                z = z->padre;
                            }
                            //CASO 3 
                            else if(hermano->izq->color == 'n') {
                                hermano->der->color = 'n';
                                hermano->color = 'r';
                                RotacionDer(hermano);
                                hermano = z->padre->izq;
                            } else {
                                hermano->color = z->padre->color;
                                z->padre->color = 'n';
                                if(hermano->izq){ hermano->izq->color = 'n'; }
                                RotacionIzq(z->padre);
                                z = raiz;
                            }
                        } 
                    }

                }
            }
            z->color = 'n';
        }

        nodo <T>* Buscar(int dato) {
            nodo <T>* temp = GetRaiz();
            if(temp == NULL) { return NULL; }

            while(temp) {
                if(dato == temp->clave){ return temp; }
                else if(dato < temp->clave){ temp = temp->izq; }
                else { temp = temp->der; }
            }
            return NULL;
        }

         void RotacionIzq(nodo <T>* x) {
            nodo <T>* nuevo = new nodo <T>;
            if(x->der->izq) { nuevo->der = x->der->izq; }
            nuevo->izq = x->izq;
            nuevo->clave = x->clave;
            nuevo->color = x->color;
            x->clave = x->der->clave;

            x->izq = nuevo;
            if(nuevo->izq){ nuevo->izq->padre = nuevo; }
            if(nuevo->der){ nuevo->der->padre = nuevo; }
            nuevo->padre = x;

            if(x->der->der){ x->der = x->der->der; }
            else { x->der = NULL; }

            if(x->der){ x->der->padre = x; }
        }

        void RotacionDer(nodo <T>* x) {
            nodo <T>* nuevo = new nodo <T>;
            if(x->izq->der){ nuevo->izq = x->izq->der; }
            nuevo->der = x->der;
            nuevo->clave = x->clave;
            nuevo->color = x->color;

            x->clave = x->izq->clave;
            x->color = x->izq->color;

            x->der = nuevo;
            if(nuevo->izq){ nuevo->izq->padre = nuevo; }
            if(nuevo->der){ nuevo->der->padre = nuevo; }
            nuevo->padre = x;

            if(x->izq->izq){ x->izq = x->izq->izq; }
            else { x->izq = NULL; }

            if(x->izq){ x->izq->padre = x; }
        }
	
        void Preorden(nodo <T>* temp) {
            if(!temp){ return; }
            cout << "--> (clave: " << temp->clave <<", info: "<<temp->info <<", color: " << temp->color << ") \n";
            Preorden(temp->izq);
            Preorden(temp->der);
        }

        void Postorden(nodo <T>*temp) {
            if(!temp){ return; }
            Postorden(temp->izq);
            Postorden(temp->der);
            cout << "--> (clave: " << temp->clave <<", info: "<<temp->info <<", color: " << temp->color << ") \n";
        }
        
        void Inorden(nodo <T>*temp) {
            if(!temp){ return; }
            Inorden(temp->izq);
            cout << "--> (clave: " << temp->clave <<", info: "<<temp->info <<", color: " << temp->color << ") \n";
            Inorden(temp->der);
        }
        
 };


