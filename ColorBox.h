#ifndef COLORBOX_H
#define COLORBOX_H

#include "Point.h"
#include "RGBColor.h"
#include "WinAdapt.h"

class ColorBox
{
protected:
    Point Position;   // oben links ecke
    Point Size;       // breite höhe
    RGBColor Color;   // Farbe
public:
    ColorBox(const Point& position, const Point& Ssize, const RGBColor& color);

    Point getPosition() const;
    void setPosition(const Point& p);

    Point getSize() const;
    void setSize(const Point& s);

    RGBColor getColor() const;
    void setColor(const RGBColor& c);

    void show() const;
    bool contains(const Point& p) const;
};

#endif // COLORBOX_H
