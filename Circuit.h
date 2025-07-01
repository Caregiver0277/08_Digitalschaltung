#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
using std::vector;
#include <string>
using std::string;
#include "Point.h"


class LogicGate;
class LogicGateSwitch;

class Circuit
{
public:
    Circuit(double CrystalFrequency);
    ~Circuit();

    void addGate(LogicGate* NewGate);
    void addSwitch(LogicGateSwitch* NewSwitch);
    void onMouse(const Point& where);
    void clock();
    void show();

    LogicGate& operator[](const unsigned Index) const;
    LogicGate& operator[](const string& ID) const;

private:
    double CrystalFrequency;

    vector<LogicGate*> Gates;
    vector<LogicGateSwitch*> Switches;
};


#endif // CIRCUIT_H
