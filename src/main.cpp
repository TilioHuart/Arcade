//
// EPITECH PROJECT, 2025
// main
// File description:
// main
//

#include "arcade.hpp"
#include "utils.hpp"

int main(int argc, char **argv)
{
    if (argc != 2 || argv == nullptr || argv[1] == nullptr)
        return EPITECH_FAILURE;
    return executeArcade(argv[1]);
}
