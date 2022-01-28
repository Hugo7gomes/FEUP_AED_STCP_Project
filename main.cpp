
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

    return 0;
}
