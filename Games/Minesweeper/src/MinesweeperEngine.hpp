//
// EPITECH PROJECT, 2025
// Minesweeper Engine
// File description:
// Minesweeper Engine
//

#pragma once

#include "AGame.hpp"
#include "IArcade.hpp"
#include "IRenderer.hpp"
#include <chrono>
#include <cstdint>

namespace ANAL {

    /**
     * @enum Difficulty
     * @brief Enumerates the difficulty levels for the Minesweeper game.
     */
    enum class Difficulty : std::uint8_t { EASY, NORMAL, HARD };

    /**
     * @enum Case
     * @brief Enumerates the different states a cell in the Minesweeper grid can have.
     */
    enum class Case : std::uint8_t {
        EMPTY,
        NEAR1,
        NEAR2,
        NEAR3,
        NEAR4,
        NEAR5,
        NEAR6,
        NEAR7,
        NEAR8,
        MINE
    };

    /**
     * @enum Visibility
     * @brief Enumerates the visibility states for cells in the Minesweeper grid.
     */
    enum class Visibility : std::uint8_t { HIDDEN, VISIBLE, FLAG };

    /**
     * @brief Overloaded prefix increment operator for the Case enum.
     *
     * Increments the value of a Case enum. Mainly use to compute the number of
     * near mines.
     *
     * @param origine Reference to the Case to be incremented.
     * @return Reference to the incremented Case.
     */
    Case &operator++(Case &origine);

    /**
     * @class MinesweeperEngine
     * @brief Minesweeper game engine class.
     *
     * The MinesweeperEngine class implements the game logic for Minesweeper. It is responsible for
     * processing events, updating the game state (such as handling clicks and propagating empty cells),
     * and rendering the game via the provided rendering interface.
     */
    class MinesweeperEngine : public AGame {
       public:
        /**
         * @brief Constructs a new MinesweeperEngine object.
         *
         * Initializes the Minesweeper engine, sets up default parameters, and prepares the game map.
         */
        MinesweeperEngine();

        /**
         * @brief Processes input events.
         *
         * Handles player inputs such as left and right mouse clicks. The events are passed as a vector
         * and processed accordingly.
         *
         * @param Event A vector containing events to be processed.
         */
        ~MinesweeperEngine() override;

        /**
         * @brief Processes input events.
         *
         * Handles player inputs such as left and right mouse clicks. The events are passed as a vector
         * and processed accordingly.
         *
         * @param Event A vector containing events to be processed.
         */
        void processEvents(std::vector<Event> &Event) override;

        /**
         * @brief Updates the game state.
         *
         * Computes the current game state based on user actions and time progression. This includes
         * checking win or lose conditions and updating the score.
         *
         * @param arcade The arcade context containing information about the game environment.
         */
        void compute(IArcade &arcade) override;

        /**
         * @brief Renders the game.
         *
         * Renders the game on the screen using the provided rendering interface. This method calls various
         * private rendering functions to display the background, cells, and game status (win/lose).
         *
         * @param renderer The renderer interface used to display graphics.
         * @param arcade The arcade context with information necessary for rendering.
         */
        void render(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) override;

       private:
        /**
         * @brief Current game difficulty.
         */
        Difficulty _difficulty = Difficulty::EASY;

        /**
         * @brief Timestamp indicating the time left to complete the game.
         */
        std::chrono::time_point<std::chrono::steady_clock> _endTime;

        /**
         * @brief Current game score.
         */
        size_t _score = 0;

        /**
         * @brief Total number of mines in the game.
         */
        uint16_t _nbMine = 10;

        /**
         * @brief Number of mines still to be flagged.
         */
        uint16_t _nbMineLeft = 10;

        /**
         * @brief Number of flags placed by the player.
         */
        uint16_t _nbFlags = 0;

        /**
         * @brief Size of the game grid.
         */
        uint16_t _gridSize = 10;

        /**
         * @brief Indicates if the player has lost the game.
         */
        bool _hasLose = false;

        /**
         * @brief Indicates if the player has won the game.
         */
        bool _hasWin = false;

        /**
         * @brief Indicates if the mines are currently displayed.
         */
        bool _mineDisplayed = false;

        /**
         * @brief Flag to indicate the first click in the game.
         */
        bool _firstClick = true;

        /**
         * @brief Internal flag indicating if the time has been added to the score.
         */
        bool _added = false;
        /**
         * @brief The Minesweeper grid map containing the type of each cell.
         */
        std::vector<std::vector<ANAL::Case>> _map;
        /**
         * @brief Grid tracking the visibility state of each cell.
         */
        std::vector<std::vector<ANAL::Visibility>> _hidden;

        /**
         * @brief Handles the first left-click event.
         *
         * Performs actions unique to the first click (such as initializing the game map) when the player
         * performs a left-click.
         *
         * @param event The event representing the player's input.
         */
        void _clickLeftFirst(const Event &event);

