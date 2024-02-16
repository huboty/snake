#include "view.h"

Ui* Ui::ui_ = NULL;

Ui* Ui::get(std::string type)
{
    if (ui_ == NULL)
    {
        if (type == "text")
            ui_ = new TextUi;
        else if (type == "draw")
            ui_ = new GraphicUi;
        // handle other inputs later
    }
    return ui_;
}

Ui::~Ui() {}

void TextUi::display_name(std::string name)
{   
    struct winsize scr_size;
    ioctl(0, TIOCGWINSZ, &scr_size);
    set_color(bright, red);
    set_frame('=', scr_size.ws_row, scr_size.ws_col);
    goto_xy(1, (scr_size.ws_col - name.length())/2 + 1);
    puts(name);
    return;
}

void TextUi::goto_xy(int x, int y)
{
    std::cout << "\e[" << x << ";" << y << "H" << std::flush;
    return;
}

void TextUi::set_color(BRIGHTNESS brightness, COLOR color)
{
    std::cout << "\e[" << brightness << ";" << color << "m" << std::flush;
    return;
}

void TextUi::set_frame(char symbol, int height, int width)
{
    clr_screen();
    goto_xy(0, 0);
    for (int i = 0; i <= height; i++)
    {
        if (i == 0 || i == height)
        {
            for (int j = 0; j < width; j++)
                putchar(symbol);
        }
        else
        {
            putchar(symbol);
            goto_xy(i, width);
            putchar(symbol);
        }
    }
    return;
}

void TextUi::puts(std::string string)
{
    std::cout << string << std::endl;
    return;
}

void TextUi::clr_screen()
{
    std::cout << "\e[H\e[J" << std::endl;
    return;
}

TextUi::~TextUi()
{
    clr_screen();
    goto_xy(0, 0);
}

void GraphicUi::display_name(std::string name)
{
    return;
}

GraphicUi::~GraphicUi()
{
}