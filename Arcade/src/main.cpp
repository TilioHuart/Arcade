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
int runApp(const char *lib);

int main(int argc, char **argv)
{
    if (argc != 2 || argv == nullptr || argv[1] == nullptr)
        return EPITECH_FAILURE;
    return runApp(argv[1]);
}
