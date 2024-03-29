
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

list<string> intersection(list<string> l1, list<string> l2){
    list<string> ret;
    for(string s1:l1){
        for(string s2: l2){
            if(s1 == s2){
                ret.push_back(s1);
            }
        }
    }
    return ret;
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, double weight, string lineCode) {
    if (src<0 || src>n || dest<0 || dest>n) return;
    Edge e;
    e.dest = dest;
    e.weight = weight;
    e.lines.push_back(lineCode);
    nodes[src].getAdj().push_back(e);
}

vector<node> &Graph::getNodes() {
    return nodes;
}

void Graph::bfs(int v, int final) {
    for (int i=1; i<=n; i++) {
        nodes[i].setVisited(false);
        nodes[i].setDist(INF);
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
                nodes[w].setCurrentLine({e.lines});
            }
        }
    }
}

void Graph::setDistances() {
    for(int i = 0; i < nodes.size(); i++){
        for(Edge& e:nodes[i].getAdj()){
            int d = e.dest;
            e.weight = haversine(nodes[i].getLati(), nodes[i].getLongi(), nodes[d].getLati(), nodes[d].getLongi());
        }
    }
}

void Graph::dijkstra_distance(int s) {
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
        nodes[u].setVisited(true);
        for (Edge e : nodes[u].getAdj()) {
            int v = e.dest;
            double w = e.weight;
            if (!nodes[v].getVisited() && nodes[u].getDist() + w < nodes[v].getDist()) {
                nodes[v].setDist(nodes[u].getDist() + w);
                q.decreaseKey(v, nodes[v].getDist());
                nodes[v].setPred(u);
                nodes[v].setCurrentLine({e.lines});
            }
        }
    }
}

double Graph::dijkstra_getDistance(int a, int b) {
    dijkstra_distance(a);
    if (nodes[b].getDist() == INF) return -1;
    return nodes[b].getDist();
}

list<int> Graph::getPath(int a, int b) {
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


void Graph::dijkstra_Lines(int s) {
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
        nodes[u].setVisited(true);
        for (Edge e : nodes[u].getAdj()) {
            list<string> intersect = intersection(nodes[u].getCurrentLine(), e.lines);
            double w = 0;
            if(intersect.empty()){
                w = 1;
            }
            int v = e.dest;
            if (!nodes[v].getVisited() && nodes[u].getDist() + w < nodes[v].getDist()) {
                nodes[v].setDist(nodes[u].getDist() + w);
                q.decreaseKey(v, nodes[v].getDist());
                nodes[v].setPred(u);
                nodes[v].setCurrentLine(intersect);
                if(intersect.empty()){
                    nodes[v].setCurrentLine(e.lines);
                }
            }
        }
    }
}

list<pair<int, string>> Graph::dijkstra_path_Lines(int a, int b) {
    dijkstra_Lines(a);
    cout << nodes[b].getDist() << endl;
    list<pair<int, string>> path;
    if (nodes[b].getDist() == INF) return path;
    pair<int, string> aux1;
    aux1.first = b;
    aux1.second = nodes[b].getCurrentLine().front();
    path.push_back(aux1);
    int v = b;
    list<string> intersect= intersection(nodes[b].getCurrentLine(), nodes[v].getCurrentLine());
    while (nodes[v].getPred() != a) {
        pair<int, string> aux;
        int k = nodes[v].getPred();
        aux.first = k;
        intersect= intersection(nodes[k].getCurrentLine(), intersect);

        if(intersect.empty()){
            aux.second = nodes[k].getCurrentLine().front();
            intersect.push_back(aux.second);
        }else{
            aux.second = intersect.front();
        }
        path.push_front(aux);
        v = k;
    }
    return path;
}

double Graph::haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    double ret = rad * c;

    return  ret;
}

void Graph::dijkstra_Zones(int s) {
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
        nodes[u].setVisited(true);
        for (Edge e : nodes[u].getAdj()) {
            int v = e.dest;
            double w = 0;
            if(nodes[v].getZone() != nodes[u].getZone()){
                w = 1;
            }
            if (!nodes[v].getVisited() && nodes[u].getDist() + w < nodes[v].getDist()) {
                nodes[v].setDist(nodes[u].getDist() + w);
                q.decreaseKey(v, nodes[v].getDist());
                nodes[v].setPred(u);
                nodes[v].setCurrentLine({e.lines});
            }
        }
    }
}

void Graph::addEdgesWalk(double distance) {
    for(node& n: nodes){
        for(node& n1:nodes){
            if(n.getCode().second == n1.getCode().second)
                continue;
            bool addEdgeBool = true;
            for(Edge e: n.getAdj()){
                if(e.dest == n1.getCode().second){
                    addEdgeBool = false;
                    break;
                }
            }
            if(haversine(n.getLati(),n.getLongi(),n1.getLati(),n1.getLongi()) < distance && addEdgeBool){
                addEdge(n.getCode().second,n1.getCode().second,1,"ANDAR");
            }
        }
    }
}

