#include "graph.h"
#include <iostream>
using namespace std;

int main() {
    graph G;
    buildGraph(G);
    cout << "\nGraf telah dibangun. Menampilkan graf:\n";
    printGraph(G);

    string start, end;
    cout << "Masukkan nama gedung awal: ";
    cin >> start;
    cout << "Masukkan nama gedung tujuan: ";
    cin >> end;
    findShortestPath(G, start, end);

    return 0;
}
