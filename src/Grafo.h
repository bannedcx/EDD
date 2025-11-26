#ifndef GRAFO_H
#define GRAFO_H

#include <string>
using namespace std;

struct NodoArista {
    int destino;
    int peso;
    NodoArista* siguiente;
    
    NodoArista(int dest, int p) : destino(dest), peso(p), siguiente(NULL) {}
};

struct NodoVertice {
    int id;
    NodoArista* listaAristas;  //Lista enlazada de aristas
    
    NodoVertice() : id(0), listaAristas(NULL) {}
};

//Nodo de pilas y colas
struct NodoPila {
    int dato;
    NodoPila* siguiente;
    
    NodoPila(int d) : dato(d), siguiente(NULL) {}
};

class Grafo {
private:
    int numVertices;
    NodoVertice* vertices;     //Array dinamico de vertices
    int** matrizPesos;         //Matriz dinamica de pesos
    bool esDirigido;
    
    //Estructuras auxiliares
    void agregarAristaALista(int origen, int destino, int peso);
    bool existeArista(int origen, int destino);
    void liberarListasAristas();
    
public:
    Grafo(int vertices, bool dirigido = false);
    ~Grafo();
    
    void agregarArista(int origen, int destino, int peso = 1);
    void mostrarGrafo();
    
    bool cargarDesdeCSV(const string& archivo);
    
    //Algoritmos de recorrido
    void BFS(int inicio);
    void DFS(int inicio);
    
    //Camino mas corto
    void dijkstra(int origen, int destino);
    
    //Otras funciones
    bool esConexo();
    int numeroAristas();
    void mostrarMatriz();
};

#endif
