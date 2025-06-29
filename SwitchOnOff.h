#ifndef SWITCHONOFF_H
#define SWITCHONOFF_H

#include "Switch.h"
#include "TextBox.h"
#include <string>

class SwitchOnOff : public Switch
{
private:
    TextBox* OnButton;
    TextBox* OffButton;
public:
    SwitchOnOff(const SwitchOnOff& source);
    SwitchOnOff(const Point& pos, const std::string& OnButtonLabel = "1", const std::string& OffButtonLabel = "0");
    ~SwitchOnOff();

    void onMouse(const Point& p);
    void setPosition(const Point& p);
    SwitchOnOff& operator=(const SwitchOnOff& rhs);
    void show() const;
};

#endif // SWITCHONOFF_H
