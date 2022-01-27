#ifndef PROJECTSTCP_NODE_H
#define PROJECTSTCP_NODE_H

#include <string>
#include <iostream>
#include <utility>
#include <list>

using namespace  std;

struct Edge {
    int dest;   // Destination node
    double weight; // An integer weight
    list<string> lines; //
};

class node {
    pair<string, int> code ;
    string zone;
    double lati;
    double longi;
    string name;
    bool visited;
    double dist;
    int pred;
    list<string> currentLine;
    list<Edge> adj;
public:
    node(string code, int n, string zone, double latitude, double longitude,string name);
    void showNode();
    pair<string, int> getCode();
    list<Edge>& getAdj();
    bool getVisited();
    void setVisited(bool visited);
    double getDist();
    void setDist(double dist);
    int getPred();
    void setPred(int pred);
    list<string> getCurrentLine();
    void setCurrentLine(list<string> line);
    double getLati();
    double getLongi();
    string getZone();
};



#endif //PROJECTSTCP_NODE_H
