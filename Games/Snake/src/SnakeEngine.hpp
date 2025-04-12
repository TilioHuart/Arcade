//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Snake
//

#pragma once

#include "AGame.hpp"
#include "Events.hpp"
#include "IArcade.hpp"
#include "Vector2.hpp"
#include <cstdint>
#include <vector>

namespace ANAL {

/**
 * @enum STATE
 * @brief Represents the different states a cell in the game map can hold.
 */
enum class STATE : std::uint8_t { EMPTY, FRUIT, SNAKE, HEAD };

/**
 * @enum DIRECTION
 * @brief Represents the possible movement directions of the snake.
 */
enum class DIRECTION : std::uint8_t { UP, DOWN, LEFT, RIGHT };

/**
 * @enum VICTORY
 * @brief Represents the possible victory states in the game.
 */
enum class VICTORY : std::uint8_t { YES, NO, UNDEFINED };

/**
 * @class SnakeEngine
 * @brief Implements the Snake game logic for the Arcade Native Agnostic Layer (ANAL) protocol.
 *
 * This class inherits from AGame and implements the core functionalities needed to run
 * the classic Snake game: processing events, computing game updates, and rendering the game state.
 */
class SnakeEngine : public ANAL::AGame {
   public:
    /**
     * @brief Constructor.
     *
     * Initializes the Snake game engine, sets up the initial game state,
     * creates the game map, and places the snake and fruit.
     */
    SnakeEngine();

    /**
     * @brief Destructor.
     *
     * Cleans up any resources and performs necessary shutdown procedures.
     */
    ~SnakeEngine() override;

    /**
     * @brief Processes user or system events.
     *
     * Updates the game state based on events, such as key presses or window events.
     *
     * @param Event A vector of ANAL::Event objects representing the current events to process.
     */
    void processEvents(std::vector<ANAL::Event> &Event) override;

    /**
     * @brief Computes the game logic.
     *
     * Updates the game state (e.g., snake movement, collision detection, fruit consumption)
     * based on the current state and the Arcade interface.
     *
     * @param arcade A reference to the IArcade interface for broader game interactions.
     */
    void compute(ANAL::IArcade &arcade) override;

    /**
     * @brief Renders the current game state.
     *
     * Draws the map, fruit, snake, and score using the provided renderer.
     *
     * @param renderer A reference to an IRenderer used to draw game elements.
     * @param arcade A reference to the IArcade interface for additional context during rendering.
     */
    void render(ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) override;

   private:
    std::vector<std::vector<STATE>> map;        ///< 2D vector representing the game map's state.
    std::vector<ANAL::Vector2<int>> snake;        ///< Vector storing the positions of the snake's segments.
    int fruitX;                                 ///< The X coordinate of the fruit.
    int fruitY;                                 ///< The Y coordinate of the fruit.
    int mapSize = 16;                           ///< The dimension of the game map (mapSize x mapSize).
    uint8_t fruitPos = 0;                       ///< Index or position identifier for the fruit (usage defined in-game logic).
    bool fruitEaten = true;                     ///< Flag indicating whether the fruit has been eaten.
    int previousX;                              ///< Previous X coordinate used in snake movement computations.
    int previousY;                              ///< Previous Y coordinate used in snake movement computations.
    DIRECTION snakeDirection = DIRECTION::RIGHT;///< Current movement direction of the snake.
    uint8_t snakeCompute = 0;                   ///< Counter used for controlling the snake's compute cycle.
    VICTORY gameState = VICTORY::UNDEFINED;      ///< Current victory state of the game.
    int score = 0;                              ///< The current score.

    /**
     * @brief Initializes the game map.
     *
     * Creates and initializes the 2D map grid with default states.
     */
    void createMap();

    /**
     * @brief Sets the initial position and state of the snake.
     *
     * Initializes the snake's segments and sets its starting position.
     */
    void setSnake();

    /**
     * @brief Places a new fruit on the game map.
     *
     * Randomly positions the fruit on the map if the previous fruit was eaten.
     */
    void setFruit();

    /**
     * @brief Renders the game map.
     *
     * Draws each cell of the map using the provided renderer.
     *
     * @param renderer A reference to an IRenderer used for drawing.
     * @param arcade A reference to the IArcade interface for additional rendering context.
     */
    void renderMap(ANAL::IRenderer &renderer, const ANAL::IArcade &arcade);

    /**
     * @brief Renders the fruit.
     *
     * Draws the fruit on the map using the provided renderer.
     *
     * @param renderer A reference to an IRenderer used for drawing.
     * @param arcade A reference to the IArcade interface for additional rendering context.
     */
    void renderFruit(ANAL::IRenderer &renderer, const ANAL::IArcade &arcade);

    /**
     * @brief Renders the snake.
     *
     * Draws the snake's segments on the map using the provided renderer.
     *
     * @param renderer A reference to an IRenderer used for drawing.
     * @param arcade A reference to the IArcade interface for additional rendering context.
     */
    void renderSnake(ANAL::IRenderer &renderer, const ANAL::IArcade &arcade);

    /**
     * @brief Renders the current score.
     *
     * Displays the score on the screen using the provided renderer.
     *
     * @param renderer A reference to an IRenderer used for drawing.
     * @param arcade A reference to the IArcade interface for additional rendering context.
     */
    void renderScore(ANAL::IRenderer &renderer, const ANAL::IArcade &arcade);

    /**
     * @brief Computes the snake's movement and game logic.
     *
     * Updates the snake's position and handles collisions, fruit consumption,
     * and other game state changes.
     */
    void computeSnake();

    /**
     * @brief Moves the snake to the right.
     */
    void moveRight();

    /**
     * @brief Moves the snake to the left.
     */
    void moveLeft();

    /**
     * @brief Moves the snake upwards.
     */
    void moveUp();

    /**
     * @brief Moves the snake downwards.
     */
    void moveDown();

    /**
     * @brief Resets the game state.
     *
     * Clears the map, resets the snake's position, score, and related parameters.
     */
    void resetGame();

    /**
     * @brief Checks for win conditions.
     *
     * Evaluates if the current game state meets the criteria for winning or ending the game.
     */
    void checkWinCondition();
};

}  // namespace ANAL
