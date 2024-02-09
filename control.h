#include <iostream>
#include <string>
#include "game.h"
#pragma once

class Control
{
private:
    void change_name();
    Game& game_;
public:
    Control(Game& game) : game_(game){};
    void run();
};