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
    /**
     * Construtor da classe node
     * @param code codigo da paragem
     * @param n id da paragem
     * @param zone zona da paragem
     * @param latitude latitude da paragem
     * @param longitude longitude da paragem
     * @param name nome da paragem
     */
    node(string code, int n, string zone, double latitude, double longitude,string name);

    /**
     * Este metodo retorna o par codigo, id da paragem
     * @return par codigo,id
     */
    pair<string, int> getCode();

    /**
     * método que retorna lista de arestas que ligam o nó
     * @return lista de arestas que ligam o nó
     */
    list<Edge>& getAdj();

    /**
     * método que retorna um boolean que indica se o nó ja foi visitado
     * @return boolean que indica se o nó ja foi visitado
     */
    bool getVisited();

    /**
     * método responsável por colocar o nó como visitado
     */
    void setVisited(bool visited);

    /**
     * método responsável por retornar a distância a que o nó está do nó inicial
     * @return distância a que o nó está do nó inicial
     */
    double getDist();

    /**
     * método responsável por colocar a distância a que o nó está do nó inicial
     * @param dist distância a que o nó está do nó inicial
     */
    void setDist(double dist);

    /**
     * método responsável por retornar o id do pai do nó
     * @return id do pai do nó
     */
    int getPred();

    /**
     * método responsável por colocar o id do pai do nó
     * @param pred
     */
    void setPred(int pred);

    /**
     *método responsável por devolver a lista das linhas que permitem chegar até esta paragem
     * @return lista de linhas
     */
    list<string> getCurrentLine();

    /**
     * método responsável por colocar a lista das linhas que permitem chegar até esta paragem
     * @param line lista das linhas que permitem chegar até esta paragem
     */
    void setCurrentLine(list<string> line);

    /**
     *método responsável por devolver a latitude da paragem
     * @return latitude da paragem
     */
    double getLati();

    /**
     *método responsável por devolver a longitude da paragem
     * @return longitude da paragem
     */
    double getLongi();

    /**
     *método responsável por devolver a zona da paragem
     * @return zona da paragem
     */
    string getZone();
};



#endif //PROJECTSTCP_NODE_H
