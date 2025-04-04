//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Arcade
//

#pragma once

#include "IArcade.hpp"
#include "IAsset.hpp"
#include "IEntity.hpp"
#include "IGame.hpp"
#include "IRenderer.hpp"
#include <string>
#include <utility>
#include <vector>

namespace Arcade {
    class Arcade : public ANAL::IArcade {
       public:
        Arcade() = default;
        ~Arcade() = default;

        class ArcadeError : public std::exception {
           public:
            ArcadeError(std::string msg): _msg(std::move(msg)) {};

            [[nodiscard]] const char *what() const noexcept override
            {
                return this->_msg.c_str();
            };

           private:
            std::string _msg;
        };

        void setGame(std::unique_ptr<ANAL::IGame> &);
        void setDisplay(std::unique_ptr<ANAL::IRenderer> &);
        void run();

        [[nodiscard]] std::unique_ptr<ANAL::IAsset> newAsset() const final;
        [[nodiscard]] std::unique_ptr<ANAL::IEntity> newEntity() const final;

       private:
        bool _isRunning = true;
        std::unique_ptr<ANAL::IGame> _runningGame;
        std::unique_ptr<ANAL::IRenderer> _runningDisplay;
        std::vector<std::string> gameLibList;
        std::vector<std::string> displayLibList;
    };
}  // namespace Arcade
