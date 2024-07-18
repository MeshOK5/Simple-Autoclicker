#include <SFML/Graphics.hpp>
#include <windows.h>
#include <string>
#include <math.h>
#include "Colors.h"
#include "Button.h"
#include "ConvertFunc.h"
#include "Clicks.h"
#include "DelZeros.h"

#define _WIN32_WINNT 0x0500

using namespace std;
using namespace sf;
using namespace Colors;
using namespace Clicks;

int main()
{
    RenderWindow window(VideoMode(780, 420), "Autoclicker", Style::Close | Style::Titlebar);

    bool pressed = false;
    bool with_time = true;
    double time = 0.001;
    string time_str = to_string(time);
    Keyboard::Key key;

    Image icon;
    icon.loadFromFile("resources/mouse.png");
    window.setIcon(32, 32, icon.getPixelsPtr());

    Texture logo_texture;
	logo_texture.loadFromFile("resources/logo.png");
 
	Sprite logo_sprite;
	logo_sprite.setTexture(logo_texture);
	logo_sprite.setPosition(10, 20);

    Font font;
    font.loadFromFile("resources/font.ttf");

    Text info;
    info.setFont(font);
    info.setCharacterSize(50);
    info.setStyle(Text::Bold);
    info.setPosition(10, 320);

    Button button1;
    String tex = "> <";
    button1.create(200, 200, 300, 25, tex);
    button1.button_text.setFont(font);
    button1.button_shape.setOutlineThickness(5);
    button1.button_shape.setOutlineColor(color_for_button_text);

    Button button2;
    String tex2 = "> <";
    button2.create(200, 200, 550, 25, tex2);
    button2.button_text.setFont(font);
    button2.button_shape.setOutlineThickness(5);
    button2.button_shape.setOutlineColor(color_for_button_text);

    Button SpeedQuest;
    String tex3 = "Speed is on";
    SpeedQuest.create(80, 80, 10, 250, tex3);
    SpeedQuest.button_text.setCharacterSize(12);
    SpeedQuest.button_text.setFont(font);
    SpeedQuest.button_shape.setOutlineThickness(5);
    SpeedQuest.button_shape.setOutlineColor(color_for_button_text);

    Text speed;
    speed.setFont(font);
    speed.setString("Speed:");
    speed.setCharacterSize(30);
    speed.setStyle(Text::Bold);
    speed.setPosition(150, 230);
    speed.setFillColor(Color::Black);

    Text speed_info;
    speed_info.setFont(font);
    speed_info.setCharacterSize(20);
    speed_info.setStyle(Text::Bold);
    speed_info.setPosition(250, 235);
    speed_info.setFillColor(Color::Black);

    RectangleShape slider_part1(Vector2f(400, 5));
    slider_part1.setPosition(300, 250);
    slider_part1.setFillColor(Color::Black);

    RectangleShape slider_part2(Vector2f(10, 5));
    slider_part2.setPosition(300, 250);
    slider_part2.setFillColor(on);

    CircleShape slider_part3(7);
    slider_part3.setPosition(300, 245);
    slider_part3.setFillColor(on);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            
            if(event.type == Event::KeyPressed)
            {
                if(pressed == true)
                {
                    key = event.key.code;
                    button1.button_text.setString(Convert(key));
                    pressed = false;
                }
            }
        }
        if(Keyboard::isKeyPressed(key) && !pressed && type_click != ' ')
        {
            click ^= 1;
            Sleep(200);
        }
        
        HWND hWnd = GetConsoleWindow();
        ShowWindow(hWnd, SW_HIDE);

        Vector2i mouse_pos = Mouse::getPosition(window);
        if(button1.button_shape.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
        {
            if(Mouse::isButtonPressed(Mouse::Left))
            {
                button1.button_text.setString(" ");
                pressed = true;
            }
        }

        if(button2.button_shape.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
        {
            if(Mouse::isButtonPressed(Mouse::Left))
            {
                button2.button_text.setString("LMB");
                type_click = 'L';
            }
            else if(Mouse::isButtonPressed(Mouse::Right))
            {
                button2.button_text.setString("RMB");
                type_click = 'R';
            }
        }

        if(SpeedQuest.button_shape.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
        {
            if(Mouse::isButtonPressed(Mouse::Left))
            {
                with_time ^= 1;
                Sleep(200);
            }
        }

        if(slider_part1.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
        {
            if(Mouse::isButtonPressed(Mouse::Left))
            {
                slider_part3.setPosition(mouse_pos.x, 245);
                slider_part2.setSize(Vector2f(mouse_pos.x - 300, 5));
                time = slider_part3.getPosition().x / 30000;
                time_str = to_string(time);
            }
        }
        speed_info.setString(ZeroDel(time_str));

        if(with_time)
        {
            SpeedQuest.button_text.setFillColor(on);
            SpeedQuest.button_text.setString("Speed is on");
        }
        else
        {
            SpeedQuest.button_text.setFillColor(off);
            SpeedQuest.button_text.setString("Speed is off");
        }

        if(click)
        {
            info.setString("Autoclicker is on");
            info.setFillColor(on);

            switch (type_click)
            {
                case 'L':
                    Left_Click();
                    if(with_time)
                    {
                        Sleep(time * 1000);
                    }
                    break;
                case 'R':
                    Right_Click();
                    if(with_time)
                    {
                        Sleep(time * 1000);
                    }
                    break;

                default:
                    break;
            }
        }

        else
        {
            info.setString("Autoclicker is off");
            info.setFillColor(off);
        }

        window.clear(background);
        window.draw(button1.button_shape);
        window.draw(button1.button_text);
        window.draw(button2.button_shape);
        window.draw(button2.button_text);
        window.draw(logo_sprite);
        window.draw(slider_part1);
        window.draw(slider_part2);
        window.draw(slider_part3);
        window.draw(SpeedQuest.button_shape);
        window.draw(SpeedQuest.button_text);
        window.draw(speed);
        window.draw(speed_info);
        window.draw(info);
        window.display();
    }

    return 0;
}