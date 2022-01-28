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
    Menus(Graph&g, readFiles& files);
    void walkMenu();
    void menuStops();
    void menuCriteria();
    void showPathLines();
    void inputStopsCode();
    void inputLocalCords();
    string nearStops();
    void showPath();
};


#endif //PROJECTSTCP_MENUS_H
