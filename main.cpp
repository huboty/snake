#include "view.h"
#include "game.h"
#include "control.h"

int main()
{
    Ui* view = Ui::get();
    Game snake("snake", *view);
    Control keyboard(snake);
    keyboard.run();
    view->~Ui();
    return 0;
}