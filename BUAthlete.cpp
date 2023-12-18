//
// Created by aegra on 3/19/2023.
//

#include "proj5-BUAthlete.hpp"

void BUAthlete::setEvaluation(int a) {
    evaluation = a;
}

void BUAthlete::setPosition(Position a) {
    position = a;
}

int BUAthlete::getEvaluation() {
    return evaluation;
}

Position BUAthlete::getPosition() {
    return position;
}

string BUAthlete::toString() {
    ostringstream out;

    out << "ID: " << athleteID << endl;
    out << "Name: " << athleteName << endl;
    out << "School: " << schoolChoice << endl;
    out << "Evaluation: " << evaluation << endl;
    out << "Position: " << position << endl;

    return out.str();
}