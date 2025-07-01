#ifndef LOGICGATESWITCH_H
#define LOGICGATESWITCH_H

#include "LogicGate.h"
#include "Switch.h"
#include "SwitchPulse.h"




class LogicGateSwitch : public LogicGate
{
public:
    LogicGateSwitch(const string& Label, const Point& Position, const string& ID, unsigned Type = 0, int Timing = 100);
    virtual ~LogicGateSwitch();

    void updateOutput() override;
    void onMouse(const Point& Where);
    void decorate() const override;
    void clock();

protected:
    Switch* SwitchElement;

private:
    SwitchPulse* TimedSwitchElement;
};

#endif // LOGICGATESWITCH_H
