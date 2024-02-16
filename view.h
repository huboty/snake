#include <iostream>
#include <string>
#include <sys/ioctl.h>
#pragma once

enum BRIGHTNESS
{
    bright,
    dull
};

enum COLOR
{
    white   = 0,
    red     = 31,
    green,
    yellow,
    blue,
    magenta,
    cyan
};

class Ui
{
private:
    static Ui* ui_;
public:
    static Ui* get(std::string type = "text");
    virtual void display_name(std::string name) = 0;
    virtual ~Ui();
};

class TextUi : public Ui
{
public:
    void display_name(std::string name);
    ~TextUi();
private:
    void goto_xy(int x, int y);
    void set_color(BRIGHTNESS brightness, COLOR color);
    void set_frame(char symbol, int height, int width);
    void puts(std::string string);
    void clr_screen();
};

class GraphicUi : public Ui
{
public:
    void display_name(std::string name);
    ~GraphicUi();
};