#include "testlevel.h"
#include "LogicGateSwitch.h"
#include "SwitchOnOff.h"
#include "SwitchToggle.h"
#include "SwitchPulse.h"
#include "LogicExceptions.h"
using std::string;



LogicGateSwitch::LogicGateSwitch(const string& Label, const Point& Position, const string& ID, unsigned Type, int Timing)
:LogicGate(Label, Position, ID)
{
    TimedSwitchElement = nullptr;

    if (Type == 0)
    {
        SwitchOnOff* ptr0 = new SwitchOnOff(Point(Position.X+70, Position.Y+3));
        SwitchElement = ptr0;
    }

    else if (Type == 1)
    {
        SwitchToggle* ptr1 = new SwitchToggle(Point(Position.X+70, Position.Y+3));
        SwitchElement = ptr1;
    }

    else if (Type == 2)
    {
        SwitchPulse* ptr2 = new SwitchPulse(Point(Position.X+70, Position.Y+3));
        SwitchElement = ptr2;
        TimedSwitchElement = ptr2;
    }

    Point poi = SwitchElement->getSize();
    this->Position = Point(poi.X+6, poi.Y+73);
}

LogicGateSwitch::~LogicGateSwitch()
{
    if (SwitchElement!=nullptr) delete SwitchElement;
}

void LogicGateSwitch::updateOutput()
{

}


void LogicGateSwitch::onMouse(const Point& Where)
{
    SwitchElement->onMouse(Where);
    setOutput(SwitchElement->getState());

}


void LogicGateSwitch::decorate()
{
    SwitchElement->show();
}


void LogicGateSwitch::clock()
{
    TimedSwitchElement->onTimerTick();
}



