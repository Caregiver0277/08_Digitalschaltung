#include "ColorBox.h"

ColorBox::ColorBox(const Point& position, const Point& Ssize, const RGBColor& color)
    :Position(position), Size(Ssize), Color(color)
{
}


Point ColorBox::getPosition() const
{
    return Position;
}

void ColorBox::setPosition(const Point& p)
{
    Position = p;
}

Point ColorBox::getSize() const
{
    return Size;
}

void ColorBox::setSize(const Point& s)
{
    Size = s;
}

RGBColor ColorBox::getColor() const
{
    return Color;
}

void ColorBox::setColor(const RGBColor& c)
{
    Color = c;
}

void ColorBox::show() const
{
    FillCol(Color.R, Color.G, Color.B);
    Rect(Position.X, Position.Y, (Position.X + Size.X), (Position.Y + Size.Y));
    FillCol(-1, -1, -1);
}

bool ColorBox::contains(const Point& p) const
{
    return (p.X >= Position.X && p.Y >= Position.Y &&
            p.X <= Position.X + Size.X && p.Y <= Position.Y + Size.Y);
}
