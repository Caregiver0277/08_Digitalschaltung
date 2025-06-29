#ifndef SWITCH_H
#define SWITCH_H

#include "ColorBox.h"

class Switch : public ColorBox
{
protected:
    bool State;
    ColorBox* Indicator;
public:
    Switch();
    Switch(const Point& Position);
    Switch(const Switch& Source);
    virtual ~Switch();

    virtual void onMouse(const Point& Position);
    virtual void setPosition(const Point& Position);
    bool getState() const;
    void setState(bool State);
    Switch& operator=(const Switch& rhs);
    virtual void show() const;
};

#endif // SWITCH_H
