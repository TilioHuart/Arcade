//
// EPITECH PROJECT, 2025
// main
// File description:
// main
//

#include "App.hpp"
#include "utils.hpp"

int main(int argc, char **argv, char **env)
{
    if (argc != 2 || argv == nullptr || argv[1] == nullptr)
        return EPITECH_FAILURE;
    return runApp(argv[1], env);
}
