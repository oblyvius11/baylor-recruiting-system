//
// Created by Aiden Grajo on 3/19/2023.
//

#ifndef PROJ5_ATHLETES_PROJ5_BUATHLETE_HPP
#define PROJ5_ATHLETES_PROJ5_BUATHLETE_HPP
#include "proj5-NCAAAthlete.hpp"
#include <sstream>

using namespace std;


enum Position {OL, QB, RB, WR, TE, DL, DE, LB, CB, S, K};
class BUAthlete : public NCAAAthlete {
protected:
    int evaluation;
    Position position;

public:
    void setEvaluation(int);
    void setPosition(Position);
    int getEvaluation();
    Position getPosition();
    string toString();

};

#endif //PROJ5_ATHLETES_PROJ5_BUATHLETE_HPP
