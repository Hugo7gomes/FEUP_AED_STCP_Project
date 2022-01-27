

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



    void dijkstra_Lines(int s);

public:
    Graph( bool dir = false, vector<node> nodes = {});

    void addEdge(int src, int dest, double weight = 1, string lineCode = "");

    void bfs (int v, int final);

    void dijkstra_Zones(int s);

    void dijkstra_distance(int s);

    double dijkstra_getDistance(int a, int b);

    list<pair<int,string>> dijkstra_path_Lines(int a, int b);

    list<int> getPath(int a, int b);

    double haversine(double lat1, double lon1, double lat2, double lon2);

    void setDistances();

    void addEdgesWalk(double distance);

    void deleteEdgesWalk();





    vector<node>& getNodes();
};

#endif
