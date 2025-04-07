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
    Arcade::Arcade arcade;

    try {
        void *loadedLib = Arcade::DlUtils::open(lib);
        auto graphical = Arcade::DlUtils::loadDisplay(loadedLib);
        // std::unique_ptr<ANAL::IGame> menu = std::make_unique<Arcade::MenuEngine>();
        void *loadedGame = Arcade::DlUtils::open("lib/arcade_minesweeper.so");
        auto game = Arcade::DlUtils::loadGame(loadedGame);
        
        arcade.setDisplay(graphical);
        arcade.setGame(game);
        arcade.run();
        Arcade::DlUtils::close(loadedLib);
    } catch (const Arcade::DlUtils::DlUtilsError &error) {
        std::cerr << "Dlutils error: " << error.what() << std::endl;
        return EPITECH_FAILURE;
    } catch (const Arcade::Arcade::ArcadeError &error) {
        std::cerr << "Arcade error: " << error.what() << std::endl;
        return EPITECH_FAILURE;
    }
    return EPITECH_SUCCESS;
}
