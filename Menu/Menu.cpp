#include "Menu.hpp"
#include <cstdlib>

Menu::Menu(std::string label, func function) :
    label(label), function(function) {}

Menu::Menu(std::string label, std::vector<Menu> menus) :
    label(label), menus(menus) {}

Menu::Menu(std::string label, func function, vany params) :
    label(label), function(function), params(params) {}

Menu::Menu(std::string label, std::vector<Menu> menus, vany params) :
    label(label), menus(menus), params(params) {}

Menu::Menu(const Menu& menu)
{
    label = menu.label;
    menus = menu.menus;
    function = menu.function;
    params = menu.params;
}

void Menu::run()
{
    run(params);
}

void Menu::run(vany _params)
{
    bool exit = false;
    while (!exit)
    {
        system("clear");
        PrintMenu();
        int select = -1;
        if (!function)
        {
            select = InputInt("Выбрать: ", 0, menus.size());
            select--;
            if (select == -1)
            {
                exit = true;
            }
            else
            {
                menus[select].run(params.empty() ? _params : params);
            }
        } 
        else 
        {
            function(params.empty() ? _params : params);
            getchar(); // задержка
            exit = true;
        }
    }
}

void Menu::PrintMenu()
{
    /*
    if (!function)
    {
        std::cout << "Меню: '" << label << "'\n";
    }
    for (size_t i = 0; i < menus.size(); i++) 
    {
        std::cout << i + 1 << ". " << menus[i].label << "\n";
    }
    if (!function)
    {
        std::cout << "0. Выйти из '" << label << "'\n";
    }
    */

    if (!function)
    {
        std::cout << "Меню: '" << label << "'\n";
        for (size_t i = 0; i < menus.size(); i++) 
        {
            std::cout << i + 1 << ". " << menus[i].label << "\n";
        }
        std::cout << "0. Выйти из '" << label << "'\n";
    }
}