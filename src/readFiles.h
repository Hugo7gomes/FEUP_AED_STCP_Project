//
// Created by jpedr on 23/01/2022.
//

#ifndef PROJECTSTCP_READFILES_H
#define PROJECTSTCP_READFILES_H
#include <vector>
#include "node.h"
#include "graph.h"
#include <map>


class readFiles {
    vector<node> nodes;
    string NODESFILENAME= "stops.csv";
    string LINESFILENAME = "lines.csv";
    map<string , int> mapCode;

public:
    readFiles();
    void readNodes();
    void addNode(node n);
    vector<node>& getNodes();
    void readLine(string fileNameline, string lineCode, Graph& g);
    void readLines(Graph& g);
    map<string, int>& getMapCode();
};


#endif //PROJECTSTCP_READFILES_H
