#include "TextBox.h"

TextBox::TextBox(const Point& position, const Point& Size, const std::string& text)
: ColorBox(position, Size, RGBColor(255, 255, 255)), Text(text)
{
}

std::string TextBox::getText() const
{
    return Text;
}

void TextBox::setText(const std::string& text)
{
    Text = text;
}

void TextBox::show() const
{
    ColorBox::show();
    ::Text(Position.X+5, Position.Y+5, Text.c_str());
}
