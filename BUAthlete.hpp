#include "NCAAAthlete.hpp"
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

