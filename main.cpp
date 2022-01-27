
#include "src/readFiles.h"
#include "src/graph.h"
#include "src/menus.h"
using namespace  std;
int main() {
    readFiles fileReader = readFiles();
    fileReader.readNodes();

    Graph g1 = Graph(true,fileReader.getNodes());
    fileReader.readLines(g1);

    Menus menus(g1, fileReader);
    menus.walkMenu();


    //Origem e destino
    string stop1, stop2;
    stop1 = "JB2";
    stop2 = "FEUP1";


    //cout << fileReader.getMapCode().find("12345")->second << endl;

    //Adicionar Edges ANDAR
    //g1.addEdgesWalk(0.03);

    //Menor numero de paragens:
    //g1.bfs(fileReader.getMapCode()[stop1], fileReader.getMapCode()[stop2]);


    //Menor distancia
    /*g1.setDistances();
    g1.dijkstra_distance(fileReader.getMapCode()[stop1]);
    double distance = g1.dijkstra_getDistance(fileReader.getMapCode()[stop1],fileReader.getMapCode()[stop2]);
    //cout << distance << endl;
    */

    //Mais barato
    //g1.dijkstra_Zones(fileReader.getMapCode()[stop1]);

    /*
    //Menor mudancas de Linha
    list<pair<int, string>> pathLines = g1.dijkstra_path_Lines(fileReader.getMapCode()[stop1],fileReader.getMapCode()[stop2]);
    for(pair<int, string> i : pathLines){
        if( !g1.getNodes()[i.first].getCurrentLine().empty()){
            cout <<"LINE:" <<  i.second << endl;
        }
        cout << g1.getNodes()[i.first].getCode().first << endl;
    }*/


    //Mostrar path
    /*list<int> path = g1.getPath(fileReader.getMapCode()[stop1],fileReader.getMapCode()[stop2]);
    for(int i : path){
        if( !g1.getNodes()[i].getCurrentLine().empty()){
            cout <<"LINE:" <<  g1.getNodes()[i].getCurrentLine().front()<< endl;
        }
        cout << g1.getNodes()[i].getCode().first << endl;
    }*/

    return 0;
}
