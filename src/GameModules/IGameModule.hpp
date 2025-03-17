//
// EPITECH PROJECT, 2025
// IGameEngine
// File description:
// IGameEngine
//

#pragma once

#include <vector>

namespace anal {
enum class Event;
class IGameModule
{
   public:
    virtual ~IGameModule() = default;
    virtual void processEvent(std::vector<Event>) = 0;
    virtual void compute() = 0;
    virtual void render() = 0;
};
}  // namespace anal
