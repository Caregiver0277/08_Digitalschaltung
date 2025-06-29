#ifndef SWITCHPULSE_H
#define SWITCHPULSE_H

#include "Switch.h"
#include "TextBox.h"
#include <string>

class SwitchPulse : public Switch
{
private:
    TextBox* PulseButton;
    int DecayTime;
    int CurrentTime;
public:
    SwitchPulse(const SwitchPulse& source);
    SwitchPulse(const Point& pos, const std::string& ButtonLabel = "Press", int DecayTime = 10);
    ~SwitchPulse();

    void onMouse(const Point& p);
    void setPosition(const Point& p);
    void onTimerTick();
    SwitchPulse& operator=(const SwitchPulse& rhs);
    void show() const;
};

#endif // SWITCHPULSE_H
