#include <iostream>
using namespace std;

class Nodo
{
public:
    int info;
    Nodo* sig;
public:
    Nodo();
    Nodo(int dato);
};

Nodo::Nodo()
{
    info = 0;
    sig = NULL;
}

Nodo::Nodo(int dato)
{
    info = dato;
    sig = NULL;
}

class ListaCircular
{
private:
    Nodo* raiz;
public:
    ListaCircular();
    bool esVacia();
    void insertarInicio(int e);
    void insertarFinal(int e);
    int eliminarInicio();
    void mostrarLista();
};

ListaCircular::ListaCircular() { raiz = NULL; }

bool ListaCircular::esVacia()
{
    return (raiz == NULL);
}

void ListaCircular::insertarInicio(int dato)
{
    Nodo* nuevo = new Nodo(dato);

    if (esVacia())
    {
        raiz = nuevo;
        raiz->sig = raiz; // El último nodo apunta a sí mismo en una lista circular
    }
    else
    {
        Nodo* aux = raiz;

        while (aux->sig != raiz)
        {
            aux = aux->sig;
        }

        nuevo->sig = raiz;
        raiz = nuevo;
        aux->sig = raiz; // Actualizamos el último nodo para que apunte al nuevo nodo
    }
}

void ListaCircular::mostrarLista()
{
    Nodo* aux = raiz;

    if (!esVacia())
    {
        cout << "raiz" << " --> ";
        do
        {
            cout << aux->info << " --> ";
            aux = aux->sig;
        } while (aux != raiz);
        cout << "raiz" << endl;
    }
    else
    {
        cout << "\nLa lista está vacía!\n";
    }
}

void ListaCircular::insertarFinal(int dato)
{
    Nodo* nuevo = new Nodo(dato);

    if (esVacia())
    {
        raiz = nuevo;
        raiz->sig = raiz; // El último nodo apunta a sí mismo en una lista circular
    }
    else
    {
        Nodo* aux = raiz;

        while (aux->sig != raiz)
        {
            aux = aux->sig;
        }

        aux->sig = nuevo;
        nuevo->sig = raiz; // El último nodo apunta al primer nodo en una lista circular
    }
}

int ListaCircular::eliminarInicio()
{
    int dato = INT_MAX;

    if (!esVacia())
    {
        Nodo* aux = raiz;

        if (raiz->sig == raiz) // Si solo hay un elemento en la lista circular
        {
            raiz = NULL;
        }
        else
        {
            Nodo* temp = raiz;
            while (temp->sig != raiz)
            {
                temp = temp->sig;
            }
            raiz = raiz->sig;
            temp->sig = raiz; // Actualizamos el último nodo para que apunte al nuevo primer nodo
        }

        dato = aux->info;
        delete aux;
    }

    return dato;
}

int main()
{
    ListaCircular lista;

    lista.insertarFinal(1);
    lista.insertarFinal(2);
    lista.insertarFinal(3);

    cout << "Lista Circular:\n";
    lista.mostrarLista();

    return 0;
}