        /**
         * @brief Handles subsequent left-click events.
         *
         * Processes left-click actions on the grid after the first click.
         *
         * @param event The event representing the player's input.
         */
        void _clickLeft(const Event &event);

        /**
         * @brief Handles right-click events.
         *
         * Processes right-click actions which typically involve flagging or unflagging a cell.
         *
         * @param event The event representing the player's input.
         */
        void _clickRight(const Event &event);

        /**
         * @brief Propagates the reveal of empty cells.
         *
         * Recursively reveals adjacent cells when an empty cell is clicked.
         *
         * @param xPos The x-coordinate of the starting cell.
         * @param yPos The y-coordinate of the starting cell.
         */
        void _propagateEmpty(int xPos, int yPos);

        /**
         * @brief Restarts the game.
         *
         * Resets all game parameters and creates a new game map.
         */
        void _restartGame();

        /**
         * @brief Increases the game difficulty.
         */
        void _changeDifficultyUp();

        /**
         * @brief Decreases the game difficulty.
         */
        void _changeDifficultyDown();

        /**
         * @brief Creates the game map.
         *
         * Sets up the Minesweeper grid, including the placement of mines and numbering of adjacent cells.
         */
        void _createMap();

        /**
         * @brief Creates an easy difficulty map.
         */
        void _createEasyMap();

        /**
         * @brief Creates an normal difficulty map.
         */
        void _createNormalMap();

        /**
         * @brief Creates an hard difficulty map.
         */
        void _createHardMap();

        /**
         * @brief Places mines on the game map.
         */
        void _placeMines();

        /**
         * @brief Sets the numbers of neighboring mines for each cell.
         *
         * Determines and assigns the number of adjacent mines for each non-mine cell.
         */
        void _setNeighbors();

        /**
         * @brief Initializes the hidden grid.
         *
         * Sets the initial visibility state for each cell in the game grid.
         */
        void _createHidden();

        /**
         * @brief Checks if the win condition is met.
         *
         * Evaluates the current game state to determine if the player has won.
         */
        void _checkWin();

        /**
         * @brief Renders the game background.
         *
         * Draws the background elements of the game area.
         *
         * @param renderer The renderer interface used to display graphics.
         * @param arcade The arcade context containing display details.
         */
        void _renderBackground(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) const;

        /**
         * @brief Renders the grid cells.
         *
         * Displays each cell of the Minesweeper grid, including numbers and mine indications.
         *
         * @param renderer The renderer interface used to display graphics.
         * @param arcade The arcade context containing display details.
         */
        void _renderCases(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) const;

        /**
         * @brief Renders additional game elements.
         *
         * Displays extra information such as the score or timer on the screen.
         *
         * @param renderer The renderer interface used to display graphics.
         */
        void _renderAth(ANAL::IRenderer &renderer);

        /**
         * @brief Displays a cell in its hidden state.
         *
         * Renders a cell that has not yet been revealed.
         *
         * @param renderer The renderer interface used to display graphics.
         * @param arcade The arcade context containing display details.
         * @param i The row index of the cell.
         * @param j The column index of the cell.
         */
        void _displayHidden(ANAL::IRenderer &renderer,
            const ANAL::IArcade &arcade, size_t i, size_t j) const;

        /**
         * @brief Displays a cell in its visible state.
         *
         * Renders a cell that has been revealed to the player.
         *
         * @param renderer The renderer interface used to display graphics.
         * @param arcade The arcade context containing display details.
         * @param i The row index of the cell.
         * @param j The column index of the cell.
         */
        void _displayVisible(ANAL::IRenderer &renderer,
            const ANAL::IArcade &arcade, size_t i, size_t j) const;

        /**
         * @brief Displays a flagged cell.
         *
         * Renders a cell that has been marked with a flag by the player.
         *
         * @param renderer The renderer interface used to display graphics.
         * @param arcade The arcade context containing display details.
         * @param i The row index of the cell.
         * @param j The column index of the cell.
         */
        void _displayFlag(ANAL::IRenderer &renderer,
            const ANAL::IArcade &arcade, size_t i, size_t j) const;

        /**
         * @brief Reveals and renders all mines on the grid.
         *
         * Displays every mine in the grid, typically when the game is lost.
         *
         * @param renderer The renderer interface used to display graphics.
         * @param arcade The arcade context containing display details.
         */
        void _displayMines(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade);

        /**
         * @brief Displays the loss screen.
         *
         * Renders the game over screen when the player loses.
         *
         * @param renderer The renderer interface used to display graphics.
         * @param arcade The arcade context containing display details.
         */
        void _displayLose(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade);

        /**
         * @brief Displays the win screen.
         *
         * Renders the game over screen when the player wins.
         *
         * @param renderer The renderer interface used to display graphics.
         * @param arcade The arcade context containing display details.
         */
        void _displayWin(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade);
    };
}  // namespace ANAL
