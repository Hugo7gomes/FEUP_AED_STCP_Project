
#include "graph.h"
#include <climits>
#include <queue>
#include <cmath>
#define INF (INT_MAX/2)

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph( bool dir, vector<node> nodes){
    this->hasDir = dir;
    this->nodes= nodes;
    n = nodes.size();
}



// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, double weight, string lineCode) {
    if (src<0 || src>n || dest<0 || dest>n) return;
    nodes[src].getAdj().push_back({dest, weight,lineCode});
    if (!hasDir) nodes[dest].getAdj().push_back({src, weight, lineCode});
}

vector<node> &Graph::getNodes() {
    return nodes;
}

void Graph::bfs(int v, int final) {
    for (int i=1; i<=n; i++) {
        nodes[i].setVisited(false);
    }
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].setDist(0);
    nodes[v].setVisited(true);
    nodes[v].setPred(v);
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();// show node order
        if(u == final){
            break;
        }
        for (auto e : nodes[u].getAdj()) {
            int w = e.dest;
            if (!nodes[w].getVisited()) {
                q.push(w);
                nodes[w].setVisited(true);
                nodes[w].setDist(nodes[u].getDist() + 1);
                nodes[w].setPred(u);
                nodes[w].setCurrentLine(e.line);
            }
        }
    }
    int aux = final;
    for(int j = 0; j <= nodes[final].getDist(); j++){
        cout << nodes[aux].getCode().first << endl;
        cout << "line:" << nodes[aux].getCurrentLine() << endl;
        aux = nodes[aux].getPred();
    }
}

void Graph::dijkstra(int s) {
    MinHeap<int, int> q(n, -1);
    for (int v=0; v<n; v++) {
        nodes[v].setDist(INF);
        q.insert(v, INF);
        nodes[v].setVisited(false);
    }

    nodes[s].setDist(0);
    q.decreaseKey(s, 0);
    nodes[s].setPred(s);
    while (q.getSize()>0) {
        int u = q.removeMin();
        // cout << "Node " << u << " with dist = " << nodes[u].dist << endl;
        nodes[u].setVisited(true);
        for (Edge e : nodes[u].getAdj()) {
            int v = e.dest;
            double w = e.weight;
            if (!nodes[v].getVisited() && nodes[u].getDist() + w < nodes[v].getDist()) {
                nodes[v].setDist(nodes[u].getDist() + w);
                q.decreaseKey(v, nodes[v].getDist());
                nodes[v].setPred(u);
                nodes[v].setCurrentLine(e.line);
            }
        }
    }
}

double Graph::dijkstra_distance(int a, int b) {
    dijkstra(a);
    if (nodes[b].getDist() == INF) return -1;
    return nodes[b].getDist();
}

list<int> Graph::dijkstra_path(int a, int b) {
    setNumStops(a);
    cout << nodes[b].getDist() << endl;
    list<int> path;
    if (nodes[b].getDist() == INF) return path;
    path.push_back(b);
    int v = b;
    while (v != a) {
        v = nodes[v].getPred();
        path.push_front(v);
    }
    return path;
}

double Graph::haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) *
                  M_PI / 180.0;
    double dLon = (lon2 - lon1) *
                  M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    double ret = rad * c;

    return  ret;
}

void Graph::setDistances() {
    for(int i = 0; i < nodes.size(); i++){
        for(Edge& e:nodes[i].getAdj()){
            int d = e.dest;
            e.weight = haversine(nodes[i].getLati(), nodes[i].getLongi(), nodes[d].getLati(), nodes[d].getLongi());
        }
    }
}

void Graph::setNumStops(int s) {

}



/*
// ----------------------------------------------------------
// 1) Algoritmo de Dijkstra e caminhos mais curtos
// ----------------------------------------------------------

// ..............................
// a) Distância entre dois nós
// TODO
int Graph::dijkstra_distance(int a, int b) {
    MinHeap<int , int> heap = MinHeap<int,int>(nodes.size(), -1);
    for (int i = 0; i < nodes.size(); i++){
        nodes[i].visited = false;
        nodes[i].dist = INT_MAX;
    }
    nodes[a].dist = 0;
    for(int i = 0; i < nodes.size(); i++){
        heap.insert(i, nodes[i].dist);
    }
    while(heap.getSize() != 0){
        int min = heap.removeMin();
        nodes[min].visited = true;
        for(Edge e:nodes[min].adj){
            if(!nodes[e.dest].visited && ((nodes[min].dist + e.weight) < nodes[e.dest].dist)){
                nodes[e.dest].dist = nodes[min].dist + e.weight;
                heap.decreaseKey(e.dest, nodes[min].dist + e.weight);
            }
        }
    }

    if(nodes[b].dist == INT_MAX){
        return -1;
    }
    return nodes[b].dist;
}

// ..............................
// b) Caminho mais curto entre dois nós
// TODO
list<int> Graph::dijkstra_path(int a, int b) {
    list<int> path;
    MinHeap<int , int> heap = MinHeap<int,int>(nodes.size(), -1);
    for (int i = 0; i < nodes.size(); i++){
        nodes[i].visited = false;
        nodes[i].dist = INT_MAX;
    }
    nodes[a].dist = 0;
    nodes[a].pred = a;
    for(int i = 0; i < nodes.size(); i++){
        heap.insert(i, nodes[i].dist);
    }
    while(heap.getSize() != 0){
        int min = heap.removeMin();
        nodes[min].visited = true;
        for(Edge e:nodes[min].adj){
            if(!nodes[e.dest].visited && ((nodes[min].dist + e.weight) < nodes[e.dest].dist)){
                nodes[e.dest].dist = nodes[min].dist + e.weight;
                nodes[e.dest].pred = min;
                heap.decreaseKey(e.dest, nodes[min].dist + e.weight);
            }
        }
    }


    return path;
}
*/