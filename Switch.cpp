#include "Switch.h"

Switch::Switch()
:ColorBox(Point(0,0), Point(102,36), RGBColor(20,200,200)),
State(false), Indicator(new ColorBox(Point(69,3), Point(30,30), RGBColor(255,0,0)))
{
    setPosition(Point(0,0));
}

Switch::Switch(const Point& Position)
:ColorBox(Position, Point(102,36), RGBColor(200,200,200)), State(false),
Indicator(new ColorBox(Point(Position.X + 102 - 30 - 3, Position.Y + 3), Point(30,30), RGBColor(255,0,0)))
{
}

Switch::Switch(const Switch& Source)
:ColorBox(Source), State(Source.State), Indicator(new ColorBox(*Source.Indicator))
{
}

Switch::~Switch()
{
    delete Indicator;
}

void Switch::onMouse(const Point&)
{
}

void Switch::setPosition(const Point& position)
{
    ColorBox::setPosition(position);
    Indicator->setPosition(Point(position.X + Size.X - 30 - 3, position.Y + 3));
}

bool Switch::getState() const
{
    return State;
}

void Switch::setState(bool state)
{
    State = state;
    if(State)
        Indicator->setColor(RGBColor(0,255,0));
    else
        Indicator->setColor(RGBColor(255,0,0));
}

Switch& Switch::operator=(const Switch& rhs)
{
    if(this != &rhs)
    {
        Position = rhs.Position;
        Size = rhs.Size;
        Color = rhs.Color;
        State = rhs.State;
        delete Indicator;
        Indicator = new ColorBox(*rhs.Indicator);
    }
    return *this;
}

void Switch::show() const
{
    ColorBox::show();
    Indicator->show();
}

