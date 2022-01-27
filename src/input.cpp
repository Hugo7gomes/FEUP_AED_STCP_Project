//
// Created by jpedr on 14/12/2021.
//

#include <iostream>
#include "input.h"

namespace input {
    void inputInt(int &num) {
        cin >> num;
        while (cin.fail()) {
            cout << "Input invalido, insira novamente!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> num;

        }
    }

    void inputDouble(double &num) {
        cin >> num;
        while (cin.fail()) {
            cout << "Input invalido, insira novamente!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> num;

        }
    }

    string inputStr() {
        string str;
        cin.clear();
        getline(cin, str);
        return str;
    }
}