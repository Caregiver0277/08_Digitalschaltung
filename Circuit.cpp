#include "testlevel.h"
#include "Circuit.h"
#include "Oscillator.h"
#include "LogicGateSwitch.h"
#include "LogicExceptions.h"





Circuit::Circuit(double CrystalFrequency):CrystalFrequency(CrystalFrequency)
{
    Gates = {0};
    Switches = {0};
}

Circuit::~Circuit()
{
    while (Gates.empty() != 0)
    {
        delete Gates.back();
        Gates.pop_back();
    }
}

    void Circuit::addGate(LogicGate* NewGate)
    {
        Gates.push_back(NewGate);
    }

    void Circuit::addSwitch(LogicGateSwitch* NewSwitch)
    {
        Gates.push_back(NewSwitch);
        Switches.push_back(NewSwitch);
    }

    void Circuit::onMouse(const Point& where)
    {
        for (unsigned i=0; i<=Switches.size(); i++)
        {
            Switches[i]->onMouse(where);
        }
    }

    void Circuit::clock()
    {
        for (unsigned i=0; i<=Switches.size(); i++)
        {
            Switches[i]->clock();
        }
    }

    void Circuit::show()
    {
        for (unsigned i=0; i<=Gates.size(); i++)
        {
            Gates[i]->show();
        }
    }

    LogicGate& Circuit::operator[](const unsigned Index) const
    {
        return *Gates[Index];
    }

    LogicGate& Circuit::operator[](const string& ID) const
    {
        for (unsigned i=0; i<=Gates.size(); i++)
        {
            if (Gates[i]->getID() == ID) return *Gates[i];
            else continue;
        }
        throw ExceptionUnknownLogicGateID();
    }


/*
private:
    double CrystalFrequency;

    vector<LogicGate*> Gates;
    vector<LogicGateSwitch*> Switches;

*/
