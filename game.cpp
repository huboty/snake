#include "game.h"

std::string Game::get_name()
{
    return name_;
}

void Game::change_name(std::string new_name)
{
    name_ = new_name;
    ui_.display_name(name_);
    return;
}