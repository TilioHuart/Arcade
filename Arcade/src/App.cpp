//
// EPITECH PROJECT, 2025
// App
// File description:
// App
//

#include "Arcade.hpp"
#include "IGame.hpp"
#include "src/DlUtils.hpp"
#include "src/Menu.hpp"
#include "src/utils.hpp"
#include <iostream>

int runApp(const char *lib)
{
    try {
        Arcade::Arcade arcade(lib);
        std::unique_ptr<ANAL::IGame> menu = std::make_unique<Arcade::MenuEngine>();
        
        arcade.setGame(menu);
        arcade.run();
    } catch (const Arcade::DlUtils::DlUtilsError &error) {
        std::cerr << "Dlutils error: " << error.what() << std::endl;
        return EPITECH_FAILURE;
    } catch (const Arcade::Arcade::ArcadeError &error) {
        std::cerr << "Arcade error: " << error.what() << std::endl;
        return EPITECH_FAILURE;
    }
    return EPITECH_SUCCESS;
}
