#include "graph.h"
#include <iostream>
using namespace std;

void createVertex(string newVertexID, adrVertex &v) {
    v = new vertex;
    infoVertex(v) = newVertexID;
    nextVertex(v) = NULL;
    firstEdge(v) = NULL;
}

void initGraph(graph &G) {
    firstVertex(G) = NULL;
}

void addVertex(graph &G, string newVertexID) {
    adrVertex newVertex;
    createVertex(newVertexID, newVertex);
    if (firstVertex(G) == NULL) {
        firstVertex(G) = newVertex;
    } else {
        adrVertex temp = firstVertex(G);
        while (nextVertex(temp) != NULL) {
            temp = nextVertex(temp);
        }
        nextVertex(temp) = newVertex;
    }
}

void addEdge(graph &G, string startVertexID, string endVertexID, int weight) {
    adrVertex start = firstVertex(G);
    adrVertex end = firstVertex(G);
    while (start != NULL && infoVertex(start) != startVertexID) {
        start = nextVertex(start);
    }
    while (end != NULL && infoVertex(end) != endVertexID) {
        end = nextVertex(end);
    }
    if (start != NULL && end != NULL) {
        adrEdge newEdge = new edge;
        destEdge(newEdge) = endVertexID;
        weightEdge(newEdge) = weight;
        nextEdge(newEdge) = firstEdge(start);
        firstEdge(start) = newEdge;

        newEdge = new edge;
        destEdge(newEdge) = startVertexID;
        weightEdge(newEdge) = weight;
        nextEdge(newEdge) = firstEdge(end);
        firstEdge(end) = newEdge;
    }
}

void buildGraph(graph &G) {
    initGraph(G);
    string vertexID;
    while (true) {
        cout << "Masukkan nama gedung: ";
        cin >> vertexID;
        if (vertexID == ".") break;
        addVertex(G, vertexID);
    }
    cout << "\nMasukkan hubungan antar gedung:" << endl;
    string start, end;
    int weight;
    while (true) {
        cout << "Masukkan gedung awal: ";
        cin >> start;
        if (start == ".") break;
        cout << "Masukkan gedung tujuan: ";
        cin >> end;
        cout << "Masukkan jarak: ";
        cin >> weight;
        addEdge(G, start, end, weight);
    }
}

void findShortestPath(graph &G, string startVertexID, string endVertexID) {
    adrVertex temp = firstVertex(G);
    bool foundStart = false, foundEnd = false;
    while (temp != NULL) {
        if (infoVertex(temp) == startVertexID) {
            foundStart = true;
        }
        if (infoVertex(temp) == endVertexID) {
            foundEnd = true;
        }
        temp = nextVertex(temp);
    }
    if (!foundStart || !foundEnd) {
        cout << "Salah satu atau kedua gedung tidak ditemukan!" << endl;
        return;
    }
    cout << "Mencari jalur terpendek dari " << startVertexID << " ke " << endVertexID << " ..." << endl;
    temp = firstVertex(G);
    while (temp != NULL) {
        if (infoVertex(temp) == startVertexID) {
            adrEdge edgeTemp = firstEdge(temp);
            while (edgeTemp != NULL) {
                cout << "Dari " << infoVertex(temp) << " ke " << destEdge(edgeTemp) << " dengan bobot " << weightEdge(edgeTemp) << endl;
                edgeTemp = nextEdge(edgeTemp);
            }
        }
        temp = nextVertex(temp);
    }
}

void printGraph(graph &G) {
    adrVertex temp = firstVertex(G);
    while (temp != NULL) {
        cout << "Gedung: " << infoVertex(temp) << endl;
        adrEdge edgeTemp = firstEdge(temp);
        while (edgeTemp != NULL) {
            cout << "  Ke: " << destEdge(edgeTemp) << " dengan bobot " << weightEdge(edgeTemp) << endl;
            edgeTemp = nextEdge(edgeTemp);
        }
        temp = nextVertex(temp);
    }
}
