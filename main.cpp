
#include "src/readFiles.h"
#include "src/graph.h"
using namespace  std;
int main() {
    readFiles fileReader = readFiles();
    fileReader.readNodes();

    Graph g1 = Graph(true,fileReader.getNodes());
    fileReader.readLines(g1);

    //cout << g1.getNodes()[fileReader.getMapCode()["PSEC2"]].getAdj().size() << endl;

    string stop1, stop2;
    stop1 = "JB2";
    stop2 = "FEUP1";
    //g1.setNumStops(fileReader.getMapCode()[stop1]);
    //cout << g1.dijkstra_distance(fileReader.getMapCode()[stop1],fileReader.getMapCode()[stop2]);

    //g1.bfs(fileReader.getMapCode()[stop1],fileReader.getMapCode()[stop2]);
    list<int> path = g1.dijkstra_path(fileReader.getMapCode()[stop1],fileReader.getMapCode()[stop2]);
    list<int>::iterator it;
    for(it = path.begin(); it != path.end();it++){
        cout << g1.getNodes()[*it].getCode().first << endl;
        cout << g1.getNodes()[*it].getCurrentLine() << endl;
    }

    return 0;
}
