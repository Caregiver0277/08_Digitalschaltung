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
        SwitchElement = new SwitchOnOff(Point(Position.X+70, Position.Y+3));
    }

    else if (Type == 1)
    {
        SwitchElement = new SwitchToggle(Point(Position.X+70, Position.Y+3));
    }

    else if (Type == 2)
    {
        auto* ptr2 = new SwitchPulse(Point(Position.X+70, Position.Y+3));
        SwitchElement = ptr2;
        TimedSwitchElement = ptr2;
    }

    Point size = SwitchElement->getSize();
    setSize(Point(size.X + 73, size.Y + 6));

}

LogicGateSwitch::~LogicGateSwitch()
{
  delete SwitchElement;
}

void LogicGateSwitch::updateOutput()
{

}


void LogicGateSwitch::onMouse(const Point& Where)
{
    SwitchElement->onMouse(Where);
    setOutput(SwitchElement->getState());

}


void LogicGateSwitch::decorate() const
{
    SwitchElement->show();
}


void LogicGateSwitch::clock()
{
    if(TimedSwitchElement != nullptr)
    {
        TimedSwitchElement->onTimerTick();
        setOutput(SwitchElement->getState());
    }
}



