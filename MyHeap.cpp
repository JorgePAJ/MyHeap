/* Jorge Plasencia Ahm Jorgensen
   A01637493
   Heap*/
#include "MyHeap.h"
#include <iostream>
#include <climits>
using namespace std;

//Constructor del heap. O(1)
MyHeap::MyHeap(int len){
    this->size = 0;
    this->len = len;
    this->values = new int[len];
}

//Regresa el elemento por salir.
int MyHeap::top(){
    if (this->size > 0){
        return this->values[0];
    }else{
        cout << "la fila priorizada no tiene un valor" << endl;
    }
    return -1;
}

//Regresa el valor padre. O(1)
int MyHeap::padre(int num){
    return (num-1)/2;
}

//Regresa el valor a la izquierda.
int MyHeap::izquierda(int num){
    return (2*num + 1);
}

//Regresa el valor a la derecha.
int MyHeap::derecha(int num){
    return (2*num + 2);
}

//Intercambia la posicion de dos valores dados.
void MyHeap::swap(int *one, int *two){
    int tmp = *one;
    *one = *two;
    *two = tmp;
}

//Agrega el valor dado. O(logn)
void MyHeap::push(int n){
    if (this->size == this->len){
        cout << "No se pudo agregar el valor" << endl;
        return;
    }
    this->size++;
    int i = this->size - 1; //Inserta el valor al final.
    this->values[i] = n;
  
    
    while (i != 0 && this->values[padre(i)] > this->values[i]){ //En caso de romper la condicion del heap, lo arregla.
       swap(&this->values[i], &this->values[padre(i)]);
       i = padre(i);
    }
}

//Hace el proceso de heapify menor. O(nLogn)
void MyHeap::heapifyMenor(int num){
    int izq = izquierda(num);
    int der = derecha(num);
    int menor = num;
    if (izq < this->size && this->values[izq] < this->values[num])
        menor = izq;
    if (der < this->size && this->values[der] < this->values[menor])
        menor = der;
    if (menor != num){
        swap(&this->values[num], &this->values[menor]);
        heapifyMenor(menor);
    }
}
//Disminuye el valor dado. O(logn)
void MyHeap::disminuir(int num, int nuevoValor){
    this->values[num] = nuevoValor;
    while (num != 0 && this->values[padre(num)] > this->values[num]){
       swap(&this->values[num], &this->values[padre(num)]);
       num = padre(num);
    }
}

//Regresa y elimina el valor menor del heap. O(logn)
int MyHeap::sacarMenor(){
    if (this->size <= 0){
        return INT_MAX;
    }
    if (this->size == 1){
        this->size--;
        return this->values[0];
    }
  
    // Guarda y remueve el valor minimo del heap.
    int root = this->values[0];
    this->values[0] = this->values[this->size-1];
    this->size--;
    heapifyMenor(0);
    return root;
}

//Elimina un valor del heap. O(logn)
void MyHeap::pop(int num){
    disminuir(num, INT_MIN);
    sacarMenor();
}

//Regresa un booleano si esta vacio o no el heap.
bool MyHeap::isEmpty(){
    return this->size == 0;
}

//Regresa el numerom de datos guardados.
int MyHeap::length(){
    return this->size;
}

//Ingrese el main aqui :)