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
#include <cstddef>
#include <cstring>
#include <exception>
#include <iostream>
#include <ostream>

static int checkEnv(char **env)
{
    size_t envChecker = 0;
    if (env == nullptr)
        return FAILURE;
    for (int i = 0; env[i] != nullptr; i += 1) {
        if (strncmp(env[i], "DISPLAY=", 8) == 0)
            envChecker += 1;
        if (strncmp(env[i], "TERM=", 5) == 0)
            envChecker += 1;
    }
    if (envChecker < 2)
        return FAILURE;
    return SUCCESS;
}

int runApp(const char *lib, char **env)
{
    if (checkEnv(env) == FAILURE)
        return EPITECH_FAILURE;
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
    } catch (std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EPITECH_FAILURE;
    }
    return EPITECH_SUCCESS;
}
