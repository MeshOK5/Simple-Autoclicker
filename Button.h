#include <SFML/Graphics.hpp>
#include "Colors.h"

using namespace sf;
using namespace Colors;
#pragma once

class Button
{
public:
    Text button_text;
    RectangleShape button_shape;

    void create(int width, int height, int x, int y, String str)
    {
        button_shape.setSize(Vector2f(height, width));
        button_shape.setPosition(x, y);
        button_shape.setFillColor(color_for_button);
        button_text.setPosition(x, y);
        button_text.setString(str);
        button_text.setCharacterSize(width / str.getSize());
        button_text.setStyle(Text::Bold);
        button_text.setFillColor(color_for_button_text);
    }
};