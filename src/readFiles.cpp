//
// Created by jpedr on 23/01/2022.
//
#include <fstream>
#include <sstream>
#include "readFiles.h"
#include <sstream>
readFiles::readFiles() {

}

void readFiles::addNode(node n) {
    this->nodes.push_back(n);
}

void readFiles::showNode(string nodeCode,Graph g) {
    g.getNodes()[mapCode[nodeCode]].showNode();
}

void readFiles::readNodes() {
    ifstream nodesStream (NODESFILENAME);
    int n = 0;
    string line;
    string code, name, zone;
    string latitude, longitude;

    getline(nodesStream, line);
    while (getline(nodesStream, line)){
        istringstream stringInput(line);
        getline(stringInput, code, ',');
        getline(stringInput, name, ',');
        getline(stringInput, zone, ',');
        getline(stringInput, latitude, ',');
        getline(stringInput,longitude,',');

        node N(code,n, zone, stod(latitude),stod(longitude), name );
        addNode(N);
        mapCode.insert(N.getCode());
        n++;
    }
    nodesStream.close();
}

vector<node>& readFiles::getNodes() {
    return nodes;
}

void readFiles::readLine(string fileNameline, string lineCode, Graph &g) {
    ifstream lineStream (fileNameline);
    string numStops;
    string stop1, stop2;
    getline(lineStream, numStops );
    getline(lineStream,stop1);

    while(getline(lineStream,stop2)){
        bool insert = false;
        for(Edge &e : g.getNodes()[mapCode[stop1]].getAdj()){
            if(e.dest == mapCode[stop2]){
                e.lines.push_back(lineCode);
                insert = true;
            }
        }
        if(!insert){
            g.addEdge(mapCode[stop1], mapCode[stop2], 1, lineCode);
        }
        stop1 = stop2;
    }
    lineStream.close();
}

void readFiles::readLines(Graph& g) {
    ifstream linesStream (LINESFILENAME);
    string line;
    string lineCode;
    getline(linesStream, line);
    while (getline(linesStream,line)){
        istringstream stringLine(line);
        getline(stringLine,lineCode , ',');
        stringstream fileLineName0, fileLineName1;

        fileLineName0 << "line_" << lineCode << "_0.csv";
        fileLineName1 << "line_" << lineCode << "_1.csv";
        readLine(fileLineName0.str(), lineCode, g);
        readLine(fileLineName1.str(), lineCode, g);
    }
    linesStream.close();

}

map<string, int>& readFiles::getMapCode() {
    return mapCode;
}




