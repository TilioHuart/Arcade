//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// DlFunctions.hpp
//

#pragma once

#include "IRenderer.hpp"
#include <memory>
#include <string>

namespace Arcade {
    class DlUtils {
       public:
        class DlUtilsError : public std::exception {
           public:
            DlUtilsError(std::string msg);
            [[nodiscard]] const char *what() const noexcept override
            {
                return this->_msg.c_str();
            };
           private:
            std::string _msg;
        };

        void open(const std::string &pathToLib);
        void sym(const std::string &pathToLib);
        void close();

       private:
        void *_lib;
    };

}  // namespace Arcade
