#ifndef MYHEAP_H
#define MYHEAP_H

//Recuerden poner como comentario en cada operación la complejidad de la misma para el mejor de los casos y para el peor de los casos
//y expliquen en cual situación se da el mejor de los casos y en cual el peor.
class   MyHeap{
    private:
        int* values; //Arreglo donde se van a guardar los valores del HEAP
        int size;    //Representa cuantos valores tiene almacenado el Heap
       int len;    //Representa el tamaño o capacidad máxima actual del arreglo
    public:
        MyHeap();//Inicializa el los atributos. El atributo values lo inicializa como un arreglo vacío tamaño de 7.
        void push(int n); //Inserta un valor en el heap. Sólo cuando el nuevo valor no cabe en el arreglo
                          //crece el arreglo al tamaño 2*n+1. (Expansión din+amica del arreglo)
                          //Es decir si se tiene el arreglo ya con 7 valores y se quiere insertar otro valor(El 8vo)
                          //entonces el arreglo se crece a tamaño 15, se copian los primeros 7 valores del arreglo original
                          //y se inserta el 8vo valor.
        void pop(int num);//Se elimina un valor del heap. No es necesario nunca decrementar el tamaño del arreglo.
        int top();//regresa quien es el siguiente elemento en salir pero sin borrarlo
        bool isEmpty();//regresa true si el heap está vacío caso contrario regresa false
        int length();//regresa cuántos elementos están almacenando el heap. OJO: NO EL TAMAÑO
        int padre(int num);//Regresa el valor padre.
        int izquierda(int num);//Regresa el valor a la izquierda.
        int derecha(int num);//Regresa el valor a la derecha.
        void swap(int* one, int* two);//Intercambia la posicion de dos valores dados.
        void disminuir(int num, int nuevoValor);//Disminuye el valor dado.
        int sacarMenor();//Regresa y elimina el valor menor del heap.
        void heapifyMenor(int num);//Hace el proceso de heapify menor.
    };
#endif 