//
// EPITECH PROJECT, 2025
// main
// File description:
// main
//

#include "DlUtils.hpp"
#include "IModule.hpp"
#include "Vector2.hpp"
#include "utils.hpp"

int main(int argc, char **argv)
{
    if (argc != 2 || argv == nullptr || argv[1] == nullptr)
        return EPITECH_FAILURE;
    void *lib = Arcade::DlUtils::open(argv[1]);
    if (Arcade::DlUtils::getLibType(lib) == ANAL::ModuleType::RENDERER) {
        auto graphique = Arcade::DlUtils::loadDisplay(lib);
        ANAL::Vector2<int> pos(100, 100);
        while (true) {
            graphique->clear();
            graphique->drawText("Coucou", pos);
            graphique->render();
        }
    }
    Arcade::DlUtils::close(lib);
    return SUCCESS;
}
