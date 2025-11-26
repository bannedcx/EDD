#include "Grafo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <climits>

using namespace std;

// Constructor
Grafo::Grafo(int vertices, bool dirigido) {
    numVertices = vertices;
    esDirigido = dirigido;
    listaAdyacencia.resize(vertices);
    pesos.resize(vertices);
    for (int i = 0; i < vertices; i++) {
        pesos[i].resize(vertices, 0);
    }
}

// Agregar arista
void Grafo::agregarArista(int origen, int destino, int peso) {
    if (origen < 0 || destino < 0 || origen >= numVertices || destino >= numVertices) {
        cout << "Error: Vertices invalidos" << endl;
        return;
    }
    
    listaAdyacencia[origen].push_back(destino);
    pesos[origen][destino] = peso;
    
    if (!esDirigido) {
        listaAdyacencia[destino].push_back(origen);
        pesos[destino][origen] = peso;
    }
    
    cout << "Arista agregada: " << origen << " -> " << destino 
         << " (peso: " << peso << ")" << endl;
}

// Mostrar grafo
void Grafo::mostrarGrafo() {
    cout << "\n==GRAFO (Lista de Adyacencia)==" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertice " << i << ": ";
        for (size_t j = 0; j < listaAdyacencia[i].size(); j++) {
            int vecino = listaAdyacencia[i][j];
            cout << vecino << "(" << pesos[i][vecino] << ")";
            if (j < listaAdyacencia[i].size() - 1) cout << " -> ";
        }
        cout << endl;
    }
}
