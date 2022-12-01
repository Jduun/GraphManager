#ifndef MENU
#define MENU
#include <any>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "../HelpFunctions.hpp"

class Menu
{
public:
    using vany = std::vector<std::any>;
    using func = std::function<void(vany)>;
    
    Menu(std::string label, func function);
    Menu(std::string label, std::vector<Menu> menus);
    Menu(std::string label, func function, vany params);
    Menu(std::string label, std::vector<Menu> menus, vany params);
    Menu(const Menu& menu);

    void run();
    void PrintMenu();

private:
    void run(vany params);

    std::string label{};
    func function{};
    std::vector<Menu> menus{};
    vany params{};
};
#endif