#include "MyHeap.h"
#include <iostream>
#include <climits>
using namespace std;

MyHeap::MyHeap(int len)
{
    this->size = 0;
    this->len = len;
    this->values = new int[len];
}

int MyHeap::top(){
    if (this->size > 0){
        return this->values[0];
    }else{
        cout << "la fila priorizada no tiene un valor" << endl;
    }
}

int MyHeap::padre(int num){
    return (num-1)/2;
}

int MyHeap::izquierda(int num){
    return (2*num + 1);
}

int MyHeap::derecha(int num){
    return (2*num + 2);
}

void MyHeap::swap(int *one, int *two){
    int tmp = *one;
    *one = *two;
    *two = tmp;
}
void MyHeap::push(int n)
{
    if (this->size == this->len)
    {
        cout << "\nOverflow: Could not inserstKey\n";
        return;
    }
  
    // First insert the new key at the end
    this->size++;
    int i = this->size - 1;
    this->values[i] = n;
  
    // Fix the min heap property if it is violated
    while (i != 0 && this->values[padre(i)] > this->values[i])
    {
       swap(&this->values[i], &this->values[padre(i)]);
       i = padre(i);
    }
}

void MyHeap::heapifyMenor(int num)
{
    int izq = izquierda(num);
    int der = derecha(num);
    int menor = num;
    if (izq < this->size && this->values[izq] < this->values[num])
        menor = izq;
    if (der < this->size && this->values[der] < this->values[menor])
        menor = der;
    if (menor != num)
    {
        swap(&this->values[num], &this->values[menor]);
        heapifyMenor(menor);
    }
}

void MyHeap::disminuir(int num, int nuevoValor)
{
    this->values[num] = nuevoValor;
    while (num != 0 && this->values[padre(num)] > this->values[num])
    {
       swap(&this->values[num], &this->values[padre(num)]);
       num = padre(num);
    }
}

int MyHeap::sacarMenor()
{
    if (this->size <= 0)
        return INT_MAX;
    if (this->size == 1)
    {
        this->size--;
        return this->values[0];
    }
  
    // Store the minimum value, and remove it from heap
    int root = this->values[0];
    this->values[0] = this->values[this->size-1];
    this->size--;
    heapifyMenor(0);
  
    return root;
}

void MyHeap::pop(int num)
{
    disminuir(num, INT_MIN);
    sacarMenor();
}

bool MyHeap::isEmpty(){
    return this->size == 0;
}

int MyHeap::length(){
    return this->size;
}

int main()
{
    MyHeap h(11);
    h.push(3);
    h.push(2);
    h.pop(1);
    h.push(15);
    h.push(5);
    h.push(4);
    h.push(45);
    cout << h.sacarMenor() << " ";
    cout << h.top() << " ";
    h.disminuir(2, 1);
    cout << h.top();
    return 0;
}