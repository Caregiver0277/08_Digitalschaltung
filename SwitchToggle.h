#ifndef SWITCHTOGGLE_H
#define SWITCHTOGGLE_H

#include "Switch.h"
#include "TextBox.h"
#include <string>

class SwitchToggle : public Switch
{
private:
    TextBox* ToggleButton;
public:
    SwitchToggle(const SwitchToggle& source);
    SwitchToggle(const Point& pos, const std::string& ToggleButtonLabel = "1/0");
    ~SwitchToggle();

    void onMouse(const Point& p);
    void setPosition(const Point& p);
    SwitchToggle& operator=(const SwitchToggle& rhs);
    void show() const;
};

#endif // SWITCHTOGGLE_H
