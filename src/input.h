//
// Created by jpedr on 14/12/2021.
//

#ifndef PROJECT_INPUT_H
#define PROJECT_INPUT_H

#include <string>

using namespace std;


namespace  input{
    /**
     * Este método controla o input de inteiros
     * @param num parametro aonde é retornado o input
     */
    void inputInt(int& num);
    /**
     * Este método controla o input de floats
     * @param num parametro aonde é retornado o input
     */
    void inputDouble(double& num);
    /**
     * Este método controla o input de strings
     * @return string inserida pelo utilizador
     */
    string inputStr();

}

#endif //PROJECT_INPUT_H
