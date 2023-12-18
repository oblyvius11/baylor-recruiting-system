//
// Created by aegra on 10/19/2023.
//

#include "proj5-BUAthleteList.hpp"
#include <iostream>

void BUAthleteList::resizeArray() {
    capacity += 2;
    BUAthlete* tmp = new BUAthlete[capacity];

    for (int i = 0; i < size; i++) {
        tmp[i] = list[i];
    }

    delete[] list;

    list = tmp;
}

void BUAthleteList::addNCAAAthlete(int ID, string name, string LOI, string school) {

    if (size == capacity) {
        resizeArray();
    }

    list[size].setID(ID);
    list[size].setName(name);
    list[size].setLOI(LOI);
    list[size].setSchool(school);

    size++;

}

void BUAthleteList::setBUInfo(int index, Position pos, int eval) {
    list[index].setPosition(pos);
    list[index].setEvaluation(eval);
}

int BUAthleteList::findBYId(int ID) {

    int left = 0;
    int right = size - 1;



    while (left <= right) {
        int mid = (left + right) / 2;
        int currID = list[mid].getID();

        if (currID == ID) {
            return mid;
        }
        else if (currID > ID) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

void BUAthleteList::sortByID(int left, int right) {

    if (left >= right) {
        return;
    }

    int piv = list[(left + right) / 2].getID();
    int a = left;
    int b = right - 1;


    while (a <= b) {
        while (list[a].getID() > piv) {
            a++;
        }
        while (list[b].getID() < piv) {
            b--;
        }
        if (a <= b) {
            swap(list[a], list[b]);
            a++;
            b--;
        }
    }
    sortByID(left, b + 1);
    sortByID(a, right);
}

void BUAthleteList::sortByPosition(int left, int right) {

    if (left >= right) {
        return;
    }

    int piv = list[(left + right) / 2].getPosition();
    int a = left;
    int b = right - 1;

    while (a <= b) {
        while (list[a].getPosition() < piv) {
            a++;
        }
        while (list[b].getPosition() > piv) {
            b--;
        }
        if (a <= b) {
            swap(list[a], list[b]);
            a++;
            b--;
        }
    }
    sortByPosition(left, b + 1);
    sortByPosition(a, right);
}

void BUAthleteList::sortByEvaluation(int left, int right) {

    if (left >= right) {
        return;
    }

    int piv = list[(left + right) / 2].getEvaluation();
    int a = left;
    int b = right - 1;

    while (a <= b) {
        while (list[a].getEvaluation() > piv) {
            a++;
        }
        while (list[b].getEvaluation() < piv) {
            b--;
        }
        if (a <= b) {
            swap(list[a], list[b]);
            a++;
            b--;
        }
    }
    sortByEvaluation(left, b + 1);
    sortByEvaluation(a, right);
}

BUAthlete& BUAthleteList::operator[](int ndx) {
    return list[ndx];
}

string BUAthleteList::toString() {
    ostringstream out;

    for (int i = 0; i < size; i++) {
        out << "[ " << i << " ]" << endl;
        out << "ID: " << list[i].getID() << endl;
        out << "Name: " << list[i].getName() << endl;

        out << "School: ";
        if (list[i].getLOI()) {
            out << list[i].getSchool() << endl;
        }
        else {
            out << "Available" << endl;
        }

        out << "Evaluation: " << list[i].getEvaluation() << endl;
        out << "Position: " << convertPostoStr(list[i].getPosition()) << endl;
        out.clear();
    }

    return out.str();
}

string convertPostoStr(Position a) {
    string result;
    if (a == OL) {
        result = "OL";
    }
    else if (a == QB) {
        result = "QB";
    }
    else if (a == RB) {
        result = "RB";
    }
    else if (a == WR) {
        result = "WR";
    }
    else if (a == TE) {
        result = "TE";
    }
    else if (a == DL) {
        result = "DL";
    }
    else if (a == DE) {
        result = "DE";
    }
    else if (a == LB) {
        result = "LB";
    }
    else if (a == CB) {
        result = "CB";
    }
    else if (a == S) {
        result = "S";
    }
    else {
        result = "K";
    }

    return result;

}


