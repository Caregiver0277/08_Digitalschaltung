#include "SwitchOnOff.h"

SwitchOnOff::SwitchOnOff(const Point& pos, const std::string& OnButtonLabel, const std::string& OffButtonLabel) : Switch(pos)
{
    OnButton = new TextBox(Point(pos.X + 3, pos.Y + 3), Point(30,30), OnButtonLabel);
    OffButton = new TextBox(Point(pos.X + 36, pos.Y + 3), Point(30,30), OffButtonLabel);
}

SwitchOnOff::SwitchOnOff(const SwitchOnOff& source) : Switch(source)
{
    OnButton = new TextBox(*source.OnButton);
    OffButton = new TextBox(*source.OffButton);
}

SwitchOnOff::~SwitchOnOff()
{
    delete OnButton;
    delete OffButton;
}

void SwitchOnOff::onMouse(const Point& p)
{
    if(OnButton->contains(p))
    {
        setState(true);
    }
    else if(OffButton->contains(p))
    {
        setState(false);
    }
}

void SwitchOnOff::setPosition(const Point& p)
{
    Switch::setPosition(p);
    OnButton->setPosition(Point(p.X + 3, p.Y + 3));
    OffButton->setPosition(Point(p.X + 36, p.Y + 3));
}

SwitchOnOff& SwitchOnOff::operator=(const SwitchOnOff& rhs)
{
    if(this != &rhs)
    {
        Switch::operator=(rhs);
        delete OnButton;
        delete OffButton;
        OnButton = new TextBox(*rhs.OnButton);
        OffButton = new TextBox(*rhs.OffButton);
    }
    return *this;
}

void SwitchOnOff::show() const
{
    Switch::show();
    OnButton->show();
    OffButton->show();
}

