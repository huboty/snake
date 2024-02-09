#include "view.h"
#include "game.h"
#include "control.h"

int main()
{
    Ui view;
    Game snake("snake", view);
    Control keyboard(snake);
    keyboard.run();
    return 0;
}