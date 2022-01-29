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
    /**
     * Construtor da classe readFiles
     */
    readFiles();

    /**
     * Este método lê a informação do ficheiro stops criando um nó por cada paragem
     */
    void readNodes();

    /**
     * Este método adciciona um nó á lista de nós
     * @param n
     */
    void addNode(node n);

    /**
     * Este método fornece o vetor de nós
     * @return vetor de nós
     */
    vector<node>& getNodes();

    /**
     * Este método adiciona as arestas de uma certa linha ao grafo
     * @param fileNameline nome do ficheiro com as paragens da linha
     * @param lineCode codigo da linha
     * @param g grafo
     */
    void readLine(string fileNameline, string lineCode, Graph& g);

    /**
     * Este método lê todas as linhas do ficheiro lines criando dinamicamente o nome do ficheiro com as paragens de cada linha
     * @param g grafo a adicionar arestas
     */
    void readLines(Graph& g);

    /**
     * Este método retorna o mapa que mapeia os codigos das paragens com o respetivo id associado
     * @return map
     */
    map<string, int>& getMapCode();
};


#endif //PROJECTSTCP_READFILES_H
