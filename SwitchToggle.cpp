#include "SwitchToggle.h"

SwitchToggle::SwitchToggle(const Point& pos, const std::string& ToggleButtonLabel) : Switch(pos)
{
    ToggleButton = new TextBox(Point(pos.X + 3, pos.Y + 3), Point(63,30), ToggleButtonLabel);
}

SwitchToggle::SwitchToggle(const SwitchToggle& source) : Switch(source)
{
    ToggleButton = new TextBox(*source.ToggleButton);
}

SwitchToggle::~SwitchToggle()
{
    delete ToggleButton;
}

void SwitchToggle::onMouse(const Point& p)
{
    if(ToggleButton->contains(p))
    {
        setState(!getState());
    }
}

void SwitchToggle::setPosition(const Point& p)
{
    Switch::setPosition(p);
    ToggleButton->setPosition(Point(p.X + 3, p.Y + 3));
}

SwitchToggle& SwitchToggle::operator=(const SwitchToggle& rhs)
{
    if(this != &rhs)
    {
        Switch::operator=(rhs);
        delete ToggleButton;
        ToggleButton = new TextBox(*rhs.ToggleButton);
    }
    return *this;
}

void SwitchToggle::show() const
{
    Switch::show();
    ToggleButton->show();
}

