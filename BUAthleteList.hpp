
#include "BUAthlete.hpp"

class BUAthleteList : public BUAthlete {
private:
    int capacity = 2;
    int size = 0;
    BUAthlete* list = new BUAthlete[2];
    void resizeArray();

public:
    ~BUAthleteList() {
        delete[] list;
    }
    void addNCAAAthlete(int ID, string name, string LOI, string school);
    void setBUInfo(int index, Position pos, int eval);
    int findBYId(int ID);
    void sortByID(int left, int right);
    void sortByPosition(int left, int right);
    void sortByEvaluation(int left, int right);
    BUAthlete& operator[](int ndx);
    string toString();

};

string convertPostoStr(Position a);


