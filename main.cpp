#include <iostream>
#include <fstream>
#include <string>
#include "proj5-BUAthleteList.hpp"

using namespace std;

Position convertStrtoPos(string a) {
    Position pos;

    if (a == "OL") {
        pos = OL;
    } else if (a == "QB") {
        pos = QB;
    } else if (a == "RB") {
        pos = RB;
    } else if (a == "WR") {
        pos = WR;
    } else if (a == "TE") {
        pos = TE;
    } else if (a == "DL") {
        pos = DL;
    } else if (a == "DE") {
        pos = DE;
    } else if (a == "LB") {
        pos = LB;
    } else if (a == "CB") {
        pos = CB;
    } else if (a == "S") {
        pos = S;
    } else {
        pos = K;
    }

    return pos;
}

int main() {
    ifstream inFile;
    int id, eval, count = 0;
    string name, decision, college, position;
    BUAthleteList athleteList;

    inFile.open("proj5-NCAAAthlete.csv");

    if (inFile) {
        cout << "File opened." << endl;
    }
    else {
        cout << "File not open. " << endl;
    }

    while (inFile >> id) {
        inFile.ignore();
        getline(inFile, name, ',');
        getline(inFile, decision, ',');
        getline(inFile, college);

        athleteList.addNCAAAthlete(id, name, decision, college);
        count++;

    }

    cout << "SORTED BY ID:" << endl;

    athleteList.sortByID(0, count);


    inFile.close();
    inFile.clear();

    inFile.open("proj5-BUAthlete.csv");

    if (inFile) {
        cout << "File opened." << endl;
    }
    else {
        cout << "File not open. " << endl;
    }

    while(inFile >> id) {
        inFile.ignore();
        getline(inFile, position, ',');

        inFile >> eval;
        inFile.ignore();

        if (athleteList.findBYId(id)!= -1) {
            athleteList.setBUInfo(athleteList.findBYId(id), convertStrtoPos(position), eval);
        }

    }

    inFile.close();

    cout << athleteList.toString() << endl << endl;


    cout << "SORTED BY EVALUATION: " << endl;

    athleteList.sortByEvaluation(0, count);

    cout << athleteList.toString() << endl << endl;

    cout << "SORTED BY POSITION" << endl;

    athleteList.sortByPosition(0, count);

    cout << athleteList.toString() << endl;




    return 0;
}