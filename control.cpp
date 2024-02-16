#include "control.h"

void Control::run()
{
    std::string command;
    do 
    {
        std::cin >> command;
        if (command == "write")
            change_name();
    } while (command != "end");
    
    return;
}

void Control::change_name()
{
    std::string new_name;
    std::cin >> new_name;
    game_.change_name(new_name);
    return;
}