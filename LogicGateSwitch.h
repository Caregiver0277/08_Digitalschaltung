#ifndef LOGICGATESWITCH_H
#define LOGICGATESWITCH_H

#include "LogicGate.h"
#include "Switch.h"
#include "SwitchPulse.h"


#endif // LOGICGATESWITCH_H

class LogicGateSwitch : public LogicGate
{
public:
    LogicGateSwitch(const string& Label, const Point& Position, const string& ID, unsigned Type = 0, int Timing = 100);
    virtual ~LogicGateSwitch();
    void updateOutput();
    void onMouse(const Point& Where);
    void decorate();
    void clock();

protected:
    Switch* SwitchElement;

private:
    SwitchPulse* TimedSwitchElement;
};
