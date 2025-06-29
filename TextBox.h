#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "ColorBox.h"
#include <string>

class TextBox : public ColorBox
{
private:
    std::string Text;
public:
    TextBox(const Point& Position, const Point& Size, const std::string& Text);

    std::string getText() const;
    void setText(const std::string& Text);
    void show() const;
};

#endif // TEXTBOX_H
