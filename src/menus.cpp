//
// Created by jpedr on 27/01/2022.
//

#include "menus.h"
#include <algorithm>

Menus::Menus(Graph& g, readFiles& files) {
    this->g1 = g;
    this->mapCode = files.getMapCode();
}

void Menus::walkMenu() {
    cout << "Deseja caminhar?" << endl;
    cout << "1) SIM" << endl;
    cout << "2) NAO" << endl;
    int inputWalk;
    input::inputInt(inputWalk);
    while ( inputWalk != 1 && inputWalk != 2)
    {
        cout << "Input invalido, insira novamente!" << endl;
        input::inputInt(inputWalk);

    }

    switch (inputWalk) {
        case 1:
            double distance;
            cout << "Introduza a distancia maxima a percorrer a pe (Km)" << endl;
            input::inputDouble(distance);
            g1.addEdgesWalk(distance);
            menuStops();
            break;
        case 2:
            menuStops();
            break;
    }

}

void Menus::menuStops() {
    bool isRunning = true;
    while(isRunning) {
        cout << "1)Indicar paragem de partida e paragem de destino" << endl;
        cout << "2)Indicar latitude e longitude de um local de partida e destino " << endl;
        cout << "0)Exit" << endl;

        int inputStops;
        input::inputInt(inputStops);

        while (inputStops != 1 && inputStops != 2 && inputStops != 0) {
            cout << "Input invalido, insira novamente!" << endl;
            input::inputInt(inputStops);

        }


        switch (inputStops) {
            case 1:
                inputStopsCode();
                menuCriteria();
                break;
            case 2:
                inputLocalCords();
                menuCriteria();
                break;
            case 0:
                isRunning= false;
                break;
        }
    }
}

void Menus::inputStopsCode() {
    //string stop1;
    //string stop2;

    cout << "Introduza o codigo da paragem de partida" << endl;
    cin.ignore(1000,'\n');
    stop1 = input::inputStr();
    while(mapCode.find(stop1) == mapCode.end()){
        cout << "Paragem nao encontrada, introduza um novo codigo " << endl;
        stop1 = input::inputStr();
    }

    cout << "Introduza o codigo da paragem de destino" << endl;

    stop2 = input::inputStr();
    while(mapCode.find(stop2) == mapCode.end()){
        cout << "Paragem nao encontrada, introduza um novo codigo " << endl;
        stop2 = input::inputStr();
    }


}

void Menus::inputLocalCords() {
    cout << "Introduza as coordenadas do local de partida" << endl;
    string src = nearStops();
    cout << "Introduza as coordenadas do local de destino" << endl;
    string dest = nearStops();

    this->stop1 = src;
    this->stop2 = dest;

}

string Menus::nearStops() {
    double lat1, long1;
    double distance = 0.4;
    string stop;

    cout << "Latitude:" << endl;
    input::inputDouble(lat1);
    cout << "Longitude:" << endl;
    input::inputDouble(long1);

    vector<string> vectorPartidas;

    for(node n: g1.getNodes()){
        if(g1.haversine(n.getLati(),n.getLongi(),lat1,long1) < distance){
            vectorPartidas.push_back(n.getCode().first);
        }
    }

    while(vectorPartidas.empty()){
        cout << "Nao existem paragens proximas da localizacao indicada" << endl;
        cout << "Latitude:" << endl;
        input::inputDouble(lat1);
        cout << "Longitude:" << endl;
        input::inputDouble(long1);

        for(node n: g1.getNodes()){
            if(g1.haversine(n.getLati(),n.getLongi(),lat1,long1) < distance){
                vectorPartidas.push_back(n.getCode().first);
            }
        }
    }



    cout << "Paragens proximas do local" << endl;
    for(string s: vectorPartidas){
        cout << s << endl;
    }
    cout << endl;
    cout << "Escolha a paragem" << endl;
    cin.ignore(1000, '\n');
    stop = input::inputStr();
    vector<string>::iterator it1;
    it1 = find(vectorPartidas.begin(), vectorPartidas.end(), stop);
    while(it1 == vectorPartidas.end()){
        cout << "Paragem nao se encontra na lista acima" << endl;
        stop = input::inputStr();
        it1 = find(vectorPartidas.begin(), vectorPartidas.end(), stop);
    }

    return stop;

}

void Menus::menuCriteria() {
    bool isRunning = true;
    while(isRunning) {
        cout << "Preferencia de percurso " << endl;
        cout << "1) Menor numero paragens" << endl;
        cout << "2) Menor distancia" << endl;
        cout << "3) Menos mudancas de linha" << endl;
        cout << "4) Mais barato (menos mudancas de zona)" << endl;
        cout << "0) Previous Menu" << endl;

        int inputCriteria;
        input::inputInt(inputCriteria);

        while (inputCriteria != 1 && inputCriteria != 2 && inputCriteria != 3 && inputCriteria != 4 && inputCriteria != 0) {
            cout << "Input invalido, insira novamente!" << endl;
            input::inputInt(inputCriteria);
        }

        switch (inputCriteria) {
            case 1:
                g1.bfs(mapCode[stop1], mapCode[stop2]);
                showPath();
                break;
            case 2:
                g1.setDistances();
                cout << "Distancia:" << g1.dijkstra_getDistance(mapCode[stop1], mapCode[stop2]) << endl;
                showPath();
                break;
            case 3:
                showPathLines();
                break;
            case 4:
                g1.dijkstra_Zones(mapCode[stop1]);
                showPath();
                break;
            case 0:
                isRunning = false;
                break;
        }
    }
}

void Menus::showPath() {
    list<int> path = g1.getPath(mapCode[stop1], mapCode[stop2]);
    for (int i: path) {
        if (!g1.getNodes()[i].getCurrentLine().empty()) {
            cout << "LINES: ";
            for(string s : g1.getNodes()[i].getCurrentLine()){
                cout << s << " ";
            }
            cout << endl;
        }
        cout << g1.getNodes()[i].getCode().first << endl;
    }
    cout << endl;
}

void Menus::showPathLines(){
    list<pair<int, string>> pathLines = g1.dijkstra_path_Lines(mapCode[stop1],mapCode[stop2]);
    for(pair<int, string> i : pathLines){
        if( !g1.getNodes()[i.first].getCurrentLine().empty()){
            cout <<"LINE:" <<  i.second << endl;
        }
        cout << g1.getNodes()[i.first].getCode().first << endl;
    }
}




