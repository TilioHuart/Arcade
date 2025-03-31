//
// EPITECH PROJECT, 2025
// Case
// File description:
// Case
//

#include "MinesweeperEngine.hpp"

ANAL::Case &ANAL::operator++(ANAL::Case &origine)
{
    switch (origine) {
        case ANAL::Case::EMPTY:
            origine = ANAL::Case::NEAR1;
            break;
        case ANAL::Case::NEAR1:
            origine = ANAL::Case::NEAR2;
            break;
        case ANAL::Case::NEAR2:
            origine = ANAL::Case::NEAR3;
            break;
        case ANAL::Case::NEAR3:
            origine = ANAL::Case::NEAR4;
            break;
        case ANAL::Case::NEAR4:
            origine = ANAL::Case::NEAR5;
            break;
        case ANAL::Case::NEAR5:
            origine = ANAL::Case::NEAR6;
            break;
        case ANAL::Case::NEAR6:
            origine = ANAL::Case::NEAR7;
            break;
        case ANAL::Case::NEAR7:
            origine = ANAL::Case::NEAR8;
            break;
        default:
            break;
    }
    return origine;
}
