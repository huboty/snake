#include <string>
#include "view.h"
#pragma once

class Game
{
private:
    std::string name_;
    Ui& ui_;
public:
    Game(std::string name, Ui& ui) : name_(name), ui_(ui){};
    std::string get_name();
    void change_name(std::string new_name);
    ~Game() {};
};
