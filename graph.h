#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
using namespace std;

#define firstVertex(G) G.firstVertexID
#define firstEdge(V) V->firstEdge
#define nextVertex(V) V->nextVertex
#define infoVertex(V) V->idVertex
#define destEdge(E) E->destVertexID
#define weightEdge(E) E->weight
#define nextEdge(E) E->nextEdge

struct edge;
struct vertex;

typedef vertex *adrVertex;
typedef edge *adrEdge;

struct edge {
    string destVertexID;
    int weight;
    adrEdge nextEdge;
};

struct vertex {
    string idVertex;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct graph {
    adrVertex firstVertexID;
};

void createVertex(string newVertexID, adrVertex &v);
void initGraph(graph &G);
void addVertex(graph &G, string newVertexID);
void addEdge(graph &G, string startVertexID, string endVertexID, int weight);
void buildGraph(graph &G);
void findShortestPath(graph &G, string startVertexID, string endVertexID);
void printGraph(graph &G);

#endif
