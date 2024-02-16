#include "view.h"
#include "game.h"
#include "control.h"

int main()
{
    Ui* view = Ui::get();
    Game* snake = new Game("snake", *view);
    Control* keyboard = new Control(*snake);
    keyboard->run();
    delete view;
    delete snake;
    delete keyboard;
    return 0;
}