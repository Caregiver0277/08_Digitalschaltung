#include "SwitchPulse.h"

SwitchPulse::SwitchPulse(const Point& pos, const std::string& ButtonLabel, int DecayTime)
:Switch(pos), PulseButton(new TextBox(Point(pos.X + 3, pos.Y + 3), Point(63,30), ButtonLabel)), DecayTime(DecayTime), CurrentTime(0)
{
}

SwitchPulse::~SwitchPulse()
{
    delete PulseButton;
}

void SwitchPulse::onMouse(const Point& p)
{
    if(PulseButton->contains(p))
    {
        setState(true);
        CurrentTime = DecayTime;
    }
}

void SwitchPulse::setPosition(const Point& p)
{
    Switch::setPosition(p);
    PulseButton->setPosition(Point(p.X + 3, p.Y + 3));
}

void SwitchPulse::onTimerTick()
{
    if(CurrentTime > 0)
    {
        --CurrentTime;
        if(CurrentTime <= 0)
            setState(false);
    }
}

SwitchPulse& SwitchPulse::operator=(const SwitchPulse& rhs)
{
    if(this != &rhs)
    {
        Switch::operator=(rhs);
        delete PulseButton;
        PulseButton = new TextBox(*rhs.PulseButton);
        DecayTime = rhs.DecayTime;
        CurrentTime = rhs.CurrentTime;
    }
    return *this;
}

void SwitchPulse::show() const
{
    Switch::show();
    PulseButton->show();
}

