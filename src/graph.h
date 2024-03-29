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


    /**
     * Este método executa o algortimo djikstra em que o peso da aresta aumenta em 1 se o utilizador for obrigado a mudar de linha
     * @param s id do nó de origem
     */
    void dijkstra_Lines(int s);

public:
    /**
     * Construtor da classe graph
     * @param dir grafo dirigido ou nao
     * @param nodes vetor de nós
     */
    Graph( bool dir = false, vector<node> nodes = {});

    /**
     * Este método adiciona uma aresta ao grafo
     * @param src origem
     * @param dest destino
     * @param weight peso
     * @param lineCode codigo da linha
     */
    void addEdge(int src, int dest, double weight = 1, string lineCode = "");

    /**
     * Este método executa o algoritmo bfs
     * @param v id do nó de origem
     * @param final id do nó de destino
     */
    void bfs (int v, int final);

    /**
     * Este método executa o algoritmo dijkstra em que o peso da aresta é 1 se mudar de zona,  0 nos restantes casos
     * @param s id do nó de origem
     */
    void dijkstra_Zones(int s);

    /**
     * Este método executa o algoritmo dijkstra em que o peso é a distância real entre paragens
     * @param s id do nó de origem
     */
    void dijkstra_distance(int s);

    /**
     * este método fornece a distância entre dois nós
     * @param a id do nó de origem
     * @param b id do nó de destino
     * @return distância entre dois nós
     */
    double dijkstra_getDistance(int a, int b);

    /**
     * Este método fornece a lista de paragens de 'a' a 'b' passando pelo menor numero de linhas
     * @param a id do nó de origem
     * @param b id do nó de destino
     * @return
     */
    list<pair<int,string>> dijkstra_path_Lines(int a, int b);

    /**
     * este método fornece a lista de paragens de 'a' a 'b'
     * @param a id do nó de origem
     * @param b id do nó de destino
     * @return lista de paragens
     */
    list<int> getPath(int a, int b);

    /**
     * método responsável por calcular a distância entre dois pontos
     * @param lat1 latitude do local de partida
     * @param lon1 longitude do local de partida
     * @param lat2 latitude do local de destino
     * @param lon2 longitude do local de destino
     * @return
     */
    double haversine(double lat1, double lon1, double lat2, double lon2);

    /**
     * método responsável por colocar a distancia nas respetivas arestas
     */
    void setDistances();

    /**
     * método responsável por adicionar as arestas a andar a pé
     * @param distance distância que o utilizador está disposto a andar a pé
     */
    void addEdgesWalk(double distance);

    /**
     * método responsável por retornar o vetor com todos os nós do grafo
     * @return vetor com todos os nós do grafo
     */
    vector<node>& getNodes();
};

#endif
