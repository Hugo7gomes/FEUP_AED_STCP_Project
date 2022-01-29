//
// Created by jpedr on 27/01/2022.
//

#ifndef PROJECTSTCP_MENUS_H
#define PROJECTSTCP_MENUS_H

#include <string>
#include "graph.h"
#include <map>
#include "input.h"
#include "readFiles.h"

using namespace  std;
class Menus {
    string stop1, stop2;
    Graph g1;
    map<string , int> mapCode;

public:
    /**
     * construtor da classe menus
     * @param g grafo com as diferentes linhas e paragens
     * @param files classe com o mapa que traduz o id no nome da paragem
     */
    Menus(Graph&g, readFiles& files);

    /**
     *este método pergunta ao utilizador se deseja andar ou não e, se sim, a distancia a andar
     */
    void walkMenu();

    /**
     * Este método fornece  as possiveis maneiras de escolher o local de partida e chegada
     */
    void menuStops();

    /**
     * Este método fornece os possiveis criterios para chegar do local de partida ao de chegada
     */
    void menuCriteria();

    /**
     *Este método mostra as linhas a apanhar
     */
    void showPathLines();

    /**
     *Este método assegura que as paragens inseridas existem
     */
    void inputStopsCode();

    /**
     * Este método pede as coordenadas de partida e destino
     */
    void inputLocalCords();

    /**
     *Este método assegura que existe alguma paragem próxima as coordenadas inseridas
     * @return nome da paragem escolhida pelo utilizador
     */
    string nearStops();

    /**
     *Este método mostra as linhas a apanhar
     */
    void showPath();
};


#endif //PROJECTSTCP_MENUS_H
