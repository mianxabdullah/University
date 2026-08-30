# 🎮 Tic Tac Toe Game

A C++ implementation of the classic Tic Tac Toe game with multiple game modes and AI opponents featuring different difficulty levels.

## ✨ Features

- **🕹️ Multiple Game Modes:**
  - 👥 Human vs. Human
  - 🤖 Human vs. Nonsense Computer (random moves)
  - 🧠 Human vs. Sensible Computer (intelligent AI)
  - 🤖🆚🧠 Nonsense Computer vs. Sensible Computer (AI vs. AI)

- **🧠 Intelligent AI Opponent:**
  - **Sensible Computer Player**: Uses strategic logic to:
    - 🏆 Win when it has the opportunity
    - 🛡️ Block opponent's winning moves
    - 📊 Play strategically for future wins
    - 📋 Fill empty cells when no strategic moves available

- **🎯 Interactive Gameplay:**
  - ✏️ Choose marks (X or O) for players
  - 🪙 Random coin toss to determine who starts first
  - 📋 Visual board representation for easy tracking
  - 🔄 Play multiple games consecutively

## ⚙️ Requirements

- 💻 C++ compiler (C++11 or later)
- 📚 Standard C++ libraries

## 🔧 Compilation

```bash
g++ -o tictactoe tictactoe.cpp
```

or with other compilers:

```bash
clang++ -o tictactoe tictactoe.cpp
```

## ▶️ Usage

Run the compiled executable:

```bash
./tictactoe
```

or on Windows:

```bash
tictactoe.exe
```

### 📋 Game Instructions

1. **Select Game Mode**: Choose one of four game modes at the start
2. **Enter Mark**: Choose 'X' or 'O' for Player 1
3. **Place Marks**: Enter the cell number (1-9) where you want to place your mark:
   ```
   1 | 2 | 3
   4 | 5 | 6
   7 | 8 | 9
   ```
4. **Win Condition**: Get three marks in a row (horizontal, vertical, or diagonal)
5. **Play Again**: Decide whether to play another round after the game ends

## 🏗️ Class Architecture

### 🎭 `Player` (Abstract Base Class)
- Base class for all player types
- Manages player marks and moves

### 👤 `HPlayer` (Human Player)
- Inherits from `Player`
- Allows human input for move selection

### 🤖 `NonsenseComputerPlayer` (Random AI)
- Inherits from `Player`
- Makes random moves (1-9)

### 🧠 `SensibleComputerPlayer` (Intelligent AI)
- Inherits from `Player`
- Implements strategic gameplay with methods:
  - 🏆 `WinBlock()`: Completes a winning line when possible
  - 🛡️ `DefBlock()`: Blocks opponent's winning moves
  - 📊 `BestMove()`: Plays strategically for future wins
  - 📋 `EmptyCell()`: Fills any available cell

### 📋 `Board`
- Manages the game board state
- Validates and applies player moves
- Displays the board

### 🎮 `Game`
- Controls game flow and logic
- Manages win condition checking
- Handles game mode selection
- Implements the main game loop

## 🎲 Game Logic

- **🏆 Win Detection**: Checks rows, columns, and diagonals for three consecutive marks
- **🤝 Draw Detection**: Game ends when board is full with no winner
- **✅ Move Validation**: Only allows placement in empty cells with valid indices
- **🔄 Turn Management**: Alternates between players automatically

## 📌 Example Gameplay

```
Select game mode (1-3)
Choose mark for Player 1: X
Tossing coin...
Player 1 will start first.

Current board state displayed...
Human selects cell: 5
Sensible Computer selects cell: 1
...
```

## Compilation and Execution Example

```bash
$ g++ -o tictactoe tictactoe.cpp
$ ./tictactoe
```

## 👤 Author

Created as an Object-Oriented Programming project

## 📄 License

Open source - feel free to use and modify for educational purposes
