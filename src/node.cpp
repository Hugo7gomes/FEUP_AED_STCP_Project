//
// Created by jpedr on 23/01/2022.
//

#include "node.h"

node::node(string code, int n, string zone, double latitude, double longitude, string name) {
    this->code.first = code;
    this->code.second = n;
    this->zone = zone;
    this->lati = latitude;
    this->longi = longitude;
    this->name = name;
}

void node::showNode() {
    /*cout << code.second << endl;
    cout << code.first << endl;
    cout << zone << endl;
    cout << lati << endl;
    cout << longi << endl;
    cout << name << endl;*/
    /*for(Edge e:adj){
        cout << "destino:" << e.dest << " " << "line:" << e.line << endl;
    }*/
    cout << endl;
}

pair<string, int> node::getCode() {
    return this->code;
}

list<Edge>& node::getAdj() {
    return adj;
}

bool node::getVisited() {
    return visited;
}

void node::setVisited(bool visited) {
    this->visited = visited;
}

double node::getDist() {
    return dist;
}

void node::setDist(double dist) {
    this->dist = dist;
}

int node::getPred() {
    return pred;
}

void node::setPred(int pred) {
    this->pred = pred;
}

list<string> node::getCurrentLine() {
    return currentLine;
}

void node::setCurrentLine(list<string> line) {
    this->currentLine = line;
}

double node::getLati() {
    return this->lati;
}

double node::getLongi() {
    return this->longi;
}

string node::getZone() {
    return zone;
}

