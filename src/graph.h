

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "minHeap.h"
#include "node.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Graph {

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<node> nodes; // The list of nodes being represented

    void dijkstra(int s);

public:
    Graph( bool dir = false, vector<node> nodes = {});

    void addEdge(int src, int dest, double weight = 1, string lineCode = "");

    void bfs (int v, int final);

    double dijkstra_distance(int a, int b);

    list<int> dijkstra_path(int a, int b);

    double haversine(double lat1, double lon1, double lat2, double lon2);

    void setDistances();

    void setNumStops(int s);

    vector<node>& getNodes();
};

#endif
